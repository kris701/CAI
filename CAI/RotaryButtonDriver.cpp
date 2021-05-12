#include "RotaryButtonDriver.h"

void RotaryButtonDriver::Tick()
{
    if (digitalRead(enterPin) == 0)
        enterFuncPtr();

    bool newflagA = digitalRead(incrememtPin);

    if ((flagA == LOW) && (newflagA == HIGH)) {
        if (digitalRead(decrememtPin) == HIGH)
            incrementFuncPtr();
        else 
            decrementFuncPtr();
    }

    flagA = newflagA;
}
