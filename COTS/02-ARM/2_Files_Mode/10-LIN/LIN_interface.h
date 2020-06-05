/**************************************************** 
 	 Author: Mahmoud Gamal
 ************************************************/
#ifndef LIN_INTERFACE_H
#define LIN_INTERFACE_H



#define ID_MASK    0b00111111

#define CHECKSUM_BYTES   1

#define LIN_CHANNEL_1		UART_CHANNEL_1
#define LIN_CHANNEL_3		UART_CHANNEL_2
#define LIN_CHANNEL_2		UART_CHANNEL_3


#define LIN_NODE_MODE_MASTER   0
#define LIN_NODE_MODE_SLAVE    1

#define PARITY0_MASK    0b00010111
#define PARITY1_MASK    0b00111010


#define LIN_MSG_ACTION_TX  0
#define LIN_MSG_ACTION_RX  1
#define LIN_MSG_NO_ACTION  2


/* SYNC Byte value                          */
#define SYNC_BYTE_VALUE                0x55
/* Max Data Bytes                           */
#define MAX_DATA_BYTES                 8


#define CHECK_SUM_CLASSICAL            1
#define CHECK_SUM_ENHANCED             2





typedef struct
{
	u8 Reserved                          ;
	u8 SyncByte                          ;
	u8 PID                               ;
}Header_t                              ;

typedef struct
{
	u8 DataSize                            ;
	u8 Data[MAX_DATA_BYTES]                ;
	u8 CheckSum                            ;
}Response_t                                ;



typedef struct
{
	u8 MessageID                         ;
	u8 TimeSlot                          ;
	u8 MsgAction                         ;
}Matrix_t                                ;



typedef void (*LINcBF_t)(void);


void LIN_Init(u32 LIN_CHANNEL);

ErrorStatus LIN_generateBreak(u32 LIN_CHANNEL);
ErrorStatus LIN_setCallBackBreak(u8 LIN_CHANNEL);




void LIN_MasterTask(void)              ;
void LIN_SlaveTask(void)               ;

void LIN_AddBuffer(u8 * buffer, u8 ResponseIndex);
void LIN_GetBuffer(u8 ** buffer , u8 ResponseIndex);



#endif
