
#include "planner.h"
#include "configuration.h"

long position[NUM_AXIS];
FORCE_INLINE unsigned char next_block_index(unsigned char block_index) {
	return BLOCK_MOD(block_index + 1);
	//return block_index + 1;
}

void plan_buffer_line(const float e, float feed_rate) {

//void plan_buffer_line(const float x, const float y, const float z, const float e, float feed_rate, const uint8_t extruder){

// e is unit of round
// feedrate is unit of round per second

// push a block into pipeline
	block_t *block = &block_buffer[block_buffer_head];

	//update the ini value of the block
	block->nominal_rate =(unsigned int)(feed_rate*ST_PULSE_FREQ);
	block->rounds = (unsigned int)(e - position[E_AXIS])*FLOAT_FACTOR;
	block->entry_rate = 0;
	block->exit_rate = 0;
	block->acceleration = (unsigned int)(DEFAULT_ACCELERATION);
	block->direction_bits = e > position[E_AXIS] ? 1 : 0;


	//
	block->one_micro_step_mm=(unsigned int)FLOAT_FACTOR/MICROSTEP/RESOLUTION;
	ST_PULSE_TI_Enable();
	//Enable the Interruption for stepper control and planner

	// Move buffer head
	block_buffer_head = next_block_index(block_buffer_head);
	//block_buffer_head=block_buffer_head+1;
	// Update position
	position[E_AXIS] = e;

 }
