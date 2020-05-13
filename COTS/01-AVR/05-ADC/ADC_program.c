#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "ADC_register.h"
#include "ADC_interfac.h"
#include "ADC_private.h"
#include "ADC_config.h"
#include"CLCD_interfac.h"


#define ADC_IDEL   1
#define ADC_BUSY   2
#define ADC_NUMBER_OF_USED_CHANNELS    2


//ADC_chaintype ADC_Arr[ADC_NUMBER_OF_USED_CHANNELS];


u8 EndOfJobNotifi=0;
u8 ADC_Value[8]={0};
u8 temp_index=0;

u8 Status=ADC_IDEL;
u8 ADC_Index[ADC_NUMBER_OF_USED_CHANNELS]={ADC_FIRST_CHANNEL,ADC_SECOND_CHANNEL};



static void (*ADC_pvCallBack_Func)(void)=NULL;

void ADC_voidInit(void)
{
	/*
  8 bit mode ,AVCC ref voltage,polling (not interrupt)
	 */

	/*AVCC refrence voltage*/
	CLR_BIT(ADMUX,REFS1_BIT);
	SET_BIT(ADMUX,REFS0_BIT);

#if ADC_MODE==ADC_8_BITS
	/* Activate left Adjust mode*/
	SET_BIT(ADMUX,ADLAR_BIT);
#elif ADC_MODE==ADC_10_BITS
	/* Activate RIGHT Adjust mode*/
	CLR_BIT(ADMUX,ADLAR_BIT);
#endif

	/*ADC Enable */
	SET_BIT(ADCSRA,ADEN_BIT);
	/*Prescaler*/
	SET_BIT(ADCSRA,ADPS2_BIT);
	SET_BIT(ADCSRA,ADPS1_BIT);
	SET_BIT(ADCSRA,ADPS0_BIT);

}






STD_Error ADC_StarConversion_SYNC(u8 Channel,u16 *Value )
{
	if(Status==ADC_BUSY)
	{
		return NOK;
	}
	Status=ADC_BUSY;
	u8 Counter=0;
	ADMUX&=0b11100000;
	ADMUX|=Channel;
	/*Start conversion*/
	SET_BIT(ADCSRA,ADSC_BIT);
	/*Polling on the Conversion Complete Flag*/
	while((GET_BIT(ADCSRA,ADIF_BIT))==0 || Counter==ADC_TIME_OUT)
	{
		Counter++;
	}
	if(Counter==ADC_TIME_OUT)
		return NOK;
	/*Clear The flag*/
	SET_BIT(ADCSRA,ADIF_BIT);
	/*Get the Result*/

#if ADC_MODE==ADC_8_BITS
	*Value=ADCH;
#elif ADC_MODE==ADC_10_BITS
	*Value=ADCL_ADCH;
#endif

	Status=ADC_IDEL;
	return OK;

}


STD_Error ADC_StarConversion_ASYNC(u8 Channel)
{
	if(Status==ADC_BUSY)
		return NOK;
	ADC_EnableInterrupt();
	EndOfJobNotifi=0;
	Status=ADC_BUSY;
	ADMUX&=0b11100000;
	ADMUX|=Channel;
	/*Start conversion*/
	SET_BIT(ADCSRA,ADSC_BIT);
	return OK;
}


void ADC_SetCallBack(void(*pointerfun))
{
	if(pointerfun!=NULL)
	{
		ADC_pvCallBack_Func=pointerfun;
	}
}



void __vector_16(void)
{

#if ADC_MODE==ADC_8_BITS
	ADC_Value[ADC_Index[temp_index++]]=ADCH;
#elif ADC_MODE==ADC_10_BITS
	ADC_Value[ADC_Index[temp_index++]]=ADCL_ADCH;
#endif

	if (temp_index == ADC_NUMBER_OF_USED_CHANNELS)
	{
		temp_index=0;
		EndOfJobNotifi=1;

	}
	if(ADC_pvCallBack_Func!=NULL)
	{
		ADC_pvCallBack_Func();
	}
	Status=ADC_IDEL;
	if(EndOfJobNotifi==0)
		ADC_StarConversion_ASYNC(ADC_Index[temp_index]);
}

u16 ADC_GetValue(u8 Channel)
{
	Status=ADC_IDEL;
	return ADC_Value[Channel];


}


void ADC_EnableInterrupt(void)
{
	SET_BIT(ADCSRA,ADIE_BIT);

}
void ADC_DisableInterrupt(void)
{
	CLR_BIT(ADCSRA,ADIE_BIT);
}


u8 ADC_GetEndOfJobNotification(void)
{
	return EndOfJobNotifi;
}
