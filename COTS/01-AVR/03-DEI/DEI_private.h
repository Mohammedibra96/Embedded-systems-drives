/*
Duthor :Mohamed Ibrahem 
Version:v01
Date:20-01-2020
/************************************************************
*/


#ifndef DEI_PRIVATE_H
#define DEI_PRIVATE_H



#define ENABLE 						1
#define DISABLE 					2


#define	LOW_LEVEL			1
#define	ON_CHANGE			2
#define	RISING_EDGE			3
#define	FALLING_EDGE		4

void __vector_1(void) __attribute__((signal,used));
void __vector_2(void) __attribute__((signal,used));
void __vector_3(void) __attribute__((signal,used));




#endif
