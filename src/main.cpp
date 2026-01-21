#include <Arduino.h>

#include "config.h"
#include "accel_handler.h"      // Accelerometer
float accel_x, accel_y, accel_z;

void setup() {
    // initialize digital pin LED_BUILTIN as an output.
    pinMode(LED_BUILTIN, OUTPUT);

    init_accel();
    if (DEBUG_MODE) {
        Serial.begin(9600);
        Serial.println("Hello2");
    }
    
}

void loop() {
    // turn the LED on (HIGH is the voltage level)
    digitalWriteFast(LED_BUILTIN, HIGH);
    delay(100);  // wait for a second
    
    // turn the LED off by making the voltage LOW
    digitalWriteFast(LED_BUILTIN, LOW);
    delay(100);  // wait for a second

    get_accel_force_g(accel_x, accel_y, accel_z);
    Serial.print(millis()); Serial.print(" ");
    Serial.print(accel_x); Serial.print(" ");
    Serial.print(accel_y); Serial.print(" ");
    Serial.print(accel_z); Serial.print(" ");
    Serial.println(sqrtf(pow(accel_x,2.0)+pow(accel_y,2.0)+pow(accel_z,2.0)));
}