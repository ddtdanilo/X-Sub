/*
 * OneWire.c
 *
 *  Created on: Oct 17, 2015
 *      Author: ddtdanilo
 */

/*Includes*/
#include "Cpu.h"
#include "Events.h"
#include "M1_ESC.h"
#include "M2_ESC.h"
#include "M3_ESC.h"
#include "M4_ESC.h"
/* Include shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"

/*Mis includes*/
#include "xSub.h"
#include "OneWire.h"


// Configure UART for 1-Wire RESET timing
byte onewireReset() {
	byte read;
    // Configure UART for 1-Wire RESET timing
    (void)S_Wire_SetBaudRateMode(0);
    S_Wire_SendChar(0xF0);
    
    S_Wire_RecvChar(&read);
    if (read == -1) {
        // No UART data at all
        //server.log("No circuit connected to UART.");
        return FALSE;
    } else if (read == 0xF0) {
        // UART RX will read TX if there's no device connected
        //server.log("No 1-Wire devices are present.");
        return FALSE;
    } else {
        // Switch UART to 1-Wire data speed timing 115200
       (void)S_Wire_SetBaudRateMode(1);
        return TRUE;
    }
}
 
byte onewireWriteByte(byte byteIn) {
    byte i;
    for (i = 0 ; i < 8 ; i++, byteIn = byteIn >> 1) {
        // Run through the bits in the byte, extracting the
        // LSB (bit 0) and sending it to the bus
        onewireBit(byteIn & 0x01);
    }
} 
 
byte onewireReadByte() {
    byte byteIn = 0;
    byte i;
    for (i = 0 ; i < 8 ; i++) {
        // Build up byte bit by bit, LSB first
        byteIn = (byteIn >> 1) + 0x80 * onewireBit(1);
    }
    //(void)SerialCom_SendChar(byteIn);
    return byteIn;
}
 
byte onewireBit(byte bit) {
	byte read;
	byte returnVal;
    bit = bit ? 0xFF : 0x00;
    S_Wire_SendChar(bit);
    
    S_Wire_RecvChar(&read);
    returnVal = read != 0x00 ? 1 : 0;
    //(void)SerialCom_SendChar(returnVal);
    return returnVal;
}
 
// Wake up every 5 seconds and write to the server
 
float awakeAndGetTemp(){
    byte tempLSB = 0;
    byte tempMSB = 0;
    float tempCelsius = 0;
 
    if (onewireReset()) {
        onewireWriteByte(0xCC);
        onewireWriteByte(0x44);

        // Wait for at least 750ms for data to be collated
        delay(800);

        // Get the data
        onewireReset();
        onewireWriteByte(0xCC);
        onewireWriteByte(0xBE);

        tempLSB = onewireReadByte();
        tempMSB = onewireReadByte();

        // Reset bus to stop sensor sending unwanted data
        onewireReset();
    
        // Log the Celsius temperature
        return tempCelsius = ((tempMSB * 256) + tempLSB) / 16.0;
        //server.log(format("Temperature: %3.2f degrees C", tempCelsius));
    }else{
        return 0xF0F0;
    }
}
 
// PROGRAM STARTS HERE
