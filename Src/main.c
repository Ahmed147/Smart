
#include"types.h"
#include"Macros.h"
#include"DIO.h"
#include"LCD_int.h"
#include"EEPROM.h"
#include"ArbDraw.h"
#include"ADC.h"
#include"Registers.h"
#include<avr/io.h>
#include <avr/pgmspace.h>
#include <avr/interrupt.h>
#include"PWM.h"


volatile u8 qwe[8][8];
volatile u16 data;
volatile u16 Ch2Data;
extern u8 W;
int main()
{
	u8 ch=0;
	u8 Local_u8arr[]={7,6,5,4,3,2,1,0};
	u8 Local_u8Thank[]="Thank you";
	u8 Local_u8IMT[]="IMT";
	SetPortDirection(PORT_D , 0xff);   //PORT D output for lcd data
	SetPortDirection(PORT_B,0x0f);    //for lcd control    and msb nibble is input for test
	SetPortValue(PORT_B,0xf0);     //pull up resistance for thm msb nibble used in test
//	SetPinValue(PORT_D,6,1);      //pull up resistance
//	SetPinValue(PORT_D,7,1);      //pull up resistance

	Lcd_voidInit();       //initialize the lcd
	ADC_init();                       // initialize the ADC

	EEPROM_InsertData();                         //put data in eeprom

	pwm_init();



while(1)

{

	if(ch==0)           //multiplexe between channel 0 and 1
	{
	ADC_SelcetChannel(0);
	ADC_StartConversion();         //sart conversion
	data=ADC_ReadData();           //read the conversion value
	ch=1;               //the next time take from the second channel
	}
	else if(ch==1)
	{
		ADC_SelcetChannel(1);
		ADC_StartConversion();         //sart conversion
		Ch2Data=ADC_ReadData();
		ch=0;
	}
// 	Lcd_voidWriteCmd(0b10001000);          //but curser int the specific place
//  	Lcd_voidWriteData( (data/100)+48 );
// 	Lcd_voidWriteData( ((data/10)%10)+48 );
// 	Lcd_voidWriteData( (data%10)+48 );

	   if(W==1)
	    {
		 DrawLitters();
	    if(Ch2Data>500)
	     {
		  Lcd_voidWriteSentince(Local_u8arr);
	     }
	    else if(data>700)
	     {
	       Lcd_voidWriteSentinceAscii(Local_u8Thank);
	     }
	    else if(data <700)
	     {
	       Lcd_voidWriteSentinceAscii(Local_u8IMT);
	       Lcd_voidWriteSentince(Local_u8arr);
	     }
	     W=0;
	    }
}
	return 0;
}

