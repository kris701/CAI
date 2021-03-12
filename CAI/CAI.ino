#include "CAI.h"

#pragma region Setup

#define Interface_InrementRotationPin 2
#define Interface_DecrementRotationPin 11
#define Interface_EnterPin 3

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET     -1

#define MENU_TREE_SIZE 9

void DoEncode();
void EnterMenu();

RotaryButtonDriver rotaryButtonDriver(Interface_InrementRotationPin, Interface_DecrementRotationPin, DoEncode, EnterMenu, Interface_EnterPin);
ScreenDriver screenDriver(SCREEN_WIDTH, SCREEN_HEIGHT, OLED_RESET);

uint8_t menuIndex = 1;
uint8_t currentMenuIndex = 0;

#pragma endregion

#pragma region Configuration

ModuleDriver DigitalADriver(DIGITAL_A);
ModuleDriver DigitalBDriver(DIGITAL_B);

void turnLEDON();
void turnLEDOFF();
void turnFANON();
void turnFANOFF();
void backMethod();

const char PROGMEM TEXT_LED[] = "LED";
const char PROGMEM TEXT_FAN[] = "FAN";

MenuItem menuTree[MENU_TREE_SIZE] = {
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

	EnterMenu();
	EnterMenu();
}

void loop() { delay(100); }

void DoEncode() {
	if (rotaryButtonDriver.isClockwise())
	{
		rotaryButtonDriver.incrementMenuIndex(menuTree, MENU_TREE_SIZE, &currentMenuIndex, &menuIndex);
		screenDriver.printMenu(menuTree, MENU_TREE_SIZE, currentMenuIndex, menuIndex);
	}
	else
	{
		rotaryButtonDriver.decrementMenuIndex(menuTree, MENU_TREE_SIZE, &currentMenuIndex, &menuIndex);
		screenDriver.printMenu(menuTree, MENU_TREE_SIZE, currentMenuIndex, menuIndex);
	}
}

void EnterMenu()
{
	rotaryButtonDriver.enterMenu(menuTree, &currentMenuIndex, &menuIndex);
	screenDriver.printMenu(menuTree, MENU_TREE_SIZE, currentMenuIndex, menuIndex);
}



void backMethod()
{
	while (menuTree[menuIndex].GetmenuID() != menuTree[currentMenuIndex].GetparentID())
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
	DigitalADriver.digitalSwitch(1);
}

void turnLEDOFF()
{
	DigitalADriver.digitalSwitch(0);
}

void turnFANON()
{
	DigitalBDriver.analogSwitch(150);
}

void turnFANOFF()
{
	DigitalBDriver.analogSwitch(50);
}


