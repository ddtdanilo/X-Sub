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
#include "SerialCom.h"
#include "RESET_INTERRUPT.h"
#include "ADC.h"
#include "LedLight1.h"
#include "LedLight2.h"
#include "CS1.h"
#include "I2C.h"
#include "PresenciaAgua2.h"
#include "PresenciaAgua1.h"
#include "S_Wire.h"


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

void SerialCom_OnFullRxBuf(void);
/*
** ===================================================================
**     Event       :  SerialCom_OnFullRxBuf (module Events)
**
**     Component   :  SerialCom [AsynchroSerial]
**     Description :
**         This event is called when the input buffer is full;
**         i.e. after reception of the last character 
**         that was successfully placed into input buffer.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

void SerialCom_OnFreeTxBuf(void);
/*
** ===================================================================
**     Event       :  SerialCom_OnFreeTxBuf (module Events)
**
**     Component   :  SerialCom [AsynchroSerial]
**     Description :
**         This event is called after the last character in output
**         buffer is transmitted.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

void S_Wire_OnError(void);
/*
** ===================================================================
**     Event       :  S_Wire_OnError (module Events)
**
**     Component   :  S_Wire [AsynchroSerial]
**     Description :
**         This event is called when a channel error (not the error
**         returned by a given method) occurs. The errors can be read
**         using <GetError> method.
**         The event is available only when the <Interrupt
**         service/event> property is enabled.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

void S_Wire_OnRxChar(void);
/*
** ===================================================================
**     Event       :  S_Wire_OnRxChar (module Events)
**
**     Component   :  S_Wire [AsynchroSerial]
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

void S_Wire_OnTxChar(void);
/*
** ===================================================================
**     Event       :  S_Wire_OnTxChar (module Events)
**
**     Component   :  S_Wire [AsynchroSerial]
**     Description :
**         This event is called after a character is transmitted.
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
