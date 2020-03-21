/*
Duthor :Mohamed Ibrahem 
Version:v01
Date:20-01-2020
/************************************************************
*/

#ifndef DEI_INTERFACE_H
#define DEI_INTERFACE_H


#define DEI_u8_INT0		1
#define DEI_u8_INT1		2
#define DEI_u8_INT2		3

#define DEI_u8_LOW_LEVEL			1
#define DEI_u8_ON_CHANGE			2
#define DEI_u8_FALLING_EDGE			3
#define DEI_u8_RISING_EDGE			4


/*Description: A function to initialize external interupt int0,int1,int2
 accourding to the configuration file
 Inputs:void
 Output:void

 * */
void DEI_voidInit();
/*Description: A function to Enable an external interrupt int0,int1,int2
 * accourding to the inputs
 *
 * Inputs:int number
 * DEI_u8_INT0
 * DEI_u8_INT1
 * DEI_u8_INT2
 * Outputs:STD_error
 *OK;
 *NOK;
 *NULLPointer;
 * */


STD_Error DEI_errIntEnable(u8 Copy_u8Idx);

/*Description: A function to Disable an external interrupt int0,int1,int2
 * accoarding to the inputs
 *
 * Inputs:int number
 * DEI_u8_INT0
 * DEI_u8_INT1
 * DEI_u8_INT2
 * Outputs:STD_error
 *OK;
 *NOK;
 *
 * */

STD_Error DEI_errIntDisable(u8 Copy_u8Idx);

/*
 * Description This function shall set the sence of the external interrupt accourding to the inputs
 * inputs:Copy_Idx
 * DEI_u8_INT0
 * DEI_u8_INT1O
 * DEI_u8_INT2
 *
 * Copy_u8SenceLevel
 *
 * DEI_u8_LOW_LEVEL
   DEI_u8_ON_CHANGE
   DEI_u8_FALLING_EDGE
   DEI_u8_RISING_EDGE
 *
 *
 *
 *
 * Outputs:
 *Ok
 *NOk
 *
 * */

STD_Error DEI_errSetSenseLevel(u8 Copy_Idx,u8 Copy_u8SenceLevel);
STD_Error DEI_errSetCallBack(u8 Copy_u8Idx,void (*Copy_pvCallBack));









#endif
