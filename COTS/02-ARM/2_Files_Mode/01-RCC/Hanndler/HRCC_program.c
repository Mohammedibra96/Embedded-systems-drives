#include "STD_TYPES.h"
#include"RCC.h"
#include "HRCC_interfac.h"




#define HRCC_CLOCK_TIME_OUT  10000U



/*This Function to turn on the clock and to check if the ready bit is set or not */
/*Inputs:                                                                 */
/*          1)RCC_CFGR_SW_HSI                                             */
/*          2)RCC_CFGR_SW_HSE                                             */
/*          3)RCC_CFGR_SW_PLL                                             */
/*Output:                                                                 */
/*          1)OK                                                          */
/*          2)NOK                                                         */


static STD_ERROR HRCC_SetClockON(u32 RCC_CFGR_SW)
{
	/*Switch The clock Status to ON                                         */
	RCC_SetClock_Status(RCC_CFGR_SW,RCC_STATUS_ON);
	u32 Counter=0;
	STD_ERROR LocalError=OK;
	/*Check if the Clock is turnned On or Not                               */
	if(RCC_CFGR_SW==RCC_CFGR_SW_HSI)
	{
		/*Timeout mechanism                                                   */
		while(!RCC_GetClock_Status(RCC_CFGR_SW_HSI) && Counter<=HRCC_CLOCK_TIME_OUT)
		{
			Counter++;
		}
	}
	else if(RCC_CFGR_SW==RCC_CFGR_SW_HSE)
	{
		/*Timeout mechanism                                                   */
		while(!RCC_GetClock_Status(RCC_CFGR_SW_HSE) && Counter<=HRCC_CLOCK_TIME_OUT)
		{
			Counter++;
		}
	}
	/*Load the Default Values of the PLL                                   */
	else if(RCC_CFGR_SW_PLL)
	{
		/*Timeout mechanism                                                   */
		while(!RCC_GetClock_Status(RCC_CFGR_SW_PLL) && Counter<=HRCC_CLOCK_TIME_OUT)
		{
			Counter++;
		}
	}
	/*if the argument is not valid                                       */
	else
	{
		LocalError=NOK;
	}
	/*The Clock not ready yet                                            */
	if(Counter>=HRCC_CLOCK_TIME_OUT)
	{
		LocalError=NOK;
	}
	return LocalError;
}

/*This function is used to Set the system Clock to one of three arguments */
/*Inputs:                                                                 */
/*          1)RCC_CFGR_SW_HSI                                             */
/*          2)RCC_CFGR_SW_HSE                                             */
/*          3)RCC_CFGR_SW_PLL                                             */
/*Output:                                                                 */
/*          1)OK                                                          */
/*          2)NOK                                                         */


STD_ERROR HRCC_SetSystemClock(u32 RCC_CFGR_SW)
{
	STD_ERROR LocalError=HRCC_SetClockON(RCC_CFGR_SW);
	if (LocalError==OK)
	{
		LocalError=RCC_SetSystemClock(RCC_CFGR_SW);
	}
	return  LocalError;
}
/*This function is used to Configure the PLL							  */
/*Inputs:   RCC_CFGR_PLLMUL_MUL                                           */
/*          RCC_CFGR_PLLXTPRE                                             */
/*			RCC_CFGR_PLLSRC						  						*/
/*Output:                                                                 */
/*          1)OK                                                          */
/*          2)NOK                                                         */



STD_ERROR HRCC_ConfigurePLL(u32 RCC_CFGR_PLLSRC,u32 RCC_CFGR_PLLMUL_MUL,u32 RCC_CFGR_PLLXTPRE )
{
	STD_ERROR LocalError=OK;
	/*Set the system Clock to HSI before changing the Clock to PLL          */
	LocalError=HRCC_SetSystemClock(RCC_CFGR_SW_HSI);

	if(LocalError==OK)
	{
		/*Turn Off the PLL                                                   */
		RCC_SetClock_Status(RCC_CFGR_SW_PLL,RCC_STATUS_OFF);

		/*Turn on the Source Clock of the PLL                                 */
		if(RCC_CFGR_PLLSRC==RCC_CFGR_PLLSRC_HSI_DIV2)
		{
			LocalError=HRCC_SetClockON(RCC_CFGR_SW_HSI);
		}
		else if(RCC_CFGR_PLLSRC==RCC_CFGR_PLLSRC_HSE)
		{
			LocalError=HRCC_SetClockON(RCC_CFGR_SW_HSE);
		}
		else
		{
			LocalError=NOK;
		}
	}
	/*Set the PLLON Bit                                                          */
	if (LocalError==OK)
	{
		LocalError=RCC_SetPLLSource(RCC_CFGR_PLLSRC);
	}
	if(LocalError==OK && RCC_CFGR_PLLSRC==RCC_CFGR_PLLSRC_HSE)
	{
		/*Set the PLL Divisor												  */
		RCC_SetPLL_Divisor(RCC_CFGR_PLLXTPRE);
	}
	if(LocalError==OK)
	{
		/*Set the Mul factor                                                  */
		RCC_SetPLLMULL(RCC_CFGR_PLLMUL_MUL);
	}
	if (LocalError==OK)
	{
		/*turn on the PLL                                                         */
		RCC_SetClock_Status(CLOCK_PLL,RCC_STATUS_ON);
	}
	return LocalError;
}

/*This fuction shall Enaable the clook for a specific peripheral */
/*Inputs:HRCC_PERIPHERAL_x_y
 * such that x the bus and y is the Peripheral														*/
/*Outputs:STD_ERROR												*/

STD_ERROR HRCC_EnablePeripheral(u32 HRCC_PERIPHERAL)
{
	STD_ERROR LocalError=OK;
	u32 Local=HRCC_PERIPHERAL & 0xC0000000;
	if(Local ==0xC0000000) /*AHP*/
	{
		RCC_EnableAHP_PeripheralClock(HRCC_PERIPHERAL&0x3FFFFFFF);
	}
	else if(Local== 0x40000000)/*APB1*/
	{
		RCC_EnableAPB1_PeripheralClock(HRCC_PERIPHERAL&0x3FFFFFFF);
	}
	else if(Local ==0x80000000)/*APB2*/
	{
		RCC_EnableAPB2_PeripheralClock(HRCC_PERIPHERAL&0x3FFFFFFF);
	}

	else
	{
		LocalError=NOK;
	}
	return LocalError;
}

/*This fuction shall Diable the clook for a specific peripheral */
/*Inputs:HRCC_PERIPHERAL_x_y
 * such that x the bus and y is the Peripheral														*/
/*Outputs:STD_ERROR												*/



STD_ERROR HRCC_DisablePeripheral(u32 HRCC_PERIPHERAL)
{
	STD_ERROR LocalError=OK;
	u32 Local=HRCC_PERIPHERAL & 0xC0000000;
	if(Local ==0xC0000000) /*AHP*/
	{
		RCC_DisableAHP_PeripheralClock(HRCC_PERIPHERAL&0x3FFFFFFF);
	}
	else if(Local== 0x40000000)/*APB1*/
	{
		RCC_DisableAPB1_PeripheralClock(HRCC_PERIPHERAL&0x3FFFFFFF);
	}
	else if(Local ==0x80000000)/*APB2*/
	{
		RCC_DisableAPB2_PeripheralClock(HRCC_PERIPHERAL&0x3FFFFFFF);
	}

	else
	{
		LocalError=NOK;
	}
	return LocalError;
}
/*This function shall set specific clock rate to the system clock  */
/*Inputs:
			HRCC_CLOCK_X_Y

 */
/*Outputs:STD_ERROR														   */

STD_ERROR HRCC_SetSysClock(u32 HRCC_CLOCK )
{
	STD_ERROR LocalError=OK;
	u32 Local=HRCC_CLOCK&0x80000000;

	if(HRCC_CLOCK==HRCC_CLOCK_8_MHZ_ENTERNAL )
	{
		HRCC_SetSystemClock(RCC_CFGR_SW_HSE);
	}
	else if(HRCC_CLOCK==HRCC_CLOCK_8_MHZ_INTERNAL)
	{
		HRCC_SetSystemClock(RCC_CFGR_SW_HSI);
	}
	else
	{
		if(Local==0)
		{
			LocalError=HRCC_ConfigurePLL(RCC_CFGR_PLLSRC_HSE,HRCC_CLOCK,RCC_CFGR_PLLXTPRE_HSE_DIV2);
		}
		else
		{
			LocalError=HRCC_ConfigurePLL(RCC_CFGR_PLLSRC_HSE,HRCC_CLOCK,RCC_CFGR_PLLXTPRE_HSE);
		}
		HRCC_SetSystemClock(RCC_CFGR_SW_PLL);

	}
	return LocalError;

}


u32 HRCC_GetAPB1_Speed(void)
{
	u32 speed=RCC_GetAHP_Speed();


	switch (RCC_GetAHP_Prescaler())
	{
	case RCC_CFGR_HPRE_SYSCLK_DIVIDED_2:
		speed/=2;
		break;
	case RCC_CFGR_HPRE_SYSCLK_DIVIDED_4:
		speed/=4;
		break;
	case RCC_CFGR_HPRE_SYSCLK_DIVIDED_8:
		speed/=8;
		break;
	case RCC_CFGR_HPRE_SYSCLK_DIVIDED_16:
		speed/=16;
		break;
	case RCC_CFGR_HPRE_SYSCLK_DIVIDED_64:
		speed/=64;
		break;
	case RCC_CFGR_HPRE_SYSCLK_DIVIDED_128:
		speed/=128;
		break;
	case RCC_CFGR_HPRE_SYSCLK_DIVIDED_256:
		speed/=256;
		break;
	case RCC_CFGR_HPRE_SYSCLK_DIVIDED_512:
		speed/=512;
		break;
	}
	switch (RCC_GetAPB1_Prescaler())
	{
	case RCC_CFGR_PPRE1_HCLK_DIVIDED_2:
		speed/=2;
		break;
	case RCC_CFGR_PPRE1_HCLK_DIVIDED_4:
		speed/=4;
		break;
	case RCC_CFGR_PPRE1_HCLK_DIVIDED_8:
		speed/=8;
		break;

	case RCC_CFGR_PPRE1_HCLK_DIVIDED_16:
		speed/=16;
		break;
	}
	/*trace_printf("%d",speed);*/
	return speed;

}

u32 HRCC_GetAPB2_Speed(void)
{
	u32 speed=RCC_GetAHP_Speed();


	switch (RCC_GetAHP_Prescaler())
	{
	case RCC_CFGR_HPRE_SYSCLK_DIVIDED_2:
		speed/=2;
		break;
	case RCC_CFGR_HPRE_SYSCLK_DIVIDED_4:
		speed/=4;
		break;
	case RCC_CFGR_HPRE_SYSCLK_DIVIDED_8:
		speed/=8;
		break;
	case RCC_CFGR_HPRE_SYSCLK_DIVIDED_16:
		speed/=16;
		break;
	case RCC_CFGR_HPRE_SYSCLK_DIVIDED_64:
		speed/=64;
		break;
	case RCC_CFGR_HPRE_SYSCLK_DIVIDED_128:
		speed/=128;
		break;
	case RCC_CFGR_HPRE_SYSCLK_DIVIDED_256:
		speed/=256;
		break;
	case RCC_CFGR_HPRE_SYSCLK_DIVIDED_512:
		speed/=512;
		break;
	}
	switch (RCC_GetAPB2_Prescaler())
	{
	case RCC_CFGR_PPRE2_HCLK_DIVIDED_2:
		speed/=2;
		break;
	case RCC_CFGR_PPRE2_HCLK_DIVIDED_4:
		speed/=4;
		break;
	case RCC_CFGR_PPRE2_HCLK_DIVIDED_8:
		speed/=8;
		break;

	case RCC_CFGR_PPRE2_HCLK_DIVIDED_16:
		speed/=16;
		break;
	}
	/*trace_printf("%d",speed);*/
	return speed;

}








