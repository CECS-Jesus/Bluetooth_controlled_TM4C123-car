#include "Motors.h"

#define SPEED_STEP			PERIOD * 0.1
uint64_t currDuty;

void LeftMotor_Init(void);
void RightMotor_Init(void);
void MotorDirection_Init(void);

void Motors_Init(void) {
	currDuty = STOP;
	RightMotor_Init();		// PB6/M0PWM0
	LeftMotor_Init();		// PB7/M0PWM1
	MotorDirection_Init();	// DIR/SLP motor pins on GPIOPortE
}

// Output on PB7/M0PWM1 left motor
void LeftMotor_Init(void) {
	SYSCTL_RCGCPWM_R |= 0x01;             // 1) activate PWM0
	SYSCTL_RCGCGPIO_R |= 0x02;            // 2) activate port B
	GPIO_PORTB_AFSEL_R |= 0x80;           // enable alt funct on PB7
	GPIO_PORTB_PCTL_R &= ~0xF0000000;     // configure PB7 as M0PWM1
	GPIO_PORTB_PCTL_R |= 0x40000000;
	GPIO_PORTB_AMSEL_R &= ~0x80;          // disable analog functionality on PB7
	GPIO_PORTB_DEN_R |= 0x80;             // enable digital I/O on PB7
	SYSCTL_RCC_R |= SYSCTL_RCC_USEPWMDIV; // 3) use PWM divider
	SYSCTL_RCC_R &= ~SYSCTL_RCC_PWMDIV_M; //    clear PWM divider field
	SYSCTL_RCC_R += SYSCTL_RCC_PWMDIV_2;  //    configure for /2 divider
	PWM0_0_CTL_R = 0;                     // 4) re-loading down-counting mode
	PWM0_0_GENB_R = (PWM_0_GENB_ACTCMPBD_ONE|PWM_0_GENB_ACTLOAD_ZERO); // 0xC08
	// PB7 goes low on LOAD
	// PB7 goes high on CMPB down
	PWM0_0_LOAD_R = PERIOD - 1;           // 5) cycles needed to count down to 0: LAB2: PF1->M1PWM5:PWM1_2_
	PWM0_0_CMPB_R = 0;             // 6) count value when output rises: Lab 2:5%2=1->CMPB, GENB
	PWM0_0_CTL_R |= 0x00000001;           // 7) start PWM0: odd->B, even->A
	PWM0_ENABLE_R |= 0x00000002;          // enable PB7/M0PWM1
}

// Output on PB6/M0PWM0 right motor
void RightMotor_Init(void) {
	SYSCTL_RCGCPWM_R |= 0x01;             // 1) activate PWM0
	SYSCTL_RCGCGPIO_R |= 0x02;            // 2) activate port B: 000010
	while((SYSCTL_RCGCGPIO_R&0x02) == 0);
	GPIO_PORTB_AFSEL_R |= 0x40;           // enable alt funct on PB6: 0100 0000
	GPIO_PORTB_PCTL_R &= ~0x0F000000;     // configure PB6 as PWM0
	GPIO_PORTB_PCTL_R |= 0x04000000;
	GPIO_PORTB_AMSEL_R &= ~0x40;          // disable analog functionality on PB6
	GPIO_PORTB_DEN_R |= 0x40;             // enable digital I/O on PB6
	GPIO_PORTB_DR8R_R |= 0xC0;    		// enable 8 mA drive on PB6,7
	SYSCTL_RCC_R = 0x00100000 |           // 3) use PWM divider
	(SYSCTL_RCC_R & (~0x001E0000));   	//    configure for /2 divider: PWM clock: 80Mhz/2=40MHz
	PWM0_0_CTL_R = 0;                     // 4) re-loading down-counting mode
	PWM0_0_GENA_R = 0xC8;                 // low on LOAD, high on CMPA down
	// PB6 goes low on LOAD
	// PB6 goes high on CMPA down
	PWM0_0_LOAD_R = PERIOD - 1;           // 5) cycles needed to count down to 0
	PWM0_0_CMPA_R = 0;             		// 6) count value when output rises
	PWM0_0_CTL_R |= 0x00000001;           // 7) start PWM0
	PWM0_ENABLE_R |= 0x00000001;          // enable PB6/M0PWM0
}

// Subroutine to initialize port E pins PE0-3 for output
// PE0-3 control direction of motor
// LEFT:	DIR - PE0, SLP - PE1
// RIGHT:	DIR - PE2, SLP - PE3
void MotorDirection_Init(void) {
	SYSCTL_RCGC2_R |= SYSCTL_RCGC2_GPIOE; //activate E clock
	while ((SYSCTL_RCGC2_R&SYSCTL_RCGC2_GPIOE)!= SYSCTL_RCGC2_GPIOE){} //wait for clk
	
	GPIO_PORTE_AMSEL_R &= ~0x0F; //disable analog function
	GPIO_PORTE_PCTL_R &= ~0x0000FFFF; //GPIO clear bit PCTL
	GPIO_PORTE_DIR_R |= 0x0F; //PE0-3 output
	GPIO_PORTE_AFSEL_R &= ~0x0F; //no alternate function
	GPIO_PORTE_DEN_R |= 0x0F; //enable digital pins PE0-3
}

// Duty is number of PWM clock cycles output is high  
void PWM_Duty(unsigned long dutyL, unsigned long dutyR) {
	PWM0_0_CMPA_R = dutyR - 1;	// PB6 right motor
	PWM0_0_CMPB_R = dutyL - 1;	// PB7 left motor
}

unsigned long GetCurrDuty(void) {
	return currDuty;
}

void IncrementSpeed(void) {
	if (currDuty + SPEED_STEP < PERIOD)
		currDuty += SPEED_STEP;
	else
		currDuty = PERIOD - 1;	// MAX SPEED
	PWM_Duty(currDuty, currDuty);
}

void DecrementSpeed(void) {
	if (0 < currDuty - SPEED_STEP)
		currDuty -= SPEED_STEP;
	else
		currDuty = STOP;
	PWM_Duty(currDuty, currDuty);
}