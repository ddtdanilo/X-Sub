/* ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : S_PanCamera.c
**     Project     : X-Sub MCU Firmware
**     Processor   : MCF51QE128CLK
**     Component   : PWM
**     Version     : Component 02.240, Driver 01.28, CPU db: 3.00.078
**     Compiler    : CodeWarrior ColdFireV1 C Compiler
<<<<<<< HEAD
**     Date/Time   : 2015-07-10, 08:37, # CodeGen: 29
=======
**     Date/Time   : 2015-06-15, 15:15, # CodeGen: 10
>>>>>>> ef6348856dbd10b0d1ac938feeb92755e9868d98
**     Abstract    :
**         This component implements a pulse-width modulation generator
**         that generates signal with variable duty and fixed cycle. 
**     Settings    :
**         Used output pin             : 
**             ----------------------------------------------------
**                Number (on package)  |    Name
**             ----------------------------------------------------
**                       23            |  PTB4_TPM2CH1_MISO1
**             ----------------------------------------------------
**
**         Timer name                  : TPM2 [16-bit]
**         Counter                     : TPM2CNT   [0xFFFF8051]
**         Mode register               : TPM2SC    [0xFFFF8050]
**         Run register                : TPM2SC    [0xFFFF8050]
**         Prescaler                   : TPM2SC    [0xFFFF8050]
**         Compare register            : TPM2C1V   [0xFFFF8059]
**         Flip-flop register          : TPM2C1SC  [0xFFFF8058]
**
**         User handling procedure     : not specified
**
**         Port name                   : PTB
**         Bit number (in port)        : 4
**         Bit mask of the port        : 0x0010
**         Port data register          : PTBD      [0xFFFF8002]
**         Port control register       : PTBDD     [0xFFFF8003]
**
**         Initialization:
**              Output level           : low
**              Timer                  : Enabled
**              Event                  : Enabled
**         High speed mode
<<<<<<< HEAD
**             Prescaler               : divide-by-1
**             Clock                   : 14942208 Hz
=======
**             Prescaler               : divide-by-2
**             Clock                   : 12582912 Hz
>>>>>>> ef6348856dbd10b0d1ac938feeb92755e9868d98
**           Initial value of            period     pulse width
**             Xtal ticks              : 109        0
**             microseconds            : 3333       0
**             milliseconds            : 3          0
<<<<<<< HEAD
**             seconds (real)          : 0.003333309241 0.0
=======
**             seconds (real)          : 0.003333330154 0.0
>>>>>>> ef6348856dbd10b0d1ac938feeb92755e9868d98
**
**     Contents    :
**         Enable     - byte S_PanCamera_Enable(void);
**         Disable    - byte S_PanCamera_Disable(void);
**         SetRatio8  - byte S_PanCamera_SetRatio8(byte Ratio);
**         SetRatio16 - byte S_PanCamera_SetRatio16(word Ratio);
**         SetDutyUS  - byte S_PanCamera_SetDutyUS(word Time);
**         SetDutyMS  - byte S_PanCamera_SetDutyMS(word Time);
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
** @file S_PanCamera.c
** @version 01.28
** @brief
**         This component implements a pulse-width modulation generator
**         that generates signal with variable duty and fixed cycle. 
*/         
/*!
**  @addtogroup S_PanCamera_module S_PanCamera module documentation
**  @{
*/         


/* MODULE S_PanCamera. */

#include "PE_Error.h"
#include "S_PanCamera.h"


static word ActualRatio;               /* Ratio of L-level to H-level */

/* Internal method prototypes */

/*
** ===================================================================
**     Method      :  SetRatio (component PWM)
**
**     Description :
**         The method stores duty value to compare register(s) and sets 
**         necessary bits or (in List mode) call SetReg method for duty 
**         value storing.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
static void SetRatio(void);

/* End of Internal methods declarations */

