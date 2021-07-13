#include "Systems.h"
#include "ModuleDrivers.h"

#define screwUnscrewTime 5000

ModuleDriver DigitalADriver(DIGITAL_C);
ModuleDriver DigitalBDriver(DIGITAL_B);

DualModuleDriver HeadbedDriver(MOTOR_A_1, MOTOR_A_2);
DualModuleDriver ToolheadDriver(MOTOR_B_1, MOTOR_B_2);

void base3DPrint()
{
	turnLEDON();
	turnFANON();
	screwHeadbed();
	screwToolhead();
}

void baseCNC()
{
	turnLEDON();
	screwHeadbed();
	screwToolhead();
}

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
	DigitalBDriver.digitalSwitch(1);
}

void turnFANOFF()
{
	DigitalBDriver.digitalSwitch(0);
}

void screwHeadbed()
{
	HeadbedDriver.motorControllerDigital(0, 1);
	delay(screwUnscrewTime);
	HeadbedDriver.motorControllerDigital(0, 0);
}

void unScrewHeadbed()
{
	HeadbedDriver.motorControllerDigital(1, 0);
	delay(screwUnscrewTime);
	HeadbedDriver.motorControllerDigital(0, 0);
}

void screwToolhead()
{
	ToolheadDriver.motorControllerDigital(0, 1);
	delay(screwUnscrewTime);
	ToolheadDriver.motorControllerDigital(0, 0);
}

void unScrewToolhead()
{
	ToolheadDriver.motorControllerDigital(1, 0);
	delay(screwUnscrewTime);
	ToolheadDriver.motorControllerDigital(0, 0);
}

void title() {}
