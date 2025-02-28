#include "ssd1306.h"
#include "font_5x7.h"
#include "sl_string.h"

#define WAVEFORM_GAIN       1
#define WAVEFORM_DC_OFFSET  17.8
#define FFT_SIZE            1024

static unsigned char buffer[129];
static I2C_TransferSeq_TypeDef seq;
static const uint8_t init[] = {0x00, 0xA8, 0x3F, 0xD3, 0x00, 0x40, 0xA1, 0xC8, 0xDA, ((SSD1306_LCDHEIGHT/64)<<4)+2, 0x81, 0xFF, 0xA4, 0xA6, 0xD5, 0x80, 0x8D, 0x14, 0xAF};
static uint8_t setXY[] = {0x00, 0x21, 0x00, SSD1306_LCDWIDTH-1, 0x22, 0x00, SSD1306_LCDHEIGHT/8-1};
#define BAR_WIDTH   4 //SSD1306_LCDWIDTH / 16; // divide the display into 16 bars 8 pixels wide
const unsigned char barHeights[9] = {0x00, 0x80, 0xC0, 0xE0, 0xF0, 0xF8, 0xFC, 0xFE, 0xFF};
static uint8_t avgWaveCount = 0;
static int16_t avgWaveTable[FFT_SIZE];
static int16_t avgWaveTablePrev[FFT_SIZE];

void ssd1306_init(void) {
  seq.addr = SSD1306_SLAVE_ADDRESS;
  seq.buf[0].data = (uint8_t*) init;
  seq.buf[0].len = sizeof(init);
  seq.flags = I2C_FLAG_WRITE;
  I2CSPM_Transfer(I2C1, &seq);
}

void ssd1306_clearDisplay(void) {
  uint8_t i;
  buffer[0] = 0x40;
  for (i=1; i<=128; i++)
    buffer[i] = 0;                      // value to fill on screen
  for (i=0; i<SSD1306_LCDHEIGHT/8; i++) {     // loop over all OLED pages
    ssd1306_setPosition(0, i);
    seq.buf[0].data = buffer;
    seq.buf[0].len = 129;
    I2CSPM_Transfer(I2C1, &seq);
  }
}

void ssd1306_setPosition(uint8_t column, uint8_t page) {
  seq.buf[0].data = setXY;
  seq.buf[0].len = sizeof(setXY);
  setXY[2] = column;
  setXY[5] = page;
  I2CSPM_Transfer(I2C1, &seq);
}

void ssd1306_printVerticalBar(uint8_t x, uint8_t height, uint8_t color)
{
  uint8_t temp;
//  if (height < 1)
//    height = 0;
  if (height <= 1) return;
  if (height > 64)
    height = 64;
  uint8_t y = 7;
  int i;
  buffer[0] = 0x40;
  temp = (color) ? 0xFF : 0;
  while (height > 8) {
    ssd1306_setPosition(x, y);
    seq.buf[0].data = buffer;
    seq.buf[0].len = BAR_WIDTH + 1;
    for (i = 0; i < 8; i++)
      buffer[i+1] = temp;
    I2CSPM_Transfer(I2C1, &seq);
    height -= 8;
    y--;
  }
  if (height > 0) {         // print the top part only if needed
    ssd1306_setPosition(x, y);
    seq.buf[0].data = buffer;
    seq.buf[0].len = BAR_WIDTH + 1;
    temp = (color) ? barHeights[height] : 0;
    for (i = 0; i < 8; i++)
      buffer[i+1] = temp;
    I2CSPM_Transfer(I2C1, &seq);
  }
}

void ssd1306_updateVerticalBar(uint8_t x, uint8_t height_new, uint8_t height_old)
{
  int8_t i, fill, diff, diff2, y;
  if (height_old > 64) height_old = 64;
  if (height_new > 64) height_new = 64;
  if (height_old == 0) height_old = 1;
  if (height_new == 0) height_new = 1;
  diff = diff2 = height_new - height_old;
  if (diff2 == 0) return;             //new bar is the same as the old one
  y = 7-(height_old>>3);            // 1st page number to update (bottom=7, top=0)
  if (diff2 > 0)
    diff = height_new - (height_old&0xf8);
  else {
    if ((height_old & 7) == 0) {        // old height is a multiple of 8
      if ((height_new & 7) == 0)        // new height is a multiple of 8
        diff = height_old - height_new;
      else                      // new height is not a multiple of 8
        diff = height_old - ((height_new+8)&0xf8) + (height_new&7);
      y++;
    }
    else {                      // old height is not a multiple of 8
      if ((height_new & 7) == 0)        // new height is a multiple of 8
        diff = ((height_old+8)&0xf8) - height_new;
      else
        diff = ((height_old+8)&0xf8) - ((height_new+8)&0xf8) + (height_new&7);
    }
  }

  fill = (diff2 > 0) ? 0xff : 0;        // "color to draw" (black or white)
  while (diff >= 8) {               // draw complete 8x8 bar segment
    ssd1306_setPosition(x, y);
    seq.buf[0].data = buffer;
    seq.buf[0].len = BAR_WIDTH + 1;
    for (i = 0; i < 8; i++)
      buffer[i+1] = fill;
    I2CSPM_Transfer(I2C1, &seq);
    diff -= 8;
    (diff2 > 0) ? y-- : y++;
  }
  if (diff > 0) {                 // draw possibly incomplete top bar's segment
//    fill = (diff2 > 0) ? barHeights[diff] : 0;
    ssd1306_setPosition(x, y);
    seq.buf[0].data = buffer;
    seq.buf[0].len = BAR_WIDTH + 1;
    for (i = 0; i < 8; i++)
      buffer[i+1] = barHeights[diff];
    I2CSPM_Transfer(I2C1, &seq);
  }
}

int32_t map(int32_t x, int32_t in_min, int32_t in_max, int32_t out_min, int32_t out_max) {
    return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

void ssd1306_drawWaveform(int16_t* samples, int fftSize)
{
  ssd1306_setPosition(0, 0);
  buffer[0] = 0x40;
  float avg = 0;
  for (int i = 0; i < fftSize; ++i) {
      avg += samples[i] - WAVEFORM_DC_OFFSET;
      if ((i+1) % 8 == 0) {
          avg /= 8;
          avg /= 2047;
          avg *= 3.5;   // range +- 3.5
          avg += 3.5;   // range 0, 7
          buffer[(i+1)/8] = 1 << (int)avg;
          avg = 0;
      }
  }
  seq.buf[0].data = buffer;
  seq.buf[0].len = 129;
  I2CSPM_Transfer(I2C1, &seq);
}

//void ssd1306_drawAveragedWaveform(int32_t* samples, int fftSize, int num_avg)
//{
//  if (avgWaveCount < num_avg) {
//      avgWaveCount++;
//      for (int i = 0; i < fftSize; ++i) {
//          avgWaveTable[i] += samples[i];
//      }
//  }
//  if (avgWaveCount == num_avg) {
//      avgWaveCount++;
//      for (int i = 0; i < fftSize; i++) {
//          avgWaveTable[i] = (avgWaveTable[i] + samples[i]) / num_avg;
//      }
//  }
//  if (avgWaveCount > num_avg) {
//      avgWaveCount = 0;
//      ssd1306_drawWaveform(avgWaveTable, fftSize);
//      for (int i = 0; i < fftSize; ++i) {
//          avgWaveTable[i] = samples[i];
//      }
//  }
//}

void ssd1306_drawAveragedWaveform(int32_t* samples, int fftSize)
{
  switch (avgWaveCount) {
    case 0:
      avgWaveCount++;
      for (int i = 0; i < fftSize; ++i) {
          avgWaveTablePrev[i] = samples[i];
      }
      break;

    case 1:
      avgWaveCount++;
      for (int i = 0; i < fftSize; ++i) {
          avgWaveTable[i] = avgWaveTablePrev[i] + samples[i];
      }
      ssd1306_drawWaveform(avgWaveTable, fftSize);
      break;

    default:
      for (int i = 0; i < fftSize; ++i) {
          avgWaveTable[i] = avgWaveTable[i] - avgWaveTablePrev[i] + samples[i];
          avgWaveTablePrev[i] = avgWaveTable[i];
      }
      ssd1306_drawWaveform(avgWaveTable, fftSize);
      break;
  }
}

void ssd1306_printText(uint8_t x, uint8_t y, char *ptString) {
  uint8_t i;
  ssd1306_setPosition(x, y);
  buffer[0] = 0x40;                     // control byte
  buffer[6] = 0x0;                      // separation column
  seq.buf[0].data = buffer;
  seq.buf[0].len = 7;                   // send 7 bytes per character

  while (*ptString != '\0') {
    if ((x + 5) >= SSD1306_LCDWIDTH) {          // char will run off screen
      x = 0;                                  // set column to 0
      y = (y+1) & (SSD1306_LCDHEIGHT/8-1);      // jump to next page
      ssd1306_setPosition(x, y);                // send position change to oled
    }

    for (i=0; i<5; i++) {
      buffer[i+1] = font_5x7[*ptString - ' '][i];
    }

    I2CSPM_Transfer(I2C1, &seq);
    ptString++;
    x = (x+6) & (SSD1306_LCDWIDTH-1);
  }
}

void ssd1306_printTextBlock(uint8_t x, uint8_t y, char *ptString) {
  char word[12];
  uint8_t i;
  uint8_t endX = x;
  while (*ptString != '\0') {             // extract the next word
    i = 0;
    while ((*ptString != ' ') && (*ptString != '\0')) {
      word[i] = *ptString;
      ptString++;
      i++;
      endX += 6;
    }
    word[i++] = '\0';                   // terminating zero

    if (endX >= 127) {                  // print the word on a new line
      x = 0;
      y++;
      ssd1306_printText(x, y, word);
      endX = (i * 6);
      x = endX;
    } else {                          // print the word in the same line
      ssd1306_printText(x, y, word);
      endX += 6;
      x = endX;
    }
    if (*ptString != '\0')
      ptString++;
  }
}

void ssd1306_printInt( uint8_t x, uint8_t y, int32_t val, uint8_t Hcenter ) {
  char text[14];
  uint32_t length, xx;
  length = sprintf(text, "%d", (int) val);
  xx = SSD1306_LCDWIDTH/2 - 3*length;
  if (Hcenter) {
    ssd1306_printText(xx, y, text);
  } else {
    ssd1306_printText(x, y, text);
  }
}
