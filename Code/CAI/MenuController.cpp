#include "MenuController.h"

void MenuController::incrementMenuIndex(const MenuItem menuTree[], const uint8_t treeSize, uint8_t* currentMenuIndex, uint8_t* menuIndex)
{
	incrememtIndex(treeSize, menuIndex);
	while (menuTree[*menuIndex].parentID != menuTree[*currentMenuIndex].menuID)
	{
		incrememtIndex(treeSize, menuIndex);
	}
}

void MenuController::decrementMenuIndex(const MenuItem menuTree[], const uint8_t treeSize, uint8_t* currentMenuIndex, uint8_t* menuIndex)
{
	decrememtIndex(treeSize, menuIndex);
	while (menuTree[*menuIndex].parentID != menuTree[*currentMenuIndex].menuID)
	{
		decrememtIndex(treeSize, menuIndex);
	}
}

void MenuController::enterMenu(const MenuItem menuTree[], const uint8_t treeSize, uint8_t* currentMenuIndex, uint8_t* menuIndex)
{
	if (menuTree[*menuIndex].command == NULL)
	{
		*currentMenuIndex = *menuIndex;
		*menuIndex = 0;
		incrementMenuIndex(menuTree, treeSize, currentMenuIndex, menuIndex);
	}
	else
	{
		menuTree[*menuIndex].command();
		*menuIndex = 0;
		incrementMenuIndex(menuTree, treeSize, currentMenuIndex, menuIndex);
	}
}

void MenuController::incrememtIndex(uint8_t const treeSize, uint8_t* menuIndex)
{
	if (*menuIndex == treeSize)
		*menuIndex = 0;
	else
		(*menuIndex)++;
}

void MenuController::decrememtIndex(uint8_t const treeSize, uint8_t* menuIndex)
{
	if (*menuIndex == 0)
		*menuIndex = treeSize - 1;
	else
		(*menuIndex)--;
}