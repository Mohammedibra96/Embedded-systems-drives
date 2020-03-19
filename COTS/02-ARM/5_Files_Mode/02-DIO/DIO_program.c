#include"STD_Types.h"
#include"BIT_MATH.h"
#include"DIO_register.h"
#include"DIO_interface.h"
#include"DIO_private.h"
#include"DIO_config.h"


void DIO_SetPinMode(u8 port ,u8 Pin,u8 Mode)
{
  switch(port)
  {
    case 'A':
      if(Pin<=7)
      {
        /*clear 4 bits */
        PORTA_CRL&=~(0b1111)<<(Pin*4);
        /*Set mode*/
        PORTA_CRL|=Mode<<(Pin*4);
      }
      else if(Pin<=15)
        {
          Pin=Pin-8;
        /*clear 4 bits */
        PORTA_CRL&=~(0b1111<<(Pin*4));
        /*Set mode*/
        PORTA_CRL|=(Mode<<(Pin*4));

        }
    break;
    case 'B':
          if(Pin<=7)
      {
        /*clear 4 bits */
        PORTB_CRL&=~(0b1111)<<(Pin*4);
        /*Set mode*/
        PORTB_CRL|=Mode<<(Pin*4);
      }
      else if(Pin<=15)
        {
          Pin=Pin-8;
        /*clear 4 bits */
        PORTB_CRL&=~(0b1111<<(Pin*4));
        /*Set mode*/
        PORTB_CRL|=(Mode<<(Pin*4));

        }
    break;
    case 'C':
          if((Pin>=13)&& (Pin<=15))
      {
        /*clear 4 bits */
        PORTC_CRL&=~(0b1111)<<(Pin*4);
        /*Set mode*/
        PORTC_CRL|=Mode<<(Pin*4);
      }
    break;
  }
}
void DIO_SetPinVal(u8 Port,u8 Pin,u8 Val)
{
  switch(Port)
  case 'A':
  if(Val==1)
  {
    SET_BIT(PORTA,Pin);
  }
  else 
  {
    CLR_BIT(PORTA,Pin);
  }
  break;
  case 'B':
  if(Val==1)
  {
    SET_BIT(PORTB,Pin);
  }
  else 
  {
    CLR_BIT(PORTB,Pin);
  }
  break;

  case 'C':
  if(Val==1)
  {
    SET_BIT(PORTC,Pin);
  }
  else 
  {
    CLR_BIT(PORTC,Pin);
  }
  break;
}
u8 DIO_GetPinVal(u8 Port,u8 Pin)
{
  GET_BIT(Port,Bit_Num)
  switch(Port)
{
  case 'A':
 
    return (GET_BIT(PORTA,Pin));
 
  case 'B':

    return (GET_BIT(PORTB,Pin));

  case 'C':
      return (GET_BIT(PORTC,Pin));

  }
}
