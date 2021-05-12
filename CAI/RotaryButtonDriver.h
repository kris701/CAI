// RotaryButtonDriver.h

#ifndef _ROTARYBUTTONDRIVER_h
#define _ROTARYBUTTONDRIVER_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#ifndef _CLASSES_h
	#include "Classes.h"
#endif

class RotaryButtonDriver {
private:
	const uint8_t incrememtPin;
	const uint8_t decrememtPin;
	const uint8_t enterPin;
	bool flagA;
	void (*enterFuncPtr)();
	void (*incrementFuncPtr)();
	void (*decrementFuncPtr)();

public:
	RotaryButtonDriver(uint8_t incrememtPin, uint8_t decrememtPin, uint8_t enterPin, void (*incrementFunc)(), void (*decrementFunc)(), void (*enterFunc)())
		: incrememtPin(incrememtPin), decrememtPin(decrememtPin), enterPin(enterPin)
	{
		pinMode(incrememtPin, INPUT);
		pinMode(decrememtPin, INPUT);
		pinMode(enterPin, INPUT_PULLUP);

		enterFuncPtr = enterFunc;
		incrementFuncPtr = incrementFunc;
		decrementFuncPtr = decrementFunc;

		flagA = digitalRead(incrememtPin);
	};

	void RotaryButtonDriver::Tick();
};

#endif
