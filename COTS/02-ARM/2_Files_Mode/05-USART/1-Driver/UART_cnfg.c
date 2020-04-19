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
				.Mode        = UART_MODE             ,
				.DateSize    = UART_CR1_DATA_BITS_NUM,
				.StopBit     = UART_CR2_STOP_BIT     ,
				.BaudRate    = UART_BAUDRATE_4800
		},
		{
				.Parity      = UART_CR1_PARITY_STATE ,
				.Mode        = UART_MODE             ,
				.DateSize    = UART_CR1_DATA_BITS_NUM,
				.StopBit     = UART_CR2_STOP_BIT     ,
				.BaudRate    = UART_BAUDRATE_9600
		},
		{
				.Parity      = UART_CR1_PARITY_STATE ,
				.Mode        = UART_MODE             ,
				.DateSize    = UART_CR1_DATA_BITS_NUM,
				.StopBit     = UART_CR2_STOP_BIT     ,
				.BaudRate    = UART_BAUDRATE_9600
		}


};


UART_CFG_t* Get_UART_CnfStruct(void)
{
	return 	UART_cfg;
}



