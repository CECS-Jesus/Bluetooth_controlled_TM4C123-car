#include "Move.h"

#define DIRECTION	(*((volatile unsigned long *)0x4002403C))	// Mask for PE0-3
#define FORWARD 	0x0F	//1111
#define BACKWARD 	0x0A	//1010
#define LEFTPIVOT 	0x09	//1001
#define RIGHTPIVOT 	0x06	//0110
#define L_MOTOR		0x02	// M0PWM1
#define R_MOTOR		0x01	// M0PWM0

// Car movements
void MoveForward(void) {
	LED = Green;
	DIRECTION = FORWARD;
	PWM0_ENABLE_R |= L_MOTOR;	// enable left wheel
	PWM0_ENABLE_R |= R_MOTOR;	// enable right wheel
}

void MoveBackward(void) {
	LED = Blue;
	DIRECTION = BACKWARD;
	PWM0_ENABLE_R |= L_MOTOR;	// enable left wheel
	PWM0_ENABLE_R |= R_MOTOR;	// enable right wheel
}

// Turn left in place
void MoveLeftPivot(void) {
	LED = Yellow;
	DIRECTION = LEFTPIVOT;
	PWM0_ENABLE_R |= L_MOTOR;	// enable left wheel
	PWM0_ENABLE_R |= R_MOTOR;	// enable right wheel
}

// Turn right in place
void MoveRightPivot(void) {
	LED = Purple;
	DIRECTION = RIGHTPIVOT;
	PWM0_ENABLE_R |= L_MOTOR;	// enable left wheel
	PWM0_ENABLE_R |= R_MOTOR;	// enable right wheel
}

void MoveLeftTurn(void) {
	LED = Yellow;
	DIRECTION = FORWARD;
	PWM0_ENABLE_R &= ~L_MOTOR; 	// stop left wheel
	PWM0_ENABLE_R |= R_MOTOR; 	// enable right wheel
}

void MoveRightTurn(void) {
	LED = Purple;
	DIRECTION = FORWARD;
	PWM0_ENABLE_R |= L_MOTOR; 	// enable left wheel
	PWM0_ENABLE_R &= ~R_MOTOR; 	// stop right wheel
}

void MoveLeftBackTurn(void) {
	LED = Blue;
	DIRECTION = BACKWARD;
	PWM0_ENABLE_R &= ~L_MOTOR; 	// stop left wheel
	PWM0_ENABLE_R |= R_MOTOR; 	// enable right wheel
}

void MoveRightBackTurn(void) {
	LED = Blue;
	DIRECTION = BACKWARD;
	PWM0_ENABLE_R |= L_MOTOR; 	// enable left wheel
	PWM0_ENABLE_R &= ~R_MOTOR; 	// stop right wheel
}

void MoveStop(void) {
	LED = Dark;
	PWM0_ENABLE_R &= ~L_MOTOR; 	// stop right wheel
	PWM0_ENABLE_R &= ~R_MOTOR; 	// stop left wheel
}