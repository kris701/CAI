#include "ScreenCom.h"

void s_printHeader(const char* text) {
	Serial.print(F("Titel: "));
	Serial.println(text);
}

void s_printListItem(const char* text, bool highLight) {
	if (highLight)
		Serial.print(F(":=> "));
	else
		Serial.print(F(":   "));
	Serial.println(text);
}
