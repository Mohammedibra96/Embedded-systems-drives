/**********************************************************************************************
Author :Mohamed Ibrahem, Mahmoud Gamal
Version:1.0
Date:13 May 2020
Description:This Source file is used to interface with the SCB module in STM32f10x evaluation kit
 ***********************************************************************************************/
#include "STD_TYPES.h"
#include "SCB_interface.h"
#include "SCB_cnfg.h"





typedef struct SCB_t
{
	u32 CPUID ;
	u32 ICDR  ;
	u32 VTOR  ;
	u32 AIRCR ;
	u32 SCR   ;
	u32 CCR   ;
	u32 SHPR1 ;
	u32 SHPR2 ;
	u32 SHPR3 ;

}SCB_T;




#define SCB_BASE_ADDRESS   0xE000ED00

#define SCB_VECT_OFFSET   8



volatile SCB_T * SCB =(volatile SCB_T *)SCB_BASE_ADDRESS;

ErrorStatus_t SCB_SetVectorOffset(u32 *CopyOffset ,u32 SCB_VECT_BASE)
{
	ErrorStatus_t LocalError = E_OK ;
	/* Check if the input is NULL or address */
	if (CopyOffset && ( SCB_VECT_BASE == SCB_VECT_BASE_SRAM || SCB_VECT_BASE == SCB_VECT_BASE_CODE ))
	{
		SCB->VTOR &=~ SCB_VECT_BASE_CODE ;
		SCB->VTOR |= SCB_VECT_BASE ;
		/* Check if the address is aligned to 4 or not */
		if ( *CopyOffset % 0x200 == 0 )
		{
			SCB->VTOR |= (*CopyOffset) << SCB_VECT_OFFSET;
		}
		else
		{
			LocalError = E_NOT_OK;
		}
	}
	else
	{
		LocalError |= E_NULL_POINTER ;
	}
	return LocalError;
}


void SCB_Reset(void)
{
	SCB->AIRCR = 0x05FA0004;

}
