// ModuleDrivers.h

#ifndef _MODULEDRIVERS_h
#define _MODULEDRIVERS_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

void digitalSwitch(int pin, bool state);
void analogSwitch(int pin, byte value);
void motorControllerDigital(int pinA, int pinB, bool valueA, bool valueB);
void motorControllerAnalog(int pinA, int pinB, byte valueA, byte valueB);



#endif

