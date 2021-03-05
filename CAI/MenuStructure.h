#pragma once

#include <Arduino.h>

class MenuItem {
public:
	const int submenuCount;
	const int menuID;
	const int parentID;
	const char* name;
	void(*command)(void);

	MenuItem(const int submenuCount, const int menuID, const int parentID, const char* name, void(*command)(void)) : submenuCount(submenuCount), menuID(menuID), parentID(parentID), name(name), command(command) {}
};
