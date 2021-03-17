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

	display.clearDisplay();

	display.setFont(font, fontWidth, fontHeight);
}

void ScreenDriver::printHeader() {
	display.clearDisplay();
	printRect(headerRect, WHITE);
	printText(F("CAI 1.0"), headerRect, 5,2, BLACK, TRANSPARENT);
}

void ScreenDriver::printMenu(MenuItem menuTree[], const uint8_t treeSize, uint8_t currentMenuIndex, uint8_t menuIndex, bool isClick = false) {
	uint8_t printIndex = 0;
	uint8_t printMenuIndex = 0;
	uint8_t printMenuPage = 0;
	uint8_t printArrowIndex = 0;
	uint8_t printArrowPage = 0;
	uint8_t printArrowPageIndex = 0;

	bool keepBufferingPage = true;
	bool keepBuffering = true;

	for (uint8_t i = 0; i < treeSize; i++)
	{
		if (menuTree[i].parentID == menuTree[currentMenuIndex].menuID)
		{
			if ((printIndex % menuLength) == 0 && printIndex != 0)
			{
				if (!keepBufferingPage)
					keepBuffering = false;
				printMenuPage++;
				if (printArrowIndex == 0)
					printMenuIndex = i;
			}
			if (i == menuIndex)
			{
				keepBufferingPage = false;
				printArrowPageIndex = printIndex % menuLength;
				printArrowIndex = i;
				printArrowPage = printMenuPage;
			}

			if (keepBuffering)
				menuBuffer[(printIndex % menuLength)] = i;

			printIndex++;
		}
	}
	if (printIndex % menuLength != 0 && keepBuffering)
		for (uint8_t i = (printIndex % menuLength); i < menuLength; i++)
			menuBuffer[i] = UINT8_MAX;

	if (isClick)
	{
		hightlightMenuItem(currentMenuIndex, printArrowIndex, printArrowPageIndex);
	}
	else
	{
		printMenuHeader(menuTree, currentMenuIndex);
		printPageArrows(currentMenuIndex, printArrowPage, printMenuPage);
		printMenuItems(menuTree, currentMenuIndex, printArrowPage, printMenuIndex, printArrowIndex);
		printCursor(currentMenuIndex, printArrowIndex, printArrowPageIndex);
		lastMenuIndex = currentMenuIndex;
	}
}

void ScreenDriver::printMenuHeader(MenuItem menuTree[], uint8_t currentMenuIndex) {
	if (lastMenuIndex != currentMenuIndex)
	{
		printRect(menuHeaderRect, BLACK);
		printTextln(menuTree[currentMenuIndex].name, menuHeaderRect, 10, 2);
	}
}

void ScreenDriver::printPageArrows(uint8_t currentMenuIndex, uint8_t printArrowPage, uint8_t printMenuPage) {
	if (lastMenu != printArrowPage || lastMenuIndex != currentMenuIndex)
	{
		printRect(pageArrowRect, BLACK);
		if (printMenuPage > printArrowPage)
			printText(F("v"), pageArrowRect, 0, 40);
		if (printArrowPage > 0)
			printText(F("^"), pageArrowRect, 0, 5);
	}
}

void ScreenDriver::printMenuItems(MenuItem menuTree[], uint8_t currentMenuIndex, uint8_t printArrowPage, uint8_t printMenuIndex, uint8_t printArrowIndex) {
	if (lastMenu != printArrowPage || lastMenuIndex != currentMenuIndex)
	{
		printRect(menuItemsRect, BLACK);
		for (uint8_t i = 0; i < menuLength; i++)
		{
			if (menuBuffer[i] != UINT8_MAX)
				printTextln(menuTree[menuBuffer[i]].name, menuItemsRect);
		}
		lastMenu = printArrowPage;
	}
}

void ScreenDriver::hightlightMenuItem(uint8_t currentMenuIndex, uint8_t printArrowIndex, uint8_t printArrowPageIndex) {
	if (lastCursorIndex != printArrowIndex || lastMenuIndex != currentMenuIndex)
	{
		Rectangle coverText = { menuItemsRect.x, menuItemsRect.y + fontHeight * printArrowPageIndex, menuItemsRect.width, fontHeight };
		printRect(coverText, WHITE);

		lastCursorIndex = printArrowIndex;
	}
}

void ScreenDriver::printCursor(uint8_t currentMenuIndex, uint8_t printArrowIndex, uint8_t printArrowPageIndex) {
	if (lastCursorIndex != printArrowIndex || lastMenuIndex != currentMenuIndex)
	{
		printRect(cursorRect, BLACK);

		printTextln(F("=>"), cursorRect, 5, printArrowPageIndex * fontHeight);

		lastCursorIndex = printArrowIndex;
	}
}

void ScreenDriver::printText(const __FlashStringHelper* text, Rectangle drawRect, uint8_t xOffset = 0, uint8_t yOffset = 0, uint8_t frontColor = WHITE, uint8_t backColor = BLACK)
{
	if (drawRect.x != lastRect.x || 
		drawRect.y != lastRect.y || 
		drawRect.width != lastRect.width || 
		drawRect.height != lastRect.height)
	{
		setTextSettings(drawRect.x + xOffset, drawRect.y + yOffset, frontColor, backColor);
		lastRect = drawRect;
	}
	else
	{
		if (xOffset != 0 || yOffset != 0)
			setTextSettings(drawRect.x + xOffset, drawRect.y + yOffset, frontColor, backColor);
	}
	display.print(text);
}

void ScreenDriver::printTextln(const __FlashStringHelper* text, Rectangle drawRect, uint8_t xOffset = 0, uint8_t yOffset = 0, uint8_t frontColor = WHITE, uint8_t backColor = BLACK)
{
	printText(text, drawRect, xOffset, yOffset, frontColor, backColor);
	setVCursor(drawRect.x, currentY + fontHeight);
}

void ScreenDriver::setTextSettings(uint8_t x, uint8_t y, uint8_t frontColor, uint8_t backColor)
{
	display.setTextColor(frontColor, backColor);
	setVCursor(x, y);
}

void ScreenDriver::printIntro() {
	printText(F("CAI Starting..."), menuItemsRect, 0, 10);
	delay(2000);
	display.clearDisplay();
	printHeader();
}

void ScreenDriver::setVCursor(uint8_t x = 0, uint8_t y = 0) {
	currentX = x;
	currentY = y;
	display.setCursor(x, y);
}

void ScreenDriver::printRect(Rectangle rect, uint8_t color) {
	display.fillRect(rect.x, rect.y, rect.width, rect.height, color);
}

void ScreenDriver::printEnterMenu(MenuItem menuTree[], const uint8_t treeSize, uint8_t currentMenuIndex, uint8_t menuIndex) {
	lastMenuIndex = -1;
	printMenu(menuTree, treeSize, currentMenuIndex, menuIndex, true);
	delay(50);
}