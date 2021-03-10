#include "RotaryButtonDriver.h"

void RotaryButtonDriver::incrementMenuIndex(MenuItem menuTree[], const uint8_t treeSize, uint8_t* currentMenuIndex, uint8_t* menuIndex)
{
	incrememtIndex(treeSize, menuIndex);
	while (menuTree[*menuIndex].GetparentID() != menuTree[*currentMenuIndex].GetmenuID())
	{
		incrememtIndex(treeSize, menuIndex);
	}
}

void RotaryButtonDriver::decrementMenuIndex(MenuItem menuTree[], const uint8_t treeSize, uint8_t* currentMenuIndex, uint8_t* menuIndex)
{
	decrememtIndex(treeSize, menuIndex);
	while (menuTree[*menuIndex].GetparentID() != menuTree[*currentMenuIndex].GetmenuID())
	{
		decrememtIndex(treeSize, menuIndex);
	}
}

void RotaryButtonDriver::enterMenu(MenuItem menuTree[], uint8_t* currentMenuIndex, uint8_t* menuIndex)
{
	if (menuTree[*menuIndex].command == NULL)
	{
		*currentMenuIndex = *menuIndex;
		(*menuIndex)++;
	}
	else
		menuTree[*menuIndex].command();
}

void RotaryButtonDriver::incrememtIndex(uint8_t const treeSize, uint8_t* menuIndex)
{
	if (*menuIndex == treeSize)
		*menuIndex = 0;
	else
		(*menuIndex)++;
}

void RotaryButtonDriver::decrememtIndex(uint8_t const treeSize, uint8_t* menuIndex)
{
	if (*menuIndex == 0)
		*menuIndex = treeSize - 1;
	else
		(*menuIndex)--;
}

bool RotaryButtonDriver::isClockwise()
{
	if (digitalRead(incrememtPin) == digitalRead(decrememtPin))
	{
		return true;
	}
	else
	{
		return false;
	}
}