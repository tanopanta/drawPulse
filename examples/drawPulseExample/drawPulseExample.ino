#include <M5Stack.h>

#include <drawPulse.h>

const int PIN_INPUT = 36;

DrawPulse drawPulse;
void setup() {
    M5.begin();
    dacWrite(25, 0); // Speaker OFF (avoid speaker noise)

    drawPulse.init();
    // drawPulse.init(0, 256); //set min, max parameter.
}

void loop() {
    int y = analogRead(PIN_INPUT);
    drawPulse.addValue(y);
    drawPulse.showMsg("value: " + String(y));
    delay(50);
}
