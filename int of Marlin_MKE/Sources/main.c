/* ###################################################################
**     Filename    : main.c
**     Project     : Marlin_MKE
**     Processor   : MKE06Z128VLK4
**     Version     : Driver 01.01
**     Compiler    : GNU C Compiler
**     Date/Time   : 2016-03-22, 09:09, # CodeGen: 0
**     Abstract    :
**         Main module.
**         This module contains user's application code.
**     Settings    :
**     Contents    :
**         No public methods
**
** ###################################################################*/
/*!
** @file main.c
** @version 01.01
** @brief
**         Main module.
**         This module contains user's application code.
*/         
/*!
**  @addtogroup main_module main module documentation
**  @{
*/         
/* MODULE main */


/* Including needed modules to compile this module/procedure */
#include "Cpu.h"
#include "Events.h"
#include "Pins1.h"
#include "ST_PULSE_TI.h"
#include "TimerIntLdd1.h"
#include "TU1.h"
#include "E0_STE.h"
#include "BitIoLdd1.h"
#include "E0_DIR.h"
#include "BitIoLdd2.h"
#include "E0_EN_INVERSE.h"
#include "BitIoLdd3.h"
#include "X_STE.h"
#include "BitIoLdd4.h"
#include "X_DIR.h"
#include "BitIoLdd5.h"
#include "X_EN_INVERSE.h"
#include "BitIoLdd6.h"
#include "Y_STE.h"
#include "BitIoLdd7.h"
#include "Y_DIR.h"
#include "BitIoLdd8.h"
#include "Y_EN_INVERSE.h"
#include "BitIoLdd9.h"
#include "Z_STE.h"
#include "BitIoLdd10.h"
#include "Z_DIR.h"
#include "BitIoLdd11.h"
#include "Z_EN_INVERSE.h"
#include "BitIoLdd12.h"
#include "DA1.h"
#include "RELAY.h"
#include "BitIoLdd13.h"
/* Including shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "PDD_Includes.h"
#include "Init_Config.h"

/* User includes (#include below this line is not maintained by Processor Expert) */
#include<planner.h>
#include<Events.h>
#include<Scheduler.h>
#include<configuration.h>
/*lint -save  -e970 Disable MISRA rule (6.3) checking. */

void setup(){

	RELAY_SetVal();


}


int main(void)
/*lint -restore Enable MISRA rule (6.3) checking. */
{
  /* Write your local variable definition here */

  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
      PE_low_level_init();
  /*** End of Processor Expert internal initialization.                    ***/

 setup();
  plan_buffer_line(2,1);
  //
  for(;;){ST_PULSE_TI_Enable();}


  //heat_manager();
  //inactivity_manager();




  /* Write your code here */
  /* For example: for(;;) { } */

  /*** Don't write any code pass this line, or it will be deleted during code generation. ***/
  /*** RTOS startup code. Macro PEX_RTOS_START is defined by the RTOS component. DON'T MODIFY THIS CODE!!! ***/
  #ifdef PEX_RTOS_START
    PEX_RTOS_START();                  /* Startup of the selected RTOS. Macro is defined by the RTOS component. */
  #endif
  /*** End of RTOS startup code.  ***/
  /*** Processor Expert end of main routine. DON'T MODIFY THIS CODE!!! ***/
  for(;;){}
  /*** Processor Expert end of main routine. DON'T WRITE CODE BELOW!!! ***/
} /*** End of main routine. DO NOT MODIFY THIS TEXT!!! ***/

/* END main */
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
