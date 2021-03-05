#include "Configuration.h"

Menu LED_Menu = Menu{ "LED", NULL, 0 };

MenuItem LED_Menus[] = {
	MenuItem("LED On", turnLEDON),
	MenuItem("LED Off", turnLEDOFF),
	MenuItem("Back", backMethod)
};

Menu FAN_Menu = Menu{ "Nozzle Blower", NULL, 0 };

MenuItem FAN_Menus[] = {
	MenuItem("Fan On", turnFANON),
	MenuItem("Fan Off", turnFANOFF),
	MenuItem("Back", backMethod)
};

Menu bmenuList[BASE_MENU_LENGTH] = {
	LED_Menu,
	FAN_Menu
};

void getConfiguration(Menu **_menuList) {
	for (int i = 0; i < BASE_MENU_LENGTH; i++)
		_menuList[i] = &bmenuList[i];
}

void ConfigureMenu(Menu** _menuList) {
	(_menuList[0])->setMenuItems(LED_Menus, 3);
	(_menuList[1])->setMenuItems(FAN_Menus, 3);
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
