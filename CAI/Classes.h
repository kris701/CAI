// Classes.h

#ifndef _CLASSES_h
#define _CLASSES_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

#ifndef _MACROS_h
	#include "Macros.h"
#endif

#define FC(string_constant) (reinterpret_cast<const __FlashStringHelper *>(string_constant))

class MenuItem {
	GET_PSET_Property(uint8_t, menuID)
	GET_PSET_Property(uint8_t, parentID)
	GET_Property(const __FlashStringHelper*, name)

public:
	void(*command)(void);

	MenuItem(uint8_t menuID, uint8_t parentID, char* name, void(*command)(void)) 
		: command(command), name(FC(name)) {
		SetmenuID(menuID);
		SetparentID(parentID);
	};
	MenuItem(uint8_t menuID, uint8_t parentID, const char* name, void(*command)(void)) 
		: command(command), name(FC(name)) {
		SetmenuID(menuID);
		SetparentID(parentID);
	};
	MenuItem(uint8_t menuID, uint8_t parentID, __FlashStringHelper* name, void(*command)(void)) 
		: command(command), name(name) {
		SetmenuID(menuID);
		SetparentID(parentID);
	};
};

#endif

