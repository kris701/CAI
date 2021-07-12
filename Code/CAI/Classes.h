// Classes.h

#ifndef _CLASSES_h
#define _CLASSES_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

#define FC(string_constant) (reinterpret_cast<const __FlashStringHelper *>(string_constant))

class MenuItem {
public:
	const uint8_t menuID;
	const uint8_t parentID;
	const __FlashStringHelper* name;
	void(*command)(void);

	MenuItem(const uint8_t menuID, const uint8_t parentID, const char* name, void(*command)(void))
		: command(command), name(FC(name)), menuID(menuID), parentID(parentID) {};
	MenuItem(const uint8_t menuID, const uint8_t parentID, const __FlashStringHelper* name, void(*command)(void))
		: command(command), name(name), menuID(menuID), parentID(parentID) {};
};

#endif

