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

#ifndef _MACROS_h
	#include "Macros.h"
#endif

class RotaryButtonDriver {
	GET_Property(const uint8_t, incrememtPin)
	GET_Property(const uint8_t, decrememtPin)
	GET_Property(const uint8_t, enterPin)

private:
	void incrememtIndex(const uint8_t treeSize, uint8_t* menuIndex);
	void decrememtIndex(const uint8_t treeSize, uint8_t* menuIndex);

public:
	RotaryButtonDriver(const uint8_t incrememtPin, const uint8_t decrememtPin, void (*doEncodeFunc)(), void (*enterFunc)(), const uint8_t enterPin) :
		incrememtPin(incrememtPin), decrememtPin(decrememtPin), enterPin(enterPin)
	{
		pinMode(incrememtPin, INPUT_PULLUP);
		pinMode(decrememtPin, INPUT_PULLUP);
		pinMode(enterPin, INPUT_PULLUP);

		attachInterrupt(digitalPinToInterrupt(incrememtPin), doEncodeFunc, CHANGE);
		attachInterrupt(digitalPinToInterrupt(enterPin), enterFunc, FALLING);
	};

	bool isClockwise();
	void incrementMenuIndex(MenuItem menuTree[], const uint8_t treeSize, uint8_t* currentMenuIndex, uint8_t* menuIndex);
	void decrementMenuIndex(MenuItem menuTree[], const uint8_t treeSize, uint8_t* currentMenuIndex, uint8_t* menuIndex);
	void enterMenu(MenuItem menuTree[], uint8_t* currentMenuIndex, uint8_t* menuIndex);
};

#endif

