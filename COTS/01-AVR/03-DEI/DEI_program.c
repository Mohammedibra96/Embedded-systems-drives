/*
Duthor :Mohamed Ibrahem 
Version:v01
Date:20-01-2020
/************************************************************
*/


#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "DEI_register.h"
#include "DEI_interfac.h"
#include "DEI_private.h"
#include "DEI_config.h"



static void (*DEI_pvCallBack_Func[3])(void)={NULL,NULL,NULL};

//
//void DEI_Int1Init(void)
//{
//	SET_BIT(SREG,GI_BIT);
//
//	/*
//	 * Faling edge
//	 * **/
//	CLR_BIT(MCUCR,2);
//	SET_BIT(MCUCR,3);
//
//	/*
//	 * Enable int0
//	 *
//	 *
//	 * **/
//	SET_BIT(GICR,6);
//
//
//
//}
//
//
//void DEI_Int0Init(void)
//{
//
//	SET_BIT(SREG,GI_BIT);
//	/*
//	 * Rising edge
//	 * **/
//	CLR_BIT(MCUCR,0);
//	SET_BIT(MCUCR,1);
//	/*
//	 * Enable int1
//	 *
//	 *
//	 * **/
//	SET_BIT(GICR,7);
//
//}


void DEI_voidInit()
{

#if DEI_u8_INT0_SENSE ==LOW_LEVEL
	CLR_BIT(MCUCR,MCUCR_ISC00);
	CLR_BIT(MCUCR,MCUCR_ISC01);

#elif DEI_u8_INT0_SENSE ==ON_LEVEL
	SET_BIT(MCUCR,MCUCR_ISC00);
	CLR_BIT(MCUCR,MCUCR_ISC01);
#elif DEI_u8_INT0_SENSE ==FALLING_EDGE
	CLR_BIT(MCUCR,MCUCR_ISC00);
	SET_BIT(MCUCR,MCUCR_ISC01);

#elif	DEI_u8_INT0_SENSE ==RISING_EDGE
	SET_BIT(MCUCR,MCUCR_ISC00);
	SET_BIT(MCUCR,MCUCR_ISC01);
#else
#error "Wrong DEI_u8_INT0_SENSE"
#endif



#if DEI_u8_INT1_SENSE ==LOW_LEVEL
	CLR_BIT(MCUCR,MCUCR_ISC10);
	CLR_BIT(MCUCR,MCUCR_ISC11);

#elif DEI_u8_INT1_SENSE ==ON_LEVEL
	SET_BIT(MCUCR,MCUCR_ISC10);
	CLR_BIT(MCUCR,MCUCR_ISC11);
#elif DEI_u8_INT1_SENSE ==FALLING_EDGE
	CLR_BIT(MCUCR,MCUCR_ISC10);
	SET_BIT(MCUCR,MCUCR_ISC11);

#elif	DEI_u8_INT1_SENSE ==RISING_EDGE
	SET_BIT(MCUCR,MCUCR_ISC10);
	SET_BIT(MCUCR,MCUCR_ISC11);
#else
#error "Wrong DEI_u8_INT1_SENSE"
#endif



#if DEI_u8_INT2_SENSE ==FALLING_EDGE
	CLR_BIT(MCUCR,MCUCSR_ISC2);

#elif DEI_u8_INT0_SENSE ==RISING_EDGE
	SET_BIT(MCUCR,MCUCSR_ISC2);

#else
#error "Wrong DEI_u8_INT2_SENSE"
#endif




#if DEI_INT0==ENABLE
	SET_BIT(GICR,GICR_INT0);
#elif DEI_INT0==DISABLE
	CLR_BIT(GICR,GICR_INT0);
#else
#error "Wrong DEI_INT0"
#endif




#if DEI_INT1==ENABLE
	SET_BIT(GICR,GICR_INT1);
#elif DEI_INT1==DISABLE
	CLR_BIT(GICR,GICR_INT1);
#else
#error "Wrong DEI_INT1"
#endif


#if DEI_INT2==ENABLE
	SET_BIT(GICR,GICR_INT2);
#elif DEI_INT2==DISABLE
	CLR_BIT(GICR,GICR_INT2);
#else
#error "Wrong DEI_INT2"
#endif





}
STD_Error DEI_errIntEnable(u8 Copy_u8Idx)
{
	STD_Error Error=NOK;

	switch(Copy_u8Idx)
	{
	case DEI_u8_INT0:
		SET_BIT(GICR,GICR_INT0);
		Error=OK;
		break;
	case DEI_u8_INT1:
		SET_BIT(GICR,GICR_INT1);
		Error=OK;
		break;
	case  DEI_u8_INT2:
		SET_BIT(GICR,GICR_INT2);
		Error=OK;
		break;

	}

	return Error;

}
STD_Error DEI_errIntDisable(u8 Copy_u8Idx)
{
	STD_Error Error=NOK;
	switch(Copy_u8Idx)
	{
	case DEI_u8_INT0:
		CLR_BIT(GICR,GICR_INT0);
		Error=OK;
		break;
	case DEI_u8_INT1:
		CLR_BIT(GICR,GICR_INT1);
		Error=OK;
		break;
	case  DEI_u8_INT2:
		CLR_BIT(GICR,GICR_INT2);
		Error=OK;
		break;
	}
	return Error;
}



