/**********************************************************************************************
Author :Mohamed Ibrahem
Version:1.0
Date:6 May 2020
Description:This Source file is used to interface with the Timer1 module in AVR ATMega32  evaluation kit
 ***********************************************************************************************/
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "Timer1_register.h"
#include "Timer1_interface.h"
#include "Timer1_private.h"
#include "Timer1_cnfg.h"
#include"DIO_interface.h"


#define TIMER1_CAPT_ISR   __vector_6
#define TIMER1_COMPA_ISR  __vector_7
#define TIMER1_COMPB_ISR  __vector_8
#define TIMER1_OVF_ISR    __vector_9

#define TIMER1_RESOLUTION 	65636


static volatile u16 ALL_Period  = 0 ;
static volatile u16 OFF_Period = 0 ;


u32  Timer1_GetTimerSpeed(void);


static void (*TIMER_pvCallBack_Func[4])(void);

u32 Num_OVs_Value =   NUM_OVER_FLOW;

void Timer1_Init(void)
{
	TCCR1A &= TCCR1A_COMPARE_OUTPUT_MAST     ;
	TCCR1A |= ( MODE_OC1A | MODE_OC1B )      ;

	TCCR1  &= WAVA_GENERATION_MAST           ;
	TCCR1  |= T1_WAVE_GENERATION        ;

	TCNT1 = PRE_LOAD_VALUE                   ;
	OCR1B = OC1B_VALUE                       ;
	ICR1  = ICR1_VALUE                       ;
}

void Timer1_SetPwmValue(u32 Value)
{
	OCR1A = Value         ;
}


void Timer1_Start(void)
{
	TCCR1B &= CLK_MASK   ;
	TCCR1B |= CLK_SELECT ;
}



void Timer1_Stop(void)
{
	TCCR1B &= CLK_MASK   ;
}

void Timer1_ClearCounter(void)
{
	TCNT1 = 0 ;
}




void Timer1_SetTimer_us(u32 Time_ms)
{
	u32 OVF_Time = ((TIMER1_RESOLUTION*(1000000 /Timer1_GetTimerSpeed()))) ;

	if (Time_ms < OVF_Time )
	{
		Num_OVs_Value = 1                         ;
		TCNT1         = (Time_ms * TIMER1_RESOLUTION)/OVF_Time  ;
	}
	else if ( Time_ms == OVF_Time )
	{
		Num_OVs_Value = 1 ;
		TCNT1         = 0 ;
	}
	else
	{
		Num_OVs_Value = (u32)(Time_ms/OVF_Time)                                   ;
		TCNT1         = (((float)Time_ms/OVF_Time)-(u32)(Time_ms/OVF_Time))*TIMER1_RESOLUTION ;
	}

	TCCR1  &= WAVA_GENERATION_MAST           ;
	TCCR1  |= T1_WG_NORMAL        ;


	/* Enable The Over flow timer */
	TIMSK |= T1_INTERRUPT_OVER_FLOW;


	/* Start the timer  */
	TCCR1B &= CLK_MASK   ;
	TCCR1B |= CLK_SELECT ;

}

void Timer1_Delay_us(u32 Time_us)
{
	u32 OVF_Time = ((TIMER1_RESOLUTION*(1000000 /Timer1_GetTimerSpeed()))) ;

	if (Time_us < OVF_Time )
	{
		Num_OVs_Value = 1                         ;
		TCNT1         = (Time_us * TIMER1_RESOLUTION)/OVF_Time  ;
	}
	else if ( Time_us == OVF_Time )
	{
		Num_OVs_Value = 1 ;
		TCNT1         = 0 ;
	}
	else
	{

		Num_OVs_Value = (u32)(Time_us/OVF_Time)                                   ;
		TCNT1         = (((float)Time_us/OVF_Time)-(u32)(Time_us/OVF_Time))*TIMER1_RESOLUTION ;
	}
	TCCR1  &= WAVA_GENERATION_MAST           ;
	TCCR1  |= T1_WG_NORMAL        ;

	/* Start the timer  */
	TCCR1B &= CLK_MASK   ;
	TCCR1B |= CLK_SELECT ;
	u32 Counter = 0 ;

	while( Counter != Num_OVs_Value)
	{
		if ( (TIFR & T1_INTERRUPT_OVER_FLOW) == 1)
		{
			Counter ++ ;
			TIFR &= ~T1_INTERRUPT_OVER_FLOW;
		}
	}

}

void Timer1_InterruptEnable(u8 T1_INTERRUPT)
{
	TIMSK |= T1_INTERRUPT;
}
void Timer1_InterruptDisable(u8 T1_INTERRUPT)
{
	TIMSK &= ~T1_INTERRUPT;
	TIMSK |= T1_INTERRUPT;
}


ErrorStatus Timer1_SetCallBackFunction(void (*CBF)(void),u8 TIMER1_INTERRUPT)
{
	ErrorStatus LocalError = NOT_VALID_INPUTS;
	if ((TIMER1_INTERRUPT) < 4 )
	{
		LocalError = NULL_POINTER;
		if ( CBF != NULL )
		{
			TIMER_pvCallBack_Func[TIMER1_INTERRUPT]=CBF;
			LocalError = OK ;
		}
		else
		{
		}
	}
	return LocalError;
}


u32  Timer1_GetTimerSpeed(void)
{
	u32 Speed = CRYSTAL_CLK_SPEED ;
	switch(CLK_SELECT)
	{
	case T1_CLK_NO_PRESCALLER:
		Speed/=1;
		break;
	case T1_CLK_PRESCALLER8:
		Speed/= 8;
		break;
	case T1_CLK_PRESCALLER64:
		Speed/=64;
		break;
	case T1_CLK_PRESCALLER256:
		Speed/=256;
		break;
	case T1_CLK_PRESCALLER1024:
		Speed/=1024;
		break;
	}
	return Speed ;
}


u16 Timer1_GetTimerCount(void)
{
	return TCNT1;
}


void Timer1_Set_ICU_Edge(u8 T1_INPUT_CAPTURE )
{

	TCCR1B &= TCCR1B_MAST ;
	TCCR1B |= T1_NOISE_CANCELER_ENABLED;

	TCCR1B |= T1_INPUT_CAPTURE;

	TIMSK |=T1_INTERRUPT_INPUT_CAPTURE;

}

STD_ERROR Timer1_ICU_GetDutyCycle(u16 *Duty  )
{
	STD_ERROR LocaolError =NOK;
	if (Duty)
	{
		if (ALL_Period && OFF_Period){
			*Duty= (((ALL_Period-OFF_Period)*100)/(ALL_Period));
		}
		else
		{
			LocaolError =NOK;
		}
	}
	else
	{
		LocaolError =NULL_POINTER;
	}
	return LocaolError;
}
STD_ERROR Timer1_ICU_Get_Frequency( u16* Freq )
{
	STD_ERROR LocaolError =NOK;
	if (Freq)
	{

		if ( ALL_Period && OFF_Period ){
			*Freq = ((Timer1_GetTimerSpeed())/ (ALL_Period));
		}
		else
		{
			LocaolError =NOK;
		}
	}
	else
	{
		LocaolError =NULL_POINTER;
	}
	return LocaolError;
}

void TIMER1_CAPT_ISR (void)  __attribute__((signal,__INTR_ATTRS));
void TIMER1_CAPT_ISR (void)
{
	static u8 LocalFlag     = 0                  ;


	if (LocalFlag == 0)
	{
		OFF_Period = ICR1                        ;
		TCCR1B    &= TCCR1B_EDGE_MAST            ;
		TCCR1B   |= T1_INPUT_CAPTURE_FALLING_EDGE;
		LocalFlag = 1                            ;
	}
	else if (LocalFlag == 1 )
	{
		TCNT1 = 0                                 ;
		ALL_Period = ICR1                         ;

		TCCR1B   &= TCCR1B_EDGE_MAST             ;
		TCCR1B   |= T1_INPUT_CAPTURE_RISING_EDGE ;

		LocalFlag = 0                            ;

		if( TIMER_pvCallBack_Func[TIMER1_INTERRUPT_INPUT_CAPTURE]!=NULL)
		{
			TIMER_pvCallBack_Func[TIMER1_INTERRUPT_INPUT_CAPTURE]();
		}

	}


}




void TIMER1_COMPA_ISR (void)  __attribute__((signal,__INTR_ATTRS));
void TIMER1_COMPA_ISR (void)
{
	static u32 CompareA = 0;
	CompareA ++;
	if (CompareA == NUM_COMPARE_MATCH_A)
	{
		CompareA = 0;
		if(TIMER_pvCallBack_Func[TIMER1_INTERRUPT_COMPARE_MATCH_A]!=NULL)
		{
			TIMER_pvCallBack_Func[TIMER1_INTERRUPT_COMPARE_MATCH_A]();
		}
	}

}





void TIMER1_OVF_ISR (void)  __attribute__((signal,__INTR_ATTRS));
void TIMER1_OVF_ISR (void)
{
	static u32 Num_OV = 0;
	Num_OV ++;
	if (Num_OV == NUM_OVER_FLOW)
	{
		Num_OV = 0;
		if(TIMER_pvCallBack_Func[TIMER1_INTERRUPT_OVER_FLOW]!=NULL)
		{
			TIMER_pvCallBack_Func[TIMER1_INTERRUPT_OVER_FLOW]();
		}
	}

}

void TIMER1_COMPB_ISR (void)  __attribute__((signal,__INTR_ATTRS));
void TIMER1_COMPB_ISR (void)
{
	static u32 CompareB = 0;
	CompareB ++;
	if (CompareB == NUM_COMPARE_MATCH_B)
	{
		CompareB = 0;
		if(TIMER_pvCallBack_Func[TIMER1_INTERRUPT_COMPARE_MATCH_B]!=NULL)
		{
			TIMER_pvCallBack_Func[TIMER1_INTERRUPT_COMPARE_MATCH_B]();
		}
	}

}

