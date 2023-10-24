#include "Move.h"

#define DIRECTION	(*((volatile unsigned long *)0x4002403C))	// Mask for PE0-3
#define FORWARD 	0x0F	//1111
#define BACKWARD 	0x0A	//1010
#define LEFTPIVOT 	0x09	//1001
#define RIGHTPIVOT 	0x06	//0110
#define L_MOTOR		0x02	// M0PWM1
#define R_MOTOR		0x01	// M0PWM0

// Car movements
void move_forward(void) {
	LED = Green;
	DIRECTION = FORWARD;
	PWM0_ENABLE_R |= L_MOTOR;	// enable left wheel
	PWM1_ENABLE_R |= R_MOTOR;	// enable right wheel
}

void move_backward(void) {
	LED = Blue;
	DIRECTION = BACKWARD;
	PWM0_ENABLE_R |= L_MOTOR;	// enable left wheel
	PWM1_ENABLE_R |= R_MOTOR;	// enable right wheel
}

// Turn left in place
void move_l_piv(void) {
	LED = Yellow;
	DIRECTION = LEFTPIVOT;
	PWM0_ENABLE_R |= L_MOTOR;	// enable left wheel
	PWM1_ENABLE_R |= R_MOTOR;	// enable right wheel
}

// Turn right in place
void move_r_piv(void) {
	LED = Purple;
	DIRECTION = RIGHTPIVOT;
	PWM0_ENABLE_R |= L_MOTOR;	// enable left wheel
	PWM1_ENABLE_R |= R_MOTOR;	// enable right wheel
}

void move_l_turn(void) {
	LED = Yellow;
	DIRECTION = FORWARD;
	PWM0_ENABLE_R &= ~L_MOTOR; 	// stop left wheel
	PWM1_ENABLE_R |= R_MOTOR; 	// enable right wheel
}

void move_r_turn(void) {
	LED = Purple;
	DIRECTION = FORWARD;
	PWM0_ENABLE_R |= L_MOTOR; 	// enable left wheel
	PWM1_ENABLE_R &= ~R_MOTOR; 	// stop right wheel
}

void move_l_back_turn(void) {
	LED = Blue;
	DIRECTION = BACKWARD;
	PWM0_ENABLE_R &= ~L_MOTOR; 	// stop left wheel
	PWM1_ENABLE_R |= R_MOTOR; 	// enable right wheel
}

void move_r_back_turn(void) {
	LED = Blue;
	DIRECTION = BACKWARD;
	PWM0_ENABLE_R |= L_MOTOR; 	// enable left wheel
	PWM1_ENABLE_R &= ~R_MOTOR; 	// stop right wheel
}

void move_stop(void) {
	LED = Dark;
	PWM0_ENABLE_R &= ~L_MOTOR; 	// stop right wheel
	PWM1_ENABLE_R &= ~R_MOTOR; 	// stop left wheel
}