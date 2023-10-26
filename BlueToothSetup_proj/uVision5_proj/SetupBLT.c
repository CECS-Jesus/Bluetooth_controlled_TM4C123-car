// SetupBLT.c
// Runs on TM4C123
// This is an example program to setup HC-05 Bluetooth module with no user interface.
// UART0 is used for the TM4C123 to communicate with PC serial terminal, 
// UART1 is used for the TM4C123 to cummunicate with HC-05 Bluetooth module
// U1Rx (PB0) connects to HC-05 TXD pin
// U1Tx (PB1) connects to HC-05 RXD pin
// HC-05 VCC connects to vbus pin on TM4C123
// HC-05 EN connects to +3.3v
// By Min He,10/11/2022

#include "tm4c123gh6pm.h"
#include "UART0.h"
#include "BLT.h"
#include "BLT_Interface.h"
#include <stdint.h>  // for data type alias
#include <string.h>

// main function for programming BT device with no UI
int main(void) {
  UART0_Init();
	BLT_Init();
	DisplaySetupPrompt();
	while (1){
		ProcessUserInput();
	}
}

