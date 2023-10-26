#include "tm4c123gh6pm.h"
#include "UART0.h"
#include "BLT.h"
#include "BLT_Interface.h"
#include <stdint.h>  // for data type alias
#include <string.h>

void DisplaySetupPrompt(){	
	//Set up the beginning prompt
	for (i=0; i<5; i++){
		UART0_OutString(SetPrompt[i]);
		while ((UART1_FR_R&UART_FR_BUSY) != 0){};
			UART0_OutString(String);		
	}
}
void ProcessUserInput(){
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
