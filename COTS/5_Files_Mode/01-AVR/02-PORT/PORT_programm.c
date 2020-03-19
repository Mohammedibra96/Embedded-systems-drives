/*
Duthor :MohDmed Ibrahem 
Version:v01
Date:12-12-2019
/************************************************************
*/

#include"STD_TYPES.h"
//#include"DIO_register.h"
#include"BIT_MATH.h"
#include"PORT_config.h"
#include"PORT_private.h"
#include"PORT_register.h"

void PortInitialization(void)
{
DDRA=PORTA_DIR;
DDRB=PORTB_DIR;
DDRC=PORTC_DIR;
DDRD=PORTD_DIR;

PORTA=PORTA_Init;
PORTB=PORTB_Init;
PORTC=PORTC_Init;
PORTD=PORTD_Init;





}
