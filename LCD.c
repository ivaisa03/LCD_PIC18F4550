/*
 * File:   LCD.c
 * Author: MIMI
 *
 * Created on 10 de octubre de 2023, 03:18 PM
 */
#define _XTAL_FREQ 8000000UL

#include "system_config.h"
#include "proyect_defines.h"
#include "LCD1602.h"
#include <stdint.h>
#include <xc.h>

#ifndef _XTAL_FREQ
#define _XTAL_FREQ 8000000UL
#endif

/*declaracion de funciones*/
void Init_Internal_Osc (_freq_int_t freq);

/*MAIN*/

void main(void) 
{
    /*CONFIGURAR EL OSCILADOR INTER*/
    Init_Internal_Osc(freq_8mhz);//Init_Internal_Osc(0b111)
    /*CONFIGURAR LA LCD*/
    LCD_Init();
    /*COLOCAR EL CURSOR AL INICIO*/
    LCD_Send_Command(0x80);
    /*ESCRIBIR UNA LETRA*/
    LCD_Send_String("FRASE CON ESPACIOS");
   
    /*BUCLE PRINCIPAL*/    
    while(1);
    return;
}
/*definición de funciones*/
void Init_Internal_Osc (_freq_int_t freq)
{
/*Limpiar el registro OSCON*/
    OSCCON=0x00;
/*CONFIGURAR*/            
    OSCCONbits.SCS=0b10; //INTERNO        
    OSCCONbits.IRCF=0b111; // OSCCONbits.ICRF=0b111
            
}