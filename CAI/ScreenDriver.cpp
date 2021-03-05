#include "ScreenDriver.h"

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setupOLEDScreen() {
	if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
#if SERIAL_PRINT
		Serial.println(F("SSD1306 allocation failed"));
#endif
		for (;;);
	}

	display.display();
	delay(2000);

	display.clearDisplay();
}

void printMenu(const MenuItem menuTree[], uint8_t treeSize, uint8_t currentMenuIndex, uint8_t menuIndex) {
	for (uint8_t i = 0; i < treeSize; i++)
	{
		if (i == currentMenuIndex)
		{
#if SERIAL_PRINT
			Serial.print(F("Titel: "));
			Serial.println(menuTree[i].name);
#else
			printText(F("Titel: "));
			printText(menuTree[i].name, 8);
#endif
		}
		if (menuTree[i].parentID == menuTree[currentMenuIndex].menuID)
		{
#if SERIAL_PRINT
			if (i == menuIndex)
				Serial.print(F(":=> "));
			else
				Serial.print(F(":   "));
			Serial.println(menuTree[i].name);
#else
			if (i == menuIndex)
				printText(F(":=> "));
			else
				printText(F(":   "));
			printText(menuTree[i].name, 5);
#endif
		}
	}
	display.display();
}

void printText(const __FlashStringHelper* text, uint8_t x = 0, uint8_t y = 0, uint8_t textSize = 1, bool print = false)
{
	setTextSettings(x, y, textSize);
	display.println(text);
	if (print)
		display.display();
}

void printText(const char* text, uint8_t x = 0, uint8_t y = 0, uint8_t textSize = 1, bool print = false)
{
	setTextSettings(x,y,textSize);
	display.println(text);
	if (print)
		display.display();
}

void setTextSettings(uint8_t x, uint8_t y, uint8_t textSize)
{
	display.setTextSize(textSize);
	display.setTextColor(WHITE);
	display.setCursor(x, y);
}

void printIntro() {
	printText(F("CAI"), 5, 5, 4, true);
	//delay(2000);
	display.clearDisplay();
}