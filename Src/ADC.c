/*
 * ADC.c
 *
 *  Created on: Dec 24, 2016
 *      Author: Abo Saad
 */
#include"types.h"
#include"DIO.h"
#include"avr/io.h"
void ADC_init(void)
{
	SET_BIT(ADCSRA,7); //enable interrupt
	SET_BIT(ADMUX,6); //vref
	CLEAR_BIT(ADMUX,7); //vref
	CLEAR_BIT(ADMUX,5); // right adjust
	SET_BIT(ADCSRA,0); // pre scaler
	SET_BIT(ADCSRA,1); //pre scaler
	SET_BIT(ADCSRA,2); //pre scaler
}

void ADC_SelectMode(u8 mode)
{
	if(mode)
	{
		SET_BIT(ADCSRA,5);     //auto trigger mode
	}
	else
	{
		CLEAR_BIT(ADCSRA,5);  //single mode
	}
}

void ADC_SelcetChannel(u8 channel)
{

	if(channel==1)        //we change the 5 LSB
	{
		SET_BIT(ADMUX,0);
	}
	else if(channel==0)
	{
		CLEAR_BIT(ADMUX,0);
	}
}


void ADC_StartConversion(void)
{
	SET_BIT(ADCSRA,6); // start conversion
}

u16 ADC_ReadData(void)
{
	u8 low;
	while( !GET_BIT(ADCSRA,4) );  //Check flag
	SET_BIT(ADCSRA,4);  //clear flag
	low=ADCL;
	return ( (ADCH<<8)|low );
}

void ADC_EnableIntrrupt(void)
{
	SET_BIT(ADCSRA,3); //enable interrupt
}
