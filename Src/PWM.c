

#include"Macros.h"
#include"Registers.h"
#include"types.h"
#include"DIO.h"
#include<avr/io.h>
#include <avr/pgmspace.h>
#include <avr/interrupt.h>
#include"data.h"
#include"EEPROM.h"
#include"ADC.h"
#include"LCD_int.h"

extern int sample_count;
#define SAMPLE_RATE 8000;

volatile u16 sample;
int sample_count;
u8 W=0;
u8 f=0;
extern volatile u16 data;
extern volatile u16 Ch2Data;
//
void pwm_init(void)
{
    /* use OC0 pin as output */
	SetPinDirection(PORT_B,3,1);
   // DDRD = _BV(PD5);

    /*
    * clear OC0 on compare match
    * set OC0 at BOTTOM, non-inverting mode
    * Fast PWM, 8bit
    */
	SET_BIT(TCCR0,COM01);
	SET_BIT(TCCR0,WGM00);
	SET_BIT(TCCR0,WGM01);

	//  TCCR1A = _BV(COM1A1) | _BV(WGM10);

    /*
    * Fast PWM, 8bit
    * Prescaler: clk/1 = 16MHz
    * PWM frequency = 16MHz / (255 + 1) = 62.5kHz
    */
//	SET_BIT(TCCR1B,WGM12);
	SET_BIT(TCCR0,CS00);

    // TCCR1B = _BV(WGM12) | _BV(CS10);

    /* set initial duty cycle to zero */
    OCR0 = 0;

    /* Setup Timer0 which will make preiodic over flow interrupt */

    TCCR2|=(1<<CS00);
    TCNT2=0;
    TIMSK|=(1<<TOIE2);
    sample_count = 8;
    sei(); //Enable interrupts
}

ISR(TIMER2_OVF_vect)
{



         sample_count--;
         if (sample_count == 0)
            {
             sample_count = 8;        // (62.5khz / 8 ) = 8 kHz our sampling rate
            if( ( Ch2Data < 500 ) && (data<700) && (f!=3) )
             {
                OCR0 = pgm_read_byte(&shokran_samples[sample++]);
               if(sample>shokran_length)
            	 {
             	 Lcd_voidWriteCmd(0b00000001);
             	 Lcd_voidWriteCmd(0b10000100);
            	 EEPROM_GetData(128);
            	 sample=0;
            	 f=3;
            	 W=1;          //to start write
            	 }
               }
             else if( (Ch2Data> 500) && (data>700) && (f!=1) )
               {

                 OCR0 = pgm_read_byte(&Basm_Allah[sample++]);
                   if(sample>Basm_allah_length)
                  	 {
               	     Lcd_voidWriteCmd(0b00000001);
               		Lcd_voidWriteCmd(0b10000100);
                	 EEPROM_GetData(0);
                  	 sample=0;
                  	 f=1;
                  	 W=1;
                  	 }
               }
             else if(  (Ch2Data > 500) && (data<700) && (f!=2) )
               {

                 OCR0 = pgm_read_byte(&ahmed_samples[sample++]);
                   if(sample>ahmed_length)
                  	 {
               	     Lcd_voidWriteCmd(0b00000001);
               		Lcd_voidWriteCmd(0b10000100);
                	 EEPROM_GetData(64);
                  	 sample=0;
                  	 f=2;
                  	 W=1;
                  	 }
               }
//             else if(f==3)
//               {
//                 OCR0 = pgm_read_byte(&kolkm_samples[sample++]);
//                   if(sample>kolkm_length)
//                  	 {
//                  	 sample=0;
//                  	 f=4;
//                  	 }
//               }
             else if( (Ch2Data < 500) && (data>700) && (f!=0) )
               {
                 OCR0 = pgm_read_byte(&Thank_samples[sample++]);
                   if(sample>Thank_length)
                  	 {
                     Lcd_voidWriteCmd(0b00000001);
                 	 Lcd_voidWriteCmd(0b10000100);
                  	 sample=0;
                  	 f=0;
                  	 W=1;
                  	 }
               }

            }
}

//......................................................................
//
//void pwm_init(void)
//{
//    /* use OC1A pin as output */
//	SetPinDirection(PORT_D,5,1);
//   // DDRD = _BV(PD5);
//
//    /*
//    * clear OC1A on compare match
//    * set OC1A at BOTTOM, non-inverting mode
//    * Fast PWM, 8bit
//    */
//	SET_BIT(TCCR1A,COM1A1);
//	SET_BIT(TCCR1A,WGM10);
//
//	//  TCCR1A = _BV(COM1A1) | _BV(WGM10);
//
//    /*
//    * Fast PWM, 8bit
//    * Prescaler: clk/1 = 8MHz
//    * PWM frequency = 8MHz / (255 + 1) = 31.25kHz
//    */
//	SET_BIT(TCCR1B,WGM12);
//	SET_BIT(TCCR1B,CS10);
//
//    // TCCR1B = _BV(WGM12) | _BV(CS10);
//
//    /* set initial duty cycle to zero */
//    OCR1A = 0;
//
//    /* Setup Timer0 */
//
//    TCCR2|=(1<<CS00);
//    TCNT2=0;
//    TIMSK|=(1<<TOIE2);
//    sample_count = 4;
//    sei(); //Enable interrupts
//}
//
//ISR(TIMER2_OVF_vect)
//{
//
//         sample_count--;
//         if (sample_count == 0)
//            {
//             sample_count = 8;
//             OCR1A = pgm_read_byte(&pcm_samples[sample++]);
//             if(sample>pcm_length)sample=0;
//            }
//}

