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

enum EncoderState { None, Clockwise, CounterClockwise };

class RotaryButtonDriver {
private:
	const uint8_t incrememtPin;
	const uint8_t decrememtPin;
	const uint8_t enterPin;
	uint8_t flagA = 0;
	uint8_t flagB = 0;
	uint8_t pos = 128;
	void RotaryButtonDriver::incrememtIndex(const uint8_t treeSize, uint8_t* menuIndex);
	void RotaryButtonDriver::decrememtIndex(const uint8_t treeSize, uint8_t* menuIndex);
	void (*enterFuncPtr)();

public:
	RotaryButtonDriver(uint8_t incrememtPin, uint8_t decrememtPin, uint8_t enterPin, void (*doEncodeFuncA)(), void (*doEncodeFuncB)(), void (*enterFunc)())
		: incrememtPin(incrememtPin), decrememtPin(decrememtPin), enterPin(enterPin)
	{
		pinMode(incrememtPin, INPUT_PULLUP);
		pinMode(decrememtPin, INPUT_PULLUP);
		pinMode(enterPin, INPUT_PULLUP);

		attachInterrupt(digitalPinToInterrupt(incrememtPin), doEncodeFuncA, RISING);
		attachInterrupt(digitalPinToInterrupt(decrememtPin), doEncodeFuncB, RISING);

		enterFuncPtr = enterFunc;
	};

	EncoderState RotaryButtonDriver::getEncoderState();
	void RotaryButtonDriver::incrementMenuIndex(const MenuItem menuTree[], const uint8_t treeSize, uint8_t* currentMenuIndex, uint8_t* menuIndex);
	void RotaryButtonDriver::decrementMenuIndex(const MenuItem menuTree[], const uint8_t treeSize, uint8_t* currentMenuIndex, uint8_t* menuIndex);
	void RotaryButtonDriver::enterMenu(const MenuItem menuTree[], const uint8_t treeSize, uint8_t* currentMenuIndex, uint8_t* menuIndex);
	void RotaryButtonDriver::EncodeFuncA();
	void RotaryButtonDriver::EncodeFuncB();
	void RotaryButtonDriver::CheckEnter();
};

#endif

