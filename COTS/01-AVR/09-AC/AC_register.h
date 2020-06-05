/**********************************************************************************************
Author :Mohamed Ibrahem
Version:1.0
Date:20 May 2020
Description:This Header file is used to interface with the AC module in AVR ATMega32 evaluation kit
***********************************************************************************************/
#ifndef AC_REGISTER_H
#define AC_REGISTER_H


#define SFIOR       *((volatile u8 * )0x50)
#define ACSR        *((volatile u8 * )0x28)
#define ADMUX_ACSR  *((volatile u16 *)0x27)



#endif
