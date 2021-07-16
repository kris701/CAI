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
void screwHeadbed();
void unScrewHeadbed();
void screwToolhead();
void unScrewToolhead();
void holdScrewToolhead();
void base3DPrint();
void baseCNC();
void title();

const char PROGMEM TEXT_MAINMENU[] = "Main Menu";
const char PROGMEM TEXT_ON[] = "On";
const char PROGMEM TEXT_OFF[] = "Off";
const char PROGMEM TEXT_BACK[] = "Back";
const char PROGMEM TEXT_SCREW[] = "SCREW";
const char PROGMEM TEXT_UNSCREW[] = "UNSCREW";
const char PROGMEM TEXT_HOLD[] = "HOLD";

const char PROGMEM TEXT_AUTO[] = " - AUTO";
const char PROGMEM TEXT_MANUAL[] = " - MANUAL";

const char PROGMEM TEXT_LED[] = "LED";
const char PROGMEM TEXT_FAN[] = "FAN";
const char PROGMEM TEXT_HEADBED[] = "HEADBED";
const char PROGMEM TEXT_TOOLHEAD[] = "TOOLHEAD";

const char PROGMEM TEXT_BASE3D[] = "BASE 3D";
const char PROGMEM TEXT_BASECNC[] = "BASE CNC";

#define MENU_TREE_SIZE 22
#define USE_TREE {									\
	{0, -1, TEXT_MAINMENU, NULL},					\
		{ 1,0, TEXT_AUTO, title },					\
		{ 2,0, TEXT_BASE3D, base3DPrint },			\
		{ 3,0, TEXT_BASECNC, baseCNC },				\
		{ 4,0, TEXT_MANUAL, title },				\
		{ 5,0, TEXT_LED, NULL },					\
			{ -1,5, TEXT_ON, turnLEDON },			\
			{ -1,5, TEXT_OFF, turnLEDOFF },			\
			{ -1,5, TEXT_BACK, backMethod },		\
		{ 6,0, TEXT_FAN, NULL },					\
			{ -1,6, TEXT_ON, turnFANON },			\
			{ -1,6, TEXT_OFF, turnFANOFF },			\
			{ -1,6, TEXT_BACK, backMethod },		\
		{ 7,0, TEXT_HEADBED, NULL },				\
			{ -1,7, TEXT_SCREW, screwHeadbed },		\
			{ -1,7, TEXT_UNSCREW, unScrewHeadbed },	\
			{ -1,7, TEXT_BACK, backMethod },		\
		{ 8,0, TEXT_TOOLHEAD, NULL },				\
			{ -1,8, TEXT_SCREW, screwToolhead },	\
			{ -1,8, TEXT_UNSCREW, unScrewToolhead },\
			{ -1,8, TEXT_HOLD, holdScrewToolhead },	\
			{ -1,8, TEXT_BACK, backMethod },		\
}													\

#endif

