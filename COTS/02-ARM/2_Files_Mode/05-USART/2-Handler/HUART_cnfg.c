/**********************************************************************************************
Author :Mohamed Ibrahem
Version:1.0
Date:5 April 2020
Description:This Source file is used to interface with the HUART module in STM32f10x evaluation kit
***********************************************************************************************/

#include "STD_TYPES.h"
#include"RCC.h"
#include"NVIC_interface.h"
#include"GPIO_interface.h"

#include "UART_interface.h"
#include "UART_cnfg.h"

#include"HRCC_interfac.h"
#include "HUART_interface.h"
#include "HUART_cnfg.h"




#define HRCC_Enable_Prepherial

/************************************
 *
 * USART1: gpio
 * 			RCC
 *
 *
 * #define UART1_GPIO_INPUT_PIN_NUM
 * #define UART1_GPIO_INPUT_PIN_MODE
 * #define UART1_GPIO_INPUT_PORT
 *
 * #define UART1_GPIO_OUTPUT_PIN_NUM
 * #define UART1_GPIO_OUTPUT_PIN_MODE
 * #define UART1_GPIO_OUTPUT_PORT
 *
 *#define UART1_HRCC
 *#define UART1_NVIC
 *
 *
 *
 * *************************************************************************/

HUART_CNFG_t HUART_cnfg[UART_MODULES_NUM]=
{
	{
		.GPIO_Output                      =
		{
				.PIN=UART1_GPIO_OUTPUT_PIN_NUM,
				.MODE=UART_Tx_PIN_MODE,
				.PORT=UART1_GPIO_OUTPUT_PORT,
		},
	    .GPIO_Input                       =
	    {
	    	 .PIN=UART1_GPIO_INPUT_PIN_NUM,
	    	 .MODE=UART_Rx_PIN_MODE,
	    	 .PORT=UART1_GPIO_INPUT_PORT,
	    },
		.HRCC_Enable_Port				  = UART1_HRCC_PORT,
	    .NVIC_Enable_Prepherial_Interrupt = UART1_NVIC,
		.NVIC_DMA_Tx= UART1_NVIC_DMA_TX,
		.NVIC_DMA_Rx=UART1_NVIC_DMA_RX,
		UART1_HRCC_PERIPHERAL,
	},
	{
			.GPIO_Output                      =
			{
					.PIN=UART2_GPIO_OUTPUT_PIN_NUM,
					.MODE=UART_Tx_PIN_MODE,
					.PORT=UART2_GPIO_OUTPUT_PORT,
			},
		    .GPIO_Input                       =
		    {
		    	 .PIN=UART2_GPIO_INPUT_PIN_NUM,
		    	 .MODE=UART_Rx_PIN_MODE,
		    	 .PORT=UART2_GPIO_INPUT_PORT,
		    },
			.HRCC_Enable_Port				  = UART2_HRCC_PORT,
		    .NVIC_Enable_Prepherial_Interrupt = UART2_NVIC,
			.NVIC_DMA_Tx= UART2_NVIC_DMA_TX,
			.NVIC_DMA_Rx=UART2_NVIC_DMA_RX,
			UART2_HRCC_PERIPHERAL,
		},
		{
				.GPIO_Output                      =
				{
						.PIN=UART3_GPIO_OUTPUT_PIN_NUM,
						.MODE=UART_Tx_PIN_MODE,
						.PORT=UART3_GPIO_OUTPUT_PORT,
				},
			    .GPIO_Input                       =
			    {
			    	 .PIN=UART3_GPIO_INPUT_PIN_NUM,
			    	 .MODE=UART_Rx_PIN_MODE,
			    	 .PORT=UART3_GPIO_INPUT_PORT,
			    },
				.HRCC_Enable_Port				  = UART3_HRCC_PORT,
			    .NVIC_Enable_Prepherial_Interrupt = UART3_NVIC,
				.NVIC_DMA_Tx= UART3_NVIC_DMA_TX,
				.NVIC_DMA_Rx=UART3_NVIC_DMA_RX,
				UART3_HRCC_PERIPHERAL,
			}
};







