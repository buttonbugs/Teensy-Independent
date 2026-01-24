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

#define CH1 23
#define CH2 22
#define CH3 21
#define CH4 20

#define RC_X_MOVE CH1
#define RC_Y_MOVE CH2
#define RC_THROTTLE CH3                 // Throttle + Mode selection -> 0: Mecanum Mode (Not Spinning), > 0: Melty Brain Mode (Spinning)
#define RC_Z_REVOLUTION CH4

/* Physical Measurement */
#define G 9.8                           // Gravitational acceleration
#define REVOLUTION_DIRECTION 1          // 1: Counterclockwise when up-side is up, -1: Clockwise when up-side is up


/* Electronics Config */
#define ACCEL_I2C_ADDRESS 0x19          // Adafuit breakout default is 0x18, Sparkfun default is 0x19
#define ACCEL_RANGE LIS331::HIGH_RANGE
#define ACCEL_MAX_SCALE 400

// Real acceleration = Sensor output + Offset
#define ACCEL_X_OFFSET 0.0
#define ACCEL_Y_OFFSET 0.0
#define ACCEL_Z_OFFSET 0.0

#define RC_MIN_PULSE_LEGNTH 1000
#define RC_MAX_PULSE_LEGNTH 2000
#define RC_PULSE_LEGNTH_RANGE (RC_MAX_PULSE_LEGNTH - RC_MIN_PULSE_LEGNTH)

/* 
ACCEL_MAX_SCALE needs to match ACCEL_RANGE value
LOW_RANGE - +/-100g for the H3LIS331DH
MED_RANGE - +/-200g for the H3LIS331DH
HIGH_RANGE - +/-400g for the H3LIS331DH -> chosen
*/


/* Calculation */
#define RC_SD 0.01f                     // A valid move require rc_signal_value differ by THIS MUCH (RC_SD) from the joy stick center
#define RC_THROTTLE_THRESHOLD 0.2f      // A valid move require rc_signal_value differ by THIS MUCH (RC_SD) from the joy stick center
#define MOTOR_PULSE_LENGTH  0.5f        // 0.0: 0 deg, 0.5: 90 deg, 1.0: 180 deg


#endif