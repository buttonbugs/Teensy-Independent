#include <Arduino.h>
// Define Pins for Channels
const int ch1Pin = 2; // Roll
const int ch2Pin = 3; // Pitch
const int ch3Pin = 4; // Throttle
const int ch4Pin = 5; // Yaw

// Variables to store PWM values
volatile uint16_t ch1Value = 1500;
volatile uint16_t ch2Value = 1500;
volatile uint16_t ch3Value = 1000; // Throttle low
volatile uint16_t ch4Value = 1500;

// Timing variables
volatile uint32_t ch1Start, ch2Start, ch3Start, ch4Start;

void setup() {
  Serial.begin(115200);
  pinMode(ch1Pin, INPUT);
  pinMode(ch2Pin, INPUT);
  pinMode(ch3Pin, INPUT);
  pinMode(ch4Pin, INPUT);

  // Attach interrupts to catch rising/falling edges
  attachInterrupt(ch1Pin, calcCh1, CHANGE);
  attachInterrupt(ch2Pin, calcCh2, CHANGE);
  attachInterrupt(ch3Pin, calcCh3, CHANGE);
  attachInterrupt(ch4Pin, calcCh4, CHANGE);
}

void loop() {
  // Print values to Serial Monitor
  Serial.print("Ch1: "); Serial.print(ch1Value);
  Serial.print(" | Ch2: "); Serial.print(ch2Value);
  Serial.print(" | Ch3: "); Serial.print(ch3Value);
  Serial.print(" | Ch4: "); Serial.println(ch4Value);
  delay(20); // 50Hz update rate
}

// Interrupt functions
void calcCh1() {
  if (digitalRead(ch1Pin) == HIGH) ch1Start = micros();
  else ch1Value = micros() - ch1Start;
}
void calcCh2() {
  if (digitalRead(ch2Pin) == HIGH) ch2Start = micros();
  else ch2Value = micros() - ch2Start;
}
void calcCh3() {
  if (digitalRead(ch3Pin) == HIGH) ch3Start = micros();
  else ch3Value = micros() - ch3Start;
}
void calcCh4() {
  if (digitalRead(ch4Pin) == HIGH) ch4Start = micros();
  else ch4Value = micros() - ch4Start;
}
