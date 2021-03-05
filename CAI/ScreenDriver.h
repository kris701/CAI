// ScreenDriver.h

#ifndef _SCREENDRIVER_h
#define _SCREENDRIVER_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#if not defined(_CLASSES_h) 
	#include "Classes.h"
#endif

#include <Adafruit_SPIDevice.h>
#include <Adafruit_I2CRegister.h>
#include <Adafruit_I2CDevice.h>
#include <Adafruit_BusIO_Register.h>
#include <splash.h>
#include <Adafruit_SSD1306.h>
#include <gfxfont.h>
#include <Adafruit_SPITFT_Macros.h>
#include <Adafruit_SPITFT.h>
#include <Adafruit_GrayOLED.h>
#include <Adafruit_GFX.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

#define OLED_RESET     -1

void setupOLEDScreen();
void printMenu(const MenuItem menuTree[], int treeSize, int currentMenuIndex, int menuIndex);

void printText(const char* text, int x = 0, int y = 0, int textSize = 1, bool print = false);
void printText(const __FlashStringHelper* text, int x = 0, int y = 0, int textSize = 1, bool print = false);
void setTextSettings(int x, int y, int textSize);
void printIntro();

#endif
