/*
 * xSub.h
 *
 *  Created on: Jun 11, 2015
 *      Author: ddtdanilo
 */

#ifndef XSUB_H_
#define XSUB_H_



/*Definiciones de tipos*/

typedef union{
	byte byte[2];
	word word;
}wordbyte;

typedef struct{
	byte data;
	byte pos;
}vFisica8;

typedef struct{
	vFisica8 HIGH;
	vFisica8 LOW;
}vFisica16;



/*
 * Variables Globales
 */

/*STATUS*/
extern bool led0x00; //0x00 sMCU_OK Led
extern bool led0x01; //0x01 sCom_In Led
extern bool led0x02; //0x02 sPC_OK  Led
extern bool led0x03; //0x03
extern bool led0x04; //0x04
extern bool led0x05; //0x05
extern bool led0x06; //0x06
extern bool led0x07; //0x07


/*Variables*/
extern byte  SIZEPACKAGE;

extern vFisica8  STATUS;
extern vFisica16 tempExterna;
extern vFisica16 tempInterna;
extern vFisica16 presExterna;
extern vFisica16 aceleracionX;
extern vFisica16 aceleracionY;
extern vFisica16 aceleracionZ;
extern vFisica16 velAngularX;
extern vFisica16 velAngularY;
extern vFisica16 velAngularZ;
extern vFisica16 velLineal;
extern vFisica16 angBrujula;
extern vFisica8  presenciaAgua;
extern vFisica8  cargaBaterias;
extern vFisica8  XOR;
extern vFisica8  finTrama;









//Se encarga de inicializar el xSub
void initMxSub(byte tipo);
void initVFisicas();//Genera la numeración de la posición
void vFisicas2Array(byte paquete[]);


//MOTORES***************
extern byte tMotor;
extern word CENTERDC;
extern word MAXFORWARD;
extern word MAXBACKWARD;

//Servos*********
extern word MINSERVOUS;
extern word MAXSERVOUS;

//Activa a sMCU_OK
void sMCU_OK_W();
//Desactiva a sMCU_OK
void sMCU_OK_NW();
//Muestra titilando a sPC_OK
void sCom_In_W();
//Muestra titilando a sPC_OK
void sCom_In_NW();
//Muestra titilando a sPC_OK
void sPC_OK_W();
//Muestra titilando a sPC_OK
void sPC_OK_NW();

//paraliza el MCU por el tiempo time en ms
void delay(word time);
//Mapea
long map(long x, long in_min,long in_max,long out_min, long out_max);

//***************Motores :D **********************************
void initMxSub(byte tipo);

//Coloca un DC a todos los motores
void setDC(word Speed);

//Setea la velocidad de los motores de manera individual. Rango de 10 bits-> 0 - 1023
void setMotorSpeed(word Speed,byte Motor);

/***SERVOS*/
void servoPanAngle(word Angle);//Resolución de 0 - 179
void servoPan1024(word In);//Resolución de 0 - 1023 (0 - 0x1023)
void servoTiltAngle(word Angle);//Resolución de 0 - 179
void servoTilt1024(word In);//Resolución de 0 - 1023 (0 - 0x1023)

#endif /* XSUB_H_ */
