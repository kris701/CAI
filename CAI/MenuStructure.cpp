#include "MenuStructure.h"

void MenuItem::printItem(bool isSelected) {
	s_printListItem(name, isSelected);
}


void Menu::setMenuItems(MenuItem* _menuItems, int _menuItemsCount) {
	menuItems = _menuItems;
	menuItemsCount = _menuItemsCount;
}

void Menu::runCommand(int menuIndex) {
	(menuItems + menuIndex)->command();
}

void Menu::printMenu(int menuIndex) {
	printHeader();
	printMenuItems(menuIndex);
}

void Menu::printHeader() {
	s_printHeader(name);
}

void Menu::printMenuItems(int menuIndex) {
	for (int i = 0; i < menuItemsCount; i++)
	{
		(menuItems + i)->printItem(i == menuIndex);
	}
}