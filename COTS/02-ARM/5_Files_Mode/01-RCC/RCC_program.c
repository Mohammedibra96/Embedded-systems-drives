#include"STD_Types.h"
#include"BIT_MATH.h"
#include"RCC_register.h"
#include"RCC_interface.h"
#include"RCC_private.h"
#include"RCC_config.h"






extern void RCC_Init(void)
{
  /*
  HSI ->off
  PLL ->OFF
  HSE ->on 
  CSS ->off
  */
  RCC_CR=0x00010000;
  /*
  sysclk        ->HSE
  AHP,APB1,APB2 ->Systemclk 'No prescaler'
  MCO           ->Not connected
  */
  RCC_CFGR=0x00000001;
  
  
}


extern void RCC_EnablePerphiralClock(u8 Bus,u8 Prephiral)
{
  switch(Bus)
  {
    case 0:SET_BIT(RCC_AHBENR,Prephiral);
    break;
    case 1:SET_BIT(RCC_AHBENR,Prephiral);
    break;
    case 2:SET_BIT(RCC_AHBENR,Prephiral);
    break;
  }
}
extern void RCC_DisablePerphiralClock(u8 Bus,u8 Preephiral)
{
  switch(Bus)
  {
    case 0:CLR_BIT(RCC_AHBENR,Preephiral);
    break;
    case 1:CLR_BIT(RCC_AHBENR,Preephiral);
    break;
    case 2:CLR_BIT(RCC_AHBENR,Preephiral);
    break;
  }
}