#ifndef MY_MATH_H_
#define MY_MATH_H_

#include <math.h>
#include "hardware.h"
#include "arm_math.h"
#include "arm_const_structs.h"
#include "printf.h"

#define M_PI          3.14159265358979
#define FFT_SIZE      1024
#define LOG2N         10
#define FREQ_BANDS    16
#define DBFS_REF      2047  // adc output range +-2047
#define DC_OFFSET     17.8
#define BLACKMAN_ENERGY_FACTOR  0.42
#define HAMMING_ENERGY_FACTOR   0.54
#define HANN_ENERGY_FACTOR      0.50

static float data[FFT_SIZE];
static float interleavedData[FFT_SIZE * 2];
static float output[FREQ_BANDS];    // 16 band analyzer
uint8_t heights[FREQ_BANDS];
static float windowTable[FFT_SIZE];

void initBlackmanWindow()
{
  for (int i = 0; i < FFT_SIZE; ++i) {
        windowTable[i] = (0.42 - 0.5*arm_cos_f32((2*M_PI*i) / (FFT_SIZE-1)) + 0.08*arm_cos_f32((4*M_PI*i) / (FFT_SIZE-1)));
    }
}

void initHannWindow()
{
  for (int i = 0; i < FFT_SIZE; ++i) {
        windowTable[i] = 0.5 * (1 - arm_cos_f32((2*M_PI*i) / (FFT_SIZE - 1)));
    }
}

void initHammingWindow()
{
  for (int i = 0; i < FFT_SIZE; ++i) {
        windowTable[i] = 0.5 * (1 - arm_cos_f32((2*M_PI*i) / (FFT_SIZE - 1)));
    }
}

void applyWindowInterleaved()
{
  for (int i = 0; i < FFT_SIZE; ++i) {
        interleavedData[2* i] = interleavedData[2*i] * windowTable[i];
        interleavedData[2* i + 1] = 0;
      }
}

void normalizeInterleaved()
{
  for (int i = 0; i < FFT_SIZE; i++) {
      interleavedData[2*i] = (buffer[i] - DC_OFFSET) / 2047.0f;
  }
}

//void applyWindow()
//{
//  for (int i = 0; i < FFT_SIZE; ++i) {
//      data[i].re = (buffer[i] - DC_OFFSET) * windowTable[i];
//      data[i].im = 0;
//    }
//}

static inline uint16_t bitReverse(uint16_t n)
{
    n = ((n & 0x5555) << 1) | ((n & 0xAAAA) >> 1);
    n = ((n & 0x3333) << 2) | ((n & 0xCCCC) >> 2);
    n = ((n & 0x0F0F) << 4) | ((n & 0xF0F0) >> 4);
    n = ((n & 0x00FF) << 8) | ((n & 0xFF00) >> 8);
    return n >> (16 - LOG2N);
}

//void performBitReversal()
//{
//    for (uint16_t i = 0; i < FFT_SIZE; i++) {
//        uint16_t rev = bitReverse(i);
//        if (i < rev) {
//            complex_f temp = data[i];
//            data[i] = data[rev];
//            data[rev] = temp;
//        }
//    }
//}

// Iterative FFT implementation
//void FFT()
//{
//    performBitReversal();
//    // Iterative FFT computation
//    for (int s = 1; s <= LOG2N; s++) {
//        int m = 1 << s;
//        int m2 = m >> 1;
//        float theta = -2 * M_PI / m;
//        complex_f wm = {cos(theta), sin(theta)}; // Twiddle factor for this stage
//
//        for (int k = 0; k < FFT_SIZE; k += m) {
//            complex_f w = {1.0, 0.0};
//            for (int j = 0; j < m2; j++) {
//                complex_f t = {
//                    w.re * data[k + j + m2].re - w.im * data[k + j + m2].im,
//                    w.re * data[k + j + m2].im + w.im * data[k + j + m2].re
//                };
//                complex_f u = data[k + j];
//                data[k + j].re = u.re + t.re;
//                data[k + j].im = u.im + t.im;
//                data[k + j + m2].re = u.re - t.re;
//                data[k + j + m2].im = u.im - t.im;
//
//                // Incrementally update w
//                complex_f temp;
//                temp.re = w.re * wm.re - w.im * wm.im;
//                temp.im = w.re * wm.im + w.im * wm.re;
//                w = temp;
//            }
//        }
//    }
//}

void magnitudeInterleaved()
{
  // int i = 0;
  // interleavedData[i] = interleavedData[i];
  for (int i = 1; i < FFT_SIZE / 2; i++) {
    interleavedData[2*i] = sqrt(interleavedData[2*i] * interleavedData[2*i] + interleavedData[2*i+1] * interleavedData[2*i+1]);
  }
  // interleavedData[2*i] = interleavedData[i];
}

//void magnitude()
//{
//    int i = 0;
//    data[i].re = fabs(data[i].re);
//    for (i = 1; i < FFT_SIZE / 2; i++) {
//      data[i].re = fabs(sqrt(data[i].re * data[i].re + data[i].im * data[i].im));
//    }
//    data[i].re = fabs(data[i].re);
//}

