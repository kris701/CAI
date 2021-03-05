#include "CAIHeader.h"

#pragma region Setup

#define MENU_TREE_SIZE 9

void turnLEDON();
void turnLEDOFF();
void turnFANON();
void turnFANOFF();
void backMethod();

const MenuItem menuTree[MENU_TREE_SIZE] = {
	{true, 0,-1, "Main Menu", NULL},
		{true, 1,0, "LED", NULL},
			{false, -1,1, "On", turnLEDON},
			{false, -1,1, "Off", turnLEDOFF},
			{false, -1,1, "Back", backMethod},
		{true, 2,0, "FAN", NULL},
			{false, -1,2, "On", turnFANON},
			{false, -1,2, "Off", turnFANOFF},
			{false, -1,2, "Back", backMethod},
};

int menuIndex = 1;
int currentMenuIndex = 0;

#pragma endregion

void setup() 
{
	Serial.begin(115200);

	attachInterrupt(digitalPinToInterrupt(Interface_InrementRotationPin), IncrementMenuIndex, CHANGE);
	attachInterrupt(digitalPinToInterrupt(Interface_DecrementRotationPin), DecrementMenuIndex, CHANGE);
	attachInterrupt(digitalPinToInterrupt(Interface_EnterPin), EnterMenu, CHANGE);

	ShowMenu();

	EnterMenu();
}

void loop() {}

void IncrementMenuIndex()
{
	menuIndex++;
	if (menuIndex > MENU_TREE_SIZE)
		menuIndex = 0;
	while (menuTree[menuIndex].parentID != menuTree[currentMenuIndex].menuID)
	{
		menuIndex++;
		if (menuIndex > MENU_TREE_SIZE)
			menuIndex = 0;
	}

	ShowMenu();
}

void DecrementMenuIndex()
{
	menuIndex--;
	if (menuIndex < 0)
		menuIndex = MENU_TREE_SIZE - 1;
	while (menuTree[menuIndex].parentID != menuTree[currentMenuIndex].menuID)
	{
		menuIndex--;
		if (menuIndex < 0)
			menuIndex = MENU_TREE_SIZE - 1;
	}

	ShowMenu();
}

void EnterMenu()
{
	if (menuTree[menuIndex].hasChildren)
	{
		currentMenuIndex = menuIndex;
		menuIndex++;
	}
	else
		menuTree[menuIndex].command();

	ShowMenu();
}

void ShowMenu() {
	for (int i = 0; i < MENU_TREE_SIZE; i++)
	{
		if (i == currentMenuIndex)
		{
			Serial.print(F("Titel: "));
			Serial.println(menuTree[i].name);
		}
		if (menuTree[i].parentID == menuTree[currentMenuIndex].menuID)
		{
			if (i == menuIndex)
				Serial.print(F(":=> "));
			else
				Serial.print(F(":   "));
			Serial.println(menuTree[i].name);
		}
	}
}

void backMethod()
{
	while (menuTree[menuIndex].menuID != menuTree[currentMenuIndex].parentID)
	{
		menuIndex++;
		if (menuIndex > MENU_TREE_SIZE)
			menuIndex = 0;
	}

	currentMenuIndex = menuIndex;
	menuIndex++;
}




void turnLEDON()
{
	Serial.println(F("LED ON!"));
}

void turnLEDOFF()
{
	Serial.println(F("LED OFF!"));
}

void turnFANON()
{
	Serial.println(F("FAN ON!"));
}

void turnFANOFF()
{
	Serial.println(F("FAN OFF!"));
}


