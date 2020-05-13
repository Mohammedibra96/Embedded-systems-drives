/* Author:Mohamed Ibrahem      */
/*Version:1.0                  */
/*Date: 11 March 2020          */




#ifndef UARTM_INTERFACE_H
#define UARTM_INTERFACE_H


#define UARTM_SEND_SYNC       0
#define UARTM_SEND_ASYNC      1
#define UARTM_RECV_SYNC       2
#define UARTM_RECV_ASYNC      3



typedef struct {
  
 u8 JobType            ;
 u8 *DataBufer         ;
 u8 Lenght             ;
void (*CallBack)(void) ; 
  
}UARTM_UART_Request;


STD_Error UARTM_PerformJobRequest(UARTM_UART_Request CopyOfJobReq);

#endif