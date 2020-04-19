#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "STK_interfac.h"
#include "STK_config.h"
#include"RCC.h"



/*this mask to Enable the timer                  */
#define STK_ENABLE_MASK             0x00000001
/*mask for Enable interrupt                      */
#define STK_ENABLE_INTERRUPT_MASK   0x00000002
/*mask for flag indicates that timer reased zero */
#define STK_FLAG_MASK   0x00000010

#define STK_CLK_SOURCE_MASK         0xFFFFFFFB


typedef struct
{
	u32 CTRL;
	u32 LOAD;
	u32 VAL;
	u32 CALIB;
}STK_t;

#define STK_BASE_ADDRESS      ((volatile u32*)0xE000E010)
//#define STK                   (STK_t*)STK_BASE_ADDRESS
STK_t* STK=(STK_t*)STK_BASE_ADDRESS;

/*Call Back Function For Systick timer*/
static void(*STKCallBackFunc)(void);


void STK_voidInit(void)
{
	/*Configure Prescaler  AHP or AHP/8    */
#if CLK_SOURCE==STK_CLK_SOURCE_AHP
	STK->CTRL|=STK_CLK_SOURCE_AHP;
#elif CLK_SOURCE==STK_CLK_SOURCE_AHP_DIV8
	STK->CTRL&=~STK_CLK_SOURCE_AHP;
#endif
	/*Enable Interrupt                     */
	STK->CTRL|=STK_ENABLE_INTERRUPT_MASK;

}

void STK_voidStart()
{
	STK->CTRL|=STK_ENABLE_MASK;
}
void STK_voidStop()
{
	STK->CTRL&=~STK_ENABLE_MASK;
}
STD_ERROR STK_voidSetCallBack(void(*Copy_ptr)(void))
{
	STD_ERROR LocalError=NOK;
	if(Copy_ptr!=NULL)
	{
		STKCallBackFunc=Copy_ptr;
		LocalError=OK;
	}
	return LocalError;
}


void SysTick_Handler(void)
{
	if(STKCallBackFunc)
		STKCallBackFunc();
}

STD_ERROR STK_SetTimer_usec(u32 Time_us,u32 AHP_CLK)
{
	STD_ERROR LocalError=OK;
	u32 STK_Clock=AHP_CLK/1000;
	u32 LocalCtrl=STK->CTRL;
	if(LocalCtrl&STK_CLK_SOURCE_AHP)
	{
		STK_Clock=AHP_CLK;
	}
	else
	{
		STK_Clock=AHP_CLK/8;
	}
	u32 Load=(Time_us*STK_Clock)/1000;
	if(Load>=0x0FFFFFFF)
	{
		LocalError=NOK;;
	}
	else
	{
		STK->LOAD=Load;
		STK->VAL=0;
		trace_printf("%d",Load);
	}
	return LocalError;
}




STD_ERROR STK_SetSourceClk(u32 STK_CLK_SOURCE)
{
	STD_ERROR localErr=OK;
	if(STK_CLK_SOURCE !=STK_CLK_SOURCE_AHP && STK_CLK_SOURCE !=STK_CLK_SOURCE_AHP_DIV8)
	{
		localErr=NOT_VALID_INPUTS;
	}
	else
	{
		u32 LocalCotrol=STK->CTRL;
		LocalCotrol&=STK_CLK_SOURCE;
		STK->CTRL|=STK_CLK_SOURCE;
	}
	return localErr;
}
