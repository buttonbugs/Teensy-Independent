#include <Arduino.h>

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  // turn the LED on (HIGH is the voltage level)
  digitalWriteFast(LED_BUILTIN, HIGH);
  delay(50);  // wait for a second

  // turn the LED off by making the voltage LOW
  digitalWriteFast(LED_BUILTIN, LOW);
  delay(50);  // wait for a second
}