void condenseInterleaved()
{
  float temp;
  // data[0] is DC (0hz)
  output[0] = interleavedData[2*1];
  output[1] = interleavedData[2*2];
  output[2] = interleavedData[2*3];
  output[3] = interleavedData[2*4];
  int i = 5;
  temp = 0;
  for (; i < 7; i++){
      temp = temp + interleavedData[2*i];
  }
  output[4] = temp / 2;

  temp = 0;
  for (; i < 9; i++){
      temp = temp + interleavedData[2*i];
  }
  output[5] = temp / 2;

  temp = 0;
  for (; i < 13; i++){
      temp = temp + interleavedData[2*i];
  }
  output[6] = temp / 4;

  temp = 0;
  for (; i < 22; i++){
      temp = temp + interleavedData[2*i];
  }
  output[7] = temp / 9;

  temp = 0;
  for (; i < 43; i++){
      temp = temp + interleavedData[2*i];
  }
  output[8] = temp / 21;

  temp = 0;
  for (; i < 86; i++){
      temp = temp + interleavedData[2*i];
  }
  output[9] = temp / 43;

  temp = 0;
  for (; i < 129; i++){
      temp = temp + interleavedData[2*i];
  }
  output[10] = temp / 43;

  temp = 0;
  for (; i < 171; i++){
      temp = temp + interleavedData[2*i];
  }
  output[11] = temp / 42;

  temp = 0;
  for (; i < 214; i++){
      temp = temp + interleavedData[2*i];
  }
  output[12] = temp / 43;

  temp = 0;
  for (; i < 321; i++){
      temp = temp + interleavedData[2*i];
  }
  output[13] = temp / 107;

  temp = 0;
  for (; i < 427; i++){
      temp = temp + interleavedData[2*i];
  }
  output[14] = temp / 106;

  temp = 0;
  for (; i < 512; i++){
      temp = temp + interleavedData[2*i];
  }
  output[15] = temp / 85;
}

//void condense_logarithmic()
//{
//  float temp;
//  output[0] = data[1].re;
//  int i = 1;
//  for (; i < 6; i++){
//      output[i] = data[i+1].re;
//  }
//  temp = 0;
//  for (; i < 8; i++){
//      temp = temp + data[i+1].re;
//  }
//  output[5] = temp / 2;
//
//  temp = 0;
//  for (; i < 11; i++){
//      temp = temp + data[i+1].re;
//  }
//  output[6] = temp / 3;
//
//  temp = 0;
//  for (; i < 17; i++){
//      temp = temp + data[i+1].re;
//  }
//  output[7] = temp / 6;
//
//  temp = 0;
//  for (; i < 26; i++){
//      temp = temp + data[i+1].re;
//  }
//  output[8] = temp / 9;
//
//  temp = 0;
//  for (; i < 39; i++){
//      temp = temp + data[i+1].re;
//  }
//  output[9] = temp / 13;
//
//  temp = 0;
//  for (; i < 60; i++){
//      temp = temp + data[i+1].re;
//  }
//  output[10] = temp / 21;
//
//  temp = 0;
//  for (; i < 91; i++){
//      temp = temp + data[i+1].re;
//  }
//  output[11] = temp / 31;
//
//  temp = 0;
//  for (; i < 141; i++){
//      temp = temp + data[i+1].re;
//  }
//  output[12] = temp / 50;
//
//  temp = 0;
//  for (; i < 216; i++){
//      temp = temp + data[i+1].re;
//  }
//  output[13] = temp / 75;
//
//  temp = 0;
//  for (; i < 333; i++){
//      temp = temp + data[i+1].re;
//  }
//  output[14] = temp / 117;
//
//  temp = 0;
//  for (; i < 511; i++){
//      temp = temp + data[i+1].re;
//  }
//  output[15] = temp / 180;
//}
//
//// bin width = SAMPLE_RATE / FFT_SIZE == 48000 / 1024 == 46.875hz
//void condense()
//{
//  float temp;
//  // data[0] is DC (0hz)
//  output[0] = data[1].re;
//  output[1] = data[2].re;
//  output[2] = data[3].re;
//  output[3] = data[4].re;
//  int i = 5;
//  temp = 0;
//  for (; i < 7; i++){
//      temp = temp + data[i].re;
//  }
//  output[4] = temp / 2;
//
//  temp = 0;
//  for (; i < 9; i++){
//      temp = temp + data[i].re;
//  }
//  output[5] = temp / 2;
//
//  temp = 0;
//  for (; i < 13; i++){
//      temp = temp + data[i].re;
//  }
//  output[6] = temp / 4;
//
//  temp = 0;
//  for (; i < 22; i++){
//      temp = temp + data[i].re;
//  }
//  output[7] = temp / 9;
//
//  temp = 0;
//  for (; i < 43; i++){
//      temp = temp + data[i].re;
//  }
//  output[8] = temp / 21;
//
//  temp = 0;
//  for (; i < 86; i++){
//      temp = temp + data[i].re;
//  }
//  output[9] = temp / 43;
//
//  temp = 0;
//  for (; i < 129; i++){
//      temp = temp + data[i].re;
//  }
//  output[10] = temp / 43;
//
//  temp = 0;
//  for (; i < 171; i++){
//      temp = temp + data[i].re;
//  }
//  output[11] = temp / 42;
//
//  temp = 0;
//  for (; i < 214; i++){
//      temp = temp + data[i].re;
//  }
//  output[12] = temp / 43;
//
//  temp = 0;
//  for (; i < 321; i++){
//      temp = temp + data[i].re;
//  }
//  output[13] = temp / 107;
//
//  temp = 0;
//  for (; i < 427; i++){
//      temp = temp + data[i].re;
//  }
//  output[14] = temp / 106;
//
//  temp = 0;
//  for (; i < 512; i++){
//      temp = temp + data[i].re;
//  }
//  output[15] = temp / 85;
//}

