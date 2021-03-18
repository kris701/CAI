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
	void RotaryButtonDriver::incrememtIndex(const uint8_t treeSize, uint8_t* menuIndex);
	void RotaryButtonDriver::decrememtIndex(const uint8_t treeSize, uint8_t* menuIndex);

public:
	RotaryButtonDriver(uint8_t incrememtPin, uint8_t decrememtPin, uint8_t enterPin, void (*doEncodeFunc)(), void (*enterFunc)())
		: incrememtPin(incrememtPin), decrememtPin(decrememtPin), enterPin(enterPin)
	{
		pinMode(incrememtPin, INPUT_PULLUP);
		pinMode(decrememtPin, INPUT_PULLUP);
		pinMode(enterPin, INPUT_PULLUP);

		attachInterrupt(digitalPinToInterrupt(incrememtPin), doEncodeFunc, CHANGE);
		attachInterrupt(digitalPinToInterrupt(enterPin), enterFunc, FALLING);
	};

	bool RotaryButtonDriver::isClockwise();
	void RotaryButtonDriver::incrementMenuIndex(const MenuItem menuTree[], const uint8_t treeSize, uint8_t* currentMenuIndex, uint8_t* menuIndex);
	void RotaryButtonDriver::decrementMenuIndex(const MenuItem menuTree[], const uint8_t treeSize, uint8_t* currentMenuIndex, uint8_t* menuIndex);
	void RotaryButtonDriver::enterMenu(const MenuItem menuTree[], const uint8_t treeSize, uint8_t* currentMenuIndex, uint8_t* menuIndex);
};

#endif

