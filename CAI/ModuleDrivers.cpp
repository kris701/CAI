#include "ModuleDrivers.h"

void digitalSwitch(uint8_t pin, bool state) {
#if SERIAL_PRINT
	Serial.print(F("Digital Switch( Pin: "));
	Serial.print(pin);
	Serial.print(F(" State: "));
	Serial.print(state);
	Serial.println(F(" )"));
#endif
	digitalWrite(pin, state);
}

void analogSwitch(uint8_t pin, uint8_t value) {
#if SERIAL_PRINT
	Serial.print(F("Analog Switch( Pin: "));
	Serial.print(pin);
	Serial.print(F(" Value: "));
	Serial.print(value);
	Serial.println(F(" )"));
#endif
	analogWrite(pin, value);
}

void motorControllerDigital(uint8_t pinA, uint8_t pinB, bool valueA, bool valueB) {
#if SERIAL_PRINT
	Serial.println(F("Digital Motor Switch"));
#endif
	digitalSwitch(pinA, valueA);
	digitalSwitch(pinB, valueB);
}

void motorControllerAnalog(uint8_t pinA, uint8_t pinB, uint8_t valueA, uint8_t valueB) {
#if SERIAL_PRINT
	Serial.println(F("Analog Motor Switch"));
#endif
	analogSwitch(pinA, valueA);
	analogSwitch(pinB, valueB);
}