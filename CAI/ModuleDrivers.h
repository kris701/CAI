// ModuleDrivers.h

#ifndef _MODULEDRIVERS_h
#define _MODULEDRIVERS_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#ifndef _CAI_h
	#include "CAI.h"
#endif

void digitalSwitch(uint8_t pin, bool state);
void analogSwitch(uint8_t pin, uint8_t value);
void motorControllerDigital(uint8_t pinA, uint8_t pinB, bool valueA, bool valueB);
void motorControllerAnalog(uint8_t pinA, uint8_t pinB, uint8_t valueA, uint8_t valueB);



#endif

