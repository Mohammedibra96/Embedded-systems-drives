/**********************************************************************************************
Author :Mohamed Ibrahem
Version:1.0
Date:5 April 2020
Description:This Header file is used to interface with the HUART module in STM32f10x evaluation kit
***********************************************************************************************/
#ifndef HUART_INTERFACE_H
#define HUART_INTERFACE_H




#if UART_AFIO == UART_NOREMAP

#define UART1_PORT		        PORTA
#define	UART1_Tx_PIN			PIN9
#define	UART1_Rx_PIN			PIN10


#elif UART_AFIO == UART_REMAP

#define UART1_PORT			PORTB
#define	UART1_Tx_PIN			PIN6
#define	UART1_Rx_PIN			PIN7

#endif



#define UART2_PORT			    PORTA
#define	UART2_Tx_PIN			PIN2
#define	UART2_Rx_PIN			PIN3



#define UART3_PORT			    PORTB
#define	UART3_Tx_PIN			PIN10
#define	UART3_Rx_PIN			PIN11

/*
#define UART4_PORT			    PORTA
#define	UART4_Tx_PIN			PIN9
#define	UART4_Rx_PIN			PIN10



#define UART5_PORT			    PORTA
#define	UART5_Tx_PIN			PIN9
#define	UART5_Rx_PIN			PIN10


 */



#define UART_Tx_PIN_MODE MODE_OUTPUT_10_AF_PUSHPULL
#define UART_Rx_PIN_MODE MODE_INPUT_PULLUP




/*Configuration for UART1							*/

#define UART1_GPIO_INPUT_PIN_NUM    UART1_Rx_PIN
#define UART1_GPIO_INPUT_PIN_MODE	UART1_Rx_PIN_MODE
#define UART1_GPIO_INPUT_PORT		UART1_PORT

#define UART1_GPIO_OUTPUT_PIN_NUM	UART1_Tx_PIN
#define UART1_GPIO_OUTPUT_PIN_MODE	UART1_Tx_PIN_MODE
#define UART1_GPIO_OUTPUT_PORT		UART1_PORT

#define UART1_HRCC_PERIPHERAL	HRCC_PERIPHERAL_APB2ENR_USART1EN
#define UART1_NVIC  NVIC_USART1
#define UART1_HRCC_PORT	HRCC_PERIPHERAL_APB2ENR_IOPAEN

#define UART1_NVIC_DMA_TX NVIC_DMA1_Channel4
#define UART1_NVIC_DMA_RX NVIC_DMA1_Channel5


/*Configuration for UART2							*/

#define UART2_GPIO_INPUT_PIN_NUM    UART2_Rx_PIN
#define UART2_GPIO_INPUT_PIN_MODE	UART2_Rx_PIN_MODE
#define UART2_GPIO_INPUT_PORT		UART2_PORT

#define UART2_GPIO_OUTPUT_PIN_NUM	UART2_Tx_PIN
#define UART2_GPIO_OUTPUT_PIN_MODE	UART2_Tx_PIN_MODE
#define UART2_GPIO_OUTPUT_PORT		UART2_PORT


#define UART2_HRCC_PERIPHERAL	HRCC_PERIPHERAL_APB1ENR_USART2EN
#define UART2_NVIC  NVIC_USART2
#define UART2_HRCC_PORT	HRCC_PERIPHERAL_APB2ENR_IOPAEN

#define UART2_NVIC_DMA_TX NVIC_DMA1_Channel7
#define UART2_NVIC_DMA_RX NVIC_DMA1_Channel6



/*Configuration for UART3							*/

#define UART3_GPIO_INPUT_PIN_NUM    UART3_Rx_PIN
#define UART3_GPIO_INPUT_PIN_MODE	UART3_Rx_PIN_MODE
#define UART3_GPIO_INPUT_PORT		UART3_PORT

#define UART3_GPIO_OUTPUT_PIN_NUM	UART3_Tx_PIN
#define UART3_GPIO_OUTPUT_PIN_MODE	UART3_Tx_PIN_MODE
#define UART3_GPIO_OUTPUT_PORT		UART3_PORT


#define UART3_HRCC_PERIPHERAL	HRCC_PERIPHERAL_APB1ENR_USART3EN

#define UART3_NVIC  NVIC_USART3
#define UART3_HRCC_PORT	HRCC_PERIPHERAL_APB2ENR_IOPBEN

#define UART3_NVIC_DMA_TX NVIC_DMA1_Channel2
#define UART3_NVIC_DMA_RX NVIC_DMA1_Channel3









#define UART4_HRCC	HRCC_PERIPHERAL_APB1ENR_UART4EN
#define UART4_NVIC  NVIC_UART4






#define UART5_HRCC	HRCC_PERIPHERAL_APB1ENR_UART5EN
#define UART5_NVIC  NVIC_UART5









#include"GPIO_interface.h"


typedef struct
{
	GPIO_PinConfig_t GPIO_Output	      ;
	GPIO_PinConfig_t GPIO_Input		      ;
	u32 HRCC_Enable_Port		          ;
	u8 NVIC_Enable_Prepherial_Interrupt  ;
	u8 NVIC_DMA_Tx						  ;
	u8 NVIC_DMA_Rx						  ;
	u32 HRCC_Enable_Prepherial			  ;
}HUART_CNFG_t;






void HUART_voidInit(u8 UART_CHANNEL);
u8 HUART_errTransmit(u32 UART_CHANNEL,u8* Copy_pu8Data, u16 Copy_u16Size);
u8 HUART_errRecieve(u32 UART_CHANNEL,u8* Copy_pu8Data, u16 Copy_u16ize);



#endif
