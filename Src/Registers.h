/*
 * Register.h
 *
 *  Created on: Jan 23, 2017
 *      Author: Abo Saad
 */

#ifndef REGISTER_H_
#define REGISTER_H_

/* DIO registers address *///.........................................

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
//....................................................................

/* interrupt registers address *///...................................

#define SREG *((volatile u8*) 0x5F)
#define GIFR *((volatile u8*) 0x5A)
#define GICR *((volatile u8*) 0x5B)
#define MCUCR *((volatile u8*) 0x55)
#define MCUCSR *((volatile u8*) 0x54)

//...................................................................

/* ADC registers address *///.........................................
#define ADCSRA *((volatile u8*)0x26)
#define ADMUX *((volatile u8*)0x27)
#define ADCH *((volatile u8*)0x25)
#define ADCL *((volatile u8*)0x24)
#define SFIOR *((volatile u8*)0x50)
//...................................................................

/*TIMER0 registers address*///......................................
#define TCCR0 *((volatile u8*) 0x53)
#define TIMSK *((volatile u8*) 0x59)
#define OCR0 *((volatile u8*) 0x5C)
//.................................................................


#endif /* REGISTER_H_ */
