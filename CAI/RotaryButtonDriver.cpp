#include "RotaryButtonDriver.h"

void RotaryButtonDriver::incrementMenuIndex(const MenuItem menuTree[], const uint8_t treeSize, uint8_t* currentMenuIndex, uint8_t* menuIndex)
{
	incrememtIndex(treeSize, menuIndex);
	while (menuTree[*menuIndex].parentID != menuTree[*currentMenuIndex].menuID)
	{
		incrememtIndex(treeSize, menuIndex);
	}
}

void RotaryButtonDriver::decrementMenuIndex(const MenuItem menuTree[], const uint8_t treeSize, uint8_t* currentMenuIndex, uint8_t* menuIndex)
{
	decrememtIndex(treeSize, menuIndex);
	while (menuTree[*menuIndex].parentID != menuTree[*currentMenuIndex].menuID)
	{
		decrememtIndex(treeSize, menuIndex);
	}
}

void RotaryButtonDriver::enterMenu(const MenuItem menuTree[], const uint8_t treeSize, uint8_t* currentMenuIndex, uint8_t* menuIndex)
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

EncoderState RotaryButtonDriver::getEncoderState()
{
	if (pos == 128)
		return None;
	if (pos < 128)
	{
		pos = 128;
		return CounterClockwise;
	}
	else
	{
		pos = 128;
		return Clockwise;
	}
}

void RotaryButtonDriver::EncodeFuncB()
{
	cli();
	bool state = digitalRead(incrememtPin);
	if (state == true && flagB) {
		pos++;
		flagB = 0;
		flagA = 0;
	}
	else if (state == false) flagA = 1;
	sei();
}

void RotaryButtonDriver::EncodeFuncA()
{
	cli();
	bool state = digitalRead(decrememtPin);
	if (state == true && flagA) {
		pos--;
		flagB = 0;
		flagA = 0;
	}
	else if (state == false) flagB = 1;
	sei();
}

void RotaryButtonDriver::CheckEnter()
{
	if (digitalRead(enterPin) == 0)
		enterFuncPtr();
}