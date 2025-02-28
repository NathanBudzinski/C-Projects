#include "adc.h"
#include "em_cmu.h"
#include "em_gpio.h"

#define CLK_SRC_ADC_FREQ      40000000    // CLK_SRC_ADC - 40 MHz max
#define CLK_ADC_FREQ          10000000   // CLK_ADC - 10MHz max in normal mode
#define SAMPLING_RATE         48000

uint8_t adcReady;

void IADC_setup(void)
{
  IADC_Init_t init = IADC_INIT_DEFAULT;
  IADC_AllConfigs_t initAllConfigs = IADC_ALLCONFIGS_DEFAULT;
  IADC_InitSingle_t initSingle = IADC_INITSINGLE_DEFAULT;
  IADC_SingleInput_t initSingleInput = IADC_SINGLEINPUT_DEFAULT;

  CMU_ClockSelectSet(cmuClock_EM01GRPACLK, cmuSelect_HFXO);
  CMU_ClockEnable(cmuClock_IADC0, true);
  IADC_reset(IADC0);                          // Reset IADC to reset configuration
//  CMU_ClockSelectSet(cmuClock_IADCCLK, cmuSelect_FSRCO);    // set FSRCO as ADC clock - 20MHz
  CMU_ClockSelectSet(cmuClock_IADCCLK, cmuSelect_EM01GRPACLK);
  init.srcClkPrescale = IADC_calcSrcClkPrescale(IADC0, CLK_SRC_ADC_FREQ, 0);
  init.timerCycles = CMU_ClockFreqGet(cmuClock_IADCCLK)/SAMPLING_RATE;

  init.warmup = iadcWarmupKeepWarm;
//  init.iadcClkSuspend1 = true;

  initAllConfigs.configs[0].reference = iadcCfgReferenceInt1V2;
  initAllConfigs.configs[0].vRef = 1210;
  initAllConfigs.configs[0].osrHighSpeed = iadcCfgOsrHighSpeed2x;

//  init.srcClkPrescale = IADC_calcSrcClkPrescale(IADC0, CLK_ADC_FREQ, 0);
  initAllConfigs.configs[0].adcClkPrescale = IADC_calcAdcClkPrescale(IADC0, CLK_ADC_FREQ, 0, iadcCfgModeNormal, init.srcClkPrescale);

//  initSingle.triggerSelect = iadcTriggerSelPrs0PosEdge;
  initSingle.triggerSelect = iadcTriggerSelTimer;
  initSingle.triggerAction = iadcTriggerActionOnce;
  initSingle.dataValidLevel = iadcFifoCfgDvl2;
  initSingle.alignment = iadcAlignRight12;
  initSingle.showId = false;
  initSingle.fifoDmaWakeup = true;
  initSingle.start = false;
  initSingleInput.posInput = iadcPosInputPortBPin4;   // ADC input at PB4
  initSingleInput.negInput = iadcNegInputPortCPin1;   // ref for differential measurement

  IADC0->EN_CLR = IADC_EN_EN;                 // ADC calibration
  IADC0->CFG[0]. SCALE = 0x8002AE00;
  IADC0->EN_SET = IADC_EN_EN;

  IADC_init(IADC0, &init, &initAllConfigs);         // Initialize IADC
  IADC_initSingle(IADC0, &initSingle, &initSingleInput);
  IADC_command(IADC0, IADC_CMD_SINGLEFIFOFLUSH);
  IADC_command(IADC0, iadcCmdEnableTimer);

  GPIO->BBUSALLOC = GPIO_CDBUSALLOC_CDEVEN0_ADC0;     // allocate analog buses
  GPIO->CDBUSALLOC = GPIO_CDBUSALLOC_CDODD0_ADC0;
  adcReady = 0;

//  IADC_enableInt(IADC0, IADC_IEN_SINGLEDONE);
//  NVIC_ClearPendingIRQ(IADC_IRQn);
//  NVIC_EnableIRQ(IADC_IRQn);
}

//void IADC_IRQHandler(void)
//{
//  GPIO_PinOutToggle(gpioPortB, 0);
//  IADC_clearInt(IADC0, IADC_IF_SINGLEDONE);
//}
