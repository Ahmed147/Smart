/*
 * ADC.h
 *
 *  Created on: Dec 24, 2016
 *      Author: Abo Saad
 */

#ifndef ADC_H_
#define ADC_H_

#define AUTOTRIGGER 1
#define SINGLEMODE 0

void ADC_init(void);
void ADC_SelectMode(u8 mode);
void ADC_SelcetChannel(u8 channel);
void ADC_StartConversion(void);
u16 ADC_ReadData(void);
void ADC_EnableIntrrupt(void);

#endif /* ADC_H_ */
