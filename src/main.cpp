#include <Arduino.h>

#include "config.h"
#include "accelerometer.h"              // Accelerometer
#include "receiver.h"                   // Receiver

bool test_led_status;
float accel_x, accel_y, accel_z;
volatile unsigned long ch1, ch2, ch3, ch4;      // Receiver value

void setup() {
    /* Pin Definition */
    pinMode(LED_BUILTIN, OUTPUT);


    init_accel();
    get_accel(accel_x, accel_y, accel_z);
    get_receiver(ch1, ch2, ch3, ch4);

    Serial.begin(9600);
    
}

void loop() {
    // turn the LED on (HIGH is the voltage level)
    digitalWriteFast(LED_BUILTIN, test_led_status);
    test_led_status = !test_led_status;

    // get_accel(accel_x, accel_y, accel_z);
    get_receiver(ch1, ch2, ch3, ch4);
    // Serial.print(millis()); Serial.print(" ");
    // Serial.print(accel_x); Serial.print(" ");
    // Serial.print(accel_y); Serial.print(" ");
    // Serial.print(accel_z); Serial.print(" ");
    // Serial.println(sqrtf(pow(accel_x,2.0)+pow(accel_y,2.0)+pow(accel_z,2.0)));
    Serial.print(ch1); Serial.print(" ");
    Serial.print(ch2); Serial.print(" ");
    Serial.print(ch3); Serial.print(" ");
    Serial.print(ch4); Serial.println(" ");
}