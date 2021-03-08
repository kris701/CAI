#include "CAI.h"

#pragma region Setup

#define Interface_InrementRotationPin 5
#define Interface_DecrementRotationPin 6
#define Interface_EnterPin 7

#define MENU_TREE_SIZE 9

RotaryButtonDriver rotaryButtonDriver = {};
ScreenDriver screenDriver = {};
ModuleDriver moduleDriver = {};

void setupPins() {
	// insert pinMode here
	pinMode(DIGITAL_A, OUTPUT);
	pinMode(DIGITAL_B, OUTPUT);
}

void turnLEDON();
void turnLEDOFF();
void turnFANON();
void turnFANOFF();
void backMethod();

const char PROGMEM TEXT_LED[] = "LED";
const char PROGMEM TEXT_FAN[] = "FAN";

const MenuItem menuTree[MENU_TREE_SIZE] = {
	{0,-1, TEXT_MAINMENU, NULL},
		{1,0, TEXT_LED, NULL},
			{-1,1, TEXT_ON, turnLEDON},
			{-1,1, TEXT_OFF, turnLEDOFF},
			{-1,1, TEXT_BACK, backMethod},
		{2,0, TEXT_FAN, NULL},
			{-1,2, TEXT_ON, turnFANON},
			{-1,2, TEXT_OFF, turnFANOFF},
			{-1,2, TEXT_BACK, backMethod},
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
	rotaryButtonDriver.setup(IncrementMenuIndex, Interface_InrementRotationPin, DecrementMenuIndex, Interface_DecrementRotationPin, EnterMenu, Interface_EnterPin);
	screenDriver.setup();

	screenDriver.printIntro();
	screenDriver.printMenu(menuTree, MENU_TREE_SIZE, currentMenuIndex, menuIndex);

	// Test
	EnterMenu();
	EnterMenu();

	IncrementMenuIndex();
	IncrementMenuIndex();
	EnterMenu();

	IncrementMenuIndex();
	EnterMenu();
	EnterMenu();
}

void loop() { delay(100); }

void IncrementMenuIndex()
{
	rotaryButtonDriver.incrementMenuIndex(menuTree, MENU_TREE_SIZE, &currentMenuIndex, &menuIndex);
	screenDriver.printMenu(menuTree, MENU_TREE_SIZE, currentMenuIndex, menuIndex);
}

void DecrementMenuIndex()
{
	rotaryButtonDriver.decrementMenuIndex(menuTree, MENU_TREE_SIZE, &currentMenuIndex, &menuIndex);
	screenDriver.printMenu(menuTree, MENU_TREE_SIZE, currentMenuIndex, menuIndex);
}

void EnterMenu()
{
	rotaryButtonDriver.enterMenu(menuTree, &currentMenuIndex, &menuIndex);
	screenDriver.printMenu(menuTree, MENU_TREE_SIZE, currentMenuIndex, menuIndex);
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
	moduleDriver.digitalSwitch(DIGITAL_A, 1);
}

void turnLEDOFF()
{
	moduleDriver.digitalSwitch(DIGITAL_A, 0);
}

void turnFANON()
{
	moduleDriver.analogSwitch(DIGITAL_B, 250);
}

void turnFANOFF()
{
	moduleDriver.analogSwitch(DIGITAL_B, 5);
}


