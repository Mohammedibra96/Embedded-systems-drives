/* Author:Mohamed Ibrahem      */
/*Version:1.0                  */
/*Date: 11 March 2020          */

#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include"UART_interfac.h"
#include "UARTM_interfac.h"
#include "UARTM_private.h"
#include "UARTM_config.h"




UARTM_UART_Request  UARTM_QUEUE[UARTM_QUEUE_SIZE];
u8 UARTM_QCurrent=0                 ;
u8 UARTM_QNext=0                    ;
u8 UARTM_QAvilable=UARTM_QUEUE_SIZE;
u8 UARTM_BusyFlag=0;




STD_Error UARTM_PerformJobRequest(UARTM_UART_Request CopyOfJobReq)
{
 STD_Error LocalError=OK;

if(UARTM_QAvilable>0)
{
  /*Add Job to queue Enqueue        */
 UARTM_QAvilable--;
 UARTM_UART_Request[UARTM_QNext]=CopyOfJobReq;
/*Increamen the next*/
if(UARTM_QNext==UARTM_QUEUE_SIZE-1)
{
  UARTM_QNext=0;
}  
else
{  
   UARTM_QNext++;
}
Execute();
}
else
{
  LocalError=NOK;
}  
  return LocalError;
}


static void Execute(void )
{
  if(UARTM_BusyFlag)
  {
    Start();
  }
  else 
  {
    /*Do noting    */
    
  }
  
  
}



void Start(void)
{
  
  u8 LocalCounter;
  
  while(1)
  {
  /*Queue is Empty*/
  if(UARTM_QAvilable==UARTM_QUEUE_SIZE)
  {
    UARTM_BusyFlag=0;
    break;
  }
  /*Queue includes Jobs*/
  else 
  {
    UARTM_BusyFlag=1;
    if(UARTM_QAvilable==UARTM_QUEUE_SIZE-1)
    {
      switch(UARTM_QUEUE[UARTM_QCurrent].JobType)
      {
        case UARTM_SEND_SYNC:   SendSynch();        
        break;
        case UARTM_SEND_ASYNC:   
        break;
        case UARTM_RECV_SYNC: RecieveSynch();
        break;
        case UARTM_RECV_ASYNC:
        break;
  
        
        
        
        
      }
    
    
    }
    else 
    {
      
    }
    
  } 
  }
  
  
  
}



static void SendSynch(void)
{
  for(LocalCounter=0;LocalCounter<UARTM_QUEUE[UARTM_QCurrent].Length;LocalCounter++)
        {
         UART_TransimitDataSync(UARTM_QUEUE[UARTM_QCurrent].DataBuffer[LocalCounter]);
        }  
        UARTM_QAvilable++;
        if(UARTM_QCurrent==UARTM_QUEUE_SIZE-1)
        {
          UARTM_QCurrent=0;
        }  
        else
        {  
          UARTM_QCurrent++;
        }
 
}






static void RecieveSynch(void)
{
  for(LocalCounter=0;LocalCounter<UARTM_QUEUE[UARTM_QCurrent].Length;LocalCounter++)
        {
         UART_RecieveSync(UARTM_QUEUE[UARTM_QCurrent].DataBuffer[LocalCounter]);
        }  
        UARTM_QAvilable++;
        if(UARTM_QCurrent==UARTM_QUEUE_SIZE-1)
        {
          UARTM_QCurrent=0;
        }  
        else
        {  
          UARTM_QCurrent++;
        }
 
}


void SendAsynch(void)

{
UART_TransimitDataAsync(u8 Data,void (*ptr)(void))

}