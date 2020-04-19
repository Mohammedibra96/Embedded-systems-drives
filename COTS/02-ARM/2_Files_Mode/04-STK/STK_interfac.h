/************************************************************
Author :Mohamed Ibrahem
Version:v01
Date:13 March 2020
*************************************************************/
#ifndef STK_INTERFACE_H
#define STK_INTERFACE_H


/************************************************************
Author :Mohamed Ibrahem
Version:v01
Date:13 March 2020
*************************************************************/








/*Maks for Clock Source AHP or AHP/8             */
#define STK_CLK_SOURCE_AHP_DIV8    0x00000000
#define STK_CLK_SOURCE_AHP         0x00000004 




/*Configure Prescaler for the Timer and Enable interrupt */
void STK_voidInit(void);
/*Enable The timer for Counting                         */
void STK_voidStart();
/*Enable The timer for Counting                        */
void STK_voidStop();
/*Set Function Call back for System timer                */
STD_ERROR STK_voidSetCallBack(void(*Copy_ptr)(void));

STD_ERROR STK_SetTimer_usec(u32 Time_us,u32 AHP_CLK);

STD_ERROR STK_SetSourceClk(u32 STK_CLK_SOURCE);




#endif
