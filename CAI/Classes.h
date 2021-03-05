// Classes.h

#ifndef _CLASSES_h
#define _CLASSES_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif


class MenuItem {
public:
	const bool hasChildren;
	const int menuID;
	const int parentID;
	const char* name;
	void(*command)(void);

	MenuItem(const bool hasChildren, const int menuID, const int parentID, const char* name, void(*command)(void)) : hasChildren(hasChildren), menuID(menuID), parentID(parentID), name(name), command(command) {}
};

#endif

