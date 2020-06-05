/**********************************************************************************************
Author :Mohamed Ibrahem,Mahmoud gamal
Version:1.0
Date:6 June 2020
Description:This Source file is used to interface with the bl_com module in STM32f10x evaluation kit
***********************************************************************************************/

#include "std_types.h"
#include "bl_com_interface.h"
#include "UART_interface.h"
#include "flash.h"
#include "HUART_interface.h"
#include "Delay.h"

#define 	DELAY_ONE_MS				1

#define		APP_FLASH_SIZE				0xC400				//this is the max file size that can be recieved (49k)


#define		BL_CMD_WRITE_SECTOR			0
#define		BL_CMD_FLASH_NEW_APP		1
#define		BL_CMD_VERIFY_DATA			2

#define		BL_VERIFY_OK				0x55
#define		BL_VERIFY_NOK				0xFF

#define		PAGE_SIZE_BYTES				1024
#define		PAGE_SIZE_WORD				512

#define		STAGE_IDLE					0
#define		STAGE_RECIEVE_DATA			1
#define		STAGE_FLASH_DATA			2
#define		STAGE_CHANGE_MARKER			3


/*

typedef struct {
	u8 req_counter;
	u8 cmd;
}BL_comm_header_t;



typedef struct {

	BL_comm_header_t BL_comm_header;
	u32 baseAddress;
	u16 fileSize;
}new_app_t;


 */

extern const u16 marker;

BL_comm_header_t	BL_comm_header;
new_app_t new_app;

u8 G_counter = 0;


u8 page[PAGE_SIZE_BYTES];


void BLcomm_handler(void)
{
	u8 status = BL_VERIFY_NOK;
	u8 error_s;
	static u8  stage = STAGE_IDLE;
	static u8 writeDataCounter; 
	static u16 lastData;

	/*
	 * The first stage is actually the last else if
	 * 	it was put at the end because it will only be checked once at the beginning of the receiving operation
	 * 	*/
	if((stage == STAGE_RECIEVE_DATA) && (BL_comm_header.cmd == BL_CMD_WRITE_SECTOR))
	{
		if(writeDataCounter > 0)
		{
			/* check the consecutivity of the received counter */
			if(BL_comm_header.req_counter == G_counter)
			{
				G_counter++;
				status = BL_VERIFY_OK;
				HUART_errRecieve(UART_CHANNEL_1,page,PAGE_SIZE_BYTES);
				stage = STAGE_FLASH_DATA;

			}
			else{
				status = BL_VERIFY_NOK;
			}
			/*	the delay is needed for syncronization with the PC	*/
			Delay_ms(DELAY_ONE_MS);
			HUART_errTransmit(UART_CHANNEL_1,(u8*)&status, 1);


		}
		else if(writeDataCounter == 0)
		{
			HUART_errRecieve(UART_CHANNEL_1,page,lastData);
			stage = STAGE_FLASH_DATA;

		}
		writeDataCounter--;
	}

	else if(stage == STAGE_FLASH_DATA)
	{
		stage = STAGE_RECIEVE_DATA;
		FLASH_eraseSection((u16*)new_app.baseAddress);
		error_s = FLASH_writeData((u16*)new_app.baseAddress, page,PAGE_SIZE_WORD);
		if(error_s == OK)
		{
			new_app.baseAddress +=	PAGE_SIZE_BYTES;
			status = BL_VERIFY_OK;
		}
		else
		{
			status = BL_VERIFY_NOK;
		}
		Delay_ms(DELAY_ONE_MS);
		if(writeDataCounter >0)
		{
			HUART_errTransmit(UART_CHANNEL_1,(u8*)&status, 1);
			HUART_errRecieve(UART_CHANNEL_1,(u8*)&BL_comm_header,sizeof(BL_comm_header_t));

		}
		else
		{
			FLASH_eraseSection((u16*)&marker);

			u16 markerValue = MARKER_APP1;
			FLASH_writeHalfWord(&marker,&markerValue);
		}
	}

	else if(new_app.BL_comm_header.cmd == BL_CMD_FLASH_NEW_APP)
	{
		if(new_app.fileSize <= APP_FLASH_SIZE && (new_app.baseAddress == APP1_FLASH_ADDRESS || new_app.baseAddress == APP2_FLASH_ADDRESS) )

		{

			stage = STAGE_RECIEVE_DATA;		/*	changing stages means that you are now going to start to recieve only headers	*/
			writeDataCounter = (new_app.fileSize/PAGE_SIZE_BYTES);
			if(lastData = new_app.fileSize%PAGE_SIZE_BYTES)
				writeDataCounter++;
			status = BL_VERIFY_OK;
			HUART_errRecieve(UART_CHANNEL_1,(u8*)&BL_comm_header,sizeof(BL_comm_header_t));
		}

		Delay_ms(DELAY_ONE_MS);
		HUART_errTransmit(UART_CHANNEL_1,(u8*)&status, 1);

		if(status == BL_VERIFY_NOK)
		{
			HUART_errRecieve(UART_CHANNEL_1,(u8*)&new_app,sizeof(new_app_t));
		}
	}
}
