/* ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : Aux_Int.c
**     Project     : X-Sub MCU Firmware
**     Processor   : MCF51QE128CLK
**     Component   : TimerInt
**     Version     : Component 02.161, Driver 01.23, CPU db: 3.00.078
**     Compiler    : CodeWarrior ColdFireV1 C Compiler
<<<<<<< HEAD
**     Date/Time   : 2015-06-25, 10:24, # CodeGen: 19
=======
**     Date/Time   : 2015-06-15, 15:46, # CodeGen: 13
>>>>>>> ef6348856dbd10b0d1ac938feeb92755e9868d98
**     Abstract    :
**         This component "TimerInt" implements a periodic interrupt.
**         When the component and its events are enabled, the "OnInterrupt"
**         event is called periodically with the period that you specify.
**         TimerInt supports also changing the period in runtime.
**         The source of periodic interrupt can be timer compare or reload
**         register or timer-overflow interrupt (of free running counter).
**     Settings    :
**         Timer name                  : RTC (8-bit)
**         Compare name                : RTCmod
**         Counter shared              : No
**
**         High speed mode
**             Prescaler               : divide-by-1
<<<<<<< HEAD
**             Clock                   : 16384 Hz
**           Initial period/frequency
**             Xtal ticks              : 328
**             microseconds            : 10010
**             milliseconds            : 10
**             seconds (real)          : 0.010009765625
**             Hz                      : 100
=======
**             Clock                   : 2048 Hz
**           Initial period/frequency
**             Xtal ticks              : 4080
**             microseconds            : 124512
**             milliseconds            : 125
**             seconds (real)          : 0.12451171875
**             Hz                      : 8
>>>>>>> ef6348856dbd10b0d1ac938feeb92755e9868d98
**
**         Runtime setting             : none
**
**         Initialization:
**              Timer                  : Enabled
**              Events                 : Enabled
**
**         Timer registers
**              Counter                : RTCCNT    [0xFFFF9831]
**              Mode                   : RTCSC     [0xFFFF9830]
**              Run                    : RTCSC     [0xFFFF9830]
**              Prescaler              : RTCSC     [0xFFFF9830]
**
**         Compare registers
**              Compare                : RTCMOD    [0xFFFF9832]
**
**         Flip-flop registers
**     Contents    :
**         No public methods
**
**     Copyright : 1997 - 2014 Freescale Semiconductor, Inc. 
**     All Rights Reserved.
**     
**     Redistribution and use in source and binary forms, with or without modification,
**     are permitted provided that the following conditions are met:
**     
**     o Redistributions of source code must retain the above copyright notice, this list
**       of conditions and the following disclaimer.
**     
**     o Redistributions in binary form must reproduce the above copyright notice, this
**       list of conditions and the following disclaimer in the documentation and/or
**       other materials provided with the distribution.
**     
**     o Neither the name of Freescale Semiconductor, Inc. nor the names of its
**       contributors may be used to endorse or promote products derived from this
**       software without specific prior written permission.
**     
**     THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
**     ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
**     WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
**     DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
**     ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
**     (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
**     LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
**     ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
**     (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
**     SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**     
**     http: www.freescale.com
**     mail: support@freescale.com
** ###################################################################*/
/*!
** @file Aux_Int.c
** @version 01.23
** @brief
**         This component "TimerInt" implements a periodic interrupt.
**         When the component and its events are enabled, the "OnInterrupt"
**         event is called periodically with the period that you specify.
**         TimerInt supports also changing the period in runtime.
**         The source of periodic interrupt can be timer compare or reload
**         register or timer-overflow interrupt (of free running counter).
*/         
/*!
**  @addtogroup Aux_Int_module Aux_Int module documentation
**  @{
*/         

/* MODULE Aux_Int. */

#include "Events.h"
#include "PE_Error.h"
#include "Aux_Int.h"

/*** Internal macros and method prototypes ***/

/*
** ===================================================================
**     Method      :  SetCV (component TimerInt)
**
**     Description :
**         The method computes and sets compare eventually modulo value 
**         for time measuring.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
#define Aux_Int_SetCV(_Val) \
  (RTCMOD = (byte)(_Val))


/*** End of internal method prototypes ***/

/*
** ===================================================================
**     Method      :  Aux_Int_Init (component TimerInt)
**
**     Description :
**         Initializes the associated peripheral(s) and the component 
**         internal variables. The method is called automatically as a 
**         part of the application initialization code.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
void Aux_Int_Init(void)
{
  /* RTCSC: RTIF=0,RTCLKS=0,RTIE=0,RTCPS=0 */
  setReg8(RTCSC, 0x00U);               /* Stop HW */ 
<<<<<<< HEAD
  Aux_Int_SetCV(0xA3U);                /* Initialize appropriate value to the compare/modulo/reload register */
  RTCMOD = RTCMOD;                     /* Reset HW counter */
  /* RTCSC: RTIF=1,RTCLKS=2,RTIE=1,RTCPS=9 */
  setReg8(RTCSC, 0xD9U);               /* Run RTC (select clock source, set frequency and enable interrupt) */ 
=======
  Aux_Int_SetCV(0xFEU);                /* Initialize appropriate value to the compare/modulo/reload register */
  RTCMOD = RTCMOD;                     /* Reset HW counter */
  /* RTCSC: RTIF=1,RTCLKS=2,RTIE=1,RTCPS=0x0C */
  setReg8(RTCSC, 0xDCU);               /* Run RTC (select clock source, set frequency and enable interrupt) */ 
>>>>>>> ef6348856dbd10b0d1ac938feeb92755e9868d98
}


/*
** ===================================================================
**     Method      :  Aux_Int_Interrupt (component TimerInt)
**
**     Description :
**         The method services the interrupt of the selected peripheral(s)
**         and eventually invokes the component event(s).
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
ISR(Aux_Int_Interrupt)
{
  /* RTCSC: RTIF=1 */
  setReg8Bits(RTCSC, 0x80U);           /* Reset real-time counter request flag */ 
  Aux_Int_OnInterrupt();               /* Invoke user event */
}



/* END Aux_Int. */

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
