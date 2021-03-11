#ifndef _CAI_h
#define _CAI_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

#define SERIAL_PRINT true
#define USE_TEXT_DEFAULTS true

#define DIGITAL_A 4
#define DIGITAL_B 3
#define DIGITAL_C 2

#define MOTOR_A_1 5
#define MOTOR_A_2 6

#define MOTOR_B_1 9
#define MOTOR_B_2 10

#define ANALOG_A A7
#define ANALOG_B A6

#ifdef USE_TEXT_DEFAULTS && USE_TEXT_DEFAULTS == true
const char PROGMEM TEXT_MAINMENU[] = "Main Menu";
const char PROGMEM TEXT_ON[] = "On";
const char PROGMEM TEXT_OFF[] = "Off";
const char PROGMEM TEXT_BACK[] = "Back";
#endif 

#ifdef SERIAL_PRINT && SERIAL_PRINT == true
	#pragma message "Warning: Serial print is on!"
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

#include "Classes.h"
#include "ModuleDrivers.h"
#include "RotaryButtonDriver.h"
#include "ScreenDriver.h"

#endif