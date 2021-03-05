#pragma once

#include <Arduino.h>
#include "MenuStructure.h"

#define Interface_InrementRotationPin 5
#define Interface_DecrementRotationPin 6
#define Interface_EnterPin 7

#define BASE_MENU_LENGTH 2

void getConfiguration(Menu **_menuList);
void ConfigureMenu(Menu** menuList);

void turnLEDON();
void turnLEDOFF();

void turnFANON();
void turnFANOFF();

void backMethod();
