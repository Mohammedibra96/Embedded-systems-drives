/**********************************************************************************************
Author :Mohamed Ibrahem
Version:1.0
Date:6 May 2020
Description:This Header file is used to interface with the Timer1 module in AVR ATMega32 evaluation kit
***********************************************************************************************/
#ifndef Timer1_CNFG_H
#define Timer1_CNFG_H

#define CRYSTAL_CLK_SPEED 8000000
/* Chose the Clook of timer 0                                               */
/*OPtions
          T1_CLK_NO_Clook
          T1_CLK_NO_PRESCALLER
          T1_CLK_PRESCALLER8
          T1_CLK_PRESCALLER64
          T1_CLK_PRESCALLER256
          T1_CLK_PRESCALLER1024
          T1_CLK_EXTERNAL_CLK_FALLING_EDGE
          T1_CLK_EXTERNAL_CLK_RISING_EDGE
                                                                            */


#define CLK_SELECT                    T1_CLK_PRESCALLER8


#define MODE_OC1A                     OC1A_DISCONNECTED

#define MODE_OC1B                     OC1A_DISCONNECTED



/**/
/* Options for Wave generation:
                   T1_WG_NORMAL
                   T1_WG_PHASE_CORRECT_8_BIT
                   T1_WG_PHASE_CORRECT_9_BIT
                   T1_WG_PHASE_CORRECT_10_BIT
                   T1_WG_CTC_OCR1A_TOP
                   T1_WG_FAST_PWM_8_BIT
                   T1_WG_FAST_PWM_9_BIT
                   T1_WG_FAST_PWM_10_BIT
                   T1_WG_PHASE_CORRECT_FREQ_CORRECT_ICR1_TOP
                   T1_WG_PHASE_CORRECT_FREQ_CORRECT_OCR1A_TOP
                   T1_WG_PHASE_CORRECT_ICR1_TOP
                   T1_WG_PHASE_CORRECT_OCR1A_TOP
                   T1_WG_CTC_ICR1_TOP
                   T1_WG_FAST_PWM_ICR1_TOP
                   T1_WG_FAST_PWM_OCR1A_TOP

*/


#define T1_WAVE_GENERATION            T1_WG_NORMAL


#define OC1B_VALUE                     0

#define PRE_LOAD_VALUE                 0



#define ICR1_VALUE				      (u16)0



#define NUM_OVER_FLOW                  15
#define NUM_COMPARE_MATCH_A            1
#define NUM_COMPARE_MATCH_B            1



#define TIMER1_NUM_COMPARE			1





#endif
