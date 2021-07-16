#include "Systems.h"
#include "ModuleDrivers.h"

void motorDriver(DualModuleDriver driver, int dirA, int dirB, int holdFor);

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

void screwHeadbed() {
	motorDriver(HeadbedDriver, 0, 1, screwUnscrewTime);
}

void unScrewHeadbed() {
	motorDriver(HeadbedDriver, 1, 0, screwUnscrewTime);
}

void screwToolhead() {
	motorDriver(ToolheadDriver, 0, 1, screwUnscrewTime);
}

void unScrewToolhead() {
	motorDriver(ToolheadDriver, 1, 0 , screwUnscrewTime);
}

void holdScrewToolhead() {
	bool continueLoop = true;
	while (continueLoop) {
		motorDriver(ToolheadDriver, 0, 1, 500);
		for (int i = 0; i < 100; i++)
		{
			if (digitalRead(Interface_EnterPin) == 0) {
				continueLoop = false;
				break;
			}
			delay(100);
		}
	}
}


void motorDriver(DualModuleDriver driver, int dirA, int dirB, int holdFor) {
	driver.motorControllerDigital(dirA, dirB);
	if (holdFor != 0) {
		delay(holdFor);
		driver.motorControllerDigital(0, 0);
	}
}

void title() {}
