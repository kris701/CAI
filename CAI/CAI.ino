#include "CAI.h"

#pragma region Setup

#define MENU_TREE_SIZE 9

void setupPins() {
	// insert pinMode here
}

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

uint8_t menuIndex = 1;
uint8_t currentMenuIndex = 0;

#pragma endregion

#pragma region Base Methods

void setup()
{
#if SERIAL_PRINT
	Serial.begin(115200);
	Serial.println(F("Starting..."));
#endif

	setupPins();

	setupRotaryButton(IncrementMenuIndex, DecrementMenuIndex, EnterMenu);
	setupOLEDScreen();

	printIntro();

	printMenu(menuTree, MENU_TREE_SIZE, currentMenuIndex, menuIndex);
}

void loop() {}

void IncrementMenuIndex()
{
	incrementMenuIndex(menuTree, MENU_TREE_SIZE, &currentMenuIndex, &menuIndex);
	printMenu(menuTree, MENU_TREE_SIZE, currentMenuIndex, menuIndex);
}

void DecrementMenuIndex()
{
	decrementMenuIndex(menuTree, MENU_TREE_SIZE, &currentMenuIndex, &menuIndex);
	printMenu(menuTree, MENU_TREE_SIZE, currentMenuIndex, menuIndex);
}

void EnterMenu()
{
	enterMenu(menuTree, MENU_TREE_SIZE, &currentMenuIndex, &menuIndex);
	printMenu(menuTree, MENU_TREE_SIZE, currentMenuIndex, menuIndex);
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

#pragma endregion

void turnLEDON()
{
#if SERIAL_PRINT
	Serial.println(F("LED ON!"));
#endif
}

void turnLEDOFF()
{
#if SERIAL_PRINT
	Serial.println(F("LED OFF!"));
#endif
}

void turnFANON()
{
#if SERIAL_PRINT
	Serial.println(F("FAN ON!"));
#endif
}

void turnFANOFF()
{
#if SERIAL_PRINT
	Serial.println(F("FAN OFF!"));
#endif
}


