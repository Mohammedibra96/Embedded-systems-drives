/**********************************************************************************************
Author :Mohamed Ibrahem
Version:1.0
Date:20 May 2020
Description:This Source file is used to interface with the AC module in AVR ATMega32  evaluation kit
 ***********************************************************************************************/
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "AC_register.h"
#include "AC_interface.h"
#include "AC_private.h"
#include "AC_cnfg.h"


void (*AC_PostiveGreaterNegativeCBF)(void);
void (*AC_NegativeGreaterPostiveCBF)(void);


void AC_Init(void)
{
	/* Select the Postive Pin Input AIN0 or bandgab*/
	ACSR &= POSTIVE_PIN_MASK;
	ACSR|=POSTIVE_PIN_SELECT;

	/* Select the negative Pin */

#if AC_INPUT_NEGATIVE_SELECT == AC_INPUT_NEGATIVE_PIN_AIN1
	ADMUX_ACSR &= AC_INPUT_NEGATIVE_MASK;
	SFIOR &=~SFIOR_ANALOG_COMP_ENABLE;

#else
	ADMUX_ACSR &= AC_INPUT_NEGATIVE_MASK;
	ADMUX_ACSR |=AC_INPUT_NEGATIVE_SELECT;
	SFIOR      |=SFIOR_ANALOG_COMP_ENABLE;
#endif


	/* Interrupt Mode */

	ACSR &= INTERRUPT_MODE_MAST;
	ACSR |= INTERRUPT_SELECT;

}


ErrorStatus_t AC_GetOutputValueSync(u8 * CopyOutputValue )
{
	ErrorStatus_t LocalErrror = E_OK;
	if ( CopyOutputValue )
	{
		*CopyOutputValue = (ACSR  & ACSR_ACO)>> 5;

	}
	else
	{
		LocalErrror =NULL_POINTER;
	}
	return LocalErrror;
}
ErrorStatus_t AC_GetOutputValueAsync(u8 * CopyOutputValue,void (*PostiveCBF)(void),void (*NegativeCBF)(void))
{
	ErrorStatus_t LocalErrror = E_OK;
	if (PostiveCBF && NegativeCBF && CopyOutputValue )
	{
		*CopyOutputValue = (ACSR  & ACSR_ACO)>> 5;
		AC_PostiveGreaterNegativeCBF = PostiveCBF ;
		AC_NegativeGreaterPostiveCBF= NegativeCBF;

		/* Enable the interrupt */
		ACSR |= ACSR_INTERRUPT_ENABLE ;
	}
	else
	{
		LocalErrror =NULL_POINTER;
	}
	return LocalErrror;
}
void AC_Disable(void)
{
	/* Disable Interrupt Enable */
	ACSR &=~ACSR_INTERRUPT_ENABLE;
	/*Disable the AC    */

	ACSR |= ACSR_ANALOG_COMP_DISABLE;
}

void __vector_18 (void)  __attribute__((signal,__INTR_ATTRS));
void __vector_18 (void)
{
#if INTERRUPT_SELECT == INTERRUPT_ON_TOGGLE
	if ((ACSR  & ACSR_ACO))
	{
		if (AC_PostiveGreaterNegativeCBF)
		{
			AC_PostiveGreaterNegativeCBF();
		}
	}
	else
	{
		if (AC_NegativeGreaterPostiveCBF)
		{
			AC_NegativeGreaterPostiveCBF();
		}
	}
#elif INTERRUPT_SELECT == INTERRUPT_ON_FALLING_EDGE
	if (AC_NegativeGreaterPostiveCBF)
	{
		AC_NegativeGreaterPostiveCBF();
	}
#elif INTERRUPT_SELECT == INTERRUPT_ON_RISING_EDGE
	if (AC_PostiveGreaterNegativeCBF)
	{
		AC_PostiveGreaterNegativeCBF();
	}
#endif
}



