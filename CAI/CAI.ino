#pragma region Libraries

#include "ModuleDrivers.h"
#include <splash.h>
#include <Adafruit_SSD1306.h>
#include <gfxfont.h>
#include <Adafruit_SPITFT_Macros.h>
#include <Adafruit_SPITFT.h>
#include <Adafruit_GrayOLED.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SPIDevice.h>
#include <Adafruit_I2CRegister.h>
#include <Adafruit_I2CDevice.h>
#include <Adafruit_BusIO_Register.h>
#include "Classes.h"
#include "RotaryButtonDriver.h"
#include "ScreenDriver.h"

#pragma endregion

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

int menuIndex = 1;
int currentMenuIndex = 0;

#pragma endregion

#pragma region Base Methods

void setup()
{
	Serial.begin(115200);

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


