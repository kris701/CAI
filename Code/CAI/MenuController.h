// MenuController.h

#ifndef _MENUCONTROLLER_h
#define _MENUCONTROLLER_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#ifndef _CLASSES_h
	#include "Classes.h"
#endif

class MenuController {
private:
	void MenuController::incrememtIndex(const uint8_t treeSize, uint8_t* menuIndex);
	void MenuController::decrememtIndex(const uint8_t treeSize, uint8_t* menuIndex);

public:
	MenuController(){};

	void MenuController::incrementMenuIndex(const MenuItem menuTree[], const uint8_t treeSize, uint8_t* currentMenuIndex, uint8_t* menuIndex);
	void MenuController::decrementMenuIndex(const MenuItem menuTree[], const uint8_t treeSize, uint8_t* currentMenuIndex, uint8_t* menuIndex);
	void MenuController::enterMenu(const MenuItem menuTree[], const uint8_t treeSize, uint8_t* currentMenuIndex, uint8_t* menuIndex);
};

#endif

