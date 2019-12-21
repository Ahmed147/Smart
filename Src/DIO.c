#include"types.h"
#include"DIO.h"

volatile u8* arr[4]= {&PORTA,&PORTB,&PORTC,&PORTD};


void SetPinDirection(u8 PortNumber , u8 PinNumber , u8 Direction)
{

	if(Direction)
			SET_BIT( *(arr[PortNumber]-1) , PinNumber );
		else
			CLEAR_BIT( *(arr[PortNumber]-1) , PinNumber );
}


u8 GetPinValue(u8 PortNumber , u8 PinNumber)
{
	u8 re=0;

	re= GET_BIT( *(arr[PortNumber]-2) , PinNumber );
	return re;
}

void SetPinValue(u8 PortNumber , u8 PinNumber , u8 Value)
{

   if(Value)
 	 SET_BIT(*arr[PortNumber],PinNumber);
   else
	 CLEAR_BIT(*arr[PortNumber],PinNumber);
}

void SetPin( u8 PinNumber , u8 Value )                       // fun take the pin number from 0 to 31
{
  if(Value)
  {
	  SET_BIT( *arr[PinNumber/8] , (PinNumber%8) );
  }
  else
  {
	  CLEAR_BIT( *arr[PinNumber/8] , (PinNumber%8) );
  }


}

void SetPortDirection(u8 PortNumber , u8 Direction)
{
	*(arr[PortNumber]-1) = Direction;
}

void SetPortValue(u8 PortNumber , u8 Value)
{
	*arr[PortNumber] = Value;
}
u8 GetPortValue(u8 PortNumber)
{
	u8 re=0;
	re=*(arr[PortNumber]-2);        // -2 because  pin reg = port reg - 2
	return re;
}
