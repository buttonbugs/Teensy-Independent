#include <Arduino.h>

#include "config.h"
#include "accelerometer.h"              // Accelerometer
#include "receiver.h"                   // Receiver
#include "watchdog.h"                   // Watchdog

#ifndef DEBUG_HEADER_GUARD
#define DEBUG_HEADER_GUARD

void print_info(){
    //
    get_accel();
    Serial.print(millis()); Serial.print("\t");
    Serial.print(accel_x); Serial.print("\t");
    Serial.print(accel_y); Serial.print("\t");
    Serial.print(accel_z); Serial.print("\t");
    Serial.print(sqrtf(pow(accel_x,2.0)+pow(accel_y,2.0)+pow(accel_z,2.0))); Serial.print("\t");
    Serial.print(ch1_value, 2); Serial.print("\t");
    Serial.print(ch2_value, 2); Serial.print("\t");
    Serial.print(ch3_value, 2); Serial.print("\t");
    Serial.print(ch4_value, 2); Serial.println("\t");
}

#endif