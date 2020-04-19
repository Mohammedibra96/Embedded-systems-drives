/**********************************************************************************************
Author :Mohamed Ibrahem
Version:1.0
Date:12 April 2020
Description:This Header file is used to interface with the UART module in STM32f10x evaluation kit
 ***********************************************************************************************/
#ifndef UART_INTERFACE_H
#define UART_INTERFACE_H



#define UART_CHANNEL_1	0
#define UART_CHANNEL_2	1
#define UART_CHANNEL_3	2
#define UART_CHANNEL_4	3
#define UART_CHANNEL_5	4






/*================================================== General #Defines ==================================================*/

#define UART_NOREMAP			0
#define UART_REMAP				1

/*
#define	UART_BAUDRATE_8MHZ								0x341
#define	UART_BAUDRATE_36MHZ								0xEA6
#define	UART_BAUDRATE_72MHZ								0x1D4C
 */



#define	UART_BAUDRATE_110			u32(110)
#define	UART_BAUDRATE_300			u32(300)
#define	UART_BAUDRATE_600		    u32(600)
#define	UART_BAUDRATE_1200		u32(1200)
#define	UART_BAUDRATE_2400		u32(2400)
#define	UART_BAUDRATE_4800		(4800)
#define	UART_BAUDRATE_9600		(9600)
#define	UART_BAUDRATE_14400		u32(14400)
#define	UART_BAUDRATE_19200		u32(19200)
#define	UART_BAUDRATE_38400		u32(38400)
#define	UART_BAUDRATE_57600		u32(57500)
#define	UART_BAUDRATE_115200		(115200)













#define	UART_CR1_ENABLED								0x00002000
/*TODO: Anis has added that next line*/
#define UART_CR1_DISABLED								0xFFFFDFFF

/*TODO: Set the clear value*/
#define	UART_CR1_DATA_BITS_8									0x00000000
#define	UART_CR1_DATA_BITS_9									0X00001000





#define	UART_PARITY_DISABLED							0x00000000
#define	UART_PARITY_EVEN								0x00000400
#define	UART_PARITY_ODD									0x00000600


#define	UART_INTERRUPT_PARITY_ENABLE							0X00000100
#define UART_INTERRUPT_PARITY_DISABLE							0xFFFFFDFF




#define	UART_INTERRUPT_TXE_ENABLE					0X00000080
#define	UART_INTERRUPT_TXE_DISABLE					0XFFFFFF7F




#define	UART_INTERRUPT_TCE_ENABLE					0X00000040
#define	UART_INTERRUPT_TCE_DISABLE					0XFFFFFFBF




#define	UART_INTERRUPT_RXNEIE_ENABLE					0X00000020
#define	UART_INTERRUPT_RXNEIE_DISABLE					0XFFFFFFDF



#define	UART_TRANSMIT_ENABLE							0X8
#define	UART_RECIEVE_ENABLE								0X4

#define	UART_CR2_STOP_BIT_1									0x00000000
#define	UART_CR2_STOP_BIT_0_5								0x00001000
#define	UART_CR2_STOP_BIT_2									0x00002000
#define	UART_CR2_STOP_BIT_1_5								0x00003000


#define UART_MODE_DMA								1
#define UART_MODE_INTERRUPT						    2

/*******************************************************************
	use any of these  macros to know which error is currently present.
	Please don't change any of these
 *********************************************************************/
#define UART_STATUS_PE		(u8)1
#define UART_STATUS_FE		(u8)2
#define UART_STATUS_NE		(u8)4
#define UART_STATUS_ORE		(u8)8
#define UART_STATUS_IDLE	(u8)0x10
#define UART_STATUS_RXNE	(u8)0x20
#define UART_STATUS_TC		(u8)0x40
#define UART_STATUS_TXE		(u8)0x80
#define UART_STATUS_LBD		(u16)0x100
#define UART_STATUS_CTS		(u16)0x200






#define UART_DMA_TRANSMIT_ENABLE	(u8)0x80
#define UART_DMA_RECIEVE_ENABLE		(u8)0x40


typedef struct {
	u8  Parity;
	u8  Mode;
	u8 DateSize;
	u8 StopBit;
	u32 BaudRate;
}UART_CFG_t;






/*=============================================== General Definitions ==============================================*/

typedef void(*UART_callBack_t)(void);
typedef 	u32	UART_STATUS;


/*=================================================== Prototypes ===================================================*/

void UART_voidInitStruct(UART_CFG_t UART_cfg,u32 UART_CHANNEL,u32 sysClk);


u8 UART_errTransmit(u32 UART_CHANNEL,u8* Copy_pu8Data, u16 Copy_u16Size);

u8 UART_errRecieve(u32 UART_CHANNEL,u8* Copy_pu8Data, u16 Copy_u16ize);

u8 UART_errSetCallBackTrans(u32 UART_CHANNEL,UART_callBack_t UART_callBack);
u8 UART_errSetCallBackRecieve(u32 UART_CHANNEL,UART_callBack_t UART_callBack);
UART_STATUS UART_u16GetStatus(u32 UART_CHANNEL);


#endif
