/*
 * LCD_prog.c
 *
 *  Created on: Dec 9, 2016
 *      Author: Abo Saad
 */

#include"types.h"
#include"DIO.h"
#include<util/delay.h>
#include"LCD_int.h"

void Lcd_voidWriteSentince( u8 *Argument_pu8Sentince )
{
	u8 i=0;
	while( i<8 )
	{
		Lcd_voidWriteData( Argument_pu8Sentince[i] );
		i++;
	}

}
void Lcd_voidWriteSentinceAscii(u8 * Argument_pi8sentince)
{
	u8 i=0;
//	Lcd_voidWriteCmd(0b00000001);
	while( Argument_pi8sentince[i]!='\0' )
	{
		Lcd_voidWriteData( Argument_pi8sentince[i] );
		i++;
	}
}

void Lcd_voidWriteData( u8 Argument_u8character )
{
//	//SetPinValue(PORT_D,0,0);               //RS choose command mode
//	//SetPinValue(PORT_D,1,0);               //R/W choose write mode
//
//	PORTD = 1;
//
//	PORTA = Argument_u8character;
//	//SetPortValue(PORT_A , Argument_u8character);   //pass the command
//	//SetPinValue(PORT_D,2,1);              //enable E
//
//	PORTD |= 0x04;
//	_delay_ms(2);                    //for 1 ms
//	//SetPinValue(PORT_D,2,0);              //disable E
//	PORTD &= 0b11111011;
//	_delay_ms(2);                    //for 1 ms

	SetPinValue(PORT_B,0,1);               //RS choose data mode
	SetPinValue(PORT_B,1,0);               //R/W choose write mode
	SetPortValue(PORT_D , Argument_u8character);    //pass the data
	SetPinValue(PORT_B,2,1);              //enable E
	_delay_ms(2);                    //for 1 ms
	SetPinValue(PORT_B,2,0);              //disable E
	_delay_ms(2);                    //for 1 ms

}
void Lcd_voidWriteCmd( u8 Argument_u8character )
{
	SetPinValue(PORT_B,0,0);               //RS choose command mode
	SetPinValue(PORT_B,1,0);               //R/W choose write mode

//	PORTD = 0;
//
//	PORTA = Argument_u8character;
	SetPortValue(PORT_D , Argument_u8character);   //pass the command
	SetPinValue(PORT_B,2,1);              //enable E

//	PORTD |= 0x04;
	_delay_ms(10);                    //for 1 ms
	SetPinValue(PORT_B,2,0);              //disable E
//	PORTD &= 0b11111011;
	_delay_ms(10);                    //for 1 ms

}

void Lcd_voidInit(void)
{
	_delay_ms(30);
	Lcd_voidWriteCmd(0b00111000);    // 0011 NF xx  .. N number of line .. F ( 5x9 || 5x7 )
	_delay_ms(2);
	Lcd_voidWriteCmd(0b00001100);//00001DCB ..D ON OFF..C cursor ON OFF.. B blink cursor ON OFF
	_delay_ms(2);
	Lcd_voidWriteCmd(0b00000001); //clear
}
