/**********************************************************************************************
Author :Mohamed Ibrahem
Version:1.0
Date:30 April 2020
Description:This Source file is used to interface with the Timer0 module in AVR ATMega32  evaluation kit
 ***********************************************************************************************/
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "Timer0_register.h"
#include "Timer0_interface.h"
#include "Timer0_private.h"
#include "Timer0_cnfg.h"



#define TIMER0_RESOLUTION 			256

static void (*TIMER_pvCallBack_Func[2])(void)={NULL,NULL};
static u32  GetTimerSpeed();


u32 Num_OVs_Value ;
void Timer0_Init(void)
{
	TCCR0 &= (TIMER0_MODE_MASK & COMPARE_OUTPUT_MASK)    ;
	TCCR0 |= (TIMER0_MODE |TIMER0_COMPARE_OUTPUT_MODE)   ;
	TCNT0 =  PRE_LOAD_VALUE                              ;
	OCR0  = OC0_VALUE									 ;
}
void Timer0_Start(void)
{
	TCCR0 &= CLK_MASK   ;
	TCCR0 |= CLK_SELECT ;
}

void Timer0_Stop(void)
{
	TCCR0 &= CLK_MASK   ;
}

void Timer0_InterruptEnable(u8 T0_INTERRUPT)
{
	TIMSK |= T0_INTERRUPT;
}

void Timer0_InterruptDisable(u8 T0_INTERRUPT)
{
	TIMSK &= ~T0_INTERRUPT;
	TIMSK |= T0_INTERRUPT;
}


STD_ERROR Timer0_SetCallBackFunction(void (*CBF)(void),u8 T0_INTERRUPT)
{
	STD_ERROR LocalError = NOT_VALID_INPUTS;
	if ((T0_INTERRUPT) <= 2 )
	{
		LocalError = NULL_POINTER;
		if ( CBF != NULL )
		{
			TIMER_pvCallBack_Func[T0_INTERRUPT-1]=CBF;
			LocalError = OK ;
		}
		else 
		{

		}
	}
	return LocalError;
}



void Timer0_SetTimer_us(u32 Time_ms)
{
	u32 OVF_Time = ((TIMER0_RESOLUTION*1000000) /(GetTimerSpeed())) ;

	if (Time_ms < OVF_Time )
	{
		Num_OVs_Value = 1                         ;
		TCNT0         = (Time_ms * TIMER0_RESOLUTION)/OVF_Time  ;
	}
	else if ( Time_ms == OVF_Time )
	{
		Num_OVs_Value = 1 ;
		TCNT0         = 0 ;
	}
	else
	{

		Num_OVs_Value = (u32)(Time_ms/OVF_Time)                                   ;
		TCNT0         = (((float)Time_ms/OVF_Time)-(u32)(Time_ms/OVF_Time))*TIMER0_RESOLUTION ;
	}

	/* Enable The Over flow timer */
	TIMSK |= T0_INTERRUPT_OVER_FLOW;

	/* Start the timer  */
	TCCR0 &= CLK_MASK   ;
	TCCR0 |= CLK_SELECT ;

}

void Timer0_Delay_us(u32 Time_ms)
{
	u32 OVF_Time = ((TIMER0_RESOLUTION*1000000) /(GetTimerSpeed())) ;

	if (Time_ms < OVF_Time )
	{
		Num_OVs_Value = 1                         ;
		TCNT0         = (Time_ms * TIMER0_RESOLUTION)/OVF_Time  ;
	}
	else if ( Time_ms == OVF_Time )
	{
		Num_OVs_Value = 1 ;
		TCNT0         = 0 ;
	}
	else
	{

		Num_OVs_Value = (u32)(Time_ms/OVF_Time)                                   ;
		TCNT0         = (((float)Time_ms/OVF_Time)-(u32)(Time_ms/OVF_Time))*TIMER0_RESOLUTION ;
	}

	/* Start the timer  */
	TCCR0 &= CLK_MASK   ;
	TCCR0 |= CLK_SELECT ;
	u32 Counter = 0 ;

	while( Counter != Num_OVs_Value)
	{
		if ( (TIFR & T0_INTERRUPT_OVER_FLOW) == 1)
		{
			Counter ++ ;
			TIFR &= ~T0_INTERRUPT_OVER_FLOW;
		}
	}

}

static u32  GetTimerSpeed()
{
	u32 Speed = CRYSTAL_CLK_SPEED;
	switch(CLK_SELECT)
	{
	case T0_CLK_NO_PRESCALLER:
		Speed/=1;
		break;
	case T0_CLK_PRESCALLER8:
		Speed/= 8;
		break;
	case T0_CLK_PRESCALLER64:
		Speed/=64;
		break;
	case T0_CLK_PRESCALLER256:
		Speed/=256;
		break;
	case T0_CLK_PRESCALLER1024:
		Speed/=1024;
		break;
	}
	return Speed ;
}


void __vector_11 (void)  __attribute__((signal,__INTR_ATTRS));
void __vector_11 (void)
{

	static u32 Num_OV = 0;
	Num_OV ++;
	if (Num_OV == Num_OVs_Value)
	{
		Num_OV = 0;
		if(TIMER_pvCallBack_Func[T0_INTERRUPT_OVER_FLOW-1]!=NULL)
		{
			TIMER_pvCallBack_Func[T0_INTERRUPT_OVER_FLOW-1]();
		}
	}

}



void __vector_10 (void)  __attribute__((signal,__INTR_ATTRS));
void __vector_10 (void)
{
	static u32 NumCompareMatch = 0;
	NumCompareMatch ++;

	if (NumCompareMatch == NUM_COMPARE_MATCH)
	{
		NumCompareMatch = 0;
		if(TIMER_pvCallBack_Func[T0_INTERRUPT_COMPARE_MATCH-1]!=NULL)
		{
			TIMER_pvCallBack_Func[T0_INTERRUPT_COMPARE_MATCH-1]();
		}
	}
}
