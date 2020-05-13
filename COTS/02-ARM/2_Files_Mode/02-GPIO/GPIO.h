/**********************************************************************************************
Author :Mohamed Ibrahem
Version:1.0
Date:5 Feb 2020
Description:This header file is used to interface with the GPIO module in STM32f10x evaluation kit
 ***********************************************************************************************/

#include"STD_TYPES.h"


#ifndef GPIO_H_
#define GPIO_H_

typedef struct
{
	u16 Pin;
	u8 Mode;
	void *Port;

}GPIO_t;

#define GPIO_VALUE_HIGH 			                             (u8)1
#define GPIO_VALUE_LOW    										 (u8)0



#define PORTA_BASE_ADDRESS                                 0x40010800
#define PORTB_BASE_ADDRESS                                 0x40010C00
#define PORTC_BASE_ADDRESS                                 0x40011000

/*Port options*/
#define GPIO_PORT_A 	                                     (void *)PORTA_BASE_ADDRESS
#define GPIO_PORT_B 	                                     (void *)PORTB_BASE_ADDRESS
#define GPIO_PORT_C 	                                     (void *)PORTC_BASE_ADDRESS
#define ISGPIO_PORT(GPIO_PORT) ((GPIO_struct*)GPIO_PORT==(GPIO_struct*)GPIO_PORT_A ||\
		(GPIO_struct*)GPIO_PORT==(GPIO_struct*)GPIO_PORT_B ||\
		(GPIO_struct*)GPIO_PORT==(GPIO_struct*)GPIO_PORT_C)

/*pin Options*/
#define GPIO_PIN0                                           (u16)(1)
#define GPIO_PIN1                                           (u16)(2)
#define GPIO_PIN2                                           (u16)(4)
#define GPIO_PIN3                                           (u16)(8)
#define GPIO_PIN4                                           (u16)(16)
#define GPIO_PIN5                                           (u16)(32)
#define GPIO_PIN6                                           (u16)(64)
#define GPIO_PIN7                                           (u16)(128)
#define GPIO_PIN8                                           (u16)(256)
#define GPIO_PIN9                                           (u16)(512)
#define GPIO_PIN10                                          (u16)(1024)
#define GPIO_PIN11                                          (u16)(2048)
#define GPIO_PIN12                                          (u16)(4096)
#define GPIO_PIN13                                          (u16)(8192)
#define GPIO_PIN14                                          (u16)(16384)
#define GPIO_PIN15                                          (u16)(32768)

#define ISGPIO_PIN(PIN) ((PIN==GPIO_PIN0)||\
		(PIN==GPIO_PIN1)||\
		(PIN==GPIO_PIN2)||\
		(PIN==GPIO_PIN3)||\
		(PIN==GPIO_PIN4)||\
		(PIN==GPIO_PIN5)||\
		(PIN==GPIO_PIN6)||\
		(PIN==GPIO_PIN7)||\
		(PIN==GPIO_PIN8)||\
		(PIN==GPIO_PIN9)||\
		(PIN==GPIO_PIN10)||\
		(PIN==GPIO_PIN11)||\
		(PIN==GPIO_PIN12)||\
		(PIN==GPIO_PIN13)||\
		(PIN==GPIO_PIN14)||\
		(PIN==GPIO_PIN15))






#define GPIO_MODE_INPUT_ANALOG			                           (u8)(0b0000)
#define GPIO_MODE_INPUT_FLOATING			                       (u8)(0b0100)
#define GPIO_MODE_INPUT_PULLUP			                           (u8)(0b1000)
#define GPIO_MODE_INPUT_PULLDOWN			                       (u8)(0b1101)

#define GPIO_MODE_OUTPUT_10_GP_PUSHPULL	                           (u8)(0b0001)
#define GPIO_MODE_OUTPUT_10_GP_OPENDRAIN	                       (u8)(0b0101)
#define GPIO_MODE_OUTPUT_10_AF_PUSHPULL	                           (u8)(0b1001)
#define GPIO_MODE_OUTPUT_10_AF_OPENDRAIN	                       (u8)(0b1101)

#define GPIO_MODE_OUTPUT_2_GP_PUSHPULL	                           (u8)(0b0010)
#define GPIO_MODE_OUTPUT_2_GP_OPENDRAIN	                           (u8)(0b0110)
#define GPIO_MODE_OUTPUT_2_AF_PUSHPULL	                           (u8)(0b1010)
#define GPIO_MODE_OUTPUT_2_AF_OPENDRAIN	                           (u8)(0b1110)

#define GPIO_MODE_OUTPUT_50_GP_PUSHPULL	                           (u8)(0b0011)
#define GPIO_MODE_OUTPUT_50_GP_OPENDRAIN	                       (u8)(0b0111)
#define GPIO_MODE_OUTPUT_50_AF_PUSHPULL	                           (u8)(0b1011)
#define GPIO_MODE_OUTPUT_50_AF_OPENDRAIN	                       (u8)(0b1111)



#define ISGPIO_MODE(GPIO_MODE) (GPIO_MODE==GPIO_MODE_INPUT_ANALOG   ||\
		GPIO_MODE==GPIO_MODE_INPUT_FLOATING                         ||\
		GPIO_MODE==GPIO_MODE_INPUT_PULLUP                           ||\
		GPIO_MODE==GPIO_MODE_INPUT_PULLDOWN                         ||\
		GPIO_MODE==GPIO_MODE_OUTPUT_10_GP_PUSHPULL                  ||\
		GPIO_MODE==GPIO_MODE_OUTPUT_10_GP_OPENDRAIN                 ||\
		GPIO_MODE==GPIO_MODE_OUTPUT_10_AF_PUSHPULL                  ||\
		GPIO_MODE==GPIO_MODE_OUTPUT_10_AF_OPENDRAIN                 ||\
		GPIO_MODE==GPIO_MODE_OUTPUT_2_GP_PUSHPULL                   ||\
		GPIO_MODE==GPIO_MODE_OUTPUT_2_GP_OPENDRAIN                  ||\
		GPIO_MODE==GPIO_MODE_OUTPUT_2_AF_PUSHPULL                   ||\
		GPIO_MODE==GPIO_MODE_OUTPUT_2_AF_OPENDRAIN                  ||\
		GPIO_MODE==GPIO_MODE_OUTPUT_50_GP_PUSHPULL                  ||\
		GPIO_MODE==GPIO_MODE_OUTPUT_50_GP_OPENDRAIN                 ||\
		GPIO_MODE==GPIO_MODE_OUTPUT_50_AF_PUSHPULL                  ||\
		GPIO_MODE==GPIO_MODE_OUTPUT_50_AF_OPENDRAIN                   \
)



/*               Prototypes of the functions                            */


/* Initialization  for group of Pins */
STD_ERROR GPIO_InitPins(GPIO_t *Copy_GPIO);
/* Write group of pins value */
STD_ERROR GPIO_WritePins(GPIO_t *Copy_GPIO,u8 GPIO_VALUE);


/* The below functions access specific pin only  */
STD_ERROR GPIO_GetPinVal(void* GPIO_PORT,u16 GPIO_PIN,u32 *PinValue);
STD_ERROR GPIO_InitPin(void* GPIO_PORT,u16 GPIO_PIN,u8 GPIO_MODE);
STD_ERROR GPIO_WritePin(void* GPIO_PORT,u32 GPIO_PIN,u8 GPIO_VALUE);

/* Set the port to specific value */
STD_ERROR GPIO_writePortValue(void* GPIO_PORT , u16 PortValue);


#endif
