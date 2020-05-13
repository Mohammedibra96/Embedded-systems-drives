/**********************************************************************************************
Author :Mohamed Ibrahem
Version:1.0
Date:6 May 2020
Description:This Header file is used to interface with the Timer1 module in AVR ATMega32 evaluation kit
***********************************************************************************************/
#ifndef Timer1_INTERFACE_H
#define Timer1_INTERFACE_H




#define TCCR1A_COMPARE_OUTPUT_MAST          0x0F


/* Options for non PWM modes */

#define OC1A_DISCONNECTED		            0x00
#define TOGLE_OC1A				            0x40
#define CLEAR_OC1A_ON_COMPARE	            0x80
#define	SET_OC1A_ON_COMPARE		            0xC0


#define OC1B_DISCONNECTED		            0x00
#define TOGLE_OC1B				            0x10
#define CLEAR_OC1B_ON_COMPARE	            0x20
#define	SET_OC1B_ON_COMPARE		            0x30




/* Options for  FAST PWM modes */

#define NORMAL_OC1A_DISCONNECTED		                 0x00
#define TOGGLE_OC1A                                      0x40
#define CLEAR_OC1A_ON_COMPARE_MATCH_SET_TOP              0x80
#define CSET_OC1A_ON_COMPARE_MATCH_CLEAR_TOP             0xC0


#define NORMAL_OC1B_DISCONNECTED					     0x00
#define TOGGLE_OC1B                                      0x10
#define CLEAR_OC1B_ON_COMPARE_MATCH_SET_TOP              0x20
#define CSET_OC1B_ON_COMPARE_MATCH_CLEAR_TOP             0x30


/* Options for Phase correct */

#define NORMAL_OC1A_DISCONNECTED		                 0x00
#define TOGGLE_OC1A                                      0x40
#define CLEAR_OC1A_ON_COMPARE_UP_COUNT_SET_DOWN_COUNT    0x80
#define SET_OC1A_ON_COMPARE_UP_COUNT_CLEAR_DOWN_COUNT    0xC0


#define NORMAL_OC1B_DISCONNECTED					     0x00
#define TOGGLE_OC1B                                      0x10
#define CLEAR_OC1B_ON_COMPARE_UP_COUNT_SET_DOWN_COUNT    0x20
#define SET_OC1B_ON_COMPARE_UP_COUNT_CLEAR_DOWN_COUNT    0x30




#define  WAVA_GENERATION_MAST       				 0xFCE7

/* Wave Generation Mode */

#define T1_WG_NORMAL                                  0x0000
#define T1_WG_PHASE_CORRECT_8_BIT			          0x0100
#define T1_WG_PHASE_CORRECT_9_BIT			          0x0200
#define T1_WG_PHASE_CORRECT_10_BIT		              0x0300
#define T1_WG_CTC_OCR1A_TOP				              0x0008
#define T1_WG_FAST_PWM_8_BIT				          0x0108
#define T1_WG_FAST_PWM_9_BIT				          0x0208
#define T1_WG_FAST_PWM_10_BIT				          0x0308
#define T1_WG_PHASE_CORRECT_FREQ_CORRECT_ICR1_TOP	  0x0010
#define T1_WG_PHASE_CORRECT_FREQ_CORRECT_OCR1A_TOP    0x0110
#define T1_WG_PHASE_CORRECT_ICR1_TOP                  0x0210
#define T1_WG_PHASE_CORRECT_OCR1A_TOP                 0x0310
#define T1_WG_CTC_ICR1_TOP                            0x0018
#define T1_WG_FAST_PWM_ICR1_TOP                       0x0218
#define T1_WG_FAST_PWM_OCR1A_TOP                      0x0318



#define TCCR1B_MAST								0b00111111



#define T1_NOISE_CANCELER_ENABLED	            0b10000000

#define TCCR1B_EDGE_MAST					    0b10111111

#define T1_INPUT_CAPTURE_FALLING_EDGE           0b00000000
#define T1_INPUT_CAPTURE_RISING_EDGE            0b01000000



#define CLK_MASK                                0b11111000

/* Options for CLK                        */
#define T1_CLK_NO_Clook                         0b0000000
#define T1_CLK_NO_PRESCALLER                    0b0000001
#define T1_CLK_PRESCALLER8                      0b0000010
#define T1_CLK_PRESCALLER64                     0b0000011
#define T1_CLK_PRESCALLER256                    0b0000100
#define T1_CLK_PRESCALLER1024                   0b0000101
#define T1_CLK_EXTERNAL_CLK_FALLING_EDGE        0b0000110
#define T1_CLK_EXTERNAL_CLK_RISING_EDGE         0b0000111





/* Interrupts masks*/


#define T1_INTERRUPT_INPUT_CAPTURE              0b00100000
#define T1_INTERRUPT_COMPARE_MATCH_A            0b00010000
#define T1_INTERRUPT_COMPARE_MATCH_B            0b00001000
#define T1_INTERRUPT_OVER_FLOW                  0b00000100



#define TIMER1_INTERRUPT_INPUT_CAPTURE                 3
#define TIMER1_INTERRUPT_COMPARE_MATCH_A               2
#define TIMER1_INTERRUPT_COMPARE_MATCH_B               1
#define TIMER1_INTERRUPT_OVER_FLOW                     0





void Timer1_Init(void)                                                 ;
void Timer1_SetPwmValue(u32 Value);

void Timer1_Start(void)                                                ;
void Timer1_Stop(void)                                                 ;

void Timer1_InterruptEnable(u8 T1_INTERRUPT)                           ;
void Timer1_InterruptDisable(u8 T1_INTERRUPT)                          ;

STD_ERROR Timer1_SetCallBackFunction(void (*CBF)(void),u8 TIMER1_INTERRUPT);


u32  Timer1_GetTimerSpeed(void);
void Timer1_SetTimer_us(u32 Time_ms);
void Timer1_Delay_us(u32 Time_ms);

u16 Timer1_GetTimerCount(void);
void Timer1_ClearCounter(void);

void Timer1_Set_ICU_Edge(u8 T1_INPUT_CAPTURE );
STD_ERROR Timer1_ICU_Get_Frequency( u16* Freq );
STD_ERROR Timer1_ICU_GetDutyCycle(u16 *Duty  );



#endif
