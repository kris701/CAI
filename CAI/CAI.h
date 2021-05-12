#ifndef _CAI_h
#define _CAI_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

#define SERIAL_PRINT false
#define USE_TEXT_DEFAULTS true

#define DIGITAL_A 4
#define DIGITAL_B 3
#define DIGITAL_C 2

#define MOTOR_A_1 5
#define MOTOR_A_2 6

#define MOTOR_B_1 9
#define MOTOR_B_2 10

#define ANALOG_A A7
#define ANALOG_B A6

#define Interface_InrementRotationPin 2
#define Interface_DecrementRotationPin 3
#define Interface_EnterPin 11

void backMethod();
void IncrementFunc();
void DecrementFunc();
void EnterMenu();

#endif