/*
** ===================================================================
**     Method      :  SetRatio (component PWM)
**
**     Description :
**         The method stores duty value to compare register(s) and sets 
**         necessary bits or (in List mode) call SetReg method for duty 
**         value storing.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
static void SetRatio(void)
{
  if (ActualRatio == 0xFFFFU) {        /* Duty = 100%? */
    TPM2C1V = 0xFFFFU;                 /* Store new value to the compare reg. */
  } else {
<<<<<<< HEAD
    TPM2C1V = (word)(((0xC28FUL * (dword)ActualRatio)  + 0x8000UL) >> 0x10U); /* Calculate new compare value according to the given ratio */
=======
    TPM2C1V = (word)(((0xA3D7UL * (dword)ActualRatio)  + 0x8000UL) >> 0x10U); /* Calculate new compare value according to the given ratio */
>>>>>>> ef6348856dbd10b0d1ac938feeb92755e9868d98
  }
}

/*
** ===================================================================
**     Method      :  S_PanCamera_Enable (component PWM)
**     Description :
**         This method enables the component - it starts the signal
**         generation. Events may be generated (<DisableEvent>
**         /<EnableEvent>).
**     Parameters  : None
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
** ===================================================================
*/
byte S_PanCamera_Enable(void)
{
  /* TPM2C1SC: CH1F=0,CH1IE=0,MS1B=1,MS1A=1,ELS1B=1,ELS1A=1,??=0,??=0 */
  setReg8(TPM2C1SC, 0x3CU);            /* Set up PWM mode with output signal level low */ 
  return ERR_OK;                       /* OK */
}

/*
** ===================================================================
**     Method      :  S_PanCamera_Disable (component PWM)
**     Description :
**         This method disables the component - it stops the signal
**         generation and events calling. When the timer is disabled,
**         it is possible to call <ClrValue> and <SetValue> methods.
**     Parameters  : None
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
** ===================================================================
*/
byte S_PanCamera_Disable(void)
{
  /* TPM2C1SC: CH1F=0,CH1IE=0,MS1B=0,MS1A=0,ELS1B=0,ELS1A=0,??=0,??=0 */
  setReg8(TPM2C1SC, 0x00U);            /* Disable output signal */ 
  return ERR_OK;                       /* OK */
}

/*
** ===================================================================
**     Method      :  S_PanCamera_SetRatio8 (component PWM)
**     Description :
**         This method sets a new duty-cycle ratio. Ratio is expressed
**         as an 8-bit unsigned integer number. 0 - FF value is
**         proportional to ratio 0 - 100%. The method is available
**         only if it is not selected list of predefined values in
**         <Starting pulse width> property. 
**         Note: Calculated duty depends on the timer capabilities and
**         on the selected period.
**     Parameters  :
**         NAME            - DESCRIPTION
**         Ratio           - Ratio to set. 0 - 255 value is
**                           proportional to ratio 0 - 100%
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
** ===================================================================
*/
byte S_PanCamera_SetRatio8(byte Ratio)
{
  ActualRatio = ((word)Ratio << 0x08U) + Ratio; /* Store new value of the ratio */
  SetRatio();                          /* Calculate and set up new appropriate values of the compare and modulo registers */
  return ERR_OK;                       /* OK */
}

/*
** ===================================================================
**     Method      :  S_PanCamera_SetRatio16 (component PWM)
**     Description :
**         This method sets a new duty-cycle ratio. Ratio is expressed
**         as a 16-bit unsigned integer number. 0 - FFFF value is
**         proportional to ratio 0 - 100%. The method is available
**         only if it is not selected list of predefined values in
**         <Starting pulse width> property. 
**         Note: Calculated duty depends on the timer possibilities and
**         on the selected period.
**     Parameters  :
**         NAME            - DESCRIPTION
**         Ratio           - Ratio to set. 0 - 65535 value is
**                           proportional to ratio 0 - 100%
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
** ===================================================================
*/
byte S_PanCamera_SetRatio16(word Ratio)
{
  ActualRatio = Ratio;                 /* Store new value of the ratio */
  SetRatio();                          /* Calculate and set up new appropriate values of the compare and modulo registers */
  return ERR_OK;                       /* OK */
}

