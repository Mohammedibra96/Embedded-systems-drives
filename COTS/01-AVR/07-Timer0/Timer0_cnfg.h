/**********************************************************************************************
Author :Mohamed Ibrahem
Version:1.0
Date:30 April 2020
Description:This Header file is used to interface with the Timer0 module in AVR ATMega32 evaluation kit
***********************************************************************************************/
#ifndef Timer0_CNFG_H
#define Timer0_CNFG_H


#define CRYSTAL_CLK_SPEED   8000000


/* Chose the mode of timer 0                                             */
/*OPtions                                                                 
          TIMER0_MODE_NORMAL  
          TIMER0_MODE_PHASE_CORRECT
          TIMER0_MODE_CTC     
          TIMER0_MODE_FAST_PWM                                             */


#define TIMER0_MODE               TIMER0_MODE_FAST_PWM


/* Chose the Clook of timer 0                                               */
/*OPtions                                                                 
          T0_CLK_NO_Clook                 
          T0_CLK_NO_PRESCALLER            
          T0_CLK_PRESCALLER8              
          T0_CLK_PRESCALLER64             
         T0_CLK_PRESCALLER256
         T0_CLK_PRESCALLER1024
         T0_CLK_EXTERNAL_CLK_FALLING_EDGE
         T0_CLK_EXTERNAL_CLK_RISING_EDGE  
                                                                            */


#define CLK_SELECT                      T0_CLK_PRESCALLER8


/* chsoe Output compare match           */
/* OPtions                             */
/* 
   CTC and NORMAL OPtions

         OC0_DISCONNECTED
         TOGGLE_OC0       
         CLEAR_OC0        
         SET_OC0          

*******************************************
    PWM Options
         OC0_DISCONNECTED                
         CLEAR_OC0_ON_COMPARE_SET_OC0_TOP
         SET_OC0_ON_COMPARE_CLEAR_OC0_TOP

********************************************
    Phase correct Options

        OC0_DISCONNECTED                                      
        CLEAR_ONCOMPARE_ON_UP_COUNTING_SET_OC0_ON_DOWNCOUNTING
        SET_ONCOMPARE_ON_UP_COUNTING_CLEAR_OC0_ON_DOWNCOUNTING

*/


#define TIMER0_COMPARE_OUTPUT_MODE         CLEAR_OC0_ON_COMPARE_SET_OC0_TOP



#define OC0_VALUE                       50

#define PRE_LOAD_VALUE                   0


//#define NUM_OVER_FLOW                3900


#define NUM_COMPARE_MATCH            	10000

#endif
