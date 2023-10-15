#include "LCD1602.h"

void LCD_Init_Gpio(void)
{
    LCD_PUERTO_TRIS=0x00;//PARA QUE EL PUERTO SEA SALIDA
    LCD_RS_TRIS=0;//SALIDA
    LCD_RW_TRIS=0;//SALIDA
    LCD_EN_TRIS=0;//SALIDA
    
    LCD_RW_LAT=0;//MODO ESCRITURA
}
void LCD_Send_Command(char comando)
{
    LCD_MODO_COMANDO();//RS=0
    LCD_PUERTO_LAT=comando;
    LCD_ENABLE_TOGGLE();
}
void LCD_Send_Character(char character)
{
    LCD_MODO_CARACTER();//RS=1
    LCD_PUERTO_LAT=character;
    LCD_ENABLE_TOGGLE();
}
void LCD_Init(void)
{
    LCD_Init_Gpio();//CONFIGURAMOS LOS PINES COMO SALIDA
    LCD_Send_Command(0x01);//COMANDO: CLEAR DSIPLAY
    LCD_Send_Command(0x02);//COMANDO: RETURN HOME
    LCD_Send_Command(0x06);//COMANDO: I/D =1;DERECHA-SH=0;:INCREMENTO DERECHA SIN SHIFT (SHIFT hace que las letras se muevan)
    LCD_Send_Command(0x0F);//COMANDO: DISPLAY ON CURSOR ON Y BLINK ON | Si no quiero que haya cursor ni blink - (0x0C)
    LCD_Send_Command(0x38);//COMANDO: 8 BITS 2 LINEAS 5X8 CARACTER
    LCD_Send_Command(0x02);//COMANDO: RETURN HOME
    
}
void LCD_Send_String(char cadena[])
{
    uint8_t index = 0;
    while(cadena[index]!='\0')
    {
        LCD_Send_Character(cadena[index]);
        index++;
    }
}

void LCD_XY (uint8_t x, uint8_t y)
{
    //x fila | y columna
    if (x>0)
    {
        //fila 2
        LCD_Send_Command(0xC0 + y);
    }
    else 
    {
        //fila 1
        LCD_Send_Command(0x80+ y);
    }
}
