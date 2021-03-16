#include "ScreenDriver.h"

#ifndef _SCREENLIB
#define _SCREENLIB

// config for softwareI2Cmaster lib
#define I2C_HARDWARE 1
#define I2C_TIMEOUT 10
#define I2C_MAXWAIT 10
#define I2C_PULLUP 1
#define I2C_FASTMODE 1
#define SDA_PORT PORTC
#define SDA_PIN 4 // = A4
#define SCL_PORT PORTC
#define SCL_PIN 5 // = A5

// config for tinyprint lib
#define TP_PRINTLINES 0
#define TP_FLASHSTRINGHELPER 1
#define TP_NUMBERS 0
#define TP_FLOAT 0
#define TP_WINDOWSLINEENDS 0

#include <SH1106Lib.h>
#include "glcdfont.h"
#endif

static SH1106Lib display;

void ScreenDriver::startDisplay() {
	display.initialize();

	delay(2000);

	display.clearDisplay();

	display.setFont(font, fontWidth, fontHeight);
}

void ScreenDriver::printHeader() {
	display.clearDisplay();
	setVCursor(leftMargin, 2);
	display.fillRect(0, 0, screenWidth, fontHeight + 2, WHITE);
	display.setTextColor(BLACK, TRANSPARENT);
	printTextln(F("CAI 1.0"), true);
	setVCursor(leftMargin, fontHeight + 7);
}

void ScreenDriver::printMenu(MenuItem menuTree[], const uint8_t treeSize, uint8_t currentMenuIndex, uint8_t menuIndex) {
	printHeader();
	uint8_t newPrintIndex = 0;
	uint8_t printIndex = 0;
	uint8_t printMenuIndex = 0;
	uint8_t printMenuPage = 0;
	uint8_t printArrowIndex = 0;
	uint8_t printArrowPage = 0;
	uint8_t saveX;
	uint8_t saveY;
	for (uint8_t i = 0; i < treeSize; i++)
	{
		if (i == currentMenuIndex)
		{
			setVCursor(30, GetcurrentY());
			printTextln(menuTree[i].Getname());
		}
		if (menuTree[i].GetparentID() == menuTree[currentMenuIndex].GetmenuID())
		{
			if ((printIndex % GetmenuLength()) == 0)
			{
				printMenuPage++;
				if (printArrowIndex == 0)
					printMenuIndex = i;
			}
			if (i == menuIndex)
			{
				printArrowIndex = i;
				printArrowPage = printMenuPage;
			}
			printIndex++;
		}
	}

	saveX = GetcurrentX();
	saveY = GetcurrentY();

	if (printMenuPage > printArrowPage)
		printTextxy(F("v"), GetscreenWidth() - (GetleftMargin() * 2), GetfontHeight() * 6);
	if (printArrowPage > 1)
		printTextxy(F("^"), GetscreenWidth() - (GetleftMargin() * 2), GetfontHeight() * 3);

	SetcurrentX(saveX);
	SetcurrentY(saveY);

	setVCursor(GetleftMargin(), GetcurrentY() + 6);

	for (uint8_t i = printMenuIndex; i < treeSize; i++)
	{
		if (menuTree[i].GetparentID() == menuTree[currentMenuIndex].GetmenuID())
		{
			if (newPrintIndex >= GetmenuLength())
				break;
			newPrintIndex++;
			if (i == printArrowIndex)
			{
				printText(F("=> "));
			}
			else
			{
				printText(F("   "));
			}
			printTextln(menuTree[i].Getname());
		}
	}
}

void ScreenDriver::printTextxy(const char* text, uint8_t x = 0, uint8_t y = 0, bool manualTextSettings = false)
{
	if (!manualTextSettings)
		setTextSettings(x, y);
	display.print(text);
}

void ScreenDriver::printTextxy(const __FlashStringHelper* text, uint8_t x = 0, uint8_t y = 0, bool manualTextSettings = false)
{
	const byte textLength = FSHlength(text);
	memcpy_P(buffer, text, textLength + 1);
	printTextxy(buffer, x, y, manualTextSettings);
}

void ScreenDriver::printText(const char* text, bool manualTextSettings = false)
{
	if (!manualTextSettings)
		setTextSettings();
	display.print(text);
}

void ScreenDriver::printText(const __FlashStringHelper* text, bool manualTextSettings = false)
{
	const byte textLength = FSHlength(text);
	memcpy_P(buffer, text, textLength + 1);
	printText(buffer, manualTextSettings);
}

void ScreenDriver::printTextln(const char* text, bool manualTextSettings = false)
{
	if (!manualTextSettings)
		setTextSettings();
	display.print(text);
	setVCursor(GetleftMargin(), GetcurrentY() + GetfontHeight());
}

void ScreenDriver::printTextln(const __FlashStringHelper* text, bool manualTextSettings = false)
{
	const byte textLength = FSHlength(text);
	memcpy_P(buffer, text, textLength + 1);
	printTextln(buffer, manualTextSettings);
}

void ScreenDriver::setTextSettings(uint8_t x, uint8_t y)
{
	setTextSettings();
	setVCursor(x, y);
}

void ScreenDriver::setTextSettings()
{
	display.setTextColor(WHITE, BLACK);
}

void ScreenDriver::printIntro() {
	printTextxy(F("CAI"), 5, 5);
	delay(2000);
	display.clearDisplay();
}

void ScreenDriver::setVCursor(uint8_t x = 0, uint8_t y = 0) {
	SetcurrentX(x);
	SetcurrentY(y);
	display.setCursor(x, y);
}

unsigned int ScreenDriver::FSHlength(const __FlashStringHelper* FSHinput) {
	PGM_P FSHinputPointer = reinterpret_cast<PGM_P>(FSHinput);
	unsigned int stringLength = 0;
	while (pgm_read_byte(FSHinputPointer++)) {
		stringLength++;
	}
	return stringLength;
}
