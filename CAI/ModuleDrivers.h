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

#ifndef _MACROS_h
	#include "Macros.h"
#endif

class ModuleDriver {
	GET_PMSET_Property(uint8_t, pin,
		{
			#if SERIAL_PRINT == true && SERIAL_DEBUG == true
				CHECKVALUE(!ISVALIDPIN(value), pin, ModuleDriver)
			#endif
			pin = value;
		}
	)

public:
	ModuleDriver();
	ModuleDriver(uint8_t pin) {
		Setpin(pin);
	};

	void ModuleDriver::digitalSwitch(bool state);
	void ModuleDriver::analogSwitch(uint8_t value);
};

class DualModuleDriver {
private:
	GET_PSET_Property(ModuleDriver, driverA)
	GET_PSET_Property(ModuleDriver, driverB)

public:
	DualModuleDriver();
	DualModuleDriver(uint8_t pinA, uint8_t pinB) {
		SetdriverA(ModuleDriver(pinA));
		SetdriverB(ModuleDriver(pinB));
	};

	void DualModuleDriver::motorControllerDigital(bool valueA, bool valueB);
	void DualModuleDriver::motorControllerAnalog(uint8_t valueA, uint8_t valueB);
};

#endif

