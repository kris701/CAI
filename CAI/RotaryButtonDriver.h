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
	void (*incrementFunc)();
	void (*decrementFunc)();
	void (*enterFunc)();

	void incrememtIndex(const uint8_t treeSize, uint8_t* menuIndex);
	void decrememtIndex(const uint8_t treeSize, uint8_t* menuIndex);

public:
	RotaryButtonDriver(void (*incrementFunc)(), uint8_t incrememtPin, void (*decrementFunc)(), uint8_t decrememtPin, void (*enterFunc)(), uint8_t enterPin)
		: incrementFunc(incrementFunc), incrememtPin(incrememtPin), decrementFunc(decrementFunc), decrememtPin(decrememtPin), enterFunc(enterFunc), enterPin(enterPin) 
	{
		attachInterrupt(digitalPinToInterrupt(incrememtPin), incrementFunc, CHANGE);
		attachInterrupt(digitalPinToInterrupt(decrememtPin), decrementFunc, CHANGE);
		attachInterrupt(digitalPinToInterrupt(enterPin), enterFunc, CHANGE);
	};

	void incrementMenuIndex(const MenuItem menuTree[], const uint8_t treeSize, uint8_t* currentMenuIndex, uint8_t* menuIndex);
	void decrementMenuIndex(const MenuItem menuTree[], const uint8_t treeSize, uint8_t* currentMenuIndex, uint8_t* menuIndex);
	void enterMenu(const MenuItem menuTree[], uint8_t* currentMenuIndex, uint8_t* menuIndex);
};

#endif

