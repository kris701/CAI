// ModuleDrivers.h

#ifndef _MODULEDRIVERS_h
#define _MODULEDRIVERS_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#ifndef _CAI_h
	#include "CAI.h"
#endif

class ModuleDriver {
private:
	uint8_t pin;
public:
	ModuleDriver(uint8_t pin) : pin(pin) {};

	void ModuleDriver::digitalSwitch(bool state);
	void ModuleDriver::analogSwitch(uint8_t value);
};

class DualModuleDriver {
private:
	ModuleDriver driverA;
	ModuleDriver driverB;

public:
	DualModuleDriver(uint8_t pinA, uint8_t pinB) : driverA(ModuleDriver(pinA)), driverB(ModuleDriver(pinB)) {};

	void DualModuleDriver::motorControllerDigital(bool valueA, bool valueB);
	void DualModuleDriver::motorControllerAnalog(uint8_t valueA, uint8_t valueB);
};

#endif

