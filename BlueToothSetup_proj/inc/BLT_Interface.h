#include "tm4c123gh6pm.h"
#include <stdint.h>  // for data type alias
#include <string.h>

uint8_t userInput[66];
uint8_t output[66];
uint8_t newline [66] = "\r\n";
uint8_t i;
uint8_t String[66];
uint8_t SetPrompt[][66] = {
		">>>Welcome to Serial Terminal.<<< \r\n",
		">>>This is the setup program for HC-05 Bluetooth module.<<< \r\n",
		">>>You are 'AT' Command Mode.<<< \r\n",
		">>>Type 'AT' Command Mode.<<< \r\n",
		">>>Example: AT+NAME = Your Name.<<< \r\n"
};

void DisplaySetupPrompt();
void ProcessUserInput();