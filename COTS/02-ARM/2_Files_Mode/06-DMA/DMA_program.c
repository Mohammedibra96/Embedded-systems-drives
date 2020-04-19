/**********************************************************************************************
Author :Mohamed Ibrahem
Version:1.0
Date:5 April 2020
Description:This Source file is used to interface with the DMA module in STM32f10x evaluation kit
 ***********************************************************************************************/



#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "DMA_cnfg.h"
#include "DMA_interface.h"

void (*DMA_CBF_EndOfTransfer[NUM_CHANNELS])(void);
void (*DMA_CBF_HalfOfTransfer[NUM_CHANNELS])(void);
void (*DMA_CBF_ErrorInTransfer[NUM_CHANNELS])(void);




typedef struct DMA_CH_t
{
	u32 CCR      ;
	u32 CNDTR    ;
	u32 CPAR     ;
	u32 CMAR     ;
	u32 Reserved ;
}DMA_CH_t;


typedef struct DMA_t
{
	u32 ISR       ;
	u32 IFCR      ;
	DMA_CH_t CH[7];
}DMA_t;


#define DMA_BASE_ADDRESS 	0x40020000
static volatile DMA_t * DMA=((volatile DMA_t*)DMA_BASE_ADDRESS);



void DMA_init(void)
{

}


/*
This function shall start the trnsfer
Inputs: u32 
        DMA_CHANNEL_1
        DMA_CHANNEL_2
        DMA_CHANNEL_3
        DMA_CHANNEL_4
        DMA_CHANNEL_5
        DMA_CHANNEL_6
        DMA_CHANNEL_7


Outputs:STD_ERROR

 */

STD_ERROR DMA_enableChannel(u8 DMA_CHANNEL)
{
	STD_ERROR LocalError=OK;
	if(DMA_CHANNEL< 7)
	{
		DMA->CH[DMA_CHANNEL].CCR|=DMA_CCR_ENABLE;
	}
	else
	{
		LocalError=NOT_VALID_INPUTS;
	}
	return LocalError;
}

/*
This function shall stop the trnsfer
Inputs: u32 
        DMA_CHANNEL_1
        DMA_CHANNEL_2
        DMA_CHANNEL_3
        DMA_CHANNEL_4
        DMA_CHANNEL_5
        DMA_CHANNEL_6
        DMA_CHANNEL_7

Outputs:STD_ERROR

 */

STD_ERROR DMA_disableChannel(u8 DMA_CHANNEL)
{
	STD_ERROR LocalError=OK;
	if(DMA_CHANNEL< 7)
	{
		DMA->CH[DMA_CHANNEL].CCR&=DMA_CCR_DISABLE;
	}
	else
	{
		LocalError=NOT_VALID_INPUTS;
	}
	return LocalError;
}  


/*This function shall set the call back function for end of transfer 
Inputs: u32 
        DMA_CHANNEL_1
        DMA_CHANNEL_2 
        DMA_CHANNEL_3 
        DMA_CHANNEL_4 
        DMA_CHANNEL_5 
        DMA_CHANNEL_6
        DMA_CHANNEL_7 

       void (*CBF)(void)


Outputs:STD_ERROR

 */

STD_ERROR DMA_setCBF_EndOfTransfer(u8 DMA_CHANNEL,void(*CBF)(void))
{
	STD_ERROR LocalError =OK;
	if(CBF)
	{
		if(DMA_CHANNEL <7)
		{
			DMA_CBF_EndOfTransfer[DMA_CHANNEL]=CBF;
			LocalError=OK;
		}
		else
		{
			LocalError|=NOT_VALID_INPUTS;
		}
	}
	else
	{
		LocalError|=NULL_POINTER;
	}
	return LocalError;
}


/*This function shall set the call back function for half of transfer 
Inputs: u32 
        DMA_CHANNEL_1
        DMA_CHANNEL_2 
        DMA_CHANNEL_3 
        DMA_CHANNEL_4 
        DMA_CHANNEL_5 
        DMA_CHANNEL_6
        DMA_CHANNEL_7 

void (*CBF)(void)

Outputs:STD_ERROR
 */
STD_ERROR DMA_setCBF_HalfOfTransfer(u8 DMA_CHANNEL,void(*CBF)(void))
{
	STD_ERROR LocalError =OK;
	if(CBF)
	{
		if( DMA_CHANNEL <7)
		{
			DMA_CBF_HalfOfTransfer[DMA_CHANNEL]=CBF;
			LocalError=OK;
		}
		else
		{
			LocalError|=NOT_VALID_INPUTS;
		}
	}
	else
	{
		LocalError|=NULL_POINTER;
	}
	return LocalError;
}



/*This function shall set the call back function for error in the transfer 
Inputs: u32 
        DMA_CHANNEL_1
        DMA_CHANNEL_2 
        DMA_CHANNEL_3 
        DMA_CHANNEL_4 
        DMA_CHANNEL_5 
        DMA_CHANNEL_6
        DMA_CHANNEL_7 

void (*CBF)(void)

Outputs:STD_ERROR
 */


STD_ERROR DMA_setCBF_ErrorInTransfer(u8 DMA_CHANNEL,void(*CBF)(void))
{
	STD_ERROR LocalError =OK;
	if(CBF)
	{
		if(DMA_CHANNEL <7)
		{
			DMA_CBF_ErrorInTransfer[DMA_CHANNEL]=CBF;
			LocalError=OK;
		}
		else
		{
			LocalError|=NOT_VALID_INPUTS;
		}
	}
	else
	{
		LocalError|=NULL_POINTER;
	}
	return LocalError;
}

/*This function shall set the call back function for error in the transfer 
Inputs: u8 DMA_CHANNEL
        DMA_CHANNEL_1
        DMA_CHANNEL_2 
        DMA_CHANNEL_3 
        DMA_CHANNEL_4 
        DMA_CHANNEL_5 
        DMA_CHANNEL_6
        DMA_CHANNEL_7 

        u32 DMA_CCR_PL
        DMA_CCR_PL_LOW      
        DMA_CCR_PL_MED      
        DMA_CCR_PL_HIGH     
        DMA_CCR_PL_VERY_HIGH

Outputs:STD_ERROR
 */

STD_ERROR DMA_SetChannelPriority(u8 DMA_CHANNEL,u32 DMA_CCR_PL)
{
	STD_ERROR LocalError=OK;
	if((DMA_CHANNEL< 7)  && (DMA_CCR_PL == DMA_CCR_PL_LOW ||DMA_CCR_PL==DMA_CCR_PL_MED|| DMA_CCR_PL== DMA_CCR_PL_VERY_HIGH))
	{
		DMA->CH[DMA_CHANNEL].CCR&=DMA_CCR_PL_MASK;
		DMA->CH[DMA_CHANNEL].CCR|=DMA_CCR_PL;
	}
	else
	{
		LocalError=NOT_VALID_INPUTS;
	}
	return LocalError;
}

/*This function shall set the call back function for error in the transfer 
Inputs: 
 ********u8 DMA_CHANNEL**********************
        DMA_CHANNEL_1
        DMA_CHANNEL_2 
        DMA_CHANNEL_3 
        DMA_CHANNEL_4 
        DMA_CHANNEL_5 
        DMA_CHANNEL_6
        DMA_CHANNEL_7 

 ********u32 DMA_CCR_PSIZE**********************
        DMA_CCR_PSIZE_8_BITS 
        DMA_CCR_PSIZE_16_BITS 
        DMA_CCR_PSIZE_32_BITS 

 ********u32 DMA_CCR_PINC***********************
        DMA_CCR_PINC_ENABLE 
        DMA_CCR_PINC_DISABLE

 ********u32 DMA_CCR_MSIZE**********************

        DMA_CCR_MSIZE_8_BITS 
        DMA_CCR_MSIZE_16_BITS
        DMA_CCR_MSIZE_32_BITS

 ********u32 DMA_CCR_MINC***********************

        DMA_CCR_MINC_ENABLE 
        DMA_CCR_MINC_DISABLE        

Outputs:STD_ERROR
 */


STD_ERROR DMA_configureChannel(u8 DMA_CHANNEL,u32 DMA_CCR_PSIZE,u32 DMA_CCR_PINC,u32 DMA_CCR_MSIZE,u32 DMA_CCR_MINC)
{
	STD_ERROR LocalError=OK;
	if((DMA_CHANNEL< 7)&&
			(DMA_CCR_PSIZE ==DMA_CCR_PSIZE_8_BITS || DMA_CCR_PSIZE ==DMA_CCR_PSIZE_16_BITS || DMA_CCR_PSIZE ==DMA_CCR_PSIZE_32_BITS)&&
			(DMA_CCR_MSIZE ==DMA_CCR_MSIZE_8_BITS || DMA_CCR_MSIZE ==DMA_CCR_MSIZE_16_BITS ||DMA_CCR_MSIZE ==DMA_CCR_MSIZE_32_BITS)&&
			(DMA_CCR_PINC == DMA_CCR_PINC_ENABLE || DMA_CCR_PINC == DMA_CCR_PINC_DISABLE)&&
			(DMA_CCR_MINC == DMA_CCR_MINC_ENABLE || DMA_CCR_MINC == DMA_CCR_MINC_DISABLE))
	{
		DMA->CH[DMA_CHANNEL].CCR&=(DMA_CCR_PSIZE_MASK|DMA_CCR_MSIZE |DMA_CCR_PINC_MASK|DMA_CCR_MINC_MASK);
		DMA->CH[DMA_CHANNEL].CCR|=(DMA_CCR_PSIZE|DMA_CCR_MSIZE|DMA_CCR_MINC|DMA_CCR_PINC);
	}
	else
	{
		LocalError=NOT_VALID_INPUTS;
	}

	return LocalError;
}


/*This function shall Enable the dma interrupts
Inputs:
 ********u8 DMA_CHANNEL**********************
        DMA_CHANNEL_1
        DMA_CHANNEL_2 
        DMA_CHANNEL_3 
        DMA_CHANNEL_4 
        DMA_CHANNEL_5 
        DMA_CHANNEL_6
        DMA_CHANNEL_7 

 *********DMA_CCR_INTERRUPT**************************
         DMA_CCR_INTERRUPT_TCIE
         DMA_CCR_INTERRUPT_HTIE
         DMA_CCR_INTERRUPT_TEIE

or use   DMA_CCR_INTERRUPT_TCIE|DMA_CCR_INTERRUPT_HTIE

Outputs:STD_ERROR         
 */

STD_ERROR DMA_enableInterrupt(u8 DMA_CHANNEL,u32 DMA_CCR_INTERRUPT)
{
	STD_ERROR LocalError=OK;
	if((DMA_CHANNEL< 7)&&
			(DMA_CCR_INTERRUPT>=DMA_CCR_INTERRUPT_TCIE && DMA_CCR_INTERRUPT<=DMA_CCR_INTERRUPT_ALL))
	{
		DMA->CH[DMA_CHANNEL].CCR|=DMA_CCR_INTERRUPT;

	}
	else
	{
		LocalError=NOT_VALID_INPUTS;
	}
	return LocalError;


}


/*This function shall Disable the dma interrupts
Inputs:
 ********u8 DMA_CHANNEL**********************
        DMA_CHANNEL_1
        DMA_CHANNEL_2 
        DMA_CHANNEL_3 
        DMA_CHANNEL_4 
        DMA_CHANNEL_5 
        DMA_CHANNEL_6
        DMA_CHANNEL_7 

 *********DMA_CCR_INTERRUPT**************************
         DMA_CCR_INTERRUPT_TCIE
         DMA_CCR_INTERRUPT_HTIE
         DMA_CCR_INTERRUPT_TEIE

or use   DMA_CCR_INTERRUPT_TCIE|DMA_CCR_INTERRUPT_HTIE

Outputs:STD_ERROR         
 */

STD_ERROR DMA_disableInterrupt(u8 DMA_CHANNEL ,u32 DMA_CCR_INTERRUPT)
{

	STD_ERROR LocalError=OK;
	if((DMA_CHANNEL< 7)&&
			(DMA_CCR_INTERRUPT>=DMA_CCR_INTERRUPT_TCIE && DMA_CCR_INTERRUPT<=DMA_CCR_INTERRUPT_ALL))
	{
		if(DMA_CCR_INTERRUPT&DMA_CCR_INTERRUPT_TCIE)
		{
			DMA->CH[DMA_CHANNEL].CCR&=~DMA_CCR_INTERRUPT_TCIE;
		}
		if(DMA_CCR_INTERRUPT&DMA_CCR_INTERRUPT_HTIE)
		{
			DMA->CH[DMA_CHANNEL].CCR&=~DMA_CCR_INTERRUPT_HTIE;
		}
		if(DMA_CCR_INTERRUPT&DMA_CCR_INTERRUPT_TEIE)
		{
			DMA->CH[DMA_CHANNEL].CCR&=~DMA_CCR_INTERRUPT_TEIE;
		}
	}

	else
	{
		LocalError=NOT_VALID_INPUTS;
	}
	return LocalError;
}

/*This function shall Enable the circular mode of the dma 
Inputs:
 ********u8 DMA_CHANNEL**********************
        DMA_CHANNEL_1
        DMA_CHANNEL_2 
        DMA_CHANNEL_3 
        DMA_CHANNEL_4 
        DMA_CHANNEL_5 
        DMA_CHANNEL_6
        DMA_CHANNEL_7 

Outputs:STD_ERROR         

 */

STD_ERROR DMA_enableCircular(u8 DMA_CHANNEL )
{
	STD_ERROR LocalError=OK;
	if(DMA_CHANNEL< 7)
	{
		DMA->CH[DMA_CHANNEL].CCR|=DMA_CCR_CIRC_ENABLE;
	}
	else
	{
		LocalError=NOT_VALID_INPUTS;
	}
	return LocalError;
}

/*This function shall Disable the circular mode of the dma 
Inputs:
 ********u8 DMA_CHANNEL**********************
        DMA_CHANNEL_1
        DMA_CHANNEL_2 
        DMA_CHANNEL_3 
        DMA_CHANNEL_4 
        DMA_CHANNEL_5 
        DMA_CHANNEL_6
        DMA_CHANNEL_7 

Outputs:STD_ERROR         

 */

STD_ERROR DMA_disableCircular(u8 DMA_CHANNEL)
{
	STD_ERROR LocalError=OK;
	if(DMA_CHANNEL< 7)
	{
		DMA->CH[DMA_CHANNEL].CCR&=DMA_CCR_CIRC_DISABLE;
	}
	else
	{
		LocalError=NOT_VALID_INPUTS;
	}
	return LocalError;
}  

/*This function shall Set the dma channel direction  
Inputs:
 ********u8 DMA_CHANNEL**********************
        DMA_CHANNEL_1
        DMA_CHANNEL_2 
        DMA_CHANNEL_3 
        DMA_CHANNEL_4 
        DMA_CHANNEL_5 
        DMA_CHANNEL_6
        DMA_CHANNEL_7 

 ********u32 DMA_CCR_DIR_FROM*****************
        DMA_CCR_DIR_FROM_PERIPHERAL
        DMA_CCR_DIR_FROM_MEMORY    

Outputs:STD_ERROR         

 */

STD_ERROR DMA_setDirction(u8 DMA_CHANNEL,u32 DMA_CCR_DIR_FROM)
{
	STD_ERROR LocalError=OK;
	if(DMA_CHANNEL< 7 &&
			(DMA_CCR_DIR_FROM== DMA_CCR_DIR_FROM_PERIPHERAL|| DMA_CCR_DIR_FROM==DMA_CCR_DIR_FROM_MEMORY))
	{
		DMA->CH[DMA_CHANNEL].CCR&=DMA_CCR_DIR_MASK;
		DMA->CH[DMA_CHANNEL].CCR|=DMA_CCR_DIR_FROM;
	}
	else
	{
		LocalError=NOT_VALID_INPUTS;
	}
	return LocalError;
}


/*This function shall Enable dma channel memory to memory   
Inputs:
 ********u8 DMA_CHANNEL**********************
        DMA_CHANNEL_1
        DMA_CHANNEL_2 
        DMA_CHANNEL_3 
        DMA_CHANNEL_4 
        DMA_CHANNEL_5 
        DMA_CHANNEL_6
        DMA_CHANNEL_7 

Outputs:STD_ERROR         

 */




STD_ERROR DMA_enableMem2Mem(u8 DMA_CHANNEL )
{
	STD_ERROR LocalError=OK;
	if(DMA_CHANNEL< 7)
	{
		DMA->CH[DMA_CHANNEL].CCR|=DMA_CCR_MEM2MEM_ENABLE;
	}
	else
	{
		LocalError=NOT_VALID_INPUTS;
	}
	return LocalError;
}



/*This function shall Disable dma channel memory to memory   
Inputs:
 ********u8 DMA_CHANNEL**********************
        DMA_CHANNEL_1
        DMA_CHANNEL_2 
        DMA_CHANNEL_3 
        DMA_CHANNEL_4 
        DMA_CHANNEL_5 
        DMA_CHANNEL_6
        DMA_CHANNEL_7 

Outputs:STD_ERROR         

 */


STD_ERROR DMA_disableMem2Mem(u8 DMA_CHANNEL)
{
	STD_ERROR LocalError=OK;
	if(DMA_CHANNEL< 7)
	{
		DMA->CH[DMA_CHANNEL].CCR&=DMA_CCR_MEM2MEM_DISABLE;
	}
	else
	{
		LocalError=NOT_VALID_INPUTS;
	}
	return LocalError;
}




/*This function shall Set the DMA channel number of data transfer   
Inputs:
 ********u8 DMA_CHANNEL**********************
        DMA_CHANNEL_1
        DMA_CHANNEL_2 
        DMA_CHANNEL_3 
        DMA_CHANNEL_4 
        DMA_CHANNEL_5 
        DMA_CHANNEL_6
        DMA_CHANNEL_7 

Outputs:STD_ERROR         

 */

STD_ERROR DMA_setNumberOfDataTransfer(u8 DMA_CHANNEL,u32 CopyNumber_Transfer)
{
	STD_ERROR LocalError=OK;
	if(DMA_CHANNEL< 7)
	{
		DMA->CH[DMA_CHANNEL].CNDTR=CopyNumber_Transfer;
	}
	else
	{
		LocalError=NOT_VALID_INPUTS;
	}

	return LocalError;
}

/*This function shall Set the DMA channel Peripheral Address  
Inputs:
 ********u8 DMA_CHANNEL**********************
        DMA_CHANNEL_1
        DMA_CHANNEL_2 
        DMA_CHANNEL_3 
        DMA_CHANNEL_4 
        DMA_CHANNEL_5 
        DMA_CHANNEL_6
        DMA_CHANNEL_7 

Outputs:STD_ERROR         

 */

STD_ERROR DMA_setPeripheralAddress(u8 DMA_CHANNEL,u32 CopyPeripheralAddr)
{
	STD_ERROR LocalError=OK;
	if(DMA_CHANNEL< 7)
	{
		DMA->CH[DMA_CHANNEL].CPAR=CopyPeripheralAddr;
	}
	else
	{
		LocalError=NOT_VALID_INPUTS;
	}

	return LocalError;
}


/*This function shall Set the DMA channel Memory Address  
Inputs:
 ********u8 DMA_CHANNEL**********************
        DMA_CHANNEL_1
        DMA_CHANNEL_2 
        DMA_CHANNEL_3 
        DMA_CHANNEL_4 
        DMA_CHANNEL_5 
        DMA_CHANNEL_6
        DMA_CHANNEL_7 

Outputs:STD_ERROR         

 */

STD_ERROR DMA_setMemoryAddress(u8 DMA_CHANNEL,u32 CopyMemokryAddr)
{
	STD_ERROR LocalError=OK;
	if(DMA_CHANNEL< 7)
	{
		DMA->CH[DMA_CHANNEL].CMAR=CopyMemokryAddr;
	}
	else
	{
		LocalError=NOT_VALID_INPUTS;

	}
	return LocalError;
}





void DMA1_Channel1_IRQHandler(void)
{
	/*transfer error */
	if(DMA->ISR &DMA_ISR_TEIF_CH_1)
	{
		/*Clear transfer error flag */
		DMA->IFCR|=DMA_IFCR_CTEIF_CH_1;
		/*Check the call back function */
		if(DMA_CBF_ErrorInTransfer[DMA_CHANNEL_1])
			DMA_CBF_ErrorInTransfer[DMA_CHANNEL_1]();
	}
	/*half transfer */
	if(DMA->ISR &DMA_ISR_HTIF_CH_1)
	{
		/*Clear half transfer flag */
		DMA->IFCR|=DMA_IFCR_CHTIF_CH_1;
		/*Check the call back function */
		if(DMA_CBF_HalfOfTransfer[DMA_CHANNEL_1])
			DMA_CBF_HalfOfTransfer[DMA_CHANNEL_1]();
	}
	/*transfer complete                                */
	if(DMA->ISR &DMA_ISR_TCIF_CH_1)
	{
		/*Clear the transfer flag	*/
		DMA->IFCR|=DMA_IFCR_CTCIF_CH_1;
		/*Check the call back function */
		if(DMA_CBF_EndOfTransfer[DMA_CHANNEL_1])
			DMA_CBF_EndOfTransfer[DMA_CHANNEL_1]();
	}

}

void DMA1_Channel2_IRQHandler(void)
{
	/*transfer error */
	if(DMA->ISR &DMA_ISR_TEIF_CH_2)
	{
		/*Clear transfer error flag */
		DMA->IFCR|=DMA_IFCR_CTEIF_CH_2;
		/*Check the call back function */
		if(DMA_CBF_ErrorInTransfer[DMA_CHANNEL_2])
			DMA_CBF_ErrorInTransfer[DMA_CHANNEL_2]();
	}
	/*half transfer */
	if(DMA->ISR &DMA_ISR_HTIF_CH_2)
	{
		/*Clear half transfer flag */
		DMA->IFCR|=DMA_IFCR_CHTIF_CH_2;
		/*Check the call back function */
		if(DMA_CBF_HalfOfTransfer[DMA_CHANNEL_2])
			DMA_CBF_HalfOfTransfer[DMA_CHANNEL_2]();
	}
	/*transfer complete                                */
	if(DMA->ISR &DMA_ISR_TCIF_CH_2)
	{
		/*Clear the transfer flag	*/
		DMA->IFCR|=DMA_IFCR_CTCIF_CH_2;
		/*Check the call back function */
		if(DMA_CBF_EndOfTransfer[DMA_CHANNEL_2])
			DMA_CBF_EndOfTransfer[DMA_CHANNEL_2]();
	}

}

void DMA1_Channel3_IRQHandler(void)
{
	/*transfer error */
	if(DMA->ISR &DMA_ISR_TEIF_CH_3)
	{
		/*Clear transfer error flag */
		DMA->IFCR|=DMA_IFCR_CTEIF_CH_3;
		/*Check the call back function */
		if(DMA_CBF_ErrorInTransfer[DMA_CHANNEL_3])
			DMA_CBF_ErrorInTransfer[DMA_CHANNEL_3]();
	}
	/*half transfer */
	if(DMA->ISR &DMA_ISR_HTIF_CH_3)
	{
		/*Clear half transfer flag */
		DMA->IFCR|=DMA_IFCR_CHTIF_CH_3;
		/*Check the call back function */
		if(DMA_CBF_HalfOfTransfer[DMA_CHANNEL_3])
			DMA_CBF_HalfOfTransfer[DMA_CHANNEL_3]();
	}
	/*transfer complete                                */
	if(DMA->ISR &DMA_ISR_TCIF_CH_3)
	{
		/*Clear the transfer flag	*/
		DMA->IFCR|=DMA_IFCR_CTCIF_CH_3;
		/*Check the call back function */
		if(DMA_CBF_EndOfTransfer[DMA_CHANNEL_3])
			DMA_CBF_EndOfTransfer[DMA_CHANNEL_3]();
	}

}


void DMA1_Channel4_IRQHandler(void)
{
	/*transfer error */
	if(DMA->ISR &DMA_ISR_TEIF_CH_4)
	{
		/*Clear transfer error flag */
		DMA->IFCR|=DMA_IFCR_CTEIF_CH_4;
		/*Check the call back function */
		if(DMA_CBF_ErrorInTransfer[DMA_CHANNEL_4])
			DMA_CBF_ErrorInTransfer[DMA_CHANNEL_4]();
	}
	/*half transfer */
	if(DMA->ISR &DMA_ISR_HTIF_CH_4)
	{
		/*Clear half transfer flag */
		DMA->IFCR|=DMA_IFCR_CHTIF_CH_4;
		/*Check the call back function */
		if(DMA_CBF_HalfOfTransfer[DMA_CHANNEL_4])
			DMA_CBF_HalfOfTransfer[DMA_CHANNEL_4]();
	}
	/*transfer complete                                */
	if(DMA->ISR &DMA_ISR_TCIF_CH_4)
	{
		/*Clear the transfer flag	*/
		DMA->IFCR|=DMA_IFCR_CTCIF_CH_4;
		/*Check the call back function */
		if(DMA_CBF_EndOfTransfer[DMA_CHANNEL_4])
			DMA_CBF_EndOfTransfer[DMA_CHANNEL_4]();
	}

}
void DMA1_Channel5_IRQHandler(void)
{
	/*transfer error */
	if(DMA->ISR &DMA_ISR_TEIF_CH_5)
	{
		/*Clear transfer error flag */
		DMA->IFCR|=DMA_IFCR_CTEIF_CH_5;
		/*Check the call back function */
		if(DMA_CBF_ErrorInTransfer[DMA_CHANNEL_5])
			DMA_CBF_ErrorInTransfer[DMA_CHANNEL_5]();
	}
	/*half transfer */
	if(DMA->ISR &DMA_ISR_HTIF_CH_5)
	{
		/*Clear half transfer flag */
		DMA->IFCR|=DMA_IFCR_CHTIF_CH_5;
		/*Check the call back function */
		if(DMA_CBF_HalfOfTransfer[DMA_CHANNEL_5])
			DMA_CBF_HalfOfTransfer[DMA_CHANNEL_5]();
	}
	/*transfer complete                                */
	if(DMA->ISR &DMA_ISR_TCIF_CH_5)
	{
		/*Clear the transfer flag	*/
		DMA->IFCR|=DMA_IFCR_CTCIF_CH_5;
		/*Check the call back function */
		if(DMA_CBF_EndOfTransfer[DMA_CHANNEL_5])
			DMA_CBF_EndOfTransfer[DMA_CHANNEL_5]();
	}

}
void DMA1_Channel6_IRQHandler(void)
{
	/*transfer error */
	if(DMA->ISR &DMA_ISR_TEIF_CH_6)
	{
		/*Clear transfer error flag */
		DMA->IFCR|=DMA_IFCR_CTEIF_CH_6;
		/*Check the call back function */
		if(DMA_CBF_ErrorInTransfer[DMA_CHANNEL_6])
			DMA_CBF_ErrorInTransfer[DMA_CHANNEL_6]();
	}
	/*half transfer */
	if(DMA->ISR &DMA_ISR_HTIF_CH_6)
	{
		/*Clear half transfer flag */
		DMA->IFCR|=DMA_IFCR_CHTIF_CH_6;
		/*Check the call back function */
		if(DMA_CBF_HalfOfTransfer[DMA_CHANNEL_6])
			DMA_CBF_HalfOfTransfer[DMA_CHANNEL_6]();
	}
	/*transfer complete                                */
	if(DMA->ISR &DMA_ISR_TCIF_CH_6)
	{
		/*Clear the transfer flag	*/
		DMA->IFCR|=DMA_IFCR_CTCIF_CH_6;
		/*Check the call back function */
		if(DMA_CBF_EndOfTransfer[DMA_CHANNEL_6])
			DMA_CBF_EndOfTransfer[DMA_CHANNEL_6]();
	}

}
void DMA1_Channel7_IRQHandler(void)
{
	/*transfer error */
	if(DMA->ISR &DMA_ISR_TEIF_CH_7)
	{
		/*Clear transfer error flag */
		DMA->IFCR|=DMA_IFCR_CTEIF_CH_7;
		/*Check the call back function */
		if(DMA_CBF_ErrorInTransfer[DMA_CHANNEL_7])
			DMA_CBF_ErrorInTransfer[DMA_CHANNEL_7]();
	}
	/*half transfer */
	if(DMA->ISR &DMA_ISR_HTIF_CH_7)
	{
		/*Clear half transfer flag */
		DMA->IFCR|=DMA_IFCR_CHTIF_CH_7;
		/*Check the call back function */
		if(DMA_CBF_HalfOfTransfer[DMA_CHANNEL_7])
			DMA_CBF_HalfOfTransfer[DMA_CHANNEL_7]();
	}
	/*transfer complete                                */
	if(DMA->ISR &DMA_ISR_TCIF_CH_7)
	{
		/*Clear the transfer flag	*/
		DMA->IFCR|=DMA_IFCR_CTCIF_CH_7;
		/*Check the call back function */
		if(DMA_CBF_EndOfTransfer[DMA_CHANNEL_7])
			DMA_CBF_EndOfTransfer[DMA_CHANNEL_7]();
	}

}

