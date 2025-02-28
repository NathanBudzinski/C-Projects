#include "hardware.h"
#include "em_iadc.h"
#include "adc.h"
#include "em_cmu.h"
#include "dmadrv.h"

#define PRS_CHANNEL   0
#define IADC_LDMA_CH    0
#define SAMPLE_FREQ     48000

static bool LDMA_callback(unsigned int channel, unsigned int sequenceNo, void *userParam);
static LDMA_TransferCfg_t transferCfg;
static LDMA_Descriptor_t descriptor;
static unsigned int dma_channel;
int32_t buffer[NUM_SAMPLES];

void GPIO_init(void)
{
  CMU_ClockEnable(cmuClock_GPIO, true);
  GPIO_PinModeSet(LED0_PORT, LED0_PIN, gpioModePushPull, 0);
  GPIO_PinModeSet(BTN0_PORT, BTN0_PIN, gpioModeInputPullFilter, 1);
}

void LDMA_init(void)
{
  transferCfg = (LDMA_TransferCfg_t) LDMA_TRANSFER_CFG_PERIPHERAL(ldmaPeripheralSignal_IADC0_IADC_SINGLE);
  descriptor = (LDMA_Descriptor_t) LDMA_DESCRIPTOR_LINKREL_P2M_WORD(&IADC0->SINGLEFIFODATA, buffer, NUM_SAMPLES, 0);
  DMADRV_Init();
  DMADRV_AllocateChannel(&dma_channel, NULL);
  DMADRV_LdmaStartTransfer(dma_channel, &transferCfg, &descriptor, LDMA_callback, NULL);
}

static bool LDMA_callback(unsigned int channel, unsigned int sequenceNo, void *userParam)
{
  (void) channel;
  (void) sequenceNo;
  (void) userParam;
  IADC_command(IADC0, iadcCmdStopSingle);
  adcReady = 1;
  GPIO_PinOutClear(LED0_PORT, LED0_PIN);
  return(true);
}

