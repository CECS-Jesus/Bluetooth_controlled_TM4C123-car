//////////// SetupBLT.c
//////////// Runs on TM4C123
//////////// This is an example program to setup HC-05 Bluetooth module with no user interface.
//////////// UART0 is used for the TM4C123 to communicate with PC serial terminal, 
//////////// UART1 is used for the TM4C123 to cummunicate with HC-05 Bluetooth module
//////////// U1Rx (PB0) connects to HC-05 TXD pin
//////////// U1Tx (PB1) connects to HC-05 RXD pin
//////////// HC-05 VCC connects to vbus pin on TM4C123
//////////// HC-05 EN connects to +3.3v
//////////// By Min He,10/11/2022

#include "tm4c123gh6pm.h"
#include "UART0.h"
#include "BLT.h"
#include <stdint.h>  // for data type alias
#include <string.h>

// main function for programming BT device with no UI
int main(void) {
	uint8_t String[66];
	uint8_t userInput[66];
	uint8_t output[66];
	uint8_t newline [66] = "\r\n";
	uint8_t i;
	uint8_t quesMark = 0; //question mark flag
	uint8_t SetPrompt[][66] = {">>>Welcome to Serial Terminal.<<< \r\n",">>>This is the setup program for HC-05 Bluetooth module.<<< \r\n",
	">>>You are 'AT' Command Mode.<<< \r\n",">>>Type 'AT' Command Mode.<<< \r\n",">>>Example: AT+NAME = Your Name.<<< \r\n"};
  UART0_Init();
	BLT_Init();
  
  // Setup the Begining Prompt
	for (i=0;i<5;i++) {
		UART0_OutString(SetPrompt[i]); 				
    while ((UART1_FR_R&UART_FR_BUSY) != 0){};
			UART0_OutString(String);
	}
	
	while (1) {
    UART0_NextLine(); // new line
    UART0_InString(userInput, 66); // user enters an input
    BLT_OutString(userInput); // input will be sent to blt
    BLT_OutString(newline); // new line will be sent to blt
		
    while ((UART1_FR_R&UART_FR_BUSY) != 0){}; // Wait for a response from the Bluetooth module
			
			// Capture the response from bluetooth
			BLT_InString(output); //blt will read input
			UART0_NextLine(); //next line
			UART0_OutString(output); //blt rill respond to user
			UART0_NextLine(); //next line
				
			if(userInput[7] == '?'){ //if at index 7 there is a question mark
				// Capture the response from bluetooth
				BLT_InString(output); 
				UART0_OutString(output); 
				UART0_NextLine();
			}
	}
}

