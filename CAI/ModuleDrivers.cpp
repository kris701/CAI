#include "ModuleDrivers.h"

void digitalSwitch(int pin, bool state) {
	digitalWrite(pin, state);
}

void analogSwitch(int pin, byte value) {
	analogWrite(pin, value);
}

void motorControllerDigital(int pinA, int pinB, bool valueA, bool valueB) {
	digitalWrite(pinA, valueA);
	digitalWrite(pinB, valueB);
}

void motorControllerAnalog(int pinA, int pinB, byte valueA, byte valueB) {
	analogWrite(pinA, valueA);
	analogWrite(pinB, valueB);
}