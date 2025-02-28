#include "mcp4162.h"
#include "em_gpio.h"
#include "em_cmu.h"

void mcp4162_init(void)
{
	CMU_ClockEnable(cmuClock_USART0, true);
	GPIO_PinModeSet(gpioPortB, 3, gpioModePushPull, 0);	// configure PB3 for output (MOSI)
	GPIO_PinModeSet(gpioPortB, 2, gpioModePushPull, 0);	// configure PB2 for output (SLCK)
	GPIO_PinModeSet(gpioPortC, 0, gpioModeInput, 0);		// configure PC0 for input  (MISO)
	GPIO_PinModeSet(gpioPortB, 1, gpioModePushPull, 1);	// configure PB1 for output (CS)

	GPIO->USARTROUTE[0].TXROUTE =  gpioPortB | (3 << _GPIO_USART_TXROUTE_PIN_SHIFT);
	GPIO->USARTROUTE[0].CLKROUTE = gpioPortB | (2 << _GPIO_USART_CLKROUTE_PIN_SHIFT);
	GPIO->USARTROUTE[0].RXROUTE =  gpioPortC | (0 << _GPIO_USART_RXROUTE_PIN_SHIFT);
	GPIO->USARTROUTE[0].CSROUTE =  gpioPortB | (1 << _GPIO_USART_CSROUTE_PIN_SHIFT);

	GPIO->USARTROUTE[0].ROUTEEN = GPIO_USART_ROUTEEN_RXPEN + GPIO_USART_ROUTEEN_TXPEN +
			GPIO_USART_ROUTEEN_CLKPEN + GPIO_USART_ROUTEEN_CSPEN;
	USART_InitSync_TypeDef spiInit = USART_INITSYNC_DEFAULT;
	spiInit.baudrate = 1000000;
	spiInit.master = true;
	spiInit.msbf = true;
	spiInit.autoCsEnable = true;
	spiInit.autoCsSetup = 5;
	spiInit.autoCsHold = 5;
	spiInit.databits = usartDatabits8;
	USART_InitSync(USART0, &spiInit);
}

uint8_t mcp4162_readStatus(void)
{
	USART_Tx(USART0, 0x5C);												// send read command
	USART_Tx(USART0, 0);													// send fake byte
	USART0->CMD = USART_CMD_CLEARRX;									// clear USART RX FIFO buffer
	while (!(USART0->STATUS & USART_STATUS_TXC)) {}
	while (!(USART0->STATUS & USART_STATUS_RXDATAV)) {}
	return ((USART0->RXDOUBLE)>>8);
}

uint8_t mcp4162_readVwiper(void)					// read volatile wiper position
{
	USART_Tx(USART0, 0x0C);												// send read command
	USART_Tx(USART0, 0);													// send fake byte
	USART0->CMD = USART_CMD_CLEARRX;									// clear USART RX FIFO buffer
	while (!(USART0->STATUS & USART_STATUS_TXC)) {}
	while (!(USART0->STATUS & USART_STATUS_RXDATAV)) {}
	return ((USART0->RXDOUBLE)>>8);
}

uint8_t mcp4162_readNVwiper(void)				// read non-volatile wiper position
{
	USART_Tx(USART0, 0x2C);												// send read command
	USART_Tx(USART0, 0);													// send fake byte
	USART0->CMD = USART_CMD_CLEARRX;									// clear USART RX FIFO buffer
	while (!(USART0->STATUS & USART_STATUS_TXC)) {}
	while (!(USART0->STATUS & USART_STATUS_RXDATAV)) {}
	return ((USART0->RXDOUBLE)>>8);
}

void mcp4162_writeVwiper(uint8_t p)				// write volatile wiper position
{
	USART_Tx(USART0, 0x00);												// send write command
	USART_Tx(USART0, p);													// send data byte
	while (!(USART0->STATUS & USART_STATUS_TXC)) {}				// wait for end of transfer
}

void mcp4162_writeNVwiper(uint8_t p)			// write non-volatile wiper position
{
	USART_Tx(USART0, 0x20);												// send write command
	USART_Tx(USART0, p);													// send data byte
	while (!(USART0->STATUS & USART_STATUS_TXC)) {}				// wait for end of transfer
}

void mcp4162_incVwiper(void)						// increment volatile wiper position
{
	USART_Tx(USART0, 0x04);												// send write command
	while (!(USART0->STATUS & USART_STATUS_TXC)) {}				// wait for end of transfer
}

void mcp4162_decVwiper(void)						// decrement volatile wiper position
{
	USART_Tx(USART0, 0x08);												// send write command
	while (!(USART0->STATUS & USART_STATUS_TXC)) {}				// wait for end of transfer
}

void mcp4162_incNVwiper(void)						// increment non-volatile wiper position
{
	USART_Tx(USART0, 0x24);												// send write command
	while (!(USART0->STATUS & USART_STATUS_TXC)) {}				// wait for end of transfer
}

void mcp4162_decNVwiper(void)						// decrement non-volatile wiper position
{
	USART_Tx(USART0, 0x28);												// send write command
	while (!(USART0->STATUS & USART_STATUS_TXC)) {}				// wait for end of transfer
}
