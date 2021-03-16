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

private:
	char buffer[50];

	unsigned int ScreenDriver::FSHlength(const __FlashStringHelper* FSHinput);
	void ScreenDriver::setVCursor(uint8_t x = 0, uint8_t y = 0);

	void ScreenDriver::printTextxy(const char* text, uint8_t x = 0, uint8_t y = 0, bool manualTextSettings = false);
	void ScreenDriver::printTextxy(const __FlashStringHelper* text, uint8_t x = 0, uint8_t y = 0, bool manualTextSettings = false);
	void ScreenDriver::printText(const char* text, bool manualTextSettings = false);
	void ScreenDriver::printText(const __FlashStringHelper* text, bool manualTextSettings = false);
	void ScreenDriver::printTextln(const char* text, bool manualTextSettings = false);
	void ScreenDriver::printTextln(const __FlashStringHelper* text, bool manualTextSettings = false);
	void ScreenDriver::printHeader();

	void ScreenDriver::setTextSettings(uint8_t x, uint8_t y);
	void ScreenDriver::setTextSettings();
	
public:
	ScreenDriver(){
		SetscreenWidth(128);
		SetscreenHeight(64);
		SetfontHeight(8);
		SetfontWidth(5);
		SetleftMargin(5);
		SetmenuLength(4);
	};

	void ScreenDriver::startDisplay();
	void ScreenDriver::printMenu(MenuItem menuTree[], const uint8_t treeSize, uint8_t currentMenuIndex, uint8_t menuIndex);
	void ScreenDriver::printIntro();
};

#endif
