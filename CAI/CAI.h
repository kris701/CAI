#ifndef _CAI_h
#define _CAI_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

#define SERIAL_PRINT false
#define SERIAL_DEBUG false
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

#ifdef USE_TEXT_DEFAULTS
	#if USE_TEXT_DEFAULTS == true
		const char PROGMEM TEXT_MAINMENU[] = "Main Menu";
		const char PROGMEM TEXT_ON[] = "On";
		const char PROGMEM TEXT_OFF[] = "Off";
		const char PROGMEM TEXT_BACK[] = "Back";
	#endif 
#endif 

#endif