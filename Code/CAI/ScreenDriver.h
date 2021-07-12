// ScreenDriver.h

#ifndef _SCREENDRIVER_h
#define _SCREENDRIVER_h

#ifndef _CLASSES_h
	#include "Classes.h"
#endif

#ifndef _CAI_h
	#include "CAI.h"
#endif

struct Rectangle {
	uint8_t x;
	uint8_t y;
	uint8_t width;
	uint8_t height;
};

const uint8_t screenWidth = 128;
const uint8_t screenHeight = 64;
const uint8_t fontHeight = 8;
const uint8_t fontWidth = 5;
static const uint8_t menuLength = 5;
const Rectangle headerRect = { 0, 0, 127, 11 };
const Rectangle cursorRect = { 0, 22, 19, 41 };
const Rectangle menuHeaderRect = { 20, 12, 97, 9 };
const Rectangle menuItemsRect = { 20, 22, 97, 41 };
const Rectangle pageArrowRect = { 118, 12, 9, 51 };

class ScreenDriver {
private:
	uint8_t currentX = 0;
	uint8_t currentY = 0;

	uint8_t lastMenu = 0;
	uint8_t lastCursorIndex = 0;
	uint8_t lastMenuIndex = -1;
	Rectangle lastRect = {};
	uint8_t menuBuffer[menuLength];

	void ScreenDriver::setVCursor(uint8_t x = 0, uint8_t y = 0);
	void ScreenDriver::printRect(Rectangle rect, uint8_t color);

	void ScreenDriver::printText(const __FlashStringHelper* text, Rectangle drawRect, uint8_t xOffset = 0, uint8_t yOffset = 0, uint8_t frontColor = 1, uint8_t backColor = 0);
	void ScreenDriver::printTextln(const __FlashStringHelper* text, Rectangle drawRect, uint8_t xOffset = 0, uint8_t yOffset = 0, uint8_t frontColor = 1, uint8_t backColor = 0);

	void ScreenDriver::printHeader();
	void ScreenDriver::printMenuHeader(const MenuItem menuTree[], uint8_t currentMenuIndex);
	void ScreenDriver::printMenuItems(const MenuItem menuTree[], uint8_t currentMenuIndex, uint8_t printArrowPage, uint8_t printMenuIndex, uint8_t printArrowIndex);
	void ScreenDriver::hightlightMenuItem(uint8_t currentMenuIndex, uint8_t printArrowIndex, uint8_t printArrowPageIndex);
	void ScreenDriver::printCursor(uint8_t currentMenuIndex, uint8_t printArrowIndex, uint8_t printArrowPageIndex);
	void ScreenDriver::printPageArrows(uint8_t currentMenuIndex, uint8_t printArrowPage, uint8_t printMenuPage);

	void ScreenDriver::setTextSettings(uint8_t x, uint8_t y, uint8_t frontColor = 1, uint8_t backColor = 0);
	
public:
	ScreenDriver(){};

	void ScreenDriver::startDisplay();
	void ScreenDriver::printMenu(const MenuItem menuTree[], const uint8_t treeSize, uint8_t currentMenuIndex, uint8_t menuIndex, bool isClick = false);
	void ScreenDriver::printEnterMenu(const MenuItem menuTree[], const uint8_t treeSize, uint8_t currentMenuIndex, uint8_t menuIndex);
	void ScreenDriver::printIntro();
	void ScreenDriver::printLoading();
};

#endif
