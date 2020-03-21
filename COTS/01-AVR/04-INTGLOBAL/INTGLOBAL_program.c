/*
Duthor :Mohamed Ibrahem 
Version:v01
Date:20-01-2020
/************************************************************
*/

#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "INTGLOBAL_register.h"
#include "INTGLOBAL_interfac.h"




void INT_void_EnableGlobal(void)
{
SET_BIT(SREG,SREG_I);
}
void INT_void_DisableGlobal(void)
{
	CLR_BIT(SREG,SREG_I);
}
