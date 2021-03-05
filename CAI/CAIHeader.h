#pragma once

#define Interface_InrementRotationPin 5
#define Interface_DecrementRotationPin 6
#define Interface_EnterPin 7

class MenuItem {
public:
	const bool hasChildren;
	const int menuID;
	const int parentID;
	const char* name;
	void(*command)(void);

	MenuItem(const bool hasChildren, const int menuID, const int parentID, const char* name, void(*command)(void)) : hasChildren(hasChildren), menuID(menuID), parentID(parentID), name(name), command(command) {}
};




