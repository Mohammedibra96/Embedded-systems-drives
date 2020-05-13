/**********************************************************************************************
Author :Mohamed Ibrahem
Version:1.0
Date:5 Feb 2020
Description:This Source file is used to interface with the GPIO module in STM32f10x evaluation kit
 ***********************************************************************************************/

#include "GPIO.h"

typedef struct 
{
	u32 CRL;
	u32 CRH;
	u32 IDR;
	u32 ODR;
	u32 BSRR;
	u32 BRR;
	u32 LCKR;

}GPIO_struct;




/* This function shall initialize pin or group of pins
 * Inputs:Copy_GPIO -> contains the PIN and the MODE of the PINS
 *		  GPIO_PORT -> {GPIO_PORT_A,GPIO_PORT_B,GPIO_PORT_C}
 *Outputs:
 *			{OK,NOK,INVALID_INPUT}
 * */
STD_ERROR GPIO_InitPins(GPIO_t *Copy_GPIO)
{
	u32 Local_Conter=0;
	STD_ERROR status=OK;
	GPIO_struct*CopyPort=(GPIO_struct*)Copy_GPIO->Port;

	if ( !ISGPIO_PORT(Copy_GPIO->Port)|| !ISGPIO_MODE(Copy_GPIO->Mode) )
	{
		status=INVALID_INPUT;
	}
	else
	{
		for(Local_Conter = 0;Local_Conter< 16;Local_Conter++)
		{
			if(Copy_GPIO->Pin & 1<<Local_Conter)
			{
				if(Local_Conter<8)
				{
					u32 Local=CopyPort->CRL;
					Local&=~(0b1111<<(4*Local_Conter));
					Local|=((Copy_GPIO->Mode)<<((Local_Conter)*4));
					CopyPort->CRL=Local;
					status=OK;
				}
				else if(Local_Conter<16)
				{
					u32 Local=CopyPort->CRH;
					Local&=~(0b1111<<4*(Local_Conter-8));
					Local|=(Copy_GPIO->Mode)<<((Local_Conter-8)*4);
					CopyPort->CRH=Local;
					status=OK;
				}
			}

		}
		if (Copy_GPIO->Mode == GPIO_MODE_INPUT_PULLUP)
			CopyPort->BSRR = Copy_GPIO-> Pin;
	}
	return status;
}
/* This function shall Write the Pin value or group of pins
 * Inputs:Copy_GPIO -> contains the PIN and the MODE of the PINS
 *		  GPIO_PORT -> {GPIO_PORT_A,GPIO_PORT_B,GPIO_PORT_C}
 *		  GPIO_VALUE -> {GPIO_VALUE_HIGH,GPIO_VALUE_LOW}
 *
 *Outputs:
 *			{OK,INVALID_INPUT}
 * */
STD_ERROR GPIO_WritePins(GPIO_t *Copy_GPIO,u8 GPIO_VALUE)
{
	STD_ERROR status=OK;
	GPIO_struct*CopyPort=(GPIO_struct*)Copy_GPIO->Port;

	if ( !ISGPIO_PORT(Copy_GPIO->Port) || !ISGPIO_MODE(Copy_GPIO->Mode))
	{
		status=INVALID_INPUT;
	}
	else
	{
		switch(GPIO_VALUE)
		{
		case GPIO_VALUE_HIGH:
			CopyPort->BSRR=Copy_GPIO->Pin;
			status=OK;
			break;
		case GPIO_VALUE_LOW:
			CopyPort->BRR=Copy_GPIO->Pin;
			status=OK;
			break;
		}
	}
	return status;
}


/* This function shall Write the Pin value
 * Inputs:
 *		  GPIO_PORT -> {GPIO_PORT_A,GPIO_PORT_B,GPIO_PORT_C}
 *		  GPIO_PIN	-> {GPIO_PIN_x}
 *		  GPIO_VALUE -> {GPIO_VALUE_HIGH,GPIO_VALUE_LOW}
 *
 *Outputs:
 *			{OK,INVALID_INPUT}
 * */

STD_ERROR GPIO_WritePin(void* GPIO_PORT,u32 GPIO_PIN,u8 GPIO_VALUE)
{
	STD_ERROR status=OK;
	GPIO_struct*CopyPort=(GPIO_struct*)GPIO_PORT;

	if (!ISGPIO_PIN(GPIO_PIN) || !ISGPIO_PORT(GPIO_PORT) )
	{
		status=INVALID_INPUT;
	}
	switch(GPIO_VALUE)
	{
	case GPIO_VALUE_HIGH:
		CopyPort->BSRR = GPIO_PIN;
		status=OK;
		break;
	case GPIO_VALUE_LOW:
		CopyPort->BRR = GPIO_PIN;
		status=OK;
		break;
	}
	return status;
}


/* This function shall Read the Pin value
 * Inputs:
 *		  GPIO_PORT -> {GPIO_PORT_A,GPIO_PORT_B,GPIO_PORT_C}
 *		  GPIO_PIN	-> {GPIO_PIN_x}
 *		  PinValue -> contains the pin value returned from the function {GPIO_VALUE_HIGH,GPIO_VALUE_LOW}
 *
 *Outputs:
 *			{OK,INVALID_INPUT}
 * */

STD_ERROR GPIO_GetPinVal(void* GPIO_PORT,u16 GPIO_PIN,u32 *PinValue)
{
	STD_ERROR LocalError=OK;
	GPIO_struct*CopyPort=(GPIO_struct*)GPIO_PORT;

	if (!ISGPIO_PIN(GPIO_PIN) || !ISGPIO_PORT(GPIO_PORT) )
	{
		LocalError=INVALID_INPUT;
	}
	else
	{
		if(CopyPort->IDR & GPIO_PIN)
		{
			*PinValue=GPIO_VALUE_HIGH;
		}
		else
		{
			*PinValue=GPIO_VALUE_LOW;
		}
	}
	return LocalError;
}


/* This function shall Set the Pin Mode
 * Inputs:
 *		  GPIO_PORT -> {GPIO_PORT_A,GPIO_PORT_B,GPIO_PORT_C}
 *		  GPIO_PIN	-> {GPIO_PIN_x}
 *
 *Outputs:
 *			{OK,INVALID_INPUT}
 * */

STD_ERROR GPIO_InitPin(void* GPIO_PORT,u16 GPIO_PIN,u8 GPIO_MODE)
{
	STD_ERROR LocalError=OK;
	u32 Local_Conter     = 0;
	GPIO_struct*CopyPort=(GPIO_struct*)GPIO_PORT;

	if (!ISGPIO_PIN(GPIO_PIN) || !ISGPIO_PORT(GPIO_PORT) || !ISGPIO_MODE(GPIO_MODE))
	{

		LocalError=INVALID_INPUT;
	}
	else
	{
		while( (1<<Local_Conter) != GPIO_PIN)
		{
			Local_Conter++;
		}
		if(Local_Conter<8)
		{
			u32 Local=CopyPort->CRL;
			Local&=~(0b1111<<(4*Local_Conter));
			Local|=(GPIO_MODE<<((Local_Conter)*4));
			CopyPort->CRL=Local;
			LocalError=OK;
		}
		else if(Local_Conter<16)
		{
			u32 Local=CopyPort->CRH;
			Local&=~(0b1111<<4*(Local_Conter-8));
			Local|=(GPIO_MODE)<<((Local_Conter-8)*4);
			CopyPort->CRH=Local;
			LocalError=OK;
		}
		if (GPIO_MODE == GPIO_MODE_INPUT_PULLUP)
			CopyPort->BSRR = GPIO_PIN;
	}
	return LocalError;
}


/* This function shall Write the Port value
 * Inputs:
 *		  GPIO_PORT -> {GPIO_PORT_A,GPIO_PORT_B,GPIO_PORT_C}
 *		  PortValue	-> { any value assigned to the port from 0x0000 to 0xffff}
 *Outputs:
 *			{OK,INVALID_INPUT}
 * */



STD_ERROR GPIO_writePortValue(void* GPIO_PORT , u16 PortValue)
{
	STD_ERROR status=OK;
	GPIO_struct*CopyPort=(GPIO_struct*)GPIO_PORT;
	if ( !ISGPIO_PORT(GPIO_PORT) )
	{
		status=INVALID_INPUT;
	}
	else
	{
		CopyPort->ODR =PortValue;
	}
	return status;
}

