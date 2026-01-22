#include <Arduino.h>

#include "config.h"

volatile uint32_t ch1_start, ch2_start, ch3_start, ch4_start = 0;

// Variables to store PWM values
volatile uint32_t ch1_value = 1500;
volatile uint32_t ch2_value = 1500;
volatile uint32_t ch3_value = 1000; // Throttle low
volatile uint32_t ch4_value = 1500;

// Interrupt functions
void ch_changed(
    const uint8_t pin,
    volatile uint32_t& ch_start,
    volatile uint32_t& ch_value
) {
    if (digitalRead(pin) == HIGH) {
        ch_start = micros();
    } else {
        ch_value = micros() - ch_start;
        // calculate from uint32_t to float
    }
}


void init_receiver() {
    pinMode(CH1, INPUT);
    pinMode(CH2, INPUT);
    pinMode(CH3, INPUT);
    pinMode(CH4, INPUT);

    // Attach interrupts to catch rising/falling edges
    attachInterrupt(CH1, []() {ch_changed(CH1, ch1_start, ch1_value);}, CHANGE);
    attachInterrupt(CH2, []() {ch_changed(CH2, ch2_start, ch2_value);}, CHANGE);
    attachInterrupt(CH3, []() {ch_changed(CH3, ch3_start, ch3_value);}, CHANGE);
    attachInterrupt(CH4, []() {ch_changed(CH4, ch4_start, ch4_value);}, CHANGE);
}

void get_receiver(
    volatile uint32_t& ch1,
    volatile uint32_t& ch2,
    volatile uint32_t& ch3,
    volatile uint32_t& ch4
) {
    /* Read RC */
    ch1 = ch1_value;
    ch2 = ch2_value;
    ch3 = ch3_value;
    ch4 = ch4_value;
}