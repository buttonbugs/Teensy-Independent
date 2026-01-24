#include <Arduino.h>

#include "config.h"
#include "accelerometer.h"              // Accelerometer
#include "receiver.h"                   // Receiver
#include "debug.h"

bool test_led_status;

void setup() {
    /* Pin Definition */
    pinMode(LED_BUILTIN, OUTPUT);


    init_accel();
    init_receiver();
    get_accel();

    Serial.begin(9600);
    
}

void loop() {
    // turn the LED on (HIGH is the voltage level)
    digitalWriteFast(LED_BUILTIN, test_led_status);
    test_led_status = !test_led_status;

    print_info();
    delay(100);
}