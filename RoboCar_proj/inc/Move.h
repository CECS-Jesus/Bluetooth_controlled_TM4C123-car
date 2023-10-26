#ifndef MOVE_H
#define MOVE_H

#include "LED.h"
#include "tm4c123gh6pm.h"

void MoveForward(void);
void MoveBackward(void);
void MoveLeftPivot(void);
void MoveRightPivot(void);
void MoveLeftTurn(void);
void MoveRightTurn(void);
void MoveLeftBackTurn(void);
void MoveRightBackTurn(void);
void MoveStop(void);

#endif