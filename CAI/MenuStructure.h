#pragma once

#include <Arduino.h>
#include "ScreenCom.h"

class MenuItem {
public:
	String name;
	void(*command)(void);

	MenuItem(String name, void(*command)(void)) : name(name), command(command) {}
	MenuItem() : name() {}

	void MenuItem::printItem(bool isSelected);
};

class Menu {
private:
	MenuItem* menuItems;
public:
	String name;
	int menuItemsCount;

	Menu::Menu(String name, MenuItem* menuItems, int menuItemsCount) : name(name), menuItems(menuItems), menuItemsCount(menuItemsCount) {}
	Menu::Menu() : name(), menuItems(NULL), menuItemsCount(0) {};

	void Menu::setMenuItems(MenuItem* _menuItems, int _menuItemsCount);

	void Menu::runCommand(int menuIndex);

	void Menu::printMenu(int menuIndex);

	void Menu::printHeader();

	void Menu::printMenuItems(int menuIndex);

	void Menu::backMenu();
};
