/**********************************************************************************************
Author :Mohamed Ibrahem
Version:1.0
Date:6 May 2020
Description:This Header file is used to interface with the Timer1 module in AVR ATMega32 evaluation kit
***********************************************************************************************/
#ifndef Timer1_REGISTER_H
#define Timer1_REGISTER_H


#define TIMSK 	*((volatile u8 *)0x59)
#define TIFR 	*((volatile u8 *)0x58)

#define TCCR1A 	*((volatile u8 *)0x4F)
#define TCCR1B 	*((volatile u8 *)0x4E)
#define TCCR1 	*((volatile u16 *)0x4E)

#define TCNT1H 	*((volatile u8 *)0x4D)
#define TCNT1L 	*((volatile u8 *)0x4C)
#define TCNT1 	*((volatile u16 *)0x4C)

#define OCR1AH 	*((volatile u8 *)0x4B)
#define OCR1AL 	*((volatile u8 *)0x4A)
#define OCR1A 	*((volatile u16 *)0x4A)

#define OCR1BH 	*((volatile u8 *)0x49)
#define OCR1BL 	*((volatile u8 *)0x48)
#define OCR1B 	*((volatile u16 *)0x48)

#define ICR1H 	*((volatile u8 *)0x47)
#define ICR1L 	*((volatile u8 *)0x46)
#define ICR1 	*((volatile u16 *)0x46)



#endif
