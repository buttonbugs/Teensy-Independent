#include <Arduino.h>
#include "Watchdog_t4.h"
#include "config.h"

#ifndef WATCHDOG_HEADER_GUARD
#define WATCHDOG_HEADER_GUARD

WDT_T4<WDT1> wdt;
void my_watchdog_callback() {
    Serial.println("FEED THE DOG SOON, OR RESET!");
}

void init_watchdog() {
    WDT_timings_t config;
    config.trigger = 10; /* in seconds, 0->128 */
    config.timeout = WATCH_DOG_TIMEOUT_S; /* in seconds, 0->128 */
    config.callback = my_watchdog_callback;
    Serial.print("Watchdog begin");
    Serial.println(WATCH_DOG_TIMEOUT_S);
    wdt.begin(config);
    pinMode(13, OUTPUT);
}


#endif