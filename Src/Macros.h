/*
 * Macros.h
 *
 *  Created on: Jan 23, 2017
 *      Author: Abo Saad
 */

#ifndef MACROS_H_
#define MACROS_H_

#define GET_BIT(reg,bit) ((reg&(1<<bit))>>bit)
#define SET_BIT(reg,bit) (reg|=(1<<bit))
#define CLEAR_BIT(reg,bit) (reg&=~(1<<bit))
#define TOGGEL_BIT(reg,bit) (reg^=(1<<bit))

#define PORT_A 0
#define PORT_B 1
#define PORT_C 2
#define PORT_D 3

//.....Timer0 registers bits macros..................
//....................................................
#define CS00    0
#define CS01    1
#define CS02    2
#define WGM01   3
#define COM00   4
#define COM01   5
#define WGM00   6
#define FOC0    7
//......................................................
#define TOIE0   0
#define OCIE0   1
//......................................................



#endif /* MACROS_H_ */
