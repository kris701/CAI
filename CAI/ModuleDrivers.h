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

void digitalSwitch(const uint8_t pin, bool state);
void analogSwitch(const uint8_t pin, uint8_t value);
void motorControllerDigital(const uint8_t pinA, const uint8_t pinB, bool valueA, bool valueB);
void motorControllerAnalog(const uint8_t pinA, const uint8_t pinB, uint8_t valueA, uint8_t valueB);



#endif

