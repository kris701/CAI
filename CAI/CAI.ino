#include "CAI.h"
#include "Systems.h"
#include "ScreenDriver.h"
#include "RotaryButtonDriver.h"

#pragma region Setup

ScreenDriver screenDriver = ScreenDriver();
RotaryButtonDriver rotaryButtonDriver(Interface_InrementRotationPin, Interface_DecrementRotationPin, Interface_EnterPin, EncodeA, EncodeB, EnterMenu);

uint8_t menuIndex = 1;
uint8_t currentMenuIndex = 0;

const MenuItem menuTree[MENU_TREE_SIZE] = USE_TREE;

#pragma endregion

#pragma region Base Methods

void setup()
{
#if SERIAL_PRINT
	Serial.flush();
	Serial.begin(115200);
	Serial.println(F("Warning: Serial print is on!"));
	Serial.println(F("Starting..."));
	delay(100);
#endif

	screenDriver.startDisplay();
	screenDriver.printIntro();
	screenDriver.printMenu(menuTree, MENU_TREE_SIZE, currentMenuIndex, menuIndex);
}

void loop() { 
	rotaryButtonDriver.CheckEnter(); 
	delay(100); 
}

void EncodeA() {
	rotaryButtonDriver.EncodeFuncA();
	DoEncode();
}

void EncodeB() {
	rotaryButtonDriver.EncodeFuncB();
	DoEncode();
}

void DoEncode() {
	EncoderState value = rotaryButtonDriver.getEncoderState();
	if (value != None)
	{
		if (value == Clockwise)
		{
			rotaryButtonDriver.incrementMenuIndex(menuTree, MENU_TREE_SIZE, &currentMenuIndex, &menuIndex);
			screenDriver.printMenu(menuTree, MENU_TREE_SIZE, currentMenuIndex, menuIndex);
		}
		if (value == CounterClockwise)
		{
			rotaryButtonDriver.decrementMenuIndex(menuTree, MENU_TREE_SIZE, &currentMenuIndex, &menuIndex);
			screenDriver.printMenu(menuTree, MENU_TREE_SIZE, currentMenuIndex, menuIndex);
		}
	}
}

void EnterMenu()
{
	// Interupt pin is floating rigth now, commented out for now
	screenDriver.printEnterMenu(menuTree, MENU_TREE_SIZE, currentMenuIndex, menuIndex);
	rotaryButtonDriver.enterMenu(menuTree, MENU_TREE_SIZE, &currentMenuIndex, &menuIndex);
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

