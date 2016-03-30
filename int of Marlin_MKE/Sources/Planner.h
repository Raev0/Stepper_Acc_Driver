#include "ST_PULSE_TI.h"
#include "global.h"
#include "configuration.h"
#include "math.h"

typedef struct {
	// nominal variables. will be update in planner.c
	unsigned int nominal_rate; // The nominal speed for this block in round/sec
	unsigned int entry_rate; // Entry speed at previous-current junction in round/sec
	unsigned int max_entry_rate; // Maximum allowable junction entry speed in round/sec
	unsigned int  rounds;             // The total travel of this block in round
	unsigned int acceleration;                      // acceleration round/sec^2
	unsigned int exit_rate;
	char direction_bits;
	// instance variables. will be update in stepper.c
	unsigned int instance_rate; // The instant speed for this block in round/sec
	unsigned int rounds_behind;
	unsigned int rounds_ahead;
	unsigned int rounds_count_per_mstep;
	unsigned int one_micro_step_mm;
	volatile char busy;
} block_t;

//void plan_buffer_line(const float x, const float y, const float z, const float e, float feed_rate, const uint8_t extruder);

void plan_buffer_line(const float e, float feed_rate);

#define BLOCK_MOD(n) ((n)&(BLOCK_BUFFER_SIZE-1))// USE & because buffer size should be a power of 2

// ST_PULSE_FREQ REPRESENTED THE FREQ BY WHICH THE SPEED IS UPDATED

// the speed would be below 10r/s,radius would be 10mm; int/long would be 4 bil (10^9).
//for um accuracy the pulse freq would be limited to (9-2-3)/2=2? below 10hz
//for 10um accuracy, would be 100hz
//for 100um accuracy, would be 1k


// the max length we run would be below 1000; long/long uint64 would be  (10^19).
//for um accuracy the pulse freq would be limited to (19-2-3)/2=7? below 10MHhz
//for 10um accuracy, would be 100THhz


#define F2I_V_UNIT_CONVERT(n) (unsigned int)(2*PI*RADIUS*n*ST_PULSE_FREQ)// r/s -> FLOAT_FACTOR*mm/pulse
#define F2I_A_UNIT_CONVERT(n) (unsigned int)(2*PI*RADIUS*n)// r/s2 -> FLOAT_FACTOR*mm/pulse2
#define r2mm_UNIT_CONVERT(n) (unsigned int)(2*PI*RADIUS*n*FLOAT_FACTOR)// r -> FLOAT_FACTOR*mm
#define F2I_UNIT_INVERT(n) (float)(1.0*n/ST_PULSE_FREQ)  // to mm/s


//===========================================================================
//============ block buffer variable and structure are here	 =============
//===========================================================================

block_t block_buffer[BLOCK_BUFFER_SIZE]; // A ring buffer for motion instfructions
volatile unsigned char block_buffer_head; // Index of the next block to be pushed
volatile unsigned char block_buffer_tail;   // Index of the block to process now

// Returns true if the buffer has a queued block, false otherwise
FORCE_INLINE bool blocks_queued() {
	return (block_buffer_head != block_buffer_tail);
}

// Gets the current block. Returns NULL if buffer empty
FORCE_INLINE block_t *plan_get_current_block() {
	if (blocks_queued()) {
		block_t *block = &block_buffer[block_buffer_tail];
		block->busy = true
		;
		return block;
	} else
		return NULL;
}
