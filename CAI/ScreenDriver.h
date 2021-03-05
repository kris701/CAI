// ScreenDriver.h

#ifndef _SCREENDRIVER_h
#define _SCREENDRIVER_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#if not defined(_CLASSES_h) 
	#include "Classes.h"
#endif

void printMenu(const MenuItem menuTree[], int treeSize, int currentMenuIndex, int menuIndex);

#endif
