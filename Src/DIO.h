#ifndef DIO_H
#define DIO_H

#define DDRA *((volatile u8*)0x3A)
#define PORTA *((volatile u8*)0x3B)
#define PINA *((volatile u8*)0x39)
#define DDRB *((volatile u8*)0x37)
#define PORTB *((volatile u8*)0x38)
#define PINB *((volatile u8*)0x36)
#define DDRC *((volatile u8*)0x34)
#define PORTC *((volatile u8*)0x35)
#define PINC *((volatile u8*)0x33)
#define DDRD *((volatile u8*)0x31)
#define PORTD *((volatile u8*)0x32)
#define PIND *((volatile u8*)0x30)

#define PORT_A 0
#define PORT_B 1
#define PORT_C 2
#define PORT_D 3

#define GET_BIT(reg,bit) ((reg&(1<<bit))>>bit)
#define SET_BIT(reg,bit) (reg|=(1<<bit))
#define CLEAR_BIT(reg,bit) (reg&=~(1<<bit))

void SetPinDirection(u8 PortNumber , u8 PinNumber , u8 Direction);
u8 GetPinValue(u8 PortNumber , u8 PinNumber);
void SetPinValue(u8 PortNumber , u8 PinNumber , u8 Value);
void SetPin(u8 PinNumber , u8 Value);
void SetPortDirection(u8 PortNumber ,u8 Direction);
void SetPortValue(u8 PortNumber , u8 Value);
u8 GetPortValue(u8 PortNumber);

#endif
