/**********************************************************************************************
Author :Mohamed Ibrahem
Version:1.0
Date:12 April 2020
Description:This Source file is used to interface with the UART module in STM32f10x evaluation kit
 ***********************************************************************************************/
#include "STD_TYPES.h"
#include "UART_interface.h"
#include "UART_cnfg.h"



const UART_CFG_t UART_cfg [UART_MODULES_NUM]={
		{
				.Parity      = UART_CR1_PARITY_STATE ,
				.TX_Mode     = UART_CH1_TX_MODE          ,
				.RX_Mode     = UART_CH1_RX_MODE          ,
				.DateSize    = UART_CR1_DATA_BITS_NUM,
				.StopBit     = UART_CR2_STOP_BIT     ,
				.LINstate 	 = UART_LIN_ENABLE		 ,
				.BaudRate    = UART_BAUDRATE_4800
		},

		{
				.Parity      = UART_CR1_PARITY_STATE ,
				.TX_Mode     = UART_CH2_TX_MODE          ,
				.RX_Mode     = UART_CH2_RX_MODE          ,
				.DateSize    = UART_CR1_DATA_BITS_NUM,
				.StopBit     = UART_CR2_STOP_BIT     ,
				.LINstate 	 = UART_LIN_ENABLE		 ,
				.BaudRate    = UART_BAUDRATE_4800
		},

		{
				.Parity      = UART_CR1_PARITY_STATE ,
				.TX_Mode     = UART_CH3_TX_MODE          ,
				.RX_Mode     = UART_CH3_RX_MODE          ,
				.DateSize    = UART_CR1_DATA_BITS_NUM,
				.StopBit     = UART_CR2_STOP_BIT     ,
				.LINstate 	 = UART_LIN_ENABLE		 ,
				.BaudRate    = UART_BAUDRATE_4800
		}


};


UART_CFG_t* Get_UART_CnfStruct(u8 UART_CHANNEL)
{
	return 	&UART_cfg[UART_CHANNEL];
}



