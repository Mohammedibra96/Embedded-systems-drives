#ifndef ADC_INTERFACE_H
#define ADC_INTERFACE_H


/*
For ADMUX register
 */
#define MUX0_BIT   0
#define MUX1_BIT   1
#define MUX2_BIT   2
#define MUX3_BIT   3
#define MUX4_BIT   4
#define ADLAR_BIT  5
#define REFS0_BIT  6
#define REFS1_BIT  7


		/*For ADCSRA   */


#define ADPS0_BIT     0
#define ADPS1_BIT     1
#define ADPS2_BIT     2
#define ADIE_BIT      3
#define ADIF_BIT      4
#define ADATE_BIT     5
#define ADSC_BIT      6
#define ADEN_BIT      7




typedef struct
{
u8 *ChannelArr;
u8 Chainlen;

}ADC_chaintype;





/* Refrence Voltage */

#define ADMUX_REF_VOLATGE_MASK                                     (u8)(0b00111111)

#define ADMUX_REF_VOLATGE_AREF                                     (u8)(0b00000000)
#define ADMUX_REF_VOLATGE_AVCC                                     (u8)(0b01000000)
#define ADMUX_REF_VOLTAGE_INTERNAL_2.56                            (u8)(0b11000000)



#define LEFT_ADJUST                                           (u8)(0b00100000)
#define RIGHT_ADJUST                                          (u8)(0b00000000)



/*Input Channel */
#define ADMUX_CHANNEL_MASK                                          (u8)(0b11100000)

#define ADMUX_CHANNEL_SINGALE_ADCO                                  (u8)(0)
#define ADMUX_CHANNEL_SINGLE_ADC1                                   (u8)(1)
#define ADMUX_CHANNEL_SINGLE_ADC2                                   (u8)(2)
#define ADMUX_CHANNEL_SINGLE_ADC3                                   (u8)(3)
#define ADMUX_CHANNEL_SINGLE_ADC4                                   (u8)(4)
#define ADMUX_CHANNEL_SINGLE_ADC5                                   (u8)(5)
#define ADMUX_CHANNEL_SINGLE_ADC6                                   (u8)(6)
#define ADMUX_CHANNEL_SINGLE_ADC7                                   (u8)(7)


#define ADMUX_CHANNEL_DIFFERENTIAL_ADC0_ADC0_GAIN_10                (u8)(8)
#define ADMUX_CHANNEL_DIFFERENTIAL_ADC1_ADC0_GAIN_10                (u8)(9)
#define ADMUX_CHANNEL_DIFFERENTIAL_ADC0_ADC0_GAIN_200               (u8)(10)
#define ADMUX_CHANNEL_DIFFERENTIAL_ADC1_ADC0_GAIN_200               (u8)(11)
#define ADMUX_CHANNEL_DIFFERENTIAL_ADC2_ADC2_GAIN_10                (u8)(12)
#define ADMUX_CHANNEL_DIFFERENTIAL_ADC3_ADC2_GAIN_10                (u8)(13)
#define ADMUX_CHANNEL_DIFFERENTIAL_ADC2_ADC2_GAIN_200               (u8)(14)
#define ADMUX_CHANNEL_DIFFERENTIAL_ADC3_ADC2_GAIN_200               (u8)(15)
#define ADMUX_CHANNEL_DIFFERENTIAL_ADC0_ADC1_GAIN_1                 (u8)(16)
#define ADMUX_CHANNEL_DIFFERENTIAL_ADC1_ADC1_GAIN_1                 (u8)(17)
#define ADMUX_CHANNEL_DIFFERENTIAL_ADC2_ADC1_GAIN_1                 (u8)(18)
#define ADMUX_CHANNEL_DIFFERENTIAL_ADC3_ADC1_GAIN_1                 (u8)(19)
#define ADMUX_CHANNEL_DIFFERENTIAL_ADC4_ADC1_GAIN_1                 (u8)(20)
#define ADMUX_CHANNEL_DIFFERENTIAL_ADC5_ADC1_GAIN_1                 (u8)(21)
#define ADMUX_CHANNEL_DIFFERENTIAL_ADC6_ADC1_GAIN_1                 (u8)(22)
#define ADMUX_CHANNEL_DIFFERENTIAL_ADC7_ADC1_GAIN_1                 (u8)(23)
#define ADMUX_CHANNEL_DIFFERENTIAL_ADC0_ADC2_GAIN_1                 (u8)(24)
#define ADMUX_CHANNEL_DIFFERENTIAL_ADC1_ADC2_GAIN_1                 (u8)(25)
#define ADMUX_CHANNEL_DIFFERENTIAL_ADC2_ADC2_GAIN_1                 (u8)(26)
#define ADMUX_CHANNEL_DIFFERENTIAL_ADC3_ADC2_GAIN_1                 (u8)(27)
#define ADMUX_CHANNEL_DIFFERENTIAL_ADC4_ADC2_GAIN_1                 (u8)(28)
#define ADMUX_CHANNEL_DIFFERENTIAL_ADC5_ADC2_GAIN_1                 (u8)(29)
#define ADMUX_CHANNEL_SINGLE_1.22V                                  (u8)(30)
#define ADMUX_CHANNEL_SINGLE_0V                                     (u8)(31)


