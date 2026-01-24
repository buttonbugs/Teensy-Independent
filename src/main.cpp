#include <Arduino.h>

#include "config.h"
#include "accelerometer.h"              // Accelerometer
#include "receiver.h"                   // Receiver
#include "watchdog.h"                   // Watchdog
#include "debug.h"

bool test_led_status;

void setup() {
    /* Pin Definition */
    pinMode(LED_BUILTIN, OUTPUT);

    Serial.begin(9600);

    init_watchdog();
    init_accel();
    init_receiver();
    get_accel();
}

void loop() {
    // turn the LED on (HIGH is the voltage level)
    digitalWriteFast(LED_BUILTIN, test_led_status);
    test_led_status = !test_led_status;

    print_info();
    delay(100);
    if (ch1_value > 0.5) {
        delay(21000);   // Pretend as if the robot were dead
    } else {
        wdt.feed();
    }
    
}