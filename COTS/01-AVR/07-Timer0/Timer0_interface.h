/**********************************************************************************************
Author :Mohamed Ibrahem
Version:1.0
Date:30 April 2020
Description:This Header file is used to interface with the Timer0 module in AVR ATMega32 evaluation kit
***********************************************************************************************/
#ifndef Timer0_INTERFACE_H
#define Timer0_INTERFACE_H




#define TIMER0_MODE_MASK          0b10110111

#define TIMER0_MODE_NORMAL                  0b00000000
#define TIMER0_MODE_PHASE_CORRECT           0b00001000
#define TIMER0_MODE_CTC                     0b01000000
#define TIMER0_MODE_FAST_PWM                0b01001000



#define COMPARE_OUTPUT_MASK      0b11001111

/* OPtion for   CTC and Normal modes */

#define OC0_DISCONNECTED          0b00000000
#define TOGGLE_OC0                0b00010000
#define CLEAR_OC0                 0b00100000
#define SET_OC0                   0b00110000

/* Options for fast PWM */

#define OC0_DISCONNECTED                      0b00000000
#define CLEAR_OC0_ON_COMPARE_SET_OC0_TOP      0b00100000
#define SET_OC0_ON_COMPARE_CLEAR_OC0_TOP      0b00110000

/* OPtions for Phase corresct mode */
#define OC0_DISCONNECTED                                        0b00000000
#define CLEAR_ONCOMPARE_ON_UP_COUNTING_SET_OC0_ON_DOWNCOUNTING  0b00100000
#define SET_ONCOMPARE_ON_UP_COUNTING_CLEAR_OC0_ON_DOWNCOUNTING  0b00110000





#define CLK_MASK                             0b11111000


/* Options for CLK                        */
#define T0_CLK_NO_Clook                         0b0000000
#define T0_CLK_NO_PRESCALLER                    0b0000001
#define T0_CLK_PRESCALLER8                      0b0000010
#define T0_CLK_PRESCALLER64                     0b0000011
#define T0_CLK_PRESCALLER256                    0b0000100
#define T0_CLK_PRESCALLER1024                   0b0000101
#define T0_CLK_EXTERNAL_CLK_FALLING_EDGE        0b0000110
#define T0_CLK_EXTERNAL_CLK_RISING_EDGE         0b0000111





#define T0_INTERRUPT_COMPARE_MATCH       0b00000010

#define T0_INTERRUPT_OVER_FLOW           0b00000001






void Timer0_Init(void)                                                 ;
void Timer0_Start(void)                                                ;
void Timer0_Stop(void)                                                 ;
void Timer0_InterruptEnable(u8 T0_INTERRUPT)                           ;
void Timer0_InterruptDisable(u8 T0_INTERRUPT)                          ;
STD_ERROR Timer0_SetCallBackFunction(void (*CBF)(void),u8 T0_INTERRUPT);
void Timer0_SetTimer_us(u32 Time_ms);
void Timer0_Delay_us(u32 Time_ms);



#endif
