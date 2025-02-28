#ifndef HARDWARE_H_
#define HARDWARE_H_

#include "em_ldma.h"
#include "em_prs.h"
#include "em_timer.h"
#include "em_gpio.h"
#include "em_emu.h"

#define LED0_PORT   gpioPortA
#define LED0_PIN    4
#define BTN0_PORT   gpioPortC
#define BTN0_PIN    7
#define NUM_SAMPLES 1024

extern int32_t buffer[NUM_SAMPLES];

void GPIO_init(void);
void LDMA_init(void);

#endif /* HARDWARE_H_ */
