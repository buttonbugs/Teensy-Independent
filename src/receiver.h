// This file gets data from the receiver and stores them as variables
// Those variables will be used whenever needed

#include <Arduino.h>

#include "config.h"
#include "motor_status_range.h"


#ifndef RECEIVER_HEADER_GUARD
#define RECEIVER_HEADER_GUARD

volatile uint32_t ch1_start, ch2_start, ch3_start, ch4_start = 0;

// Variables to store PWM values
volatile float ch1_value = 0.5;
volatile float ch2_value = 0.5;
volatile float ch3_value = 0.0; // Throttle low
volatile float ch4_value = 0.5;

float ch1_ratio = 0.1;

// Interrupt functions
void ch_changed(
    const uint8_t pin,
    volatile uint32_t& ch_start,
    volatile float& ch_value
) {
    if (digitalRead(pin) == HIGH) {
        ch_start = micros();
    } else {
        /* convert the pulse length
            From uint8_t range: from RC_MIN_PULSE_LEGNTH to RC_MAX_PULSE_LEGNTH
            To float range:     from -1.0 to 1.0
         */
        ch_value = (micros() - ch_start - (float)RC_MIN_PULSE_LEGNTH) * (2.0f / RC_PULSE_LEGNTH_RANGE) - 1;
    }
}

// Bind Functoins
void ch1_changed(){
    ch_changed(CH1, ch1_start, ch1_value);
}
void ch2_changed(){
    ch_changed(CH2, ch2_start, ch2_value);
}
void ch3_changed(){
    ch_changed(CH3, ch3_start, ch3_value);
}
void ch4_changed(){
    ch_changed(CH4, ch4_start, ch4_value);
}


void init_receiver() {
    pinMode(CH1, INPUT);
    pinMode(CH2, INPUT);
    pinMode(CH3, INPUT);
    pinMode(CH4, INPUT);

    // Attach interrupts to catch rising/falling edges
    attachInterrupt(CH1, ch1_changed, CHANGE);
    attachInterrupt(CH2, ch2_changed, CHANGE);
    attachInterrupt(CH3, ch3_changed, CHANGE);
    attachInterrupt(CH4, ch4_changed, CHANGE);
}

#endif