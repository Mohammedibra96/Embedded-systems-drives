/**********************************************************************************************
Author :Mohamed Ibrahem
Version:1.0
Date:20 May 2020
Description:This Header file is used to interface with the AC module in AVR ATMega32 evaluation kit
***********************************************************************************************/
#ifndef AC_INTERFACE_H
#define AC_INTERFACE_H






/* SFIOR   */

#define SFIOR_ANALOG_COMP_ENABLE               0b00001000


/**/

#define ACSR_ANALOG_COMP_DISABLE   0b10000000

#define ACSR_BAND_GAB_ENABLE       0b01000000

#define ACSR_ACO                   0b00100000
#define ACSR_INTERRUPT_FLAG        0b00010000
#define ACSR_INTERRUPT_ENABLE      0b00001000

#define ACSR_ICU_ENABLE            0b00000100




/* Macros for Postive Pin input */


#define POSTIVE_PIN_MASK    0b10111111


#define AC_INPUT_POSITIVE_PIN_BANDGAB   0b01000000
#define AC_INPUT_POSITIVE_PIN_AIN0		0b00000000



/* Macros for negative Pin input */


#define AC_INPUT_NEGATIVE_SELECT  AC_INPUT_NEGATIVE_PIN_AIN1



#define AC_INPUT_NEGATIVE_MASK      0b00011111


#define AC_INPUT_NEGATIVE_PIN_AIN1   0x10   //AC
#define AC_INPUT_NEGATIVE_PIN_ADC0   0x00
#define AC_INPUT_NEGATIVE_PIN_ADC1   0x01
#define AC_INPUT_NEGATIVE_PIN_ADC2   0x02
#define AC_INPUT_NEGATIVE_PIN_ADC3   0x03
#define AC_INPUT_NEGATIVE_PIN_ADC4   0x04
#define AC_INPUT_NEGATIVE_PIN_ADC5   0x05
#define AC_INPUT_NEGATIVE_PIN_ADC6   0x06
#define AC_INPUT_NEGATIVE_PIN_ADC7   0x07



/* Interrupt options */


#define INTERRUPT_MODE_MAST	                0b11111100

#define INTERRUPT_ON_TOGGLE			        0b00000000
#define INTERRUPT_ON_FALLING_EDGE			0b00000010
#define INTERRUPT_ON_RISING_EDGE			0b00000011




void AC_Init(void);
ErrorStatus_t AC_GetOutputValueSync(u8 * CopyOutputValue );
ErrorStatus_t AC_GetOutputValueAsync(u8 * CopyOutputValue,void (*PostiveCBF)(void),void (*NegativeCBF)(void));
void AC_Disable(void);



#endif
