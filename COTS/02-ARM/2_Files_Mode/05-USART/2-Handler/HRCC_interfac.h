/************************************************************
Author :Mohamed Ibrahem
Version:v02
Date:31 March 2020
*************************************************************/
#ifndef HRCC_INTERFACE_H
#define HRCC_INTERFACE_H


/*AHP 11 */
/*APB1 01*/
/*APB2 10*/
/*DMA1EN: DMA1 clock enable									*/
#define HRCC_PERIPHERAL_AHBENR_DMA1              			    (0xC0000001)
/*DMA2EN: DMA2 clock enable*/
#define HRCC_PERIPHERAL_AHBENR_DMA2              		 	    (0xC0000002)
/*SRAMEN: SRAM interface clock enable*/
#define HRCC_PERIPHERAL_AHBENR_SRAM              		 	    (0xC0000004)
/*FLITFEN: FLITF clock enable*/
#define HRCC_PERIPHERAL_AHBENR_FLITF              			    (0xC0000010)
/*CRCEN: CRC clock enable*/
#define HRCC_PERIPHERAL_AHBENR_CRC                		 	    (0xC0000040)
/*FSMCEN: FSMC clock enable*/
#define HRCC_PERIPHERAL_AHBENR_FSMC              		 	    (0xC0000100)
/*SDIOEN: SDIO clock enable*/
#define HRCC_PERIPHERAL_AHBENR_SDIO              		 	    (0xC0000400)



/*AFIOEN: Alternate function IO clock enable*/
#define HRCC_PERIPHERAL_APB2ENR_AFIOEN              			 (0x80000001)
/*IOPAEN: IO port A clock enable*/
#define HRCC_PERIPHERAL_APB2ENR_IOPAEN              		 	 (0x80000004)
/*IOPBEN: IO port B clock enable*/
#define HRCC_PERIPHERAL_APB2ENR_IOPBEN              		 	 (0x80000008)
/*IOPCEN: IO port C clock enable*/
#define HRCC_PERIPHERAL_APB2ENR_IOPCEN              			 (0x80000010)
/*IOPDEN: IO port D clock enable*/
#define HRCC_PERIPHERAL_APB2ENR_IOPDEN              		 	 (0x80000020)
/*IOPEEN: IO port E clock enable*/
#define HRCC_PERIPHERAL_APB2ENR_IOPEEN              		 	 (0x80000040)
/*IOPFEN: IO port F clock enable*/
#define HRCC_PERIPHERAL_APB2ENR_IOPFEN              		 	 (0x80000080)
/*IOPGEN: IO port G clock enable*/
#define HRCC_PERIPHERAL_APB2ENR_IOPGEN              			 (0x80000100)
/*ADC1EN: ADC 1 interface clock enable*/
#define HRCC_PERIPHERAL_APB2ENR_ADC1EN              		 	 (0x80000200)
/*ADC2EN: ADC 2 interface clock enable*/
#define HRCC_PERIPHERAL_APB2ENR_ADC2EN              		 	 (0x80000400)
/*TIM1EN: TIM1 timer clock enable*/
#define HRCC_PERIPHERAL_APB2ENR_TIM1EN              			 (0x80000800)
/*SPI1EN: SPI1 clock enable*/
#define HRCC_PERIPHERAL_APB2ENR_SPI1EN              		 	 (0x80001000)
/*TIM8EN: TIM8 Timer clock enable*/
#define HRCC_PERIPHERAL_APB2ENR_TIM8EN              		 	 (0x80002000)
/*USART1EN: USART1 clock enable*/
#define HRCC_PERIPHERAL_APB2ENR_USART1EN              		     (0x80004000)
/*ADC3EN: ADC3 interface clock enable*/
#define HRCC_PERIPHERAL_APB2ENR_ADC3EN                			 (0x80008000)
/*TIM9EN: TIM9 timer clock enable*/
#define HRCC_PERIPHERAL_APB2ENR_TIM9EN               		 	 (0x80080000)
/*TIM10EN: TIM10 timer clock enable*/
#define HRCC_PERIPHERAL_APB2ENR_TIM10EN                  		 (0x80100000)
/*TIM11EN: TIM11 timer clock enable*/
#define HRCC_PERIPHERAL_APB2ENR_TIM11EN                  		 (0x80200000)



