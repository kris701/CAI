#include "ModuleDrivers.h"

void ModuleDriver::digitalSwitch(bool state) {
#if SERIAL_PRINT
	Serial.print(F("Digital Switch( Pin: "));
	Serial.print(pin);
	Serial.print(F(" State: "));
	Serial.print(state);
	Serial.println(F(" )"));
#endif
	digitalWrite(pin, state);
}

void ModuleDriver::analogSwitch(uint8_t value) {
#if SERIAL_PRINT
	Serial.print(F("Analog Switch( Pin: "));
	Serial.print(pin);
	Serial.print(F(" Value: "));
	Serial.print(value);
	Serial.println(F(" )"));
#endif
	analogWrite(pin, value);
}

void DualModuleDriver::motorControllerDigital(bool valueA, bool valueB) {
#if SERIAL_PRINT
	Serial.println(F("Digital Motor Switch"));
#endif
	driverA.digitalSwitch(valueA);
	driverA.digitalSwitch(valueB);
}

void DualModuleDriver::motorControllerAnalog(uint8_t valueA, uint8_t valueB) {
#if SERIAL_PRINT
	Serial.println(F("Analog Motor Switch"));
#endif
	driverA.analogSwitch(valueA);
	driverA.analogSwitch(valueB);
}