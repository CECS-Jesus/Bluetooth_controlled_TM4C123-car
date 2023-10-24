#ifndef MOVE_H
#define MOVE_H

#include "LED.h"
#include "tm4c123gh6pm.h"

void move_forward(void);
void move_backward(void);
void move_l_piv(void);
void move_r_piv(void);
void move_l_turn(void);
void move_r_turn(void);
void move_l_back_turn(void);
void move_r_back_turn(void);
void move_stop(void);

#endif