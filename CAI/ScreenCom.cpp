#include "ScreenCom.h"

int listLength = 0;
int menuIndex = 0;

void s_printHeader(const char* text) {
	Serial.print(F("Titel: "));
	Serial.println(text);
}

void s_printListItem(const char* text, bool highLight) {
	if (highLight)
		Serial.print(F(":=> "));
	else
		Serial.print(F(":   "));
	Serial.println(text);
}

void s_IncrementMenuIndex(Menu* currerntMenu, Menu menuList[BASE_MENU_LENGTH])
{
	menuIndex++;
	if (menuIndex >= listLength)
		menuIndex = 0;
	s_ShowMenu(menuList, currerntMenu);
}

void s_DecrementMenuIndex(Menu* currerntMenu, Menu menuList[BASE_MENU_LENGTH])
{
	menuIndex--;
	if (menuIndex < 0)
		menuIndex = listLength - 1;
	s_ShowMenu(menuList, currerntMenu);
}

void s_EnterMenu(Menu* currerntMenu, Menu menuList[BASE_MENU_LENGTH])
{
	if (currentMenu == NULL)
	{
		currentMenu = &(menuList[menuIndex]);
		listLength = currentMenu->menuItemsCount;
	}
	else
	{
		currentMenu->runCommand(menuIndex);
	}
	menuIndex = 0;
	s_ShowMenu(menuList, currerntMenu);
}

void s_ShowMenu(Menu *currerntMenu, Menu menuList[BASE_MENU_LENGTH])
{
	if (currentMenu == NULL)
	{
		s_printHeader("Main Menu");
		for (int i = 0; i < BASE_MENU_LENGTH; i++)
		{
			s_printListItem(menuList[i].name, i == menuIndex);
		}
	}
	else
		currentMenu->printMenu(menuIndex);
}
