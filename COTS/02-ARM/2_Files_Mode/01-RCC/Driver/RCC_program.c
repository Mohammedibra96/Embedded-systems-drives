#include"RCC.h"

/*       Private Section                                            */

/*Base Address of RCC Register                                      */
#define  RCC_BASE_ADDRESS  (volatile u32*)0x40021000

typedef struct
{
	u32 CR;
	u32 CFGR;
	u32 CIR;
	u32 APB2RSTR;
	u32 APB1RSTR;
	u32 AHBENR;
	u32 APB2ENR;
	u32 APB1ENR;
	u32 BDCR;
	u32 CSR;

}RCC_t;

RCC_t* RCC= (RCC_t*)RCC_BASE_ADDRESS;





/*This Function shall take 2 argument
CLOCK={CLOCK_HSI,CLOCK_HSE,CLOCK_PLL}
RCC_STATUS={RCC_STATUS_ON,RCC_STATUS_OFF}
Output:
{OK,NOK}
 */

STD_ERROR RCC_SetClock_Status(u32 CLOCK,u32 RCC_STATUS)
{
	STD_ERROR STD_Error=NOK;
	switch(CLOCK)
	{
	case CLOCK_HSI:

		if(RCC_STATUS==RCC_STATUS_ON)
		{
			RCC->CR|=RCC_CR_HSI_ON_MASK;
			STD_Error=OK;
		}
		else if(RCC_STATUS==RCC_STATUS_OFF)
		{
			RCC->CR&=~RCC_CR_HSI_ON_MASK;
			STD_Error=OK;
		}
		break;
	case CLOCK_HSE:
		if(RCC_STATUS==RCC_STATUS_ON)
		{
			RCC->CR|=RCC_CR_HSE_ON_MASK;
			STD_Error=OK;
		}
		else if(RCC_STATUS==RCC_STATUS_OFF)
		{
			RCC->CR&=~RCC_CR_HSE_ON_MASK;
			STD_Error=OK;
		}
		break;
	case CLOCK_PLL:
		if(RCC_STATUS==RCC_STATUS_ON)
		{
			RCC->CR|=RCC_CR_PLL_ON_MASK;
			STD_Error=OK;
		}
		else if(RCC_STATUS==RCC_STATUS_OFF)
		{
			RCC->CR&=~RCC_CR_PLL_ON_MASK;
			STD_Error=OK;
		}
		break;

	}
	return STD_Error;
}


/*This function  shall get the status of the Clock
Inputs: {CLOCK_HSI,CLOCK_HSE,CLOCK_PLL}
Output: {RCC_STATUS_ON,RCC_STATUS_OFF}
to Indicate the Clock is RCC_STATUS_ON or RCC_STATUS_OFF or -1 for Error
 */
u32 RCC_GetClock_Status(u32 CLOCK)
{
	switch(CLOCK)
	{
	case CLOCK_HSI:
		return (RCC->CR &RCC_CR_HSI_RDY_MASK);
	case CLOCK_HSE:
		return RCC->CR &RCC_CR_HSE_RDY_MASK;
	case CLOCK_PLL:
		return RCC->CR &RCC_CR_PLL_RDY_MASK;
	}
	return -1;
}
/*This Function shall Set the status of the CSS 
Inputs:{RCC_STATUS_ON,RCC_STATUS_ON}
Outputs:{OK,NOK}
 */

STD_ERROR RCC_SetCSS_Status(u32 RCC_STATUS)
{
	STD_ERROR STD_Erorr=NOK;
	if(RCC_STATUS==RCC_STATUS_ON)
	{
		RCC->CR|=RCC_CR_CSS_ON_MASK;
		STD_Erorr=OK;
	}
	else if(RCC_STATUS==RCC_STATUS_OFF)
	{
		RCC->CR&=~RCC_CR_CSS_ON_MASK;
		STD_Erorr=OK;
	}
	return STD_Erorr;
}

/*This Function shall Set the status of the HSEBYPASS 
Inputs:{RCC_STATUS_ON,RCC_STATUS_ON}
Outputs:{OK,NOK}
 */
STD_ERROR RCC_SetHSEBYPASS_Status(u32 RCC_STATUS)
{
	STD_ERROR STD_Erorr=NOK;
	if(RCC_STATUS==RCC_STATUS_ON)
	{
		RCC->CR|=RCC_CR_HSEBY_MASK;
		STD_Erorr=OK;
	}
	else if(RCC_STATUS==RCC_STATUS_OFF)
	{
		RCC->CR&=~RCC_CR_HSEBY_MASK;
		STD_Erorr=OK;
	}
	return STD_Erorr;
}


/*This function  shall Set the System Clock 
Inputs:{PRCC_CFGR_SW_HSI,RCC_CFGR_SW_HSE,RCC_CFGR_SW_PLL}
Outputs:{OK,NOK}
*/

STD_ERROR RCC_SetSystemClock(u32 RCC_CFGR_SW)
{
	STD_ERROR Std_Error=OK;
	/*Check for the Input arguments                         */
  if(RCC_CFGR_SW !=RCC_CFGR_SW_HSI && RCC_CFGR_SW !=RCC_CFGR_SW_HSE && RCC_CFGR_SW !=RCC_CFGR_SW_PLL)
	{
		Std_Error=NOK;
		return NOK;
	}
	u32 locRCCCFGRCopy=RCC->CFGR;
	/*Clear the bits of SW                                  */
	locRCCCFGRCopy&=RCC_CFGR_SW_MASK;
	/*Set the clk                                           */
	locRCCCFGRCopy|=RCC_CFGR_SW;
	RCC->CFGR=locRCCCFGRCopy;
	return Std_Error;
}

/*This function  shall Get the System Clock 
as a pointer in the input arguments 
Inputs:{CLOCK_HSI,CLOCK_HSE,CLOCK_PLL}
Outputs:{OK,NOK}
*/
STD_ERROR RCC_GetSystemClock(u32 *CLOCK)
{
	STD_ERROR STD_Error=NOK;
	switch(RCC->CFGR & RCC_CFGR_SWS_MASK)
	{
	case RCC_CFGR_SWS_HSI:
		*CLOCK=CLOCK_HSI;
		STD_Error=OK;
		break;
	case RCC_CFGR_SWS_HSE:
		*CLOCK=CLOCK_HSE;
		STD_Error=OK;
		break;
	case RCC_CFGR_SWS_PLL:
		*CLOCK=CLOCK_PLL;
		STD_Error=OK;
		break;
	}
	return STD_Error;
}


/*This Function shall Set the PLL Source 
Inputs:{RCC_CFGR_PLLSRC_HSI_DIV2,RCC_CFGR_PLLSRC_HSE}
Outputs:{OK,NOK}
 */

STD_ERROR RCC_SetPLLSource(u32 RCC_CFGR_PLLSRC)
{
  /*Check the validity of the input arguments */
	if (RCC_CFGR_PLLSRC!=RCC_CFGR_PLLSRC_HSI_DIV2 && RCC_CFGR_PLLSRC!=RCC_CFGR_PLLSRC_HSE)
	{
		return NOK;
	}
	RCC->CFGR |=RCC_CFGR_PLLSRC_MASK;
	RCC->CFGR&=RCC_CFGR_PLLSRC;
	return OK;
}


/*This function shall set the PLL multiplication factor 
Inputs:
RCC_CFGR_PLLMUL_MUL_2
RCC_CFGR_PLLMUL_MUL_3
RCC_CFGR_PLLMUL_MUL_4
RCC_CFGR_PLLMUL_MUL_5
RCC_CFGR_PLLMUL_MUL_6
RCC_CFGR_PLLMUL_MUL_7
RCC_CFGR_PLLMUL_MUL_8
RCC_CFGR_PLLMUL_MUL_9
RCC_CFGR_PLLMUL_MUL_10
RCC_CFGR_PLLMUL_MUL_11
RCC_CFGR_PLLMUL_MUL_12
RCC_CFGR_PLLMUL_MUL_13
RCC_CFGR_PLLMUL_MUL_14
RCC_CFGR_PLLMUL_MUL_15

Outputs:void
 */


void RCC_SetPLLMULL(u32 RCC_CFGR_PLLMUL_MUL)
{
	RCC->CFGR &=RCC_CFGR_PLLMUL_MASK;
	RCC->CFGR|=RCC_CFGR_PLLMUL_MUL;
}


/*This function shall Get the PLL Multiplication factor 
Inputs:{void}
Outputs:{1-16}
*/
u32 RCC_GetPLL_MUL_Factor()
{
	u32 Factor=1;
	u32 LocalCFGR=0;
	LocalCFGR=RCC->CFGR;
	LocalCFGR&=RCC_CFGR_PLLMUL_MUL_16_TOO;
	switch(LocalCFGR)
	{
	case RCC_CFGR_PLLMUL_MUL_2:
		Factor=2;
		break;
	case RCC_CFGR_PLLMUL_MUL_3:
		Factor=3;
		break;
	case RCC_CFGR_PLLMUL_MUL_4:
		Factor=4;
		break;
	case RCC_CFGR_PLLMUL_MUL_5:
		Factor=5;
		break;
	case RCC_CFGR_PLLMUL_MUL_6:
		Factor=6;
		break;
	case RCC_CFGR_PLLMUL_MUL_7:
		Factor=7;
		break;
	case RCC_CFGR_PLLMUL_MUL_8:
		Factor=8;
		break;
	case RCC_CFGR_PLLMUL_MUL_9:
		Factor=9;
		break;
	case RCC_CFGR_PLLMUL_MUL_10:
		Factor=10;
		break;
	case RCC_CFGR_PLLMUL_MUL_11:
		Factor=11;
		break;
	case RCC_CFGR_PLLMUL_MUL_12:
		Factor=12;
		break;
	case RCC_CFGR_PLLMUL_MUL_13:
		Factor=13;
		break;
	case RCC_CFGR_PLLMUL_MUL_14:
		Factor=14;
		break;
	case RCC_CFGR_PLLMUL_MUL_15:
		Factor=15;
		break;
	case RCC_CFGR_PLLMUL_MUL_16:
		Factor=16;
		break;
	}
	return Factor;
}


/*
This function Shall enable or disable a port 
Inputs:{RCC_PORTA,RCC_PORTB,RCC_PORTC}
Output:{OK,NOK}
Status={RCC_STATUS_ON,RCC_STATUS_OFF}
*/


STD_ERROR RCC_SetPortStatus(u32 RCC_PORT,u32 RCC_STATUS)
{
	STD_ERROR STD_Error=NOK;
	switch(RCC_PORT)
	{
	case RCC_PORTA:
		if(RCC_STATUS)
		{
			RCC->APB2ENR |=RCC_APB2ENR_IOPAEN_MAKS;
			STD_Error=OK;
		}
		else
		{
			RCC->APB2ENR &=~RCC_APB2ENR_IOPAEN_MAKS;
			STD_Error=NOK;
		}
		break;
	case RCC_PORTB:
		if(RCC_STATUS)
		{
			RCC->APB2ENR |=RCC_APB2ENR_IOPBEN_MAKS;
			STD_Error=OK;
		}
		else
		{
			RCC->APB2ENR &=~RCC_APB2ENR_IOPBEN_MAKS;
			STD_Error=NOK;
		}
		break;
	case RCC_PORTC:
		if(RCC_STATUS)
		{
			RCC->APB2ENR |=RCC_APB2ENR_IOPCEN_MAKS;
			STD_Error=OK;
		}
		else
		{
			RCC->APB2ENR &=~RCC_APB2ENR_IOPCEN_MAKS;
			STD_Error=NOK;
		}
		break;
	}
	return STD_Error;
}


/*
This function Shall Set the AHP prescaler 
Inputs:
RCC_CFGR_HPRE_SYSCLK_DIVIDED_2
RCC_CFGR_HPRE_SYSCLK_DIVIDED_4
RCC_CFGR_HPRE_SYSCLK_DIVIDED_8
RCC_CFGR_HPRE_SYSCLK_DIVIDED_16
RCC_CFGR_HPRE_SYSCLK_DIVIDED_64
RCC_CFGR_HPRE_SYSCLK_DIVIDED_128
RCC_CFGR_HPRE_SYSCLK_DIVIDED_256
RCC_CFGR_HPRE_SYSCLK_DIVIDED_512

Output:{OK,NOK}
 */


STD_ERROR RCC_SetAHP_Prescaler(u32 RCC_CFGR_HPRE)
{
	u32 LocalError=OK;
	/*Check the validity of the input              */

	if(RCC_CFGR_HPRE!=RCC_CFGR_HPRE_SYSCLK_NOT_DIVIDED
			&&RCC_CFGR_HPRE!=RCC_CFGR_HPRE_SYSCLK_DIVIDED_2
			&&RCC_CFGR_HPRE!=RCC_CFGR_HPRE_SYSCLK_DIVIDED_4
			&&RCC_CFGR_HPRE!=RCC_CFGR_HPRE_SYSCLK_DIVIDED_8
			&&RCC_CFGR_HPRE!=RCC_CFGR_HPRE_SYSCLK_DIVIDED_16
			&&RCC_CFGR_HPRE!=RCC_CFGR_HPRE_SYSCLK_DIVIDED_64
			&&RCC_CFGR_HPRE!=RCC_CFGR_HPRE_SYSCLK_DIVIDED_128
			&&RCC_CFGR_HPRE!=RCC_CFGR_HPRE_SYSCLK_DIVIDED_256
			&&RCC_CFGR_HPRE!=RCC_CFGR_HPRE_SYSCLK_DIVIDED_512)
	{
		LocalError=NOK;
	}
	else
	{
		u32 LocalCFGR=RCC->CFGR;
		/*Clear the HPRE bits for                       */
		LocalCFGR&=RCC_CFGR_HPRE_MASK;
		/*Update the Register by the new value          */
		RCC->CFGR|=RCC_CFGR_HPRE;
	}
	return LocalError;
}


/*This Function shall Get the AHP prescaler
Inputs:void
Outputs:
RCC_CFGR_HPRE_SYSCLK_DIVIDED_2
RCC_CFGR_HPRE_SYSCLK_DIVIDED_4
RCC_CFGR_HPRE_SYSCLK_DIVIDED_8
RCC_CFGR_HPRE_SYSCLK_DIVIDED_16
RCC_CFGR_HPRE_SYSCLK_DIVIDED_64
RCC_CFGR_HPRE_SYSCLK_DIVIDED_128
RCC_CFGR_HPRE_SYSCLK_DIVIDED_256
RCC_CFGR_HPRE_SYSCLK_DIVIDED_512

*/
u32 RCC_GetAHP_Prescaler()
{
	u32 LocalCFGR=RCC->CFGR;
	LocalCFGR&=~RCC_CFGR_HPRE_MASK;
	return LocalCFGR;
}




/*
This function Shall Set the APB1 prescaler 
Inputs:
RCC_CFGR_PPRE1_HCLK_NOT_DIVIDED
RCC_CFGR_PPRE1_HCLK_DIVIDED_2
RCC_CFGR_PPRE1_HCLK_DIVIDED_4
RCC_CFGR_PPRE1_HCLK_DIVIDED_8
RCC_CFGR_PPRE1_HCLK_DIVIDED_16

Output:{OK,NOK}
 */



STD_ERROR RCC_SetAPB1_Prescaler(u32 RCC_CFGR_PPRE1_HCLK)
{
	u32 LocalError=OK;
	/*Check the validity of the input              */
	if(
			RCC_CFGR_PPRE1_HCLK!=  RCC_CFGR_PPRE1_HCLK_NOT_DIVIDED
			&&RCC_CFGR_PPRE1_HCLK!=RCC_CFGR_PPRE1_HCLK_DIVIDED_2
			&&RCC_CFGR_PPRE1_HCLK!=RCC_CFGR_PPRE1_HCLK_DIVIDED_4
			&&RCC_CFGR_PPRE1_HCLK!=RCC_CFGR_PPRE1_HCLK_DIVIDED_8
			&&RCC_CFGR_PPRE1_HCLK!=RCC_CFGR_PPRE1_HCLK_DIVIDED_16
	)
	{
		LocalError=NOK;
	}
	else
	{
		u32 LocalCFGR=RCC->CFGR;
		/*Clear the APB1 bits                           */
		LocalCFGR&=RCC_CFGR_PPRE1_MASK;
		/*Update the Register by the new value          */
		RCC->CFGR|=RCC_CFGR_PPRE1_HCLK;
	}
	return LocalError;
}

/*This Function shall Get the AHP prescaler
Inputs:void
Outputs:
RCC_CFGR_PPRE1_HCLK_NOT_DIVIDED
RCC_CFGR_PPRE1_HCLK_DIVIDED_2
RCC_CFGR_PPRE1_HCLK_DIVIDED_4
RCC_CFGR_PPRE1_HCLK_DIVIDED_8
RCC_CFGR_PPRE1_HCLK_DIVIDED_16
*/

u32 RCC_GetAPB1_Prescaler()
{
	u32 LocalCFGR=RCC->CFGR;
	LocalCFGR&=~RCC_CFGR_PPRE1_MASK;
	return LocalCFGR;
}
/*This Function shall set the AHP prescaler
Inputs:
RCC_CFGR_PPRE2_HCLK_NOT_DIVIDED
RCC_CFGR_PPRE2_HCLK_DIVIDED_2
RCC_CFGR_PPRE2_HCLK_DIVIDED_4
RCC_CFGR_PPRE2_HCLK_DIVIDED_8
RCC_CFGR_PPRE2_HCLK_DIVIDED_16

Outputs:{OK,NOK}
*/

STD_ERROR RCC_SetAPB2_Prescaler(u32 RCC_CFGR_PPRE2_HCLK)
{
	u32 LocalError=OK;
	/*Check the validity of the input              */
	if(
			RCC_CFGR_PPRE2_HCLK!=  RCC_CFGR_PPRE2_HCLK_NOT_DIVIDED
			&&RCC_CFGR_PPRE2_HCLK!=RCC_CFGR_PPRE2_HCLK_DIVIDED_2
			&&RCC_CFGR_PPRE2_HCLK!=RCC_CFGR_PPRE2_HCLK_DIVIDED_4
			&&RCC_CFGR_PPRE2_HCLK!=RCC_CFGR_PPRE2_HCLK_DIVIDED_8
			&&RCC_CFGR_PPRE2_HCLK!=RCC_CFGR_PPRE2_HCLK_DIVIDED_16
	)
	{
		LocalError=NOK;
	}
	else
	{
		u32 LocalCFGR=RCC->CFGR;
		/*Clear the APB2 bits                           */
		LocalCFGR&=RCC_CFGR_PPRE2_MASK;
		/*Update the Register by the new value          */
		RCC->CFGR|=RCC_CFGR_PPRE2_HCLK;
	}
	return LocalError;
}



/*This Function shall Get the AHP prescaler
Inputs:void
Outputs:
RCC_CFGR_PPRE2_HCLK_NOT_DIVIDED
RCC_CFGR_PPRE2_HCLK_DIVIDED_2
RCC_CFGR_PPRE2_HCLK_DIVIDED_4
RCC_CFGR_PPRE2_HCLK_DIVIDED_8
RCC_CFGR_PPRE2_HCLK_DIVIDED_16
*/

u32 RCC_GetAPB2_Prescaler()
{
	u32 LocalCFGR=RCC->CFGR;
	LocalCFGR&=~RCC_CFGR_PPRE2_MASK;
	return LocalCFGR;
}


/*This Function shall set the ADC prescaler
Inputs:
RCC_CFGR_ADC_PCLK_DIVIDED_2
RCC_CFGR_ADC_PCLK_DIVIDED_4
RCC_CFGR_ADC_PCLK_DIVIDED_6
RCC_CFGR_ADC_PCLK_DIVIDED_8
Outputs:{OK,NOK}
*/

STD_ERROR RCC_SetADC_Prescaler(u32 RCC_CFGR_ADC_PCLK)
{
	u32 LocalError=OK;
	/*Check the validity of the input              */
	if(
			RCC_CFGR_ADC_PCLK!=  RCC_CFGR_ADC_PCLK_DIVIDED_2
			&&RCC_CFGR_ADC_PCLK!=RCC_CFGR_ADC_PCLK_DIVIDED_4
			&&RCC_CFGR_ADC_PCLK!=RCC_CFGR_ADC_PCLK_DIVIDED_6
			&&RCC_CFGR_ADC_PCLK!=RCC_CFGR_ADC_PCLK_DIVIDED_8
	)
	{
		LocalError=NOK;
	}
	else
	{
		u32 LocalCFGR=RCC->CFGR;
		/*Clear the ADC  bits                           */
		LocalCFGR&=RCC_CFGR_ADC_MASK;
		/*Update the Register by the new value          */
		RCC->CFGR|=RCC_CFGR_ADC_PCLK;
	}
	return LocalError;
}


/*This Function shall set PLL Divisor 
Inputs:{RCC_CFGR_PLLXTPRE_HSE,RCC_CFGR_PLLXTPRE_HSE_DIV2}
Outputs:{OK,NOK}
*/
STD_ERROR RCC_SetPLL_Divisor(u32 RCC_CFGR_PLLXTPRE)
{
	u32 LocalError=OK;
	/*Check the validity of the input              */
	if(
			RCC_CFGR_PLLXTPRE!=  RCC_CFGR_PLLXTPRE_HSE
			&&RCC_CFGR_PLLXTPRE!=RCC_CFGR_PLLXTPRE_HSE_DIV2
	)
	{
		LocalError=NOK;
	}
	else
	{
		u32 LocalCFGR=RCC->CFGR;
		/*Clear the PLL Divisor bits                    */
		LocalCFGR&=RCC_CFGR_PLLXTPRE_MASK;
		/*Update the Register by the new value          */
		RCC->CFGR|=RCC_CFGR_PLLXTPRE;
	}
	return LocalError;


}

/*This function shall Set USB Prescaler 
Inputs:{RCC_CFGR_USBPRE_PLL_DIV_1_5,RCC_CFGR_USBPRE_PLL_NOT_DIV}
Outputs:{OK,NOK}
*/
STD_ERROR RCC_SetUSB_Prescaler(u32 RCC_CFGR_USBPRE_PLL)
{
	u32 LocalError=OK;
	/*Check the validity of the input              */
	if(
			RCC_CFGR_USBPRE_PLL!=  RCC_CFGR_USBPRE_PLL_DIV_1_5
			&&RCC_CFGR_USBPRE_PLL!=RCC_CFGR_USBPRE_PLL_NOT_DIV

	)
	{
		LocalError=NOK;
	}
	else
	{
		u32 LocalCFGR=RCC->CFGR;
		/*Clear the USB prescaler bits                  */
		LocalCFGR&=RCC_CFGR_USBPRE_MASK;
		/*Update the Register by the new value          */
		RCC->CFGR|=RCC_CFGR_USBPRE_PLL;
	}
	return LocalError;
}

/*This Function shall set MCO source 
Inputs:
RCC_CFGR_MCO_SYSCLK
RCC_CFGR_MCO_HSI
RCC_CFGR_MCO_HSE
RCC_CFGR_MCO_PLL
Outputs:{OK,NOK}
*/

STD_ERROR RCC_SetMCO(u32 RCC_CFGR_MCO)
{
	u32 LocalError=OK;
	/*Check the validity of the input              */
	if(
			RCC_CFGR_MCO!=  RCC_CFGR_MCO_SYSCLK
			&&RCC_CFGR_MCO!=RCC_CFGR_MCO_HSI
			&&RCC_CFGR_MCO!=RCC_CFGR_MCO_HSE
			&&RCC_CFGR_MCO!=RCC_CFGR_MCO_PLL
	)
	{
		LocalError=NOK;
	}
	else
	{
		u32 LocalCFGR=RCC->CFGR;
		/*Clear the MCO bits                           */
		LocalCFGR&=RCC_CFGR_MCO_MASK;
		/*Update the Register by the new value          */
		RCC->CFGR|=RCC_CFGR_MCO;
	}
	return LocalError;
}







STD_ERROR RCC_EnableAHP_PeripheralClock(u32 RCC_AHBENR )
{
  STD_ERROR LocalError=OK;
 if(RCC_AHBENR>=0x800)
 {
   LocalError=NOT_VALID_INPUTS;
 } 
else 
{
  RCC->AHBENR|=RCC_AHBENR;
}  
  return LocalError;
}


STD_ERROR RCC_DisableAHP_PeripheralClock(u32 RCC_AHBENR)
{
  STD_ERROR LocalError=OK;
 if(RCC_AHBENR>=0x800)
 {
   LocalError=NOT_VALID_INPUTS;
 } 
else 
{
  RCC->AHBENR&=~RCC_AHBENR;
}  
  return LocalError;
}


STD_ERROR RCC_EnableAPB1_PeripheralClock(u32 RCC_APB1ENR )
{
  STD_ERROR LocalError=OK;
 if(RCC_APB1ENR>=0x40000000)
 {
   LocalError=NOT_VALID_INPUTS;
 } 
else 
{
  RCC->APB1ENR|=RCC_APB1ENR;
}  
  return LocalError;
}

STD_ERROR RCC_DisableAPB1_PeripheralClock(u32 RCC_APB1ENR)
{
  STD_ERROR LocalError=OK;
 if(RCC_APB1ENR>=0x40000000)
 {
   LocalError=NOT_VALID_INPUTS;
 } 
else 
{
  RCC->APB1ENR&=!RCC_APB1ENR;
}  
  return LocalError;
}


STD_ERROR RCC_EnableAPB2_PeripheralClock(u32 RCC_APB2ENR )
{
  STD_ERROR LocalError=OK;
 if(RCC_APB2ENR>=0x400000)
 {
   LocalError=NOT_VALID_INPUTS;
 } 
else 
{
  RCC->APB2ENR|=RCC_APB2ENR;
}  
  return LocalError;
}


STD_ERROR RCC_DisableAPB2_PeripheralClock(u32 RCC_APB2ENR)
{
 STD_ERROR LocalError=OK;
 if(RCC_APB2ENR>=0x400000)
 {
   LocalError=NOT_VALID_INPUTS;
 } 
else 
{
  RCC->APB2ENR&=~RCC_APB2ENR;
}  
  return LocalError;
}
/*Thsi function shall Get AHP Speed in hz
Inputs:{void}
Outputs:{u32}Speed of AHP in hz
*/
u32 RCC_GetAHP_Speed()
{
	u32 Speed=0;
	u32 CLK;
	u32 PLLSRC;
	u32 PLLDivider=1;
	RCC_GetSystemClock(&CLK);
	switch(CLK)
	{
	case CLOCK_HSI:
		Speed=INTERNAL_CLK_SPEED;
		break;
	case CLOCK_HSE:
		Speed=EXTERNAL_CLK_SPEED;
		//trace_printf("%d",Speed);
		break;
	case CLOCK_PLL:
		PLLSRC=RCC->CFGR;
		PLLSRC&=~RCC_CFGR_PLLSRC_MASK;

		PLLDivider=RCC->CFGR;
		if(PLLSRC & RCC_CFGR_PLLSRC_HSI_DIV2)
		{
			Speed=INTERNAL_CLK_SPEED/2;
		}
		else
		{
			Speed=EXTERNAL_CLK_SPEED;
		//	trace_printf("%d",Speed);
			if(PLLDivider&RCC_CFGR_PLLXTPRE_HSE_DIV2)
			{
				Speed/=2;
	//			trace_printf("%d",Speed);
			}
		}
		u32 PLL_MUL_Factor=RCC_GetPLL_MUL_Factor();
		Speed*=PLL_MUL_Factor;
//		trace_printf("%d",Speed);
		break;
	}

	u32 Prescaler=RCC_GetAHP_Prescaler();
	u32 Factor=1;
	switch (Prescaler)
	{
	case RCC_CFGR_HPRE_SYSCLK_DIVIDED_2:
		Factor=2;
		break;
	case RCC_CFGR_HPRE_SYSCLK_DIVIDED_4:
		Factor=4;
		break;
	case RCC_CFGR_HPRE_SYSCLK_DIVIDED_8:
		Factor=8;
		break;
	case RCC_CFGR_HPRE_SYSCLK_DIVIDED_16:
		Factor=16;
		break;
	case RCC_CFGR_HPRE_SYSCLK_DIVIDED_64:
		Factor=64;
		break;
	case RCC_CFGR_HPRE_SYSCLK_DIVIDED_128:
		Factor=128;
		break;
	case RCC_CFGR_HPRE_SYSCLK_DIVIDED_256:
		Factor=256;
		break;
	case RCC_CFGR_HPRE_SYSCLK_DIVIDED_512:
		Factor=512;
		break;
	}
	Speed/=Factor;
	trace_printf("%d",Speed);
	return Speed;
}


