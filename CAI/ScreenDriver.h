// ScreenDriver.h

#ifndef _SCREENDRIVER_h
#define _SCREENDRIVER_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#ifndef _CLASSES_h
	#include "Classes.h"
#endif

#ifndef _SCREENLIB
	#define _SCREENLIB
	#include <splash.h>
	#include <Adafruit_SSD1306.h>
	#include <gfxfont.h>
	#include <Adafruit_SPITFT_Macros.h>
	#include <Adafruit_SPITFT.h>
	#include <Adafruit_GrayOLED.h>
	#include <Adafruit_GFX.h>
	#include <Adafruit_SPIDevice.h>
	#include <Adafruit_I2CRegister.h>
	#include <Adafruit_I2CDevice.h>
	#include <Adafruit_BusIO_Register.h>
#endif

#ifndef _CAI_h
	#include "CAI.h"
#endif

#ifndef _MACROS_h
	#include "Macros.h"
#endif

class ScreenDriver {
	GET_Property(const uint8_t, screenWidth)
	GET_Property(const uint8_t, screenHeight)
	GET_Property(const uint8_t, screenReset)

private:
	Adafruit_SSD1306 display;

	void printText(const char* text, uint8_t x = 0, uint8_t y = 0, uint8_t textSize = 1, bool print = false);
	void printText(const __FlashStringHelper* text, uint8_t x = 0, uint8_t y = 0, uint8_t textSize = 1, bool print = false);
	void setTextSettings(uint8_t x, uint8_t y, uint8_t textSize);
	
public:
	ScreenDriver(const uint8_t screenWidth, const uint8_t screenHeight, const uint8_t screenReset) 
		: screenWidth(screenWidth), screenHeight(screenHeight), screenReset(screenReset){};

	void startDisplay();
	void printMenu(MenuItem menuTree[], const uint8_t treeSize, uint8_t currentMenuIndex, uint8_t menuIndex);
	void printIntro();
};

#endif
