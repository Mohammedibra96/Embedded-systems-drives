/*
Duthor :MohDmed Ibrahem 
Version:v01
Date:12-12-2019
/************************************************************
*/




#ifndef PORT_PRIVATE_H
#define PORT_PRIVATE_H
//#define PORTA_Dir  conc(Pin0,Pin1,Pin2,Pin3,Pin4,Pin5,Pin6,Pin7)


#define Conc(b7,b6,b5,b4,b3,b2,b1,b0) Conc_Helper(b7,b6,b5,b4,b3,b2,b1,b0)
#define Conc_Helper(b7,b6,b5,b4,b3,b2,b1,b0) 0b##b7##b6##b5##b4##b3##b2##b1##b0
#define PORTA_DIR   Conc(PORTA_PIN7_DIR,PORTA_PIN6_DIR,PORTA_PIN5_DIR,PORTA_PIN4_DIR,PORTA_PIN3_DIR,PORTA_PIN2_DIR,PORTA_PIN1_DIR,PORTA_PIN0_DIR)
#define PORTB_DIR   Conc(PORTB_PIN7_DIR,PORTB_PIN6_DIR,PORTB_PIN5_DIR,PORTB_PIN4_DIR,PORTB_PIN3_DIR,PORTB_PIN2_DIR,PORTB_PIN1_DIR,PORTB_PIN0_DIR)
#define PORTC_DIR   Conc(PORTC_PIN7_DIR,PORTC_PIN6_DIR,PORTC_PIN5_DIR,PORTC_PIN4_DIR,PORTC_PIN3_DIR,PORTC_PIN2_DIR,PORTC_PIN1_DIR,PORTC_PIN0_DIR)
#define PORTD_DIR   Conc(PORTD_PIN7_DIR,PORTD_PIN6_DIR,PORTD_PIN5_DIR,PORTD_PIN4_DIR,PORTD_PIN3_DIR,PORTD_PIN2_DIR,PORTD_PIN1_DIR,PORTD_PIN0_DIR)



/*
 *  For initialization
 * */


#define Conc(b7,b6,b5,b4,b3,b2,b1,b0) Conc_Helper(b7,b6,b5,b4,b3,b2,b1,b0)
#define Conc_Helper(b7,b6,b5,b4,b3,b2,b1,b0) 0b##b7##b6##b5##b4##b3##b2##b1##b0
#define PORTA_Init   Conc(PORTA_PIN7_InintalValue,PORTA_PIN6_InintalValue,PORTA_PIN5_InintalValue,PORTA_PIN4_InintalValue,PORTA_PIN3_InintalValue,PORTA_PIN2_InintalValue,PORTA_PIN1_InintalValue,PORTA_PIN0_InintalValue)
#define PORTB_Init   Conc(PORTB_PIN7_InintalValue,PORTB_PIN6_InintalValue,PORTB_PIN5_InintalValue,PORTB_PIN4_InintalValue,PORTB_PIN3_InintalValue,PORTB_PIN2_InintalValue,PORTB_PIN1_InintalValue,PORTB_PIN0_InintalValue)
#define PORTC_Init   Conc(PORTC_PIN7_InintalValue,PORTC_PIN6_InintalValue,PORTC_PIN5_InintalValue,PORTC_PIN4_InintalValue,PORTC_PIN3_InintalValue,PORTC_PIN2_InintalValue,PORTC_PIN1_InintalValue,PORTC_PIN0_InintalValue)
#define PORTD_Init   Conc(PORTD_PIN7_InintalValue,PORTD_PIN6_InintalValue,PORTD_PIN5_InintalValue,PORTD_PIN4_InintalValue,PORTD_PIN3_InintalValue,PORTD_PIN2_InintalValue,PORTD_PIN1_InintalValue,PORTD_PIN0_InintalValue)








#endif