STD_Error DEI_errSetSenseLevel(u8 Copy_Idx,u8 Copy_u8SenceLevel)
{
	STD_Error Local_error=NOK;

	switch(Copy_Idx)
	{
	case DEI_u8_INT0:
		switch (Copy_u8SenceLevel)
		{
		case DEI_u8_LOW_LEVEL:
			CLR_BIT(MCUCR,MCUCR_ISC00);
			CLR_BIT(MCUCR,MCUCR_ISC01);
			Local_error=OK;
			break;
		case DEI_u8_ON_CHANGE:
			SET_BIT(MCUCR,MCUCR_ISC00);
			CLR_BIT(MCUCR,MCUCR_ISC01);
			Local_error=OK;
			break;
		case DEI_u8_FALLING_EDGE:
			CLR_BIT(MCUCR,MCUCR_ISC00);
			SET_BIT(MCUCR,MCUCR_ISC01);
			Local_error=OK;
			break;
		case DEI_u8_RISING_EDGE:
			SET_BIT(MCUCR,MCUCR_ISC00);
			SET_BIT(MCUCR,MCUCR_ISC01);
			Local_error=OK;
			break;
		}


		break;
		case DEI_u8_INT1:
			switch (Copy_u8SenceLevel)
			{
			case DEI_u8_LOW_LEVEL:
				CLR_BIT(MCUCR,MCUCR_ISC10);
				CLR_BIT(MCUCR,MCUCR_ISC11);
				Local_error=OK;
				break;
			case DEI_u8_ON_CHANGE:
				SET_BIT(MCUCR,MCUCR_ISC10);
				CLR_BIT(MCUCR,MCUCR_ISC11);
				Local_error=OK;
				break;
			case DEI_u8_FALLING_EDGE:
				CLR_BIT(MCUCR,MCUCR_ISC10);
				SET_BIT(MCUCR,MCUCR_ISC11);
				Local_error=OK;
				break;
			case DEI_u8_RISING_EDGE:
				SET_BIT(MCUCR,MCUCR_ISC10);
				SET_BIT(MCUCR,MCUCR_ISC11);
				Local_error=OK;
				break;
			}


			break;
			case DEI_u8_INT2:
				switch(Copy_u8SenceLevel)
				{
				case DEI_u8_FALLING_EDGE:
					CLR_BIT(MCUCR,MCUCSR_ISC2);
					Local_error=OK;
					break;
				case DEI_u8_RISING_EDGE:
					SET_BIT(MCUCR,MCUCSR_ISC2);
					Local_error=OK;
					break;
				}
				break;

	}
	return Local_error;
}



STD_Error DEI_errSetCallBack(u8 Copy_u8Idx,void (*Copy_pvCallBack))
{
	STD_Error Loca_error=OK;
	if(Copy_pvCallBack!=NULL)
	{
		if(Copy_u8Idx<3)
		{
			DEI_pvCallBack_Func[Copy_u8Idx]=Copy_pvCallBack;
		}
		else
		{
			Loca_error=NOK;
		}
	}

	return Loca_error;
}


void __vector_1(void)
{
	if(DEI_pvCallBack_Func[0]!=NULL)
	{
		DEI_pvCallBack_Func[0]();
	}

}
void __vector_2(void)
{
	if(DEI_pvCallBack_Func[1]!=NULL)
	{
		DEI_pvCallBack_Func[1]();
	}

}
void __vector_3(void)
{
	if(DEI_pvCallBack_Func[2]!=NULL)
	{
		DEI_pvCallBack_Func[2]();
	}

}


