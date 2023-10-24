#ifndef MOTORS_H
#define MOTORS_H

#define STOP				1
#define MAX_SPEED			PERIOD - 1
#define HALF_SPEED			PERIOD * 0.5

#include <stdint.h>
#include "tm4c123gh6pm.h"
#include "PLL.h"

void Motors_Init(void);
void PWM_Duty(uint64_t dutyL, uint64_t dutyR);
uint64_t getCurrDuty(void);
void incrementSpeed(void);
void decrementSpeed(void);

#endif