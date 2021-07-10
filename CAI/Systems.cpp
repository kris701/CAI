#include "Systems.h"
#include "ModuleDrivers.h"

ModuleDriver DigitalADriver(DIGITAL_A);
ModuleDriver DigitalBDriver(DIGITAL_C);

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
	turnFANON();
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
	HeadbedDriver.motorControllerDigital(1, 0);
	delay(3000);
	HeadbedDriver.motorControllerDigital(0, 0);
}

void unScrewHeadbed()
{
	HeadbedDriver.motorControllerDigital(0, 1);
	delay(3000);
	HeadbedDriver.motorControllerDigital(0, 0);
}

void screwToolhead()
{
	ToolheadDriver.motorControllerDigital(1, 0);
	delay(3000);
	ToolheadDriver.motorControllerDigital(0, 0);
}

void unScrewToolhead()
{
	ToolheadDriver.motorControllerDigital(0, 1);
	delay(3000);
	ToolheadDriver.motorControllerDigital(0, 0);
}

void title() {}
