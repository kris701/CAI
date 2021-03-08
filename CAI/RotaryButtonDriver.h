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

#define Interface_InrementRotationPin 5
#define Interface_DecrementRotationPin 6
#define Interface_EnterPin 7

void incrememtIndex(const uint8_t treeSize, uint8_t* menuIndex);
void decrememtIndex(const uint8_t treeSize, uint8_t* menuIndex);
void setupRotaryButton(void (*incrementFunc)(), void (*decrementFunc)(), void (*enterFunc)());
void incrementMenuIndex(const MenuItem menuTree[], const uint8_t treeSize, uint8_t* currentMenuIndex, uint8_t* menuIndex);
void decrementMenuIndex(const MenuItem menuTree[], const uint8_t treeSize, uint8_t* currentMenuIndex, uint8_t* menuIndex);
void enterMenu(const MenuItem menuTree[], uint8_t* currentMenuIndex, uint8_t* menuIndex);

#endif

