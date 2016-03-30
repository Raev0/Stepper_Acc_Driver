/* ###################################################################
**     Filename    : Events.h
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
** @file Events.h
** @version 01.00
** @brief
**         This is user's event module.
**         Put your event handler code here.
*/         
/*!
**  @addtogroup Events_module Events module documentation
**  @{
*/         

#ifndef __Events_H
#define __Events_H
/* MODULE Events */

#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
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

#ifdef __cplusplus
extern "C" {
#endif 

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
void Cpu_OnNMI(void);


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
void ST_PULSE_TI_OnInterrupt(void);

/* END Events */

#ifdef __cplusplus
}  /* extern "C" */
#endif 

#endif 
/* ifndef __Events_H*/
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
