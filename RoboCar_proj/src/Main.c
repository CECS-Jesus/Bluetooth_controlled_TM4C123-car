#define MAX_ASCII 255

#include "PLL.h"
#include "LED.h"
#include "Motors.h"
#include "Bluetooth.h"
#include "Move.h"
#include <ctype.h>

void System_Init(void);
void InvalidInput(void);

// User input = idx, moveChoices[idx] = run function
void (*moveChoices[MAX_ASCII])(void);

int main(void) {
	System_Init();

	unsigned char userInput;
	for (int i = 0; i < MAX_ASCII; i++)
		moveChoices[i] = InvalidInput;
	moveChoices['f'] = MoveForward;
	moveChoices['b'] = MoveBackward;
	moveChoices['l'] = MoveLeftTurn;
	moveChoices['r'] = MoveRightTurn;
	moveChoices['s'] = MoveStop;
	moveChoices['u'] = IncrementSpeed;
	moveChoices['d'] = DecrementSpeed;

	while(1) {
		userInput = UART1_InChar();
		moveChoices[tolower(userInput)]();
	}
}

void System_Init(void) {
	PLL_Init();
	LED_Init();
	Motors_Init();
	Bluetooth_Init();
}

void InvalidInput(void) {
	//UART0_OutString((unsigned char *)"Invalid Input\n\r");
}