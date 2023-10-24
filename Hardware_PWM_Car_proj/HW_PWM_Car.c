/////////////////////////////////////////////////////////////////////////////
// Course Number: CECS 347
// Example project for Hardware PWM controlled Car
// Description: 
// Hardware connections: assume L298N is used for DC motor driver
// PB67 for motor PWM signals: PB6 - Left DC Motor, PB7 - Right DC Motor
// PB5432 for motor directions: PB54 - left DC Motor, PB32 - right DC Motor
// By Min He, 10/19/2022
/////////////////////////////////////////////////////////////////////////////

//////////////////////1. Pre-processor Directives Section////////////////////
#include "tm4c123gh6pm.h"
#include "PWM.h"
#include "GPIO.h"
/////////////////////////////////////////////////////////////////////////////

//////////////////////2. Declarations Section////////////////////////////////

////////// Local Global Variables //////////

////////// Function Prototypes //////////
void Delay(void);

//////////////////////3. Subroutines Section/////////////////////////////////
// MAIN: This main is meant for the command configuration of the hc05.
int main(void){ 
	LED_Init();
	Car_Dir_Init();
	PWM_PB76_Init();
	PWM_PB76_Duty(START_SPEED, START_SPEED);

	// moving forward
	LED = Green;
	DIRECTION = FORWARD;
	PWM0_ENABLE_R |= 0x00000003; // enable both wheels
	Delay();

	// stop
	LED = Dark;
	PWM0_ENABLE_R &= ~0x00000003; // stop both wheels
	Delay();

	// Enable blue LED,moving backward
	LED = Blue;
	DIRECTION = BACKWARD;
	PWM0_ENABLE_R |= 0x00000003; // enable both wheels
	Delay();

	// stop
	LED = Dark;
	PWM0_ENABLE_R &= ~0x00000003; // stop both wheels
	Delay();

	// Forward left turn
	LED = Yellow;
	DIRECTION=FORWARD;
	PWM0_ENABLE_R |= 0x00000002; // Enable right wheel
	PWM0_ENABLE_R &= ~0x00000001; // Disable left wheel
	Delay();

	// stop
	LED = Dark;
	PWM0_ENABLE_R &= ~0x00000003; // stop both wheels
	Delay();

	// Forward right turn
	LED = Purple;
	DIRECTION=FORWARD;
	PWM0_ENABLE_R &= ~0x00000002; // Disable right wheel
	PWM0_ENABLE_R |= 0x00000001; // Enable left wheel
	Delay();

	// stop
	LED = Dark;
	PWM0_ENABLE_R &= ~0x00000003; // stop both wheels
	Delay();

	// Backward left turn
	LED = Yellow;
	DIRECTION = BACKWARD;
	PWM0_ENABLE_R &= ~0x00000002; // Disable right wheel
	PWM0_ENABLE_R |= 0x00000001; // Enable left wheel
	Delay();
		
	// stop
	LED = Dark;
	PWM0_ENABLE_R &= ~0x00000003; // stop both wheels
	Delay();

	// Backward right turn
	LED = Purple;
	DIRECTION=BACKWARD;
	PWM0_ENABLE_R |= 0x00000002; // Enable right wheel
	PWM0_ENABLE_R &= ~0x00000001; // Disable left wheel
	Delay();

	// stop
	LED = Dark;
	PWM0_ENABLE_R &= ~0x00000003; // stop both wheels
	Delay();

	// Left pivot turn
	LED = Cran;
	DIRECTION=LEFTPIVOT;
	PWM0_ENABLE_R |= 0x00000003; // Enable both wheels
	Delay();

	// stop
	LED = Dark;
	PWM0_ENABLE_R &= ~0x00000003; // stop both wheels
	Delay();

	// right pivot turn
	LED = White;
	DIRECTION=RIGHTPIVOT;
	PWM0_ENABLE_R |= 0x00000003; // Enable both wheels
	Delay();

	LED = Dark;
	PWM0_ENABLE_R &= ~0x00000003; // stop both wheels

	while(1){}
}

// Subroutine to wait 0.25 sec
// Inputs: None
// Outputs: None
// Notes: ...
void Delay(void){
	unsigned long volatile time;
	time = 727240*500/91;  // 0.25sec
	while(time){
		time--;
	}
}
