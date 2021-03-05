#pragma once

#include "MenuStructure.h"

void s_printHeader(const char* text);

void s_printListItem(const char* text, bool highLight);

#define BASE_MENU_LENGTH 2

void s_ShowMenu(Menu* currerntMenu, Menu menuList[BASE_MENU_LENGTH]);
void s_EnterMenu(Menu* currerntMenu, Menu menuList[BASE_MENU_LENGTH]);
void s_DecrementMenuIndex(Menu* currerntMenu, Menu menuList[BASE_MENU_LENGTH]);
void s_IncrementMenuIndex(Menu* currerntMenu, Menu menuList[BASE_MENU_LENGTH]);