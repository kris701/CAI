#include "ScreenDriver.h"

void ScreenDriver::startDisplay() {

	display = Adafruit_SSD1306(screenWidth, screenHeight, &Wire, screenReset);

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

void ScreenDriver::printMenu(MenuItem menuTree[], const uint8_t treeSize, uint8_t currentMenuIndex, uint8_t menuIndex) {
	for (uint8_t i = 0; i < treeSize; i++)
	{
		if (i == currentMenuIndex)
		{
#if SERIAL_PRINT
			Serial.print(F("Titel: "));
			Serial.println(menuTree[i].Getname());
#endif
			printText(F("Titel: "));
			printText(menuTree[i].Getname(), 8);
		}
		if (menuTree[i].GetparentID() == menuTree[currentMenuIndex].GetmenuID())
		{
#if SERIAL_PRINT
			if (i == menuIndex)
				Serial.print(F(":=> "));
			else
				Serial.print(F(":   "));
			Serial.println(menuTree[i].Getname());
#endif
			if (i == menuIndex)
				printText(F(":=> "));
			else
				printText(F(":   "));
			printText(menuTree[i].Getname(), 5);
		}
	}
	display.display();
}

void ScreenDriver::printText(const __FlashStringHelper* text, uint8_t x = 0, uint8_t y = 0, uint8_t textSize = 1, bool print = false)
{
	setTextSettings(x, y, textSize);
	display.println(text);
	if (print)
		display.display();
}

void ScreenDriver::printText(const char* text, uint8_t x = 0, uint8_t y = 0, uint8_t textSize = 1, bool print = false)
{
	setTextSettings(x,y,textSize);
	display.println(text);
	if (print)
		display.display();
}

void ScreenDriver::setTextSettings(uint8_t x, uint8_t y, uint8_t textSize)
{
	display.setTextSize(textSize);
	display.setTextColor(WHITE);
	display.setCursor(x, y);
}

void ScreenDriver::printIntro() {
	printText(F("CAI"), 5, 5, 4, true);
	//delay(2000);
	display.clearDisplay();
}
