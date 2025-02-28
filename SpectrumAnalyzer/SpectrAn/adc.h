#ifndef ADC_H_
#define ADC_H_

#include "em_iadc.h"

extern int32_t adcResult;
extern uint8_t adcReady;

void IADC_setup(void);

#endif /* ADC_H_ */