/*Masks For ADCSRA*/

#define ADCSRA_ADC_ENABLE                                           (u8)(0b10000000)
#define ADCSRA_ADC_DISABLE                                          (u8)(0b01111111)


#define ADCSRA_ADC_START_CONVERSION                                 (u8)(64)


#define ADCSRA_AUTO_TRIGGER_ENABLE                                  (u8)(32)
#define ADCSRA_INTERRUPT_FLAG                                       (u8)(16)

#define ADCSRA_INTERRUPT_ENABLE                                     (u8)(8)



#define ADCSRA_PRESCALER_MASK                                       (u8)(0b11111000)

#define ADCSRA_PRESCALER_2                                          (u8)(0)
#define ADCSRA_PRESCALER_2_RESERVED                                 (u8)(1)
#define ADCSRA_PRESCALER_4                                          (u8)(2)
#define ADCSRA_PRESCALER_8                                          (u8)(3)
#define ADCSRA_PRESCALER_16                                         (u8)(4)
#define ADCSRA_PRESCALER_32                                         (u8)(5)
#define ADCSRA_PRESCALER_64                                         (u8)(6)
#define ADCSRA_PRESCALER_128                                        (u8)(7)




/*The first channel that can be converted in the channing*/
#define ADC_FIRST_CHANNEL	ADMUX_CHANNEL_SINGLE_ADC2
#define ADC_SECOND_CHANNEL	ADMUX_CHANNEL_SINGLE_ADC1
#define ADC_THIRD_CHANNEL	ADMUX_CHANNEL_SINGLE_ADC1
#define ADC_FORTH_CHANNEL	ADMUX_CHANNEL_SINGLE_ADC1
#define ADC_FIFTH_CHANNEL	ADMUX_CHANNEL_SINGLE_ADC1
#define ADC_SIXTH_CHANNEL	ADMUX_CHANNEL_SINGLE_ADC1
#define ADC_SEVENTH_CHANNEL	ADMUX_CHANNEL_SINGLE_ADC1
#define ADC_EIGHTTH_CHANNEL	ADMUX_CHANNEL_SINGLE_ADC1





void ADC_voidInit(void);
STD_Error ADC_StarConversion_SYNC(u8 Channel,u16 *Value );
void ADC_EnableInterrupt(void);
void ADC_DisableInterrupt(void);
/*plz enter the ADC_START_CHANNEL the channel u want to start with */
STD_Error ADC_StarConversion_ASYNC(u8 Channel);
u16 ADC_GetValue(u8 Channel);
void ADC_SetCallBack(void(*pointerfun));
u8 ADC_GetEndOfJobNotification(void);


#endif
