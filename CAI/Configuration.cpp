#include "Configuration.h"

Menu LED_Menu = { "LED" };
MenuItem LED_Menus[] = {
	{"LED On", turnLEDON},
	{"LED Off", turnLEDOFF},
	{"Back", backMethod}
};

Menu FAN_Menu = { "Nozzle Blower"};
MenuItem FAN_Menus[] = {
	{"Fan On", turnFANON},
	{"Fan Off", turnFANOFF},
	{"Back", backMethod}
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