/*
** ===================================================================
**     Method      :  S_PanCamera_SetDutyUS (component PWM)
**     Description :
**         This method sets the new duty value of the output signal.
**         The duty is expressed in microseconds as a 16-bit
**         unsigned integer number.
**     Parameters  :
**         NAME            - DESCRIPTION
**         Time            - Duty to set [in microseconds]
**                      (0 to 3333 us in high speed mode)
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
**                           ERR_MATH - Overflow during evaluation
**                           ERR_RANGE - Parameter out of range
** ===================================================================
*/
byte S_PanCamera_SetDutyUS(word Time)
{
  dlong rtval;                         /* Result of two 32-bit numbers multiplication */
  if (Time > 0x0D05U) {                /* Is the given value out of range? */
    return ERR_RANGE;                  /* If yes then error */
  }
<<<<<<< HEAD
  PE_Timer_LngMul((dword)Time, 0x13A93380UL, &rtval); /* Multiply given value and High speed CPU mode coefficient */
=======
  PE_Timer_LngMul((dword)Time, 0x13A92B6BUL, &rtval); /* Multiply given value and High speed CPU mode coefficient */
>>>>>>> ef6348856dbd10b0d1ac938feeb92755e9868d98
  if (PE_Timer_LngHi3(rtval[0], rtval[1], &ActualRatio)) { /* Is the result greater or equal than 65536 ? */
    ActualRatio = 0xFFFFU;             /* If yes then use maximal possible value */
  }
  SetRatio();                          /* Calculate and set up new appropriate values of the compare and modulo registers */
  return ERR_OK;                       /* OK */
}

/*
** ===================================================================
**     Method      :  S_PanCamera_SetDutyMS (component PWM)
**     Description :
**         This method sets the new duty value of the output signal.
**         The duty is expressed in milliseconds as a 16-bit
**         unsigned integer number.
**     Parameters  :
**         NAME            - DESCRIPTION
**         Time            - Duty to set [in milliseconds]
**                      (0 to 3 ms in high speed mode)
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
**                           ERR_MATH - Overflow during evaluation
**                           ERR_RANGE - Parameter out of range
** ===================================================================
*/
byte S_PanCamera_SetDutyMS(word Time)
{
  dlong rtval;                         /* Result of two 32-bit numbers multiplication */
  if (Time > 0x03U) {                  /* Is the given value out of range? */
    return ERR_RANGE;                  /* If yes then error */
  }
<<<<<<< HEAD
  PE_Timer_LngMul((dword)Time, 0x4CCCF12EUL, &rtval); /* Multiply given value and High speed CPU mode coefficient */
=======
  PE_Timer_LngMul((dword)Time, 0x4CCCD19AUL, &rtval); /* Multiply given value and High speed CPU mode coefficient */
>>>>>>> ef6348856dbd10b0d1ac938feeb92755e9868d98
  if (PE_Timer_LngHi2(rtval[0], rtval[1], &ActualRatio)) { /* Is the result greater or equal than 65536 ? */
    ActualRatio = 0xFFFFU;             /* If yes then use maximal possible value */
  }
  SetRatio();                          /* Calculate and set up new appropriate values of the compare and modulo registers */
  return ERR_OK;                       /* OK */
}

/*
** ===================================================================
**     Method      :  S_PanCamera_Init (component PWM)
**
**     Description :
**         Initializes the associated peripheral(s) and the components 
**         internal variables. The method is called automatically as a 
**         part of the application initialization code.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
void S_PanCamera_Init(void)
{
  /* TPM2C1SC: CH1F=0,CH1IE=0,MS1B=1,MS1A=1,ELS1B=1,ELS1A=1,??=0,??=0 */
  setReg8(TPM2C1SC, 0x3CU);            /* Set up PWM mode with output signal level low */ 
  ActualRatio = 0x00U;                 /* Store initial value of the ratio */
  SetRatio();                          /* Calculate and set up new values of the compare according to the selected speed CPU mode */
}

/* END S_PanCamera. */

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
