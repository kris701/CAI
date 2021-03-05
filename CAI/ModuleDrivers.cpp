#include "ModuleDrivers.h"

void digitalSwitch(uint8_t pin, bool state) {
	digitalWrite(pin, state);
}

void analogSwitch(uint8_t pin, uint8_t value) {
	analogWrite(pin, value);
}

void motorControllerDigital(uint8_t pinA, uint8_t pinB, bool valueA, bool valueB) {
	digitalWrite(pinA, valueA);
	digitalWrite(pinB, valueB);
}

void motorControllerAnalog(uint8_t pinA, uint8_t pinB, uint8_t valueA, uint8_t valueB) {
	analogWrite(pinA, valueA);
	analogWrite(pinB, valueB);
}