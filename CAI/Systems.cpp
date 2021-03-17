#include "Systems.h"
#include "ModuleDrivers.h"

ModuleDriver DigitalADriver(DIGITAL_A);
ModuleDriver DigitalBDriver(DIGITAL_B);

void turnLEDON()
{
	DigitalADriver.digitalSwitch(1);
}

void turnLEDOFF()
{
	DigitalADriver.digitalSwitch(0);
}

void turnFANON()
{
	DigitalBDriver.analogSwitch(150);
}

void turnFANOFF()
{
	DigitalBDriver.analogSwitch(50);
}