void condense_CMSIS()
{
  float temp;
  // data[0] is DC (0hz)
  output[0] = data[1];
  output[1] = data[2];
  output[2] = data[3];
  output[3] = data[4];
  int i = 5;
  temp = 0;
  for (; i < 7; i++){
      temp = temp + data[i];
  }
  output[4] = temp / 2;

  temp = 0;
  for (; i < 9; i++){
      temp = temp + data[i];
  }
  output[5] = temp / 2;

  temp = 0;
  for (; i < 13; i++){
      temp = temp + data[i];
  }
  output[6] = temp / 4;

  temp = 0;
  for (; i < 22; i++){
      temp = temp + data[i];
  }
  output[7] = temp / 9;

  temp = 0;
  for (; i < 43; i++){
      temp = temp + data[i];
  }
  output[8] = temp / 21;

  temp = 0;
  for (; i < 86; i++){
      temp = temp + data[i];
  }
  output[9] = temp / 43;

  temp = 0;
  for (; i < 129; i++){
      temp = temp + data[i];
  }
  output[10] = temp / 43;

  temp = 0;
  for (; i < 171; i++){
      temp = temp + data[i];
  }
  output[11] = temp / 42;

  temp = 0;
  for (; i < 214; i++){
      temp = temp + data[i];
  }
  output[12] = temp / 43;

  temp = 0;
  for (; i < 321; i++){
      temp = temp + data[i];
  }
  output[13] = temp / 107;

  temp = 0;
  for (; i < 427; i++){
      temp = temp + data[i];
  }
  output[14] = temp / 106;

  temp = 0;
  for (; i < 512; i++){
      temp = temp + data[i];
  }
  output[15] = temp / 85;
}

//void condense_128_band()
//{
//  int i;
//  for (i = 0; i < 64; ++i) {
//      output[i] = data[i+1];
//  }
//  for (; i < 127; ++i) {
//      output[i] = data[i+1];
//  }
//}

uint8_t map_dBFS_to_height(float dBFS_value) {
    // Define the dBFS range
    float min_dBFS = -80.0f;
    float max_dBFS = 0.0f;

    // Define the pixel range
    uint8_t min_pixel = 0;
    uint8_t max_pixel = 55;

    // Map dBFS to pixel using linear interpolation
    int pixel = (int)(((dBFS_value - min_dBFS) / (max_dBFS - min_dBFS)) * (max_pixel - min_pixel) + min_pixel);

    // Clamp the pixel value between 0 and 56 to ensure it's within display range
    if (pixel < min_pixel) {
        pixel = min_pixel;
    } else if (pixel > max_pixel) {
        pixel = max_pixel;
    }

    return pixel;
}

// 56 pixels high will be considered 0 dBFS
uint8_t convert_dBFS_to_heights(float val)
{
  return val + 56;
}

float convert_f_to_dBFS(float val) {
  return 20 * log10f(val / (FFT_SIZE / 2 * BLACKMAN_ENERGY_FACTOR));
}

void convert_to_dBFS()
{
  for (int i = 0; i < FREQ_BANDS; ++i) {
      output[i] = convert_f_to_dBFS(output[i]);
      heights[i] = map_dBFS_to_height(output[i]);
  }
}

float get_DC_offset()
{
  float offset = 0;
  for (int i = 0; i < FFT_SIZE; i++){
      offset += buffer[i] - DC_OFFSET;
  }
  return offset / FFT_SIZE;
}





//void doWork()
//{
//  // printf("DC offset: %f\n\r", get_DC_offset());
//  applyWindow();
//  FFT();
//  magnitude();
//  condense();
//  convert_to_dBFS();
//}

void doWorkCMSIS()
{
  normalizeInterleaved();
  applyWindowInterleaved();
  arm_cfft_f32(&arm_cfft_sR_f32_len1024, interleavedData, 0, 1);
  arm_cmplx_mag_f32(interleavedData, data, FFT_SIZE);
  condense_CMSIS();
  convert_to_dBFS();
}

#endif /* MY_MATH_H_ */
