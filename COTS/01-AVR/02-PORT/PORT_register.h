/*
Duthor :Mohamed Ibrahem 
Version:v01
Date:10-12-2019
/************************************************************
*/



#ifndef POERT_REGISTER_H
#define POERT_REGISTER_H 

#define PORTA *((volatile u8 *)0x3B)
#define DDRA  *((volatile u8 *)0x3A)


#define PORTB *((volatile u8 *)0x38)
#define DDRB  *((volatile u8 *)0x37)


#define PORTC *((volatile u8 *)0x35)
#define DDRC  *((volatile u8 *)0x34)


#define PORTD *((volatile u8 *)0x32)
#define DDRD  *((volatile u8 *)0x31)





#endif