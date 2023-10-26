#ifndef BLUETOOTH_H
#define BLUETOOTH_H

#include "tm4c123gh6pm.h"
#include <stdint.h>

void Bluetooth_Init(void);
void UART0_OutChar(unsigned char data);
void UART0_OutString(unsigned char *pt);
unsigned char UART1_InChar(void);
void BLT_InString(unsigned char *bufPt);

#endif