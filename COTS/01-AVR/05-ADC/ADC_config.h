#ifndef ADC_CONFIG_H
#define ADC_CONFIG_H


#define ENABLE		1
#define DISABLE 	0


#define ADC_INTERRUPT		ENABLE
#define ADC_TIME_OUT 		10000





#define ADC_REF_VOLTAGE       ADMUX_REF_VOLATGE_AVCC

#define ADC_PRESCALER         ADCSRA_PRESCALER_8
#define ADC_ADJUST            LEFT_ADJUST


#define ADC_MODE			ADC_10_BITS
#define ADC_8_BITS			1
#define  ADC_10_BITS		2





#endif
