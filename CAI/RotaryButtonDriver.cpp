// 
// 
// 

#include "RotaryButtonDriver.h"

void setupRotaryButton(void (*incrementFunc)(), void (*decrementFunc)(), void (*enterFunc)())
{
	attachInterrupt(digitalPinToInterrupt(Interface_InrementRotationPin), incrementFunc, CHANGE);
	attachInterrupt(digitalPinToInterrupt(Interface_DecrementRotationPin), decrementFunc, CHANGE);
	attachInterrupt(digitalPinToInterrupt(Interface_EnterPin), enterFunc, CHANGE);
}

void incrementMenuIndex(const MenuItem menuTree[], int treeSize, int* currentMenuIndex, int* menuIndex)
{
	(*menuIndex)++;
	if (*menuIndex > treeSize)
		*menuIndex = 0;
	while (menuTree[*menuIndex].parentID != menuTree[*currentMenuIndex].menuID)
	{
		(*menuIndex)++;
		if (*menuIndex > treeSize)
			*menuIndex = 0;
	}
}

void decrementMenuIndex(const MenuItem menuTree[], int treeSize, int* currentMenuIndex, int* menuIndex)
{
	(*menuIndex)--;
	if (*menuIndex < 0)
		*menuIndex = treeSize - 1;
	while (menuTree[*menuIndex].parentID != menuTree[*currentMenuIndex].menuID)
	{
		(*menuIndex)--;
		if (*menuIndex < 0)
			*menuIndex = treeSize - 1;
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