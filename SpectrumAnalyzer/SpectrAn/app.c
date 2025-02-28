#include "hardware.h"
#include "ssd1306.h"
#include "mcp4162.h"
#include "adc.h"
#include "printf.h"
#include "my_math.h"

static int i;
static uint8_t heights_old[FREQ_BANDS];
// static int32_t max, min;

void app_init(void)
{
  GPIO_init();
  IADC_setup();
  LDMA_init();
  ssd1306_init();
  ssd1306_clearDisplay();
  mcp4162_init();
  initBlackmanWindow();
  printf("Wiper position: %d\n\r", mcp4162_readVwiper());
}

void app_process_action(void)
{
  IADC_command(IADC0, iadcCmdStartSingle);
  GPIO_PinOutSet(LED0_PORT, LED0_PIN);
  EMU_EnterEM1();
  if (adcReady) {
    adcReady = 0;
    doWorkCMSIS();
    for (i=0; i<FREQ_BANDS; i++) {
      ssd1306_updateVerticalBar(i<<3, heights[i], heights_old[i]);
      heights_old[i] = heights[i];
    }
    ssd1306_drawAveragedWaveform(buffer, FFT_SIZE);
//    max = buffer[0];
//    min = buffer[0];
//    for (i=0; i<FFT_SIZE; ++i) {
//        if (buffer[i] > max)
//          max = buffer[i];
//        if (buffer[i] < min)
//          min = buffer[i];
//    }
  }
//   printf("Max: %d\tMin: %d\n\r", max, min);
}

