/*
Duthor :Mohamed Ibrahem 
Version:v01
Date:20-01-2020
/************************************************************
*/


#ifndef DEI_REGISTER_H
#define DEI_REGISTER_H


#define MCUCR	 *((volatile u8 *)0x55)    /*Control Register*/
#define MCUCSR 	 *((volatile u8 *)0x54)    /*Control and stataus register*/
#define GICR 	 *((volatile u8 *)0x5B)		/*General control Register*/
#define GIFR 	 *((volatile u8 *)0x5A)		/*General Flag Register */



#define MCUCR_ISC00		0
#define MCUCR_ISC01		1
#define MCUCR_ISC10     2
#define MCUCR_ISC11		3

#define MCUCSR_ISC2		6


#define GICR_INT0       6					/*INT0 enable*/
#define GICR_INT1		7					/*Int 1 Enable*/
#define GICR_INT2		5					/*Int 2 Enable */




#define GIFR_INTF0		6					/*int flag*/
#define GIFR_INTF1		7					/*int1 flag*/
#define GIFR_INTF2		5					/*int2 flag*/




#endif

