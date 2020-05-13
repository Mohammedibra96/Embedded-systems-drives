/**********************************************************************************************
Author :Mohamed Ibrahem
Version:1.0
Date:12 April 2020
Description:This Header file is used to interface with the UART module in STM32f10x evaluation kit
***********************************************************************************************/
#ifndef UART_CNFG_H
#define UART_CNFG_H

/******************************

OPTIONS:
			1-UART_NOREMAP
			2-UART_REMAP

*******************************/
#define	UART_AFIO		UART_NOREMAP



#define UART_MODULES_NUM   3






/***************************************************************
 * Description: This configuration configures the type of parity
 * 				bit in UART Frame
 *
 * Options:
 * 		1- UART_PARITY_EVEN
 * 		2- UART_PARITY_ODD
 * 		3- UART_PARITY_DISABLED
 ***************************************************************/
#define 	UART_CR1_PARITY_STATE		UART_PARITY_DISABLED

/*
 * Description: This configuration configures the mode of the UART
 *OPTIONS:
 *
 * 				UART_MODE_DMA
 * 				UART_MODE_INTERRUPT
 *
 * ***************************/
#define UART_CH1_TX_MODE  UART_MODE_INTERRUPT
#define UART_CH1_RX_MODE  UART_MODE_INTERRUPT

#define UART_CH2_TX_MODE  UART_MODE_INTERRUPT
#define UART_CH2_RX_MODE  UART_MODE_DMA

#define UART_CH3_TX_MODE  UART_MODE_DMA
#define UART_CH3_RX_MODE  UART_MODE_DMA


/***************************************************************
 * Description: This configuration configures the number Data Bits
 *
 * Options:
 * 		1- UART_CR1_DATA_BITS_8
 * 		2- UART_CR1_DATA_BITS_9
 ***************************************************************/
#define 	UART_CR1_DATA_BITS_NUM		UART_CR1_DATA_BITS_8

/***************************************************************
 * Description: This configuration configures the USART Stop bits
 *
 * Options:
 * 		1- UART_CR2_STOP_BIT_1
 * 		2- UART_CR2_STOP_BIT_0_5
 * 		3-UART_CR2_STOP_BIT_2
 * 		4-UART_CR2_STOP_BIT_1_5
 ***************************************************************/

#define UART_CR2_STOP_BIT	           UART_CR2_STOP_BIT_1

/***************************************************************
 * Description: This configuration configures the USART BaudRate
 *
 * Options:
 * 		1- UART_BAUDRATE_8MHZ
 * 		2- UART_BAUDRATE_36MHZ
 ***************************************************************/
/*#define 	UART_BAUDRATE			UART_BAUDRATE_8MHZ   */


/***************************************************************
 * Description: Enable or disable LIN detection
 *
 * Options:
 * 		1- UART_LIN_ENABLE
 * 		2- UART_LIN_DISABLE
 ***************************************************************/

#define UART_LIN_STATE		UART_LIN_ENABLE


/***************************************************************
 * Description: Enable or disable LIN interrupt detection
 *
 * Options:
 * 		1- UART_LIN_BREAK_INTERRUPT_ENABLE
 * 		2- UART_LIN_BREAK_INTERRUPT_DISABLE
 ***************************************************************/

#define	UART_LIN_BREAK_INTERRUPT_STATE	UART_LIN_BREAK_INTERRUPT_ENABLE

/***************************************************************
 * Description: Enable or disable LIN interrupt detection
 *
 * Options:
 * 		1- UART_LIN_BREAK_11_DETECTION
 * 		2- UART_LIN_BREAK_10_DETECTION
 ***************************************************************/


#define UART_LIN_BREAK_LENGTH			UART_LIN_BREAK_11_DETECTION




UART_CFG_t* Get_UART_CnfStruct(u8 UART_CHANNEL);


#endif
