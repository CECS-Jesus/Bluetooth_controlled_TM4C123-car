#ifndef MOTORS_H
#define MOTORS_H

#define STOP				1
#define MAX_SPEED			PERIOD - 1
#define HALF_SPEED			PERIOD * 0.5

#include <stdint.h>
#include "tm4c123gh6pm.h"
#include "PLL.h"

void Motors_Init(void);
void PWM_Duty(unsigned long dutyL, unsigned long dutyR);
unsigned long GetCurrDuty(void);
void IncrementSpeed(void);
void DecrementSpeed(void);

#endif