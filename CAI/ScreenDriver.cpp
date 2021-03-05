// 
// 
// 

#include "ScreenDriver.h"


void printMenu(const MenuItem menuTree[], int treeSize, int currentMenuIndex, int menuIndex) {
	for (int i = 0; i < treeSize; i++)
	{
		if (i == currentMenuIndex)
		{
			Serial.print(F("Titel: "));
			Serial.println(menuTree[i].name);
		}
		if (menuTree[i].parentID == menuTree[currentMenuIndex].menuID)
		{
			if (i == menuIndex)
				Serial.print(F(":=> "));
			else
				Serial.print(F(":   "));
			Serial.println(menuTree[i].name);
		}
	}
}