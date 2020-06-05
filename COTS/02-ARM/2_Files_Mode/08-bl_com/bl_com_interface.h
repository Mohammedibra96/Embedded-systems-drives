/**********************************************************************************************
Author :Mohamed Ibrahem,Mahmoud gamal
Version:1.0
Date:6 June 2020
Description:This Header file is used to interface with the bl_com module in STM32f10x evaluation kit
***********************************************************************************************/
#ifndef bl_com_INTERFACE_H
#define bl_com_INTERFACE_H

#define		APP1_FLASH_ADDRESS			0x08003C00
#define		APP2_FLASH_ADDRESS			0x08008000


#define		MARKER_NO_APP	0xCCCC
#define		MARKER_APP1		0xAAAA

typedef struct __attribute__((packed))
{
	u8 req_counter;
	u8 cmd;
}BL_comm_header_t;



typedef struct __attribute__((packed))
{

	u32 baseAddress;
	u16 fileSize;
	BL_comm_header_t BL_comm_header;
}new_app_t;


void BLcomm_handler(void);




#endif