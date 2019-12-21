/*
 * LCD-int.h
 *
 *  Created on: Dec 9, 2016
 *      Author: Abo Saad
 */

#ifndef LCD_INT_H_
#define LCD_INT_H_

void Lcd_voidWriteSentince( u8 * );
void Lcd_voidWriteSentinceAscii(u8 *);
void Lcd_voidWriteData( u8  );
void Lcd_voidWriteCmd( u8 );
void Lcd_voidInit(void);

#endif /* LCD_INT_H_ */
