// Systems.h

#ifndef _SYSTEMS_h
#define _SYSTEMS_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#ifndef _CAI_h
	#include "CAI.h"
#endif

#ifndef _CLASSES_h
	#include "Classes.h"
#endif

void turnLEDON();
void turnLEDOFF();
void turnFANON();
void turnFANOFF();

const char PROGMEM TEXT_MAINMENU[] = "Main Menu";
const char PROGMEM TEXT_ON[] = "On";
const char PROGMEM TEXT_OFF[] = "Off";
const char PROGMEM TEXT_BACK[] = "Back";

const char PROGMEM TEXT_LED[] = "LED";
const char PROGMEM TEXT_FAN[] = "FAN";
const char PROGMEM TEXT_FAN2[] = "FAN2";
const char PROGMEM TEXT_FAN3[] = "FAN3";
const char PROGMEM TEXT_FAN4[] = "FAN4";
const char PROGMEM TEXT_FAN5[] = "FAN5";

#define MENU_TREE_SIZE 13
#define USE_TREE {									\
	{0, -1, TEXT_MAINMENU, NULL},					\
		{ 1,0, TEXT_LED, NULL },					\
			{ -1,1, TEXT_ON, turnLEDON },			\
			{ -1,1, TEXT_OFF, turnLEDOFF },			\
			{ -1,1, TEXT_BACK, backMethod },		\
		{ 2,0, TEXT_FAN, NULL },					\
			{ -1,2, TEXT_ON, turnFANON },			\
			{ -1,2, TEXT_OFF, turnFANOFF },			\
			{ -1,2, TEXT_BACK, backMethod },		\
		{ 3,0, TEXT_FAN2, NULL },					\
		{ 4,0, TEXT_FAN3, NULL },					\
		{ 5,0, TEXT_FAN4, NULL },					\
		{ 6,0, TEXT_FAN5, NULL }					\
}													\

#endif

