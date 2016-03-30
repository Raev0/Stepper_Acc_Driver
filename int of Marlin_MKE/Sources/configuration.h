/*
 * configuration.h
 *
 *  Created on: 2016Äê3ÔÂ24ÈÕ
 *      Author: todd
 */

#ifndef SOURCES_CONFIGURATION_H_
#define SOURCES_CONFIGURATION_H_

//===========================================================================
//======================== software configuration ==========================
//===========================================================================

#define RESOLUTION 200
#define MICROSTEP 16
#define DEFAULT_ACCELERATION 10

//#define KILO 1000000
//#define ST_PULSE_FREQ (1.5*MEGA)

#define ST_PULSE_FREQ 10000

#define FLOAT_FACTOR (ST_PULSE_FREQ*ST_PULSE_FREQ)

#define RADIUS 10
#define PI 3.14159


#define BLOCK_BUFFER_SIZE 2

//#define HARDWARE_DEBUG_MODE

//===========================================================================
//======================== hardware configuration ==========================
//===========================================================================

#define NUM_AXIS	4
#define X_AXIS	0
#define Y_AXIS	1
#define Z_AXIS	2
#define E_AXIS	3

#endif /* SOURCES_CONFIGURATION_H_ */
