/**************************************************** 
 	 Author: Mahmoud Gamal
 ************************************************/
#include "std_types.h"
#include "UART_interface.h"
#include "UART_interface.h"
#include "LIN_interface.h"
#include "LIN_cnfg.h"

Matrix_t   MatrixArray[MAX_NUM_MESSAGES] ={
		{
				.MessageID = 0x01,
				.TimeSlot  = 10,
				.MsgAction = LIN_MSG_ACTION_RX,
		},
		{
				.MessageID = 0x02,
				.TimeSlot  = 5,
				.MsgAction =LIN_MSG_ACTION_RX,
		},
		{
				.MessageID = 0x03,
				.TimeSlot  = 50,
				.MsgAction =LIN_MSG_ACTION_RX,
		}
};

Response_t Response[MAX_NUM_MESSAGES] =
{
		{
				.DataSize = 3 ,
		},
		{
				.DataSize = 3 ,
		},
		{
				.DataSize = 3 ,
		},
};



