/*
 * ArbDraw.c
 *
 *  Created on: Mar 11, 2017
 *      Author: Ahmed
 */
#include"types.h"
#include"DIO.h"
#include"LCD_int.h"

extern volatile u8 qwe[8][8];

void DrawLitters( )
{

	u8 i,j;


Lcd_voidWriteCmd(0b01000000);      // from ddram to cgram
/******************************************************************************/

for(i=0;i<8;i++)
{
	for(j=0;j<8;j++)
	{
    Lcd_voidWriteData( qwe[i][j] );
	}
}

/**********************************************************************************/
  Lcd_voidWriteCmd(0b10000100);          //from cgram to ddram the same as "move the cursor by moving in ddram"


}
