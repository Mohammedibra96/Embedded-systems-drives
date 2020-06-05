/**************************************************** 
 	 Author: Mahmoud Gamal
************************************************/

#include "std_types.h"
#include "UART_interface.h"
#include "UART_cnfg.h"

#include "HRCC_interfac.h"
#include "LIN_interface.h"
#include "LIN_cnfg.h"
#include "HUART_interface.h"


#define LIN_SYNC_PID_BYTES_LENGTH		(u8)2
#define	LIN_READ_HEADER					(u8)0
#define	LIN_READ_DATA					(u8)1
#define	LIN_TRANSMIT_DATA				(u8)2


static u8 Counter       = 0               ;


#define LIN_RX_IDEAL  		        0
#define LIN_RX_SYNC_PID             1
#define LIN_RX_DATA 		        2
#define LIN_RX_SYNC_BUSY			4
#define LIN_RX_DATA_BUSY			5

static u8 LIN_Rx_Flag = LIN_RX_IDEAL                 ;



extern Matrix_t   MatrixArray[MAX_NUM_MESSAGES] ;
extern Response_t Response[MAX_NUM_MESSAGES]    ;



Header_t   Header[MAX_NUM_MESSAGES];

static u8 RX_Buffer[MAX_DATA_BYTES+CHECKSUM_BYTES];

u8 LIN_breakBuffer[UART_MODULES_NUM][LIN_SYNC_PID_BYTES_LENGTH +1 ];

u8 LIN_status = LIN_READ_HEADER;
u8 LIN_matric_counter = 0;




LINcBF_t LIN_callBackFunction;



static void LIN_recieveSyncandPID(u8 LIN_CHANNEL);
static ErrorStatus LIN_setCallBack(u32 LIN_CHANNEL, LINcBF_t callBackFunction);
static void LIN_setSyncRecieveCallBackFunction(void);



void LIN_Init(u32 LIN_CHANNEL)
{
	LIN_setCallBack(LIN_CHANNEL,LIN_setSyncRecieveCallBackFunction);
	HUART_voidInit(LIN_CHANNEL);

}

ErrorStatus LIN_generateBreak(u32 LIN_CHANNEL)
{
	return UART_LINgenerateBreak(LIN_CHANNEL);
}


static void LIN_recieveSyncandPID(u8 LIN_CHANNEL)
{
	if (LIN_Rx_Flag == LIN_RX_IDEAL )
	{
		LIN_Rx_Flag = LIN_RX_SYNC_BUSY ;
		ErrorStatus LocalError = OK;
		/*Rx sync and PID */
		UART_errRecieve(LIN_CHANNEL,LIN_breakBuffer[LIN_CHANNEL],3);
#if LIN_NODE_MODE == LIN_NODE_MODE_MASTER
		/* Send the rest of the Header */
		LocalError |= HUART_errTransmit(LIN_CHANNEL, (u8*)&Header[Counter],3);
		Counter++;
#elif LIN_NODE_MODE == LIN_NODE_MODE_MASTER


#else

#error "NOt valid LIN Node mode "

#endif
		trace_printf("yarb");
	}
}


ErrorStatus LIN_setCallBackBreak(u8 LIN_CHANNEL)
{
	return UART_LINsetCallBackBreak(LIN_CHANNEL, LIN_recieveSyncandPID);
}

u8  materStart = 0;
void LIN_MasterTask(void)
{
	if( materStart == 0)
	{
		materStart = 1;
		u8 ParityZero =0        ;
		u8 ParityOne = 0         ;


		u8 static RemTime = 0;

		if ( MatrixArray[Counter].TimeSlot == RemTime )
		{
			trace_printf(" i am master task %d",MatrixArray[Counter].MessageID);
			RemTime = 0 ;

			u8 ID = MatrixArray[Counter].MessageID &= ID_MASK ;
			/*Construct the PID of Message ID and the parity bits*/
			/* Add the parity bits to the ID */
			ParityZero = ((((ID >> 0)&1)^((ID >> 1)&1)) ^(((ID >> 2)&1)^((ID >> 4)&1)));
			ParityOne = ((((ID >> 1)&1)^((ID >> 3)&1)) ^(((ID >> 4)&1)^((ID >> 5)&1)));
			Header[Counter].PID = ((ParityZero << 6 | ParityOne << 7 ) | ID);
			Header[Counter].SyncByte = SYNC_BYTE_VALUE;
			/*Send Break         */
			LIN_generateBreak(LIN_CHANNEL_1);
		}
		else
		{
			RemTime ++ ;
		}
		if (Counter == NUM_CNFG_MESSAGES )
		{
			Counter = 0;
		}
	}
}





static u8 CalCheckSum(u8 * CopyData,u8 size,u8 CopyID)
{

#if CHECK_SUM  == CHECK_SUM_CLASSICAL
	u8 Result = 0;
#elif  CHECK_SUM  ==   CHECK_SUM_ENHANCED
	u8 Result = CopyID;
#else
#error "Invalid LIN  Check sum option"

#endif
	for(u8 Counter = 0; Counter<size ;Counter++)
	{
		Result+= CopyData[Counter] ;
	}
	return (~Result) ;
}


void LIN_SlaveTask(void)
{
	materStart = 0 ;
	/* Check for rx bytes or not */
	u8 ParityZero = 0   ;
	u8 ParityOne  = 0   ;
	static u8 Message_Index = 0;
	u8 ID = 0           ;
	ErrorStatus LocalError = NOK ;

	if ( LIN_Rx_Flag == LIN_RX_SYNC_PID )
	{
		trace_printf("I am slave task %d , %d",LIN_breakBuffer[LIN_CHANNEL_1][1],LIN_breakBuffer[LIN_CHANNEL_1][2]);
		u8 SyncByte = LIN_breakBuffer[LIN_CHANNEL_1][1];
		u8 PID      = LIN_breakBuffer[LIN_CHANNEL_1][2];
		ParityZero  = ((((PID >> 0)&1)^((PID >> 1)&1)) ^(((PID >> 2)&1)^((PID >> 4)&1)));
		ParityOne   = ((((PID >> 1)&1)^((PID >> 3)&1)) ^(((PID >> 4)&1)^((PID >> 5)&1)));

		if (SyncByte == SYNC_BYTE_VALUE && (ParityOne == PID>> 7  &&  ParityZero == PID>> 6))
		{
			for (Message_Index =0 ; Message_Index<MAX_NUM_MESSAGES;Message_Index++ )
			{
				if (( Header[Message_Index].PID & ID_MASK)   == ( PID & ID_MASK) )
				{
					ID = Header[Message_Index].PID & ID_MASK ;
					LocalError = OK;
					break;
				}
			}

		}
		if (LocalError == OK )
		{
			/* Check if en 3aiz Tx wla 3aiz a RX */
			if (MatrixArray[Message_Index].MsgAction == LIN_MSG_ACTION_TX)
			{
				/* this variable for response waiting time */
				static u8 TX_RemTime = 1 ;

				if(TX_RemTime == 1 )
				{
					TX_RemTime = 0;
				}
				else if(TX_RemTime == 0)
				{
					LIN_Rx_Flag = LIN_RX_IDEAL ;
					u8 DataSize = Response[Message_Index].DataSize;
					Response[Message_Index].Data[DataSize] =  CalCheckSum(Response[Message_Index].Data,DataSize,ID);
					/* transmit the data and the checksum value */
					HUART_errTransmit(LIN_CHANNEL_1,Response[Message_Index].Data, DataSize + CHECKSUM_BYTES );
					/* return to the waiting state  */
					TX_RemTime = 1;
				}
			}
			else if (MatrixArray[Message_Index].MsgAction == LIN_MSG_ACTION_RX)
			{
				HUART_errRecieve(LIN_CHANNEL_1, RX_Buffer, Response[Message_Index].DataSize +CHECKSUM_BYTES);
				LIN_Rx_Flag = LIN_RX_DATA_BUSY ;
			}
		}
	}
	else if ( LIN_Rx_Flag == LIN_RX_DATA )
	{
		LIN_Rx_Flag = LIN_RX_IDEAL ;
		/*Check for the checksum value */
		if (Response[Message_Index].Data[Response[Message_Index].DataSize] ==  CalCheckSum(Response[Message_Index].Data,Response[Message_Index].DataSize,ID))
		{
			for (u8 Data_Index=0;Data_Index < Response[Message_Index].DataSize ;Data_Index++)
			{
				Response[Message_Index].Data[Data_Index] = RX_Buffer[Data_Index] ;
			}
			Message_Index = 0;
		}
	}
}


void LIN_setSyncRecieveCallBackFunction(void)
{
	if (LIN_Rx_Flag == LIN_RX_SYNC_BUSY )
	{
		LIN_Rx_Flag = LIN_RX_SYNC_PID ;
	}
	else if (LIN_Rx_Flag == LIN_RX_DATA_BUSY)
	{
		LIN_Rx_Flag =LIN_RX_DATA ;
	}
}

static ErrorStatus LIN_setCallBack(u32 LIN_CHANNEL, LINcBF_t callBackFunction)
{
	ErrorStatus LocalError = NULL_POINTER;
	if(callBackFunction)
	{
		UART_errSetCallBackRecieve(LIN_CHANNEL, callBackFunction) ;
	}
	else
	{
		LocalError = OK ;
	}
	return LocalError;
}


void LIN_AddBuffer(u8 * buffer, u8 ResponseIndex)
{
	for ( u8 index=0 ; index < Response[ResponseIndex].DataSize ; index++)
	{
		Response[ResponseIndex].Data[index] = buffer[index]  ;
	}
}


void LIN_GetBuffer(u8 ** buffer , u8 ResponseIndex)
{
	for ( u8 index=0 ; index < Response[ResponseIndex].DataSize ; index++)
	{
		*buffer[index] = Response[ResponseIndex].Data[index] ;
	}
}
