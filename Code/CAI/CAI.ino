#include "CAI.h"
#include "Systems.h"
#include "ScreenDriver.h"
#include "RotaryButtonDriver.h"
#include "MenuController.h"

#pragma region Setup

ScreenDriver screenDriver = ScreenDriver();
RotaryButtonDriver rotaryButtonDriver(Interface_InrementRotationPin, Interface_DecrementRotationPin, Interface_EnterPin, IncrementFunc, DecrementFunc, EnterMenu);
MenuController menuController = MenuController();

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
	rotaryButtonDriver.Tick(); 
	delay(10); 
}

void IncrementFunc() {
	menuController.incrementMenuIndex(menuTree, MENU_TREE_SIZE, &currentMenuIndex, &menuIndex);
	screenDriver.printMenu(menuTree, MENU_TREE_SIZE, currentMenuIndex, menuIndex);
}

void DecrementFunc() {
	menuController.decrementMenuIndex(menuTree, MENU_TREE_SIZE, &currentMenuIndex, &menuIndex);
	screenDriver.printMenu(menuTree, MENU_TREE_SIZE, currentMenuIndex, menuIndex);
}

void EnterMenu() {
	screenDriver.printEnterMenu(menuTree, MENU_TREE_SIZE, currentMenuIndex, menuIndex);
	if (menuTree[menuIndex].command != NULL)
		screenDriver.printLoading();
	menuController.enterMenu(menuTree, MENU_TREE_SIZE, &currentMenuIndex, &menuIndex);
	screenDriver.printMenu(menuTree, MENU_TREE_SIZE, currentMenuIndex, menuIndex);
}

void backMethod() {
  int jumpCursor = 0;
  while (menuTree[jumpCursor].menuID != menuTree[menuIndex].parentID)
  {
    jumpCursor++;
    if (jumpCursor > MENU_TREE_SIZE)
      jumpCursor = 0;
  }
  
	while (menuTree[menuIndex].menuID != menuTree[currentMenuIndex].parentID)
  {
    menuIndex++;
    if (menuIndex > MENU_TREE_SIZE)
      menuIndex = 0;
  }
  currentMenuIndex = menuIndex;
  menuIndex = jumpCursor;
}

#pragma endregion
