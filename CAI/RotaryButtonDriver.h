// RotaryButtonDriver.h

#ifndef _ROTARYBUTTONDRIVER_h
#define _ROTARYBUTTONDRIVER_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#if not defined(_CLASSES_h) 
	#include "Classes.h"
#endif

#define Interface_InrementRotationPin 5
#define Interface_DecrementRotationPin 6
#define Interface_EnterPin 7

void incrememtIndex(int treeSize, int* menuIndex);
void decrememtIndex(int treeSize, int* menuIndex);
void setupRotaryButton(void (*incrementFunc)(), void (*decrementFunc)(), void (*enterFunc)());
void incrementMenuIndex(const MenuItem menuTree[], int treeSize, int* currentMenuIndex, int* menuIndex);
void decrementMenuIndex(const MenuItem menuTree[], int treeSize, int* currentMenuIndex, int* menuIndex);
void enterMenu(const MenuItem menuTree[], int treeSize, int* currentMenuIndex, int* menuIndex);

#endif

