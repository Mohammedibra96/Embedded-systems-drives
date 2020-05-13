/**********************************************************************************************
Author :Mohamed Ibrahem
Version:1.0
Date:30 April 2020
Description:This Header file is used to interface with the Timer0 module in AVR ATMega32 evaluation kit
***********************************************************************************************/
#ifndef Timer0_REGISTER_H
#define Timer0_REGISTER_H



#define TCCR0 *((volatile u8 *)0x53)
#define TCNT0 *((volatile u8 *)0x52)

#define TIMSK *((volatile u8 *)0x59)
#define OCR0 *((volatile u8 *)0x5C)

#define TIFR 	*((volatile u8 *)0x58)

#endif
