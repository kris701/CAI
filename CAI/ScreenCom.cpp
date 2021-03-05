#include "ScreenCom.h"

void s_printHeader(String text) {
	Serial.print(F("Titel: "));
	Serial.println(text);
}

void s_printListItem(String text, bool highLight) {
	if (highLight)
		Serial.print(F(":=> "));
	else
		Serial.print(F(":   "));
	Serial.println(text);
}
