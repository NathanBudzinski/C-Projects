#ifndef MCP4162_H_
#define MCP4162_H_

#include "stdint.h"
#include "em_usart.h"

void mcp4162_init(void);
uint8_t mcp4162_readStatus(void);
uint8_t mcp4162_readVwiper(void);
uint8_t mcp4162_readNVwiper(void);
void mcp4162_writeVwiper(uint8_t p);
void mcp4162_writeNVwiper(uint8_t p);
void mcp4162_incVwiper(void);
void mcp4162_decVwiper(void);
void mcp4162_incNVwiper(void);
void mcp4162_decNVwiper(void);
#endif /* MCP4162_H_ */
