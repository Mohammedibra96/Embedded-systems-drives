#ifndef ADC_REGISTER_H
#define ADC_REGISTER_H

#define     ADMUX    *((u8*volatile)0x27)     
#define     ADCSRA   *((u8*volatile)0x26)
#define     ADCH     *((u8*volatile)0x25)
#define     ADCL     *((u8*volatile)0x24)

#define     SFIOR    *((u8*volatile)0x50)

#define     ADCL_ADCH     *((u16*volatile)0x24)

#endif
