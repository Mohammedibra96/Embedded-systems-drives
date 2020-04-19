/**********************************************************************************************
Author :Mohamed Ibrahem
Version:1.0
Date:12 April 2020
Description:This Source file is used to interface with the UART module in STM32f10x evaluation kit
 ***********************************************************************************************/
#include "STD_TYPES.h"
#include "UART_interface.h"
#include "UART_cnfg.h"
#include "DMA_interface.h"


#define 	UART_INIT_CONFIG		UART_CR1_ENABLED | UART_TRANSMIT_ENABLE | UART_RECIEVE_ENABLE

typedef struct
{
	u32 SR;
	u32 DR;
	u32 BRR;
	u32 CR1;
	u32 CR2;
	u32 CR3;
	u32 GTPR;
}UART_t;

typedef struct
{
	u8* data;
	u16 size;
	u16 position;
	u8 state;
}UART_data_t;

UART_data_t UART_TxBuffer;
UART_data_t UART_RxBuffer;


/*Array of call back function for transmit */
void (*UART_EndOfJobNotification_Tx[UART_MODULES_NUM])(void);
/*Array of call back function for receive */
void (*UART_EndOfJobNotification_Rx[UART_MODULES_NUM])(void);

/*Array of UART base addresses */
const uint32_t Uart_Address[UART_MODULES_NUM] = {
		0x40013800,
		0x40004400,
		0x40004800,
};

const uint32_t Uart_DMA_TX[UART_MODULES_NUM] = {
		DMA_CHANNEL_4,
		DMA_CHANNEL_7,
		DMA_CHANNEL_2
};

const uint32_t Uart_DMA_RX[UART_MODULES_NUM] = {
		DMA_CHANNEL_5,
		DMA_CHANNEL_6,
		DMA_CHANNEL_3
};








void UART_voidInitStruct(UART_CFG_t UART_cfg,u32 UART_CHANNEL,u32 sysClk)
{
	volatile UART_t* UART = ((volatile UART_t*)Uart_Address[UART_CHANNEL]);
	f64 tmpBaudRate = ((f64)sysClk / ((f64)UART_cfg.BaudRate * 16.0));
	/* Clear Baudrate Register and set the mantissa */
	UART->BRR = ((uint32_t)(tmpBaudRate)) << 4;
	/* Setting the fraction */
	UART->BRR |= (uint32_t)((tmpBaudRate - (f64)((uint32_t)tmpBaudRate))*16.0);
	/* Setting the parity bit */


	//UART->BRR=UART_cfg.BaudRate;
	if (UART_cfg.Mode==UART_MODE_INTERRUPT)
	{
		/*Enable the UART ,configure the data size,configure the parity ,Enable the rx not empty interrupt,Enable the tx and rx in UART */
		UART->CR1 =(UART_cfg.DateSize|UART_cfg.Parity|UART_INIT_CONFIG|UART_INTERRUPT_RXNEIE_ENABLE);
	}
	else
	{
		/*Enable the UART ,configure the data size,configure the parity Enable the tx and rx in UART */
		UART->CR1 =(UART_cfg.DateSize|UART_cfg.Parity|UART_INIT_CONFIG);
	}
	/*Configure number of stop bits */
	UART->CR2 = UART_cfg.StopBit;

}



void UART_IRQHandler(u32 UART_CHANNEL)
{

	volatile UART_t* UART = ((volatile UART_t*)Uart_Address[UART_CHANNEL]);

	if(UART->SR & UART_STATUS_RXNE)
	{
		if(UART_RxBuffer.state == BUSY)
		{
			UART_RxBuffer.position ++;
			UART_RxBuffer.data[UART_RxBuffer.position] = UART->DR;
		}

		if(UART_RxBuffer.position == UART_RxBuffer.size)
		{
			/*reset the data buffer */
			UART_RxBuffer.data = NULL;
			UART_RxBuffer.size = 0;
			UART_RxBuffer.position = 0;
			UART_RxBuffer.state = OK;
			/*Disable the rx not empty  interrupt */
			UART->CR1&=UART_INTERRUPT_RXNEIE_DISABLE;

			if(UART_EndOfJobNotification_Rx[UART_CHANNEL])
				UART_EndOfJobNotification_Rx[UART_CHANNEL]();
		}
	}
	/* */
	if(UART->SR & UART_STATUS_TC)
	{

		/*Disable the transmit complete interrupt */
		UART->SR &=UART_INTERRUPT_TCE_DISABLE;
		/*Call the End of notification call back function */
		if(UART_EndOfJobNotification_Tx[UART_CHANNEL])
			UART_EndOfJobNotification_Tx[UART_CHANNEL]();
	}
	/*transmit the incoming byte in the data buffer*/
	if(UART->SR & UART_STATUS_TXE)
	{
		if(UART_TxBuffer.position < UART_TxBuffer.size)
		{

			UART->DR = UART_TxBuffer.data[UART_TxBuffer.position];
			UART_TxBuffer.position ++;

		}
		else
		{
			/*Rest the data buffer */
			UART_TxBuffer.state = OK;
			UART_TxBuffer.data = NULL;
			UART_TxBuffer.size = 0;
			UART_TxBuffer.position = 0;

			/*Disable transmit empty interrupt */
			UART->CR1&=UART_INTERRUPT_TXE_DISABLE;
			/*Call the End of notification call back function */
			if(UART_EndOfJobNotification_Tx[UART_CHANNEL])
				UART_EndOfJobNotification_Tx[UART_CHANNEL]();
		}

	}

}

u8 UART_errTransmit(u32 UART_CHANNEL,u8* Copy_pu8Data, u16 Copy_u16Size)
{

	volatile UART_t* UART = ((volatile UART_t*)Uart_Address[UART_CHANNEL]);
	u8 Error_s = NULLPOINTER;
#if UART_MODE == UART_MODE_INTERRUPT
	/*Check if the pointer points to NULL */
	if(Copy_pu8Data)
	{
		Error_s = BUSY;
		/*Checkl if the UART is not busy */
		if(UART_TxBuffer.state == OK)
		{
			/*Configure the trasmite data buffer of the  */
			Error_s = OK;
			UART_TxBuffer.state = BUSY;
			UART_TxBuffer.data = Copy_pu8Data;
			UART_TxBuffer.size = Copy_u16Size;
			UART->DR = UART_TxBuffer.data[0];
			UART_TxBuffer.position++;
			/*Enable the transmit empty interrupt */
			UART->CR1|=UART_INTERRUPT_TXE_ENABLE;
		}
	}
#elif UART_MODE == UART_MODE_DMA
	if(Copy_pu8Data)
	{
		Error_s = BUSY;
		if(UART_TxBuffer.state == OK)
		{
			Error_s = OK;

			/*Disable the DMA channel to reset the DMA */
			DMA_disableChannel(Uart_DMA_TX[UART_CHANNEL]);
			/*Disable the transfer complete of the DMA */
			DMA_disableInterrupt(Uart_DMA_TX[UART_CHANNEL],DMA_CCR_INTERRUPT_TCIE);
			/*Enable the transmit using DMA */
			UART->CR3 |= UART_DMA_TRANSMIT_ENABLE;
			/* Configure the peripheral Address of the DMA */
			DMA_setPeripheralAddress(Uart_DMA_TX[UART_CHANNEL],(u32)&(UART->DR));
			/* Configure the Memory Address of the DMA */
			DMA_setMemoryAddress(Uart_DMA_TX[UART_CHANNEL], (u32)Copy_pu8Data);
			/*Configure number of transfer */
			DMA_setNumberOfDataTransfer(Uart_DMA_TX[UART_CHANNEL], Copy_u16Size);
			/*Configure the peripheral size and the memory size ,enable increment in memory and disable the increment in peripheral  */
			DMA_configureChannel(Uart_DMA_TX[UART_CHANNEL],DMA_CCR_PSIZE_8_BITS, DMA_CCR_PINC_DISABLE ,DMA_CCR_MSIZE_8_BITS, DMA_CCR_MINC_ENABLE);
			/*Set the direction of the transfer from the array to DR of the UART */
			DMA_setDirction(Uart_DMA_TX[UART_CHANNEL],DMA_CCR_DIR_FROM_MEMORY);
			/*Enable the transmit complete interrupt */
			UART->CR1|=UART_INTERRUPT_TCE_ENABLE;
			/*Clear the transmit complete */
			UART->SR &= ~UART_STATUS_TC;
			/*Start the transfer */
			DMA_enableChannel(Uart_DMA_TX[UART_CHANNEL]);
		}
	}




#else
#error "UART_MODE is incorrect"

#endif
	return Error_s;
}


u8 UART_errRecieve(u32 UART_CHANNEL,u8* Copy_pu8Data, u16 Copy_u16Size)
{
	volatile UART_t* UART = ((volatile UART_t*)Uart_Address[UART_CHANNEL]);
	u8 Error_s = NULLPOINTER;
#if UART_MODE == UART_MODE_INTERRUPT
	/*Check the pointer points to  NULL */
	if(Copy_pu8Data)
	{
		Error_s = BUSY;
		/*Check if the UART is n't busy */
		if(UART_RxBuffer.state == OK)
		{
			/*Configure the receive data buffer */
			Error_s = OK;
			UART_RxBuffer.state = BUSY;
			UART_RxBuffer.data = Copy_pu8Data;
			UART_RxBuffer.size = Copy_u16Size;
			/*Enable the UART receive not empty interrupt */
			UART->CR1|=UART_INTERRUPT_RXNEIE_ENABLE;

		}
	}

#elif UART_MODE == UART_MODE_DMA
	if(Copy_pu8Data)
	{
		Error_s = BUSY;
		if(UART_TxBuffer.state == OK)
		{
			Error_s = OK;

			/*rest the DMA registers */
			DMA_disableChannel(Uart_DMA_RX[UART_CHANNEL]);
			/*Enable transfer complete of the DMA */
			DMA_enableInterrupt(Uart_DMA_RX[UART_CHANNEL],DMA_CCR_INTERRUPT_TCIE);
			/*Enable receive using DMA */
			UART->CR3 |= UART_DMA_RECIEVE_ENABLE;
			/*Configure the peripheral address to DR of the UART */
			DMA_setPeripheralAddress(Uart_DMA_RX[UART_CHANNEL], (u32)&(UART->DR));
			/*Configure the memory address to the array */
			DMA_setMemoryAddress(Uart_DMA_RX[UART_CHANNEL], (u32)Copy_pu8Data);
			/*Configure number of transfer of the DMA */
			DMA_setNumberOfDataTransfer(Uart_DMA_RX[UART_CHANNEL], Copy_u16Size);
			/*Configure the peripheral size and the memory size ,enable increment in Peripheral  and disable the increment in memory  */
			DMA_configureChannel(Uart_DMA_RX[UART_CHANNEL],DMA_CCR_PSIZE_8_BITS, DMA_CCR_PINC_DISABLE ,DMA_CCR_MSIZE_8_BITS, DMA_CCR_MINC_ENABLE);
			/*Configure the direction the DMA from peripheral to the memory */
			DMA_setDirction(Uart_DMA_RX[UART_CHANNEL],DMA_CCR_DIR_FROM_PERIPHERAL);
			/*Start transfer */
			DMA_enableChannel(Uart_DMA_RX[UART_CHANNEL]);
		}
	}

#else
#error "UART_RECIEVE_MODE is incorrect"

#endif
	return Error_s;
}

u8 UART_errSetCallBackTrans(u32 UART_CHANNEL,UART_callBack_t UART_callBack)
{
	u8 Error_st = NULLPOINTER;

	if(UART_callBack)
	{
		Error_st = OK;
		UART_EndOfJobNotification_Tx[UART_CHANNEL] = UART_callBack;
	}
	return Error_st;

}


u8 UART_errSetCallBackRecieve(u32 UART_CHANNEL, UART_callBack_t UART_callBack)
{
	u8 Error_st = NULLPOINTER;

	if(UART_callBack)
	{
		Error_st = OK;
#if UART_MODE == UART_MODE_INTERRUPT
		UART_EndOfJobNotification_Rx[UART_CHANNEL] = UART_callBack;
#elif UART_MODE == UART_MODE_DMA
		DMA_setCBF_EndOfTransfer(Uart_DMA_RX[UART_CHANNEL],UART_callBack);
#else
#error "UART_SEND_MODE is incorrect"
#endif
	}
	return Error_st;
}

UART_STATUS UART_u16GetStatus(u32 UART_CHANNEL)
{
	volatile UART_t* UART = ((volatile UART_t*)Uart_Address[UART_CHANNEL]);
	return UART->SR;
}


void USART1_IRQHandler(void)
{
	UART_IRQHandler(UART_CHANNEL_1);

}
void USART2_IRQHandler(void)
{
	UART_IRQHandler(UART_CHANNEL_2);
}
void USART3_IRQHandler(void)
{
	UART_IRQHandler(UART_CHANNEL_3);
}

void USART4_IRQHandler(void)
{
	UART_IRQHandler(UART_CHANNEL_4);
}
void USART5_IRQHandler(void)
{
	UART_IRQHandler(UART_CHANNEL_5);
}
