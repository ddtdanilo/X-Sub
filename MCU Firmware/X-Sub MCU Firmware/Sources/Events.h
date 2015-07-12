/* ###################################################################
**     Filename    : Events.h
**     Project     : X-Sub MCU Firmware
**     Processor   : MCF51QE128CLK
**     Component   : Events
**     Version     : Driver 01.02
**     Compiler    : CodeWarrior ColdFireV1 C Compiler
**     Date/Time   : 2015-05-30, 09:28, # CodeGen: 0
**     Abstract    :
**         This is user's event module.
**         Put your event handler code here.
**     Settings    :
**     Contents    :
**         No public methods
**
** ###################################################################*/
/*!
** @file Events.h
** @version 01.02
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
#include "PE_Timer.h"
#include "M1_ESC.h"
#include "M2_ESC.h"
#include "M3_ESC.h"
#include "M4_ESC.h"
#include "S_PanCamera.h"
#include "S_TiltCamera.h"
#include "sMCU_OK.h"
#include "sPC_OK.h"
#include "sCom_In.h"
#include "Aux_Int.h"
#include "testMotor.h"
#include "SerialCom.h"
#include "RESET_INTERRUPT.h"
#include "ADC.h"


void Aux_Int_OnInterrupt(void);
/*
** ===================================================================
**     Event       :  Aux_Int_OnInterrupt (module Events)
**
**     Component   :  Aux_Int [TimerInt]
**     Description :
**         When a timer interrupt occurs this event is called (only
**         when the component is enabled - <Enable> and the events are
**         enabled - <EnableEvent>). This event is enabled only if a
**         <interrupt service/event> is enabled.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

void SerialCom_OnRxChar(void);
/*
** ===================================================================
**     Event       :  SerialCom_OnRxChar (module Events)
**
**     Component   :  SerialCom [AsynchroSerial]
**     Description :
**         This event is called after a correct character is received.
**         The event is available only when the <Interrupt
**         service/event> property is enabled and either the <Receiver>
**         property is enabled or the <SCI output mode> property (if
**         supported) is set to Single-wire mode.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

void SerialCom_OnTxChar(void);
/*
** ===================================================================
**     Event       :  SerialCom_OnTxChar (module Events)
**
**     Component   :  SerialCom [AsynchroSerial]
**     Description :
**         This event is called after a character is transmitted.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

void testMotor_OnEnd(void);
/*
** ===================================================================
**     Event       :  testMotor_OnEnd (module Events)
**
**     Component   :  testMotor [PPG]
**     Description :
**         This event is called when the specified number of iterations
**         is generated. (Only when the component is enabled - <Enable>
**         and the events are enabled - <EnableEvent>). The event is
**         available only when the peripheral supports an interrupt,
**         that is generated at the end of the PWM period.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

void RESET_INTERRUPT_OnInterrupt(void);
/*
** ===================================================================
**     Event       :  RESET_INTERRUPT_OnInterrupt (module Events)
**
**     Component   :  RESET_INTERRUPT [ExtInt]
**     Description :
**         This event is called when an active signal edge/level has
**         occurred.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

void ADC_OnEnd(void);
/*
** ===================================================================
**     Event       :  ADC_OnEnd (module Events)
**
**     Component   :  ADC [ADC]
**     Description :
**         This event is called after the measurement (which consists
**         of <1 or more conversions>) is/are finished.
**         The event is available only when the <Interrupt
**         service/event> property is enabled.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

/* END Events */
#endif /* __Events_H*/

/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.3 [05.09]
**     for the Freescale ColdFireV1 series of microcontrollers.
**
** ###################################################################
*/
