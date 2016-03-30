/* ###################################################################
 **     Filename    : Events.c
 **     Project     : Marlin_MKE
 **     Processor   : MKE06Z128VLK4
 **     Component   : Events
 **     Version     : Driver 01.00
 **     Compiler    : GNU C Compiler
 **     Date/Time   : 2016-03-22, 09:09, # CodeGen: 0
 **     Abstract    :
 **         This is user's event module.
 **         Put your event handler code here.
 **     Contents    :
 **         Cpu_OnNMI - void Cpu_OnNMI(void);
 **
 ** ###################################################################*/
/*!
 ** @file Events.c
 ** @version 01.00
 ** @brief
 **         This is user's event module.
 **         Put your event handler code here.
 */
/*!
 **  @addtogroup Events_module Events module documentation
 **  @{
 */
/* MODULE Events */

#include "Cpu.h"
#include "Events.h"
#include "Init_Config.h"
#include "PDD_Includes.h"

#ifdef __cplusplus
extern "C" {
#endif 

/* User includes (#include below this line is not maintained by Processor Expert) */
#include <configuration.h>
#include <Planner.h>

block_t *current_block; // A pointer to the block currently being traced

/*
 ** ===================================================================
 **     Event       :  Cpu_OnNMI (module Events)
 **
 **     Component   :  Cpu [MKE06Z128LK4]
 */
/*!
 **     @brief
 **         This event is called when the Non maskable interrupt had
 **         occurred. This event is automatically enabled when the [NMI
 **         interrupt] property is set to 'Enabled'.
 */
/* ===================================================================*/
void Cpu_OnNMI(void) {
	/* Write your code here ... */
}

/*
 ** ===================================================================
 **     Event       :  ST_PULSE_TI_OnInterrupt (module Events)
 **
 **     Component   :  ST_PULSE_TI [TimerInt]
 **     Description :
 **         When a timer interrupt occurs this event is called (only
 **         when the component is enabled - <Enable> and the events are
 **         enabled - <EnableEvent>). This event is enabled only if a
 **         <interrupt service/event> is enabled.
 **     Parameters  : None
 **     Returns     : Nothing
 ** ===================================================================
 */
void ST_PULSE_TI_OnInterrupt(void) {
	/* Write your code here ... */
#ifndef HARDWARE_DEBUG_MODE

	if (!current_block) {
		current_block = plan_get_current_block();
	}



#define DISTANCE_COUNT_RESET current_block->rounds_count_per_mstep-=current_block->one_micro_step_mm
#define DISTANCE_IS_ONESTEP  current_block->rounds_count_per_mstep>=current_block->one_micro_step_mm
#define DRIVE_PULSE E0_STE_SetVal();	\
		E0_STE_ClrVal()
	/*==========generate a pulse when a step accumulated===========*/

	if (DISTANCE_IS_ONESTEP) {
		DRIVE_PULSE;
		DISTANCE_COUNT_RESET;
	}


	/*update the new speed and  ... */

	if (current_block) {
		if (current_block->rounds_behind + current_block->rounds_ahead
				< current_block->rounds) {
			// accumulate the rounds and the microstep_count_for_rounds

			current_block->rounds_behind += current_block->instance_rate;
			current_block->rounds_count_per_mstep +=current_block->instance_rate;

			//when speed climbing up case
			if (current_block->instance_rate < current_block->nominal_rate) {
				current_block->instance_rate += current_block->acceleration;
			}

			//when hold¡¡the nominal_rate case
			else {
				//make sure the rate remains nominal_rate
				current_block->instance_rate = current_block->nominal_rate;
			}

			// update the rounds left for all the three case.
			current_block->rounds_ahead=current_block->instance_rate/2/current_block->acceleration*current_block->instance_rate;
		}
		//when speed slipping down case

		else if (current_block->instance_rate > current_block->exit_rate) {
			current_block->rounds_behind+= current_block->instance_rate;
			current_block->rounds_count_per_mstep +=current_block->instance_rate;
			current_block->instance_rate -= current_block->acceleration;
		}

		// at the end of the block

		else if (current_block->instance_rate <= current_block->exit_rate) {
			current_block->instance_rate = 0;
			current_block->nominal_rate = 0;
			current_block->rounds_ahead = 0;
			current_block->acceleration = 0;
			current_block->rounds = 0;
			current_block->rounds_count_per_mstep = 0;
			//ST_PULSE_TI_Disable();//current_block should update
			current_block = NULL;
		}

	}

#endif
	/*
	 #define DRIVE_PULSE E0_STE_SetVal();	\
			E0_STE_ClrVal()

	 DRIVE_PULSE
	 ;
	 // update the
	 *
	 */

}

/* END Events */

#ifdef __cplusplus
} /* extern "C" */
#endif 

/*!
 ** @}
 */
/*
 ** ###################################################################
 **
 **     This file was created by Processor Expert 10.5 [05.21]
 **     for the Freescale Kinetis series of microcontrollers.
 **
 ** ###################################################################
 */
