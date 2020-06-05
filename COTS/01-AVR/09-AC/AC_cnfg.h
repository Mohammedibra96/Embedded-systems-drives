/**********************************************************************************************
Author :Mohamed Ibrahem
Version:1.0
Date:20 May 2020
Description:This Header file is used to interface with the AC module in AVR ATMega32 evaluation kit
***********************************************************************************************/
#ifndef AC_CNFG_H
#define AC_CNFG_H
/*
 * Options:
 * 			AC_INPUT_POSITIVE_PIN_BANDGAB
			AC_INPUT_POSITIVE_PIN_AIN0
 *
 *
 *
 *
 *
 *
 * */




#define POSTIVE_PIN_SELECT  AC_INPUT_POSITIVE_PIN_AIN0


/*OPtions:
 *
 *AC_INPUT_NEGATIVE_PIN_AIN1
  AC_INPUT_NEGATIVE_PIN_ADC0
  AC_INPUT_NEGATIVE_PIN_ADC1
  AC_INPUT_NEGATIVE_PIN_ADC2
  AC_INPUT_NEGATIVE_PIN_ADC3
  AC_INPUT_NEGATIVE_PIN_ADC4
  AC_INPUT_NEGATIVE_PIN_ADC5
  AC_INPUT_NEGATIVE_PIN_ADC6
  AC_INPUT_NEGATIVE_PIN_ADC7
 *
 *
 *
 *
 * */
#define AC_INPUT_NEGATIVE_SELECT  AC_INPUT_NEGATIVE_PIN_ADC0


/*
 * Options:
 * INTERRUPT_ON_TOGGLE
   INTERRUPT_ON_FALLING_EDGE
   INTERRUPT_ON_RISING_EDGE

 * */
#define INTERRUPT_SELECT	INTERRUPT_ON_TOGGLE


#endif
