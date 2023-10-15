/* 
 * File:   LCD1602.h
 * Author: Administrador
 *
 * Created on 10 de octubre de 2023, 03:55 PM
 */

#ifndef LCD1602_H
#define	LCD1602_H

#define _XTAL_FREQ 8000000UL

#include<xc.h>
#include<stdint.h>

/*MACROS O DEFINICIONES*/

#define LCD_PUERTO_LAT LATB
#define LCD_PUERTO_TRIS TRISB

#define LCD_RS_LAT LATCbits.LATC0 
#define LCD_RW_LAT LATCbits.LATC1
#define LCD_EN_LAT LATCbits.LATC2

#define LCD_RS_TRIS TRISCbits.RC0
#define LCD_RW_TRIS TRISCbits.RC1
#define LCD_EN_TRIS TRISCbits.RC2

#define LCD_MODO_COMANDO() LCD_RS_LAT = 0;//RS MODO COMADO O MODO CARACTER RS=0-> MODO COPMANDO
#define LCD_MODO_CARACTER() LCD_RS_LAT = 1;//RS MODO COMADO O MODO CARACTER RS=1-> MODO CARACTER INFO QUE ENVIAS SE MUESTRA EN EL LCD
#define LCD_ENABLE_TOGGLE() LCD_EN_LAT = 1; __delay_ms(5);LCD_EN_LAT=0; //SOLO CAUNDO SE ACTIVA EL ENABLE PASA LA INFORMACION SOLO CUANDO ES 1(SOLO SE ACTIVA UN PERIODO DE TIEMPO)


/*FUNCIONES*/

void LCD_Init_Gpio(void);
void LCD_Send_Command(char comando);
void LCD_Send_Character(char character);
void LCD_Init(void);
void LCD_Send_String(char cadena[]);

//para las filas y columnas -  x:fila y:columna
void LCD_XY (uint8_t x, uint8_t y);

#endif	/* LCD1602_H */

