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




void HUART_voidInit(u8 UART_CHANNEL)
{
    extern  HUART_CNFG_t HUART_cnfg[];
    UART_CFG_t*UART_cfg=Get_UART_CnfStruct();

    HRCC_EnablePeripheral(HUART_cnfg[UART_CHANNEL].HRCC_Enable_Port);
    HRCC_EnablePeripheral(HUART_cnfg[UART_CHANNEL].HRCC_Enable_Prepherial);

	GPIO_InitStr(&(HUART_cnfg[UART_CHANNEL].GPIO_Input));
	GPIO_InitStr(&(HUART_cnfg[UART_CHANNEL].GPIO_Output));

	if(UART_cfg[UART_CHANNEL].Mode==UART_MODE_DMA)
	{

		HRCC_EnablePeripheral(HRCC_PERIPHERAL_AHBENR_DMA1);
		NVIC_errEnableInterrupt(HUART_cnfg[UART_CHANNEL].NVIC_DMA_Rx);
		NVIC_errEnableInterrupt(HUART_cnfg[UART_CHANNEL].NVIC_DMA_Tx);
	}
	NVIC_errEnableInterrupt(HUART_cnfg[UART_CHANNEL].NVIC_Enable_Prepherial_Interrupt);

if(UART_CHANNEL == UART_CHANNEL_1)
{
	UART_voidInitStruct(UART_cfg[UART_CHANNEL],UART_CHANNEL,HRCC_GetAPB2_Speed());

}
else
{
	UART_voidInitStruct(UART_cfg[UART_CHANNEL],UART_CHANNEL,HRCC_GetAPB1_Speed());

}

}



u8 HUART_errTransmit(u32 UART_CHANNEL,u8* Copy_pu8Data, u16 Copy_u16Size)
{
	UART_CFG_t*UART_cfg=Get_UART_CnfStruct();
	return UART_errTransmit(UART_CHANNEL,Copy_pu8Data,Copy_u16Size);
}
u8 HUART_errRecieve(u32 UART_CHANNEL,u8* Copy_pu8Data, u16 Copy_u16ize)
{
	UART_CFG_t*UART_cfg=Get_UART_CnfStruct();
	return UART_errRecieve(UART_CHANNEL,Copy_pu8Data,  Copy_u16ize);
}
