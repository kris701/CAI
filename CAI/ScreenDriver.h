// ScreenDriver.h

#ifndef _SCREENDRIVER_h
#define _SCREENDRIVER_h

#ifndef _CLASSES_h
	#include "Classes.h"
#endif

#ifndef _CAI_h
	#include "CAI.h"
#endif

#ifndef _MACROS_h
	#include "Macros.h"
#endif

struct Rectangle {
	uint8_t x;
	uint8_t y;
	uint8_t width;
	uint8_t height;
};

class ScreenDriver {
	GET_PMSET_Property(uint8_t, screenWidth, 
		{
			#if SERIAL_PRINT == true && SERIAL_DEBUG == true
				CHECKVALUE(value == 0, screenWidth, ScreenDriver)
			#endif
			screenWidth = value;
		}
	)
	GET_PMSET_Property(uint8_t, screenHeight,
		{
			#if SERIAL_PRINT == true && SERIAL_DEBUG == true
				CHECKVALUE(value == 0, screenHeight, ScreenDriver)
			#endif
			screenHeight = value;
		}
	)
	GET_PSET_Property(uint8_t, currentX)
	GET_PSET_Property(uint8_t, currentY)
	GET_PSET_Property(uint8_t, fontHeight)
	GET_PSET_Property(uint8_t, fontWidth)
	GET_PSET_Property(uint8_t, leftMargin)
	GET_PSET_Property(uint8_t, menuLength)
	GET_PSET_Property(uint8_t, lastMenu)
	GET_PSET_Property(uint8_t, lastCursorIndex)
	GET_PSET_Property(uint8_t, lastMenuIndex)
	GET_PSET_Property(Rectangle, lastRect)

private:
	const Rectangle headerRect = {0, 0, 127, 11};
	const Rectangle cursorRect = { 0, 22, 19, 41 };
	const Rectangle menuHeaderRect = { 20, 12, 97, 9 };
	const Rectangle menuItemsRect = { 20, 22, 97, 41 };
	const Rectangle pageArrowRect = { 118, 12, 9, 51 };

	void ScreenDriver::setVCursor(uint8_t x = 0, uint8_t y = 0);
	void ScreenDriver::printRect(Rectangle rect, uint8_t color);

	void ScreenDriver::printText(const __FlashStringHelper* text, Rectangle drawRect, uint8_t xOffset = 0, uint8_t yOffset = 0, uint8_t frontColor = 1, uint8_t backColor = 0);
	void ScreenDriver::printTextln(const __FlashStringHelper* text, Rectangle drawRect, uint8_t xOffset = 0, uint8_t yOffset = 0, uint8_t frontColor = 1, uint8_t backColor = 0);

	void ScreenDriver::printHeader();
	void ScreenDriver::printMenuHeader(MenuItem menuTree[], uint8_t currentMenuIndex);
	void ScreenDriver::printMenuItems(MenuItem menuTree[], const uint8_t treeSize, uint8_t currentMenuIndex, uint8_t printArrowPage, uint8_t printMenuIndex, uint8_t printArrowIndex);
	void ScreenDriver::hightlightMenuItem(MenuItem menuTree[], const uint8_t treeSize, uint8_t currentMenuIndex, uint8_t printMenuIndex, uint8_t printArrowIndex);
	void ScreenDriver::printCursor(MenuItem menuTree[], const uint8_t treeSize, uint8_t currentMenuIndex, uint8_t printArrowPage, uint8_t printMenuIndex, uint8_t printArrowIndex);
	void ScreenDriver::printPageArrows(uint8_t currentMenuIndex, uint8_t printArrowPage, uint8_t printMenuPage);

	void ScreenDriver::setTextSettings(uint8_t x, uint8_t y, uint8_t frontColor = 1, uint8_t backColor = 0);
	
public:
	ScreenDriver(){
		SetscreenWidth(128);
		SetscreenHeight(64);
		SetfontHeight(8);
		SetfontWidth(5);
		SetleftMargin(5);
		SetmenuLength(5);
		SetlastMenuIndex(-1);
	};

	void ScreenDriver::startDisplay();
	void ScreenDriver::printMenu(MenuItem menuTree[], const uint8_t treeSize, uint8_t currentMenuIndex, uint8_t menuIndex, bool isClick = false);
	void ScreenDriver::printEnterMenu(MenuItem menuTree[], const uint8_t treeSize, uint8_t currentMenuIndex, uint8_t menuIndex);
	void ScreenDriver::printIntro();
};

#endif
