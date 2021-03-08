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
public:
	RotaryButtonDriver() {};

	void RotaryButtonDriver::setup(void (*incrementFunc)(), uint8_t incrememtPin, void (*decrementFunc)(), uint8_t decrememtPin, void (*enterFunc)(), uint8_t enterPin);
	void incrementMenuIndex(const MenuItem menuTree[], const uint8_t treeSize, uint8_t* currentMenuIndex, uint8_t* menuIndex);
	void decrementMenuIndex(const MenuItem menuTree[], const uint8_t treeSize, uint8_t* currentMenuIndex, uint8_t* menuIndex);
	void enterMenu(const MenuItem menuTree[], uint8_t* currentMenuIndex, uint8_t* menuIndex);

private:
	void incrememtIndex(const uint8_t treeSize, uint8_t* menuIndex);
	void decrememtIndex(const uint8_t treeSize, uint8_t* menuIndex);
};


#endif