/*TIM2EN: TIM2 timer clock enable*/
#define HRCC_PERIPHERAL_APB1ENR_TIM2EN               			 (0x40000001)
/*TIM3EN: TIM3 timer clock enable*/
#define HRCC_PERIPHERAL_APB1ENR_TIM3EN               		 	 (0x40000002)
/*TIM4EN: TIM4 timer clock enable*/
#define HRCC_PERIPHERAL_APB1ENR_TIM4EN               		 	 (0x40000004)
/*TIM5EN: TIM5 timer clock enable*/
#define HRCC_PERIPHERAL_APB1ENR_TIM5EN               			 (0x40000008)
/*TIM6EN: TIM6 timer clock enable*/
#define HRCC_PERIPHERAL_APB1ENR_TIM6EN               		 	 (0x40000010)
/*TIM7EN: TIM7 timer clock enable*/
#define HRCC_PERIPHERAL_APB1ENR_TIM7EN               		 	 (0x40000020)
/*TIM12EN: TIM12 timer clock enable*/
#define HRCC_PERIPHERAL_APB1ENR_TIM12EN               		     (0x40000040)
/*TIM13EN: TIM13 timer clock enable*/
#define HRCC_PERIPHERAL_APB1ENR_TIM13EN               		     (0x40000080)
/*TIM14EN: TIM14 timer clock enable*/
#define HRCC_PERIPHERAL_APB1ENR_TIM14EN               		     (0x40000100)
/*WWDGEN: Window watchdog clock enable*/
#define HRCC_PERIPHERAL_APB1ENR_WWDGEN               		 	 (0x40000800)
/*SPI2EN: SPI2 clock enable*/
#define HRCC_PERIPHERAL_APB1ENR_SPI2EN               			 (0x40004000)
/*SPI3EN: SPI 3 clock enable*/
#define HRCC_PERIPHERAL_APB1ENR_SPI3EN               		 	 (0x40008000)
/*USART2EN: USART2 clock enable*/
#define HRCC_PERIPHERAL_APB1ENR_USART2EN               	         (0x40020000)
/*USART3EN: USART3 clock enable*/
#define HRCC_PERIPHERAL_APB1ENR_USART3EN               	         (0x40040000)
/*UART4EN: USART4 clock enable*/
#define HRCC_PERIPHERAL_APB1ENR_UART4EN               	         (0x40080000)
/*UART5EN: USART5 clock enable*/
#define HRCC_PERIPHERAL_APB1ENR_UART5EN               	         (0x40100000)
/*I2C1EN: I2C1 clock enable*/
#define HRCC_PERIPHERAL_APB1ENR_I2C1EN               		 	 (0x40200000)
/*I2C2EN: I2C2 clock enable*/
#define HRCC_PERIPHERAL_APB1ENR_I2C2EN               		 	 (0x40400000)
/*USBEN: USB clock enable*/
#define HRCC_PERIPHERAL_APB1ENR_USBEN               		 	 (0x40800000)
/*CANEN: CAN clock enable*/
#define HRCC_PERIPHERAL_APB1ENR_CANEN               		 	 (0x42000000)
/*BKPEN: Backup interface clock enable*/
#define HRCC_PERIPHERAL_APB1ENR_BKPEN               		 	 (0x48000000)
/*PWREN: Power interface clock enable*/
#define HRCC_PERIPHERAL_APB1ENR_PWREN               		 	 (0x50000000)
/*DACEN: DAC interface clock enable*/
#define HRCC_PERIPHERAL_APB1ENR_DACEN               		 	 (0x60000000)



/*SRC */
#define HRCC_CLOCK_8_MHZ_ENTERNAL                                 1
#define HRCC_CLOCK_8_MHZ_INTERNAL                                 2
#define HRCC_CLOCK_16_MHZ                                         0x80000000
#define HRCC_CLOCK_24_MHZ                                         0x80040000
#define HRCC_CLOCK_32_MHZ                                         0x80080000
#define HRCC_CLOCK_40_MHZ                                         0x800C0000
#define HRCC_CLOCK_48_MHZ                                         0x80100000
#define HRCC_CLOCK_56_MHZ                                         0x80140000
#define HRCC_CLOCK_64_MHZ                                         0x80180000
#define HRCC_CLOCK_72_MHZ                                         0x801C0000
/*Div /2*/
#define HRCC_CLOCK_12_MHZ                                         RCC_CFGR_PLLMUL_MUL_3
#define HRCC_CLOCK_20_MHZ                                         RCC_CFGR_PLLMUL_MUL_5
#define HRCC_CLOCK_28_MHZ                                         RCC_CFGR_PLLMUL_MUL_7
#define HRCC_CLOCK_36_MHZ                                         RCC_CFGR_PLLMUL_MUL_9
#define HRCC_CLOCK_44_MHZ                                         RCC_CFGR_PLLMUL_MUL_11
#define HRCC_CLOCK_52_MHZ                                         RCC_CFGR_PLLMUL_MUL_13
#define HRCC_CLOCK_60_MHZ                                         RCC_CFGR_PLLMUL_MUL_15






STD_ERROR HRCC_SetSysClock(u32 HRCC_CLOCK);



STD_ERROR HRCC_ConfigurePLL(u32 RCC_CFGR_PLLSRC,u32 RCC_CFGR_PLLMUL_MUL,u32 RCC_CFGR_PLLXTPRE);
STD_ERROR HRCC_SetSystemClock(u32 RCC_CFGR_SW);


STD_ERROR HRCC_EnablePeripheral(u32 HRCC_PERIPHERAL);
STD_ERROR HRCC_DisablePeripheral(u32 HRCC_PERIPHERAL);
u32 HRCC_GetAPB1_Speed(void);
u32 HRCC_GetAPB2_Speed(void);


#endif
