#include "CAIHeader.h"

#pragma region Setup

Menu* menuList[BASE_MENU_LENGTH];
Menu* currentMenu = NULL;
int listLength = 0;
int menuIndex = 0;

void Menu::backMenu() {
	listLength = BASE_MENU_LENGTH;
	currentMenu = NULL;
}

void backMethod()
{
	currentMenu->backMenu();
}

#pragma endregion

void setup() 
{
	Serial.begin(115200);

	getConfiguration(menuList);
	ConfigureMenu(menuList);

	listLength = BASE_MENU_LENGTH;

	attachInterrupt(digitalPinToInterrupt(Interface_InrementRotationPin), IncrementMenuIndex, CHANGE);
	attachInterrupt(digitalPinToInterrupt(Interface_DecrementRotationPin), DecrementMenuIndex, CHANGE);
	attachInterrupt(digitalPinToInterrupt(Interface_EnterPin), EnterMenu, CHANGE);

	showMenu();

	IncrementMenuIndex();

	EnterMenu();

	IncrementMenuIndex();

	EnterMenu();

	IncrementMenuIndex();
	IncrementMenuIndex();

	EnterMenu();
}

void loop() {}

void IncrementMenuIndex()
{
	menuIndex++;
	if (menuIndex >= listLength)
		menuIndex = 0;
	showMenu();
}

void DecrementMenuIndex()
{
	menuIndex--;
	if (menuIndex < 0)
		menuIndex = listLength - 1;
	showMenu();
}

void EnterMenu()
{
	if (currentMenu == NULL)
	{
		currentMenu = menuList[menuIndex];
		listLength = currentMenu->menuItemsCount;
	}
	else
	{
		currentMenu->runCommand(menuIndex);
	}
	menuIndex = 0;
	showMenu();
}

void showMenu() 
{
	if (currentMenu == NULL)
	{
		s_printHeader(F("Main Menu"));
		for (int i = 0; i < BASE_MENU_LENGTH; i++)
		{
			s_printListItem(menuList[i]->name, i == menuIndex);
		}
	}
	else
		currentMenu->printMenu(menuIndex);
}
