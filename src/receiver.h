#include <Arduino.h>

#include "config.h"

void init_receiver() {
    pinMode(RC_X_MOVE, INPUT);
    pinMode(RC_Y_MOVE, INPUT);
    pinMode(RC_THROTTLE, INPUT);
    pinMode(RC_Z_REVOLUTION, INPUT);
}

// reads accel and converts to G's
void get_receiver(
    volatile unsigned long& ch1,
    volatile unsigned long& ch2,
    volatile unsigned long& ch3,
    volatile unsigned long& ch4
) {
    /* Read RC */
    ch1 = pulseIn(RC_X_MOVE, HIGH);
    ch2 = pulseIn(RC_Y_MOVE, HIGH);
    ch3 = pulseIn(RC_THROTTLE, HIGH);
    ch4 = pulseIn(RC_Z_REVOLUTION, HIGH);
    
}