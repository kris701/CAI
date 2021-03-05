#include "RotaryButtonDriver.h"

void setupRotaryButton(void (*incrementFunc)(), void (*decrementFunc)(), void (*enterFunc)())
{
	attachInterrupt(digitalPinToInterrupt(Interface_InrementRotationPin), incrementFunc, CHANGE);
	attachInterrupt(digitalPinToInterrupt(Interface_DecrementRotationPin), decrementFunc, CHANGE);
	attachInterrupt(digitalPinToInterrupt(Interface_EnterPin), enterFunc, CHANGE);
}

void incrementMenuIndex(const MenuItem menuTree[], int treeSize, int* currentMenuIndex, int* menuIndex)
{
	incrememtIndex(treeSize, menuIndex);
	while (menuTree[*menuIndex].parentID != menuTree[*currentMenuIndex].menuID)
	{
		incrememtIndex(treeSize, menuIndex);
	}
}

void decrementMenuIndex(const MenuItem menuTree[], int treeSize, int* currentMenuIndex, int* menuIndex)
{
	decrememtIndex(treeSize, menuIndex);
	while (menuTree[*menuIndex].parentID != menuTree[*currentMenuIndex].menuID)
	{
		decrememtIndex(treeSize, menuIndex);
	}
}

void enterMenu(const MenuItem menuTree[], int treeSize, int* currentMenuIndex, int* menuIndex)
{
	if (menuTree[*menuIndex].hasChildren)
	{
		*currentMenuIndex = *menuIndex;
		(*menuIndex)++;
	}
	else
		menuTree[*menuIndex].command();
}

void incrememtIndex(int treeSize, int* menuIndex)
{
	(*menuIndex)++;
	if (*menuIndex > treeSize)
		*menuIndex = 0;
}

void decrememtIndex(int treeSize, int* menuIndex)
{
	(*menuIndex)--;
	if (*menuIndex < 0)
		*menuIndex = treeSize - 1;
}