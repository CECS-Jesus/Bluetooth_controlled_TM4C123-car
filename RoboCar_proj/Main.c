#include "PLL.h"
#include "LED.h"
#include "Motors.h"
#include "Move.h"

// Basic functions defined in startup.s
extern void DisableInterrupts(void);
extern void EnableInterrupts(void);
extern void WaitForInterrupt(void);

void System_Init(void);

int main(void) {
	DisableInterrupts();
	System_Init();
	EnableInterrupts();
	
	PWM_Duty(HALF_SPEED, HALF_SPEED);
	move_forward();
	while(1) {
	}
}

void System_Init(void) {
	PLL_Init();
	LED_Init();
	Motors_Init();
}