#include "config.h"
#include "SparkFun_LIS331.h"
#include <Wire.h>

/* Header Guard */
#ifndef ACCEL_HEADER_GUARD
#define ACCEL_HEADER_GUARD

LIS331 xl;
float accel_x, accel_y, accel_z;

void init_accel() {
    Wire.begin();
    /* 
        increase I2C speed to reduce read times a bit value of 400000 
        allows accel read in ~1ms
        and is verfied to work with Sparkfun level converter
        (some level converters have issues at higher speeds)
     */
    Wire.setClock(400000);

    xl.setI2CAddr(ACCEL_I2C_ADDRESS);
    xl.begin(LIS331::USE_I2C);

    // sets accelerometer to specified scale (100, 200, 400g)
    xl.setFullScale(ACCEL_RANGE);
}

// reads accel and converts to G's
void get_accel() {
    int16_t x, y, z;
    /* Read accel */
    xl.readAxes(x, y, z);
    accel_x = (xl.convertToG(ACCEL_MAX_SCALE, x) + ACCEL_X_OFFSET) * G;
    accel_y = (xl.convertToG(ACCEL_MAX_SCALE, y) + ACCEL_Y_OFFSET) * G;
    accel_z = (xl.convertToG(ACCEL_MAX_SCALE, z) + ACCEL_Z_OFFSET) * G;

    /* Read RC */
    
}

#endif