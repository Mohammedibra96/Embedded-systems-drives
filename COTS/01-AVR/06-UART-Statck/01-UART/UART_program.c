/*Author :Mohamed Ibrahem */
/*Date :9 March 2020      */
/*Version :1.0            */




#include"STD_TYPES.h"
#include"BIT_MATH.h"

#include "UART_register.h"
#include "UART_interfac.h"
#include "UART_private.h"
#include "UART_config.h"


static void (*EndofTransmitCB)(void);
static void (*EndofRecCB)(u8);


u8 BaudRateValue[3][3]={
		/*4800  ,9600  ,   115200           */
		{   0x67, 0x33 ,    0x03     },/*Clock System 0=8 Mhz           */
		{    154, 77   ,    6        },/*Clock System 1=12MHZ           */
		{   0xcf , 0x67,    0x08     } /*Clock System 2=16MHZ           */
};


void UART_Init(void)
{
	/*u2X=0*/
	CLR_BIT(UCSRA,U2X_BIT);
	/*Disable all UART interrupt */
	/*Enable RX               */
	/*Enable TX               */
	UCSRB=0x18;

	/*Asynch Mode       */
	/*char size =8 Bits */

	UCSRC=((1<<7)|
			(UART_PARITY   <<4)|
			(UART_STOP_BIT<<3)|
			(3<< 1)
	);
	/*Assign Baud rate */
	UBRRL=BaudRateValue[UART_SYS_FREQ][UART_SYS_FREQ];
}



STD_Error UART_TransimitDataSync(u8 Data)
{
	u32 Local_TimeOut=0;
	STD_Error std_error=OK;
	/*Send data on UDR */
	UDR_T=Data;
	/*wait till flag raised */
	while((GET_BIT(UCSRA,6)==0)&& Local_TimeOut<UART_TIME_OUT_TH)
	{
		Local_TimeOut++;
	}

	/*Timeout happen */
	if(Local_TimeOut>=UART_TIME_OUT_TH)
	{
		std_error=NOK;
	}
	else
	{
		/*Clear Flag */
		SET_BIT(UCSRA,6);
	}
	return std_error;
}
STD_Error UART_TransimitDataAsync(u8 Data,void (*ptr)(void))
{
	/*Enable Interrupt */
	SET_BIT(UCSRB,6);

	/*Set recieved Date to UDR*/
	UDR_T=Data;
	if (ptr==NULL)
	{
		return NOK;
	}
	EndofTransmitCB=ptr;
	return OK;
}


STD_Error UART_RecieveSync(u8 *value)
{
	u32 Local_TimeOut=0;
	STD_Error std_error=OK;
	/*wait till flag raised */
	while((GET_BIT(UCSRA,7)==0)&& Local_TimeOut<UART_TIME_OUT_TH)
	{
		Local_TimeOut++;
	}

	/*Timeout happen */
	if(Local_TimeOut>=UART_TIME_OUT_TH)
	{
		std_error=NOK;
	}
	else
	{
		/*Set datea to recieve pointer */
		*value=UDR_R;
	}
	return std_error;
}
void UART_RecieveAsynch(void (*ptr)(u8))
{
	/*Check if there is date to recieve */
	if(GET_BIT(UCSRA,7)==1)
	{
		ptr(UDR_R);
	}
	else
	{
		/*Save Call back in global Variable */
		SET_BIT(UCSRA,7);
		EndofRecCB=ptr;
	}
}


void __vector_13(void)
{
	if(EndofRecCB!=NULL)
	{
		EndofRecCB(UDR_R);
	}
}

void __vector_14(void)
{
	if(EndofTransmitCB!=NULL)
	{
		EndofTransmitCB();
	}

}

