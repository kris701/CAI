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

	void incrememtIndex(const uint8_t treeSize, uint8_t* menuIndex);
	void decrememtIndex(const uint8_t treeSize, uint8_t* menuIndex);

public:
	RotaryButtonDriver(uint8_t incrememtPin, uint8_t decrememtPin, void (*doEncodeFunc)(), void (*enterFunc)(), uint8_t enterPin)
		: incrememtPin(incrememtPin), decrememtPin(decrememtPin), enterPin(enterPin)
	{
		pinMode(incrememtPin, INPUT_PULLUP);
		pinMode(decrememtPin, INPUT_PULLUP);
		pinMode(enterPin, INPUT_PULLUP);

		attachInterrupt(digitalPinToInterrupt(incrememtPin), doEncodeFunc, CHANGE);
		attachInterrupt(digitalPinToInterrupt(enterPin), enterFunc, FALLING);
	};

	bool isClockwise();
	void incrementMenuIndex(const MenuItem menuTree[], const uint8_t treeSize, uint8_t* currentMenuIndex, uint8_t* menuIndex);
	void decrementMenuIndex(const MenuItem menuTree[], const uint8_t treeSize, uint8_t* currentMenuIndex, uint8_t* menuIndex);
	void enterMenu(const MenuItem menuTree[], uint8_t* currentMenuIndex, uint8_t* menuIndex);
};

#endif

