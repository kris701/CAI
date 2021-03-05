#include "ScreenDriver.h"

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setupOLEDScreen() {
	if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
		Serial.println(F("SSD1306 allocation failed"));
		for (;;);
	}

	display.display();
	delay(2000);

	display.clearDisplay();
}

void printMenu(const MenuItem menuTree[], int treeSize, int currentMenuIndex, int menuIndex) {
	for (int i = 0; i < treeSize; i++)
	{
		if (i == currentMenuIndex)
		{
			printText(F("Titel: "));
			printText(menuTree[i].name, 8);
			Serial.print(F("Titel: "));
			Serial.println(menuTree[i].name);
		}
		if (menuTree[i].parentID == menuTree[currentMenuIndex].menuID)
		{
			if (i == menuIndex)
				printText(F(":=> "));
			else
				printText(F(":   "));
			printText(menuTree[i].name, 5);

			if (i == menuIndex)
				Serial.print(F(":=> "));
			else
				Serial.print(F(":   "));
			Serial.println(menuTree[i].name);
		}
	}
	display.display();
}

void printText(const __FlashStringHelper* text, int x = 0, int y = 0, int textSize = 1, bool print = false)
{
	setTextSettings(x, y, textSize);
	display.println(text);
	if (print)
		display.display();
}

void printText(const char* text, int x = 0, int y = 0, int textSize = 1, bool print = false)
{
	setTextSettings(x,y,textSize);
	display.println(text);
	if (print)
		display.display();
}

void setTextSettings(int x, int y, int textSize)
{
	display.setTextSize(textSize);
	display.setTextColor(WHITE);
	display.setCursor(x, y);
}

void printIntro() {
	printText(F("CAI"), 5, 5, 4, true);
	delay(2000);
	display.clearDisplay();
}