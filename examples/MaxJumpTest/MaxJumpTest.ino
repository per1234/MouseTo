// Demonstrates the effect of different MouseTo.setMaxJump() settings.

#if ARDUINO > 10605
#include <Mouse.h>
#endif  //ARDUINO > 10605
#include <MouseTo.h>

const byte pin = 10;
byte maxJump;

void setup() {
  Mouse.begin();
  Serial.begin(9600);
  pinMode(pin, INPUT_PULLUP);
}

void loop() {
  while (digitalRead(pin) == LOW) {
    maxJump++;
    if (maxJump == 128) {
      maxJump = 1;
    }
    Serial.print(F("maxJump="));
    Serial.println(maxJump);
    MouseTo.setMaxJump(maxJump);
    while (MouseTo.moveTo(400, 400) == false) {}
    delay(3000);
  }
}

