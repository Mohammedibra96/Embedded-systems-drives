/**********************************************************************************************
Author :Mohamed Ibrahem, Mahmoud Gamal
Version:1.0
Date:13 May 2020
Description:This Header file is used to interface with the SCB module in STM32f10x evaluation kit
***********************************************************************************************/
#ifndef SCB_INTERFACE_H
#define SCB_INTERFACE_H






#define SCB_VECT_BASE_SRAM	 0x00000000
#define SCB_VECT_BASE_CODE   0x20000000



ErrorStatus_t SCB_SetVectorOffset(u32 *CopyOffset ,u32 SCB_VECT_BASE);

void SCB_Reset(void);


#endif
