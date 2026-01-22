// Configuration
#include "SparkFun_LIS331.h"

/* Header Guard */
#ifndef CONFIG_HEADER_GUARD
#define CONFIG_HEADER_GUARD

/* Debug Mode */
#define DEBUG_MODE true                 // Enable Serial

/* Pins */
#define ESC_LEFT 2
#define ESC_RIGHT 3

#define HEADING_LED_PIN 11

#define ACCEL_SDA 18
#define ACCEL_SCL 19

#define RC_X_MOVE 20
#define RC_Y_MOVE 21
#define RC_THROTTLE 22                  // Throttle + Mode selection -> 0: Mecanum Mode (Not Spinning), > 0: Melty Brain Mode (Spinning)
#define RC_Z_REVOLUTION 23

/* Physical Measurement */
#define G 9.796                         // Gravitational acceleration
#define REVOLUTION_DIRECTION 1          // 1: Counterclockwise when up-side is up, -1: Clockwise when up-side is up


/* Electronics Config */
#define ACCEL_I2C_ADDRESS 0x19          // Adafuit breakout default is 0x18, Sparkfun default is 0x19
#define ACCEL_RANGE LIS331::HIGH_RANGE
#define ACCEL_MAX_SCALE 400
// Real acceleration = Sensor output + Offset
#define ACCEL_X_OFFSET 3.810
#define ACCEL_Y_OFFSET 3.025
#define ACCEL_Z_OFFSET -6.255

/* 
ACCEL_MAX_SCALE needs to match ACCEL_RANGE value
    LOW_RANGE - +/-100g for the H3LIS331DH
    MED_RANGE - +/-200g for the H3LIS331DH
    HIGH_RANGE - +/-400g for the H3LIS331DH -> chosen
*/


/* Calculation */
#define RC_SD 23                        // RC Mid value signal deviation
#define MOTOR_PULSE_LENGTH  0.5         // 0.0: 0 deg, 0.5: 90 deg, 1.0: 180 deg


#endif