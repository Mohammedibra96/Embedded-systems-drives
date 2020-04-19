#include"STD_Types.h"



/*Speed of the Ecternal clock                 */
#define EXTERNAL_CLK_SPEED                      8000000
/*Speed of the Internal clock                */                                            
#define INTERNAL_CLK_SPEED                      8000000


#define RCC_STATUS_ON                           1
#define RCC_STATUS_OFF                          0

#define RCC_READY         		                  1
#define RCC_NOT_READY      		                  0

#define CLOCK_HSI 				                      0
#define CLOCK_HSE                               1
#define CLOCK_PLL                               2


#define	RCC_PORTA				  	                    1
#define	RCC_PORTB				  	                    2
#define	RCC_PORTC				  	                    3



/*This defines for HSION Ready*/

#define RCC_CR_HSI_ON_MASK                      0x00000001 
#define RCC_CR_HSICAL_MASK                      0x0000FF00
                                                
                                                
/*This defines for HSI Ready*/                  
                                                
#define RCC_CR_HSI_RDY_MASK				              0x00000002
/*This defines for HSE ON */                    
#define RCC_CR_HSE_ON_MASK   	                     0x00010000
                                                
/*This defines for HSE Ready */                 
                                                
#define RCC_CR_HSE_RDY_MASK                     0x00020000
                                                
/*This defines for HSEBYP*/                     
#define RCC_CR_HSEBY_MASK                       0x00040000

/*This defines for CSSON*/

#define RCC_CR_CSS_ON_MASK                      0x00080000
                                                
                                                
/*This define for PLLON */                      
#define RCC_CR_PLL_ON_MASK                      0x01000000
                                                
/*This defines for PLL Ready*/                  
                                                
#define RCC_CR_PLL_RDY_MASK                     0x02000000

/*This Defines for HSITRIM*/

#define RCC_CR_HSITRIM_MASK                     0xFFFFFF07
#define RCC_CR_HSITRIM_TRIM_0_VALUE             0x00000000
#define RCC_CR_HSITRIM_TRIM_1_VALUE             0x00000008
#define RCC_CR_HSITRIM_TRIM_2_VALUE             0x00000010
#define RCC_CR_HSITRIM_TRIM_3_VALUE             0x00000018
#define RCC_CR_HSITRIM_TRIM_4_VALUE             0x00000020
#define RCC_CR_HSITRIM_TRIM_5_VALUE             0x00000028
#define RCC_CR_HSITRIM_TRIM_6_VALUE             0x00000030
#define RCC_CR_HSITRIM_TRIM_7_VALUE             0x00000038
#define RCC_CR_HSITRIM_TRIM_8_VALUE             0x00000040
#define RCC_CR_HSITRIM_TRIM_9_VALUE             0x00000048
#define RCC_CR_HSITRIM_TRIM_10_VALUE            0x00000050
#define RCC_CR_HSITRIM_TRIM_11_VALUE            0x00000058
#define RCC_CR_HSITRIM_TRIM_12_VALUE            0x00000060
#define RCC_CR_HSITRIM_TRIM_13_VALUE            0x00000068
#define RCC_CR_HSITRIM_TRIM_14_VALUE            0x00000070
#define RCC_CR_HSITRIM_TRIM_15_VALUE            0x00000078
#define RCC_CR_HSITRIM_TRIM_16_VALUE            0x00000080
#define RCC_CR_HSITRIM_TRIM_17_VALUE            0x00000088
#define RCC_CR_HSITRIM_TRIM_18_VALUE            0x00000090
#define RCC_CR_HSITRIM_TRIM_19_VALUE            0x00000098
#define RCC_CR_HSITRIM_TRIM_20_VALUE            0x000000A0
#define RCC_CR_HSITRIM_TRIM_21_VALUE            0x000000A8
#define RCC_CR_HSITRIM_TRIM_22_VALUE            0x000000B0
#define RCC_CR_HSITRIM_TRIM_23_VALUE            0x000000B8
#define RCC_CR_HSITRIM_TRIM_24_VALUE            0x000000C0
#define RCC_CR_HSITRIM_TRIM_25_VALUE            0x000000C8
#define RCC_CR_HSITRIM_TRIM_26_VALUE            0x000000D0
#define RCC_CR_HSITRIM_TRIM_27_VALUE            0x000000D8
#define RCC_CR_HSITRIM_TRIM_28_VALUE            0x000000E0
#define RCC_CR_HSITRIM_TRIM_29_VALUE            0x000000E8
#define RCC_CR_HSITRIM_TRIM_30_VALUE            0x000000F0
#define RCC_CR_HSITRIM_TRIM_31_VALUE            0x000000F8



/*This defines For SW*/
#define RCC_CFGR_SW_MASK                        0xFFFFFFFC
#define RCC_CFGR_SW_HSI                         0x00000000
#define RCC_CFGR_SW_HSE                         0x00000001
#define RCC_CFGR_SW_PLL                         0x00000002
                                                
/*This define for SWS */                        
#define RCC_CFGR_SWS_MASK                       0x0000000C
#define RCC_CFGR_SWS_HSI                        0x00000000
#define RCC_CFGR_SWS_HSE                        0x00000004
#define RCC_CFGR_SWS_PLL                        0x00000008

/*This define for HPRE*/
#define RCC_CFGR_HPRE_MASK                      0xFFFFFF0F
#define RCC_CFGR_HPRE_SYSCLK_NOT_DIVIDED        0x00000000
#define RCC_CFGR_HPRE_SYSCLK_DIVIDED_2          0x00000080
#define RCC_CFGR_HPRE_SYSCLK_DIVIDED_4          0x00000090
#define RCC_CFGR_HPRE_SYSCLK_DIVIDED_8          0x000000A0
#define RCC_CFGR_HPRE_SYSCLK_DIVIDED_16         0x000000B0
#define RCC_CFGR_HPRE_SYSCLK_DIVIDED_64         0x000000C0
#define RCC_CFGR_HPRE_SYSCLK_DIVIDED_128        0x000000D0
#define RCC_CFGR_HPRE_SYSCLK_DIVIDED_256        0x000000E0
#define RCC_CFGR_HPRE_SYSCLK_DIVIDED_512        0x000000F0

/*This defines for APB1:*/
#define RCC_CFGR_PPRE1_MASK                     0xFFFFF8FF
#define RCC_CFGR_PPRE1_HCLK_NOT_DIVIDED         0x00000000
#define RCC_CFGR_PPRE1_HCLK_DIVIDED_2           0x00000400
#define RCC_CFGR_PPRE1_HCLK_DIVIDED_4           0x00000500
#define RCC_CFGR_PPRE1_HCLK_DIVIDED_8           0x00000600
#define RCC_CFGR_PPRE1_HCLK_DIVIDED_16          0x00000700


/*This defines for APB2:*/
#define RCC_CFGR_PPRE2_MASK                     0xFFFFC7FF
#define RCC_CFGR_PPRE2_HCLK_NOT_DIVIDED         0x00000000
#define RCC_CFGR_PPRE2_HCLK_DIVIDED_2           0x00002000
#define RCC_CFGR_PPRE2_HCLK_DIVIDED_4           0x00002800
#define RCC_CFGR_PPRE2_HCLK_DIVIDED_8           0x00003000
#define RCC_CFGR_PPRE2_HCLK_DIVIDED_16          0x00003800


/*This defines for ADC:*/
#define RCC_CFGR_ADC_MASK                       0xFFFF3FFF
#define RCC_CFGR_ADC_PCLK_DIVIDED_2             0x00004000
#define RCC_CFGR_ADC_PCLK_DIVIDED_4             0x00008000
#define RCC_CFGR_ADC_PCLK_DIVIDED_6             0x00003000
#define RCC_CFGR_ADC_PCLK_DIVIDED_8             0x0000C800


/*This defines for :For PLL source */
#define RCC_CFGR_PLLSRC_MASK                    0xFFF1FFFF
#define RCC_CFGR_PLLSRC_HSI_DIV2                0x00000000
#define RCC_CFGR_PLLSRC_HSE                     0x00010000

/*This defines For :PLL Divisor  */
#define RCC_CFGR_PLLXTPRE_MASK 				          0xFFFDFFFF
#define RCC_CFGR_PLLXTPRE_HSE                   0x00000000
#define RCC_CFGR_PLLXTPRE_HSE_DIV2              0x00020000


/*This Defined For PLL MUL Factor */
#define RCC_CFGR_PLLMUL_MASK                    0xFFC3FFFF
#define RCC_CFGR_PLLMUL_MUL_2                   0x00000000
#define RCC_CFGR_PLLMUL_MUL_3                   0x00040000
#define RCC_CFGR_PLLMUL_MUL_4                   0x00080000
#define RCC_CFGR_PLLMUL_MUL_5                   0x000C0000
#define RCC_CFGR_PLLMUL_MUL_6                   0x00100000
#define RCC_CFGR_PLLMUL_MUL_7                   0x00140000
#define RCC_CFGR_PLLMUL_MUL_8                   0x00180000
#define RCC_CFGR_PLLMUL_MUL_9                   0x001C0000
#define RCC_CFGR_PLLMUL_MUL_10                  0x00200000
#define RCC_CFGR_PLLMUL_MUL_11                  0x00240000
#define RCC_CFGR_PLLMUL_MUL_12                  0x00280000
#define RCC_CFGR_PLLMUL_MUL_13                  0x002C0000
#define RCC_CFGR_PLLMUL_MUL_14                  0x00300000
#define RCC_CFGR_PLLMUL_MUL_15                  0x00340000
#define RCC_CFGR_PLLMUL_MUL_16                  0x00380000
#define RCC_CFGR_PLLMUL_MUL_16_TOO              0x003C0000



/*This Defines for USB Prescaler                          */
#define RCC_CFGR_USBPRE_MASK                   0xFFBFFFFF
#define RCC_CFGR_USBPRE_PLL_DIV_1_5            0x00000000
#define RCC_CFGR_USBPRE_PLL_NOT_DIV            0x04000000


/*This Defines For MCO */
#define RCC_CFGR_MCO_MASK                     0xF8FFFFFF
#define RCC_CFGR_MCO_SYSCLK                   0x04000000
#define RCC_CFGR_MCO_HSI                      0x05000000
#define RCC_CFGR_MCO_HSE                      0x06000000
#define RCC_CFGR_MCO_PLL                      0x07000000

/**
 * This defines for RCC_APB2ENR
 *
 * */

#define RCC_APB2ENR_AFIOEN_MASK 		      0X00000001
#define RCC_APB2ENR_IOPAEN_MAKS			      0X00000004
#define RCC_APB2ENR_IOPBEN_MAKS			      0X00000008
#define RCC_APB2ENR_IOPCEN_MAKS			      0X00000010


/************************************************************
 * ********* AHB peripheral clock enable register ********* *
 * ********************** RCC_AHBENR ********************** *
 * *********************************************************/
/*DMA1EN: DMA1 clock enable*/
#define RCC_AHBENR_DMA1              			 (0x00000001)
/*DMA2EN: DMA2 clock enable*/
#define RCC_AHBENR_DMA2              		 	 (0x00000002)
/*SRAMEN: SRAM interface clock enable*/
#define RCC_AHBENR_SRAM              		 	 (0x00000004)
/*FLITFEN: FLITF clock enable*/
#define RCC_AHBENR_FLITF              			 (0x00000010)
/*CRCEN: CRC clock enable*/
#define RCC_AHBENR_CRC                		 	 (0x00000040)
/*FSMCEN: FSMC clock enable*/
#define RCC_AHBENR_FSMC              		 	 (0x00000100)
/*SDIOEN: SDIO clock enable*/
#define RCC_AHBENR_SDIO              		 	 (0x00000400)

/************************************************************
 * ******** APB2 peripheral clock enable register ********* *
 * ********************** RCC_APB2ENR ********************* *
 * *********************************************************/
/* RCC_AHBENR ENABLE */


/*AFIOEN: Alternate function IO clock enable*/
#define RCC_APB2ENR_AFIOEN              			 (0x00000001)
/*IOPAEN: IO port A clock enable*/
#define RCC_APB2ENR_IOPAEN              		 	 (0x00000004)
/*IOPBEN: IO port B clock enable*/
#define RCC_APB2ENR_IOPBEN              		 	 (0x00000008)
/*IOPCEN: IO port C clock enable*/
#define RCC_APB2ENR_IOPCEN              			 (0x00000010)
/*IOPDEN: IO port D clock enable*/
#define RCC_APB2ENR_IOPDEN              		 	 (0x00000020)
/*IOPEEN: IO port E clock enable*/
#define RCC_APB2ENR_IOPEEN              		 	 (0x00000040)
/*IOPFEN: IO port F clock enable*/
#define RCC_APB2ENR_IOPFEN              		 	 (0x00000080)
/*IOPGEN: IO port G clock enable*/
#define RCC_APB2ENR_IOPGEN              			 (0x00000100)
/*ADC1EN: ADC 1 interface clock enable*/
#define RCC_APB2ENR_ADC1EN              		 	 (0x00000200)
/*ADC2EN: ADC 2 interface clock enable*/
#define RCC_APB2ENR_ADC2EN              		 	 (0x00000400)
/*TIM1EN: TIM1 timer clock enable*/
#define RCC_APB2ENR_TIM1EN              			 (0x00000800)
/*SPI1EN: SPI1 clock enable*/
#define RCC_APB2ENR_SPI1EN              		 	 (0x00001000)
/*TIM8EN: TIM8 Timer clock enable*/
#define RCC_APB2ENR_TIM8EN              		 	 (0x00002000)
/*USART1EN: USART1 clock enable*/
#define RCC_APB2ENR_USART1EN              		 (0x00004000)
/*ADC3EN: ADC3 interface clock enable*/
#define RCC_APB2ENR_ADC3EN             			 (0x00008000)
/*TIM9EN: TIM9 timer clock enable*/
#define RCC_APB2ENR_TIM9EN               		 	 (0x00080000)
/*TIM10EN: TIM10 timer clock enable*/
#define RCC_APB2ENR_TIM10EN              		 (0x00100000)
/*TIM11EN: TIM11 timer clock enable*/
#define RCC_APB2ENR_TIM11EN              		 (0x00200000)


/************************************************************
 * ******** APB1 peripheral clock enable register  ******** *
 * ********************** RCC_APB1ENR ********************* *
 * *********************************************************/
/*TIM2EN: TIM2 timer clock enable*/
#define RCC_APB1ENR_TIM2EN               			 (0x00000001)
/*TIM3EN: TIM3 timer clock enable*/
#define RCC_APB1ENR_TIM3EN               		 	 (0x00000002)
/*TIM4EN: TIM4 timer clock enable*/
#define RCC_APB1ENR_TIM4EN               		 	 (0x00000004)
/*TIM5EN: TIM5 timer clock enable*/
#define RCC_APB1ENR_TIM5EN               			 (0x00000008)
/*TIM6EN: TIM6 timer clock enable*/
#define RCC_APB1ENR_TIM6EN               		 	 (0x00000010)
/*TIM7EN: TIM7 timer clock enable*/
#define RCC_APB1ENR_TIM7EN               		 	 (0x00000020)
/*TIM12EN: TIM12 timer clock enable*/
#define RCC_APB1ENR_TIM12EN               		 (0x00000040)
/*TIM13EN: TIM13 timer clock enable*/
#define RCC_APB1ENR_TIM13EN               		 (0x00000080)
/*TIM14EN: TIM14 timer clock enable*/
#define RCC_APB1ENR_TIM14EN               		 (0x00000100)
/*WWDGEN: Window watchdog clock enable*/
#define RCC_APB1ENR_WWDGEN               		 	 (0x00000800)
/*SPI2EN: SPI2 clock enable*/
#define RCC_APB1ENR_SPI2EN               			 (0x00004000)
/*SPI3EN: SPI 3 clock enable*/
#define RCC_APB1ENR_SPI3EN               		 	 (0x00008000)
/*USART2EN: USART2 clock enable*/
#define RCC_APB1ENR_USART2EN               		 (0x00020000)
/*USART3EN: USART3 clock enable*/
#define RCC_APB1ENR_USART3EN               		 (0x00040000)
/*UART4EN: USART4 clock enable*/
#define RCC_APB1ENR_UART4EN               		 (0x00080000)
/*UART5EN: USART5 clock enable*/
#define RCC_APB1ENR_UART5EN               		 (0x00100000)
/*I2C1EN: I2C1 clock enable*/
#define RCC_APB1ENR_I2C1EN               		 	 (0x00200000)
/*I2C2EN: I2C2 clock enable*/
#define RCC_APB1ENR_I2C2EN               		 	 (0x00400000)
/*USBEN: USB clock enable*/
#define RCC_APB1ENR_USBEN               		 	 (0x00800000)
/*CANEN: CAN clock enable*/
#define RCC_APB1ENR_CANEN               		 	 (0x02000000)
/*BKPEN: Backup interface clock enable*/
#define RCC_APB1ENR_BKPEN               		 	 (0x08000000)
/*PWREN: Power interface clock enable*/
#define RCC_APB1ENR_PWREN               		 	 (0x10000000)
/*DACEN: DAC interface clock enable*/
#define RCC_APB1ENR_DACEN               		 	 (0x20000000)



/*                      ProtoTypes for the Functions                         */
STD_ERROR RCC_SetClock_Status(u32 CLOCK,u32 RCC_STATUS);
STD_ERROR RCC_SetCSS_Status(u32 RCC_STATUS);
STD_ERROR RCC_SetHSEBYPASS_Status(u32 RCC_STATUS);
u32 RCC_GetClock_Status(u32 CLOCK);
STD_ERROR RCC_SetSystemClock(u32 RCC_CFGR_SW);
STD_ERROR RCC_GetSystemClock(u32 *CLOCK);
STD_ERROR RCC_SetPLLSource(u32 RCC_CFGR_PLLSRC);
void RCC_SetPLLMULL(u32 RCC_CFGR_PLLMUL_MUL);
STD_ERROR RCC_SetPortStatus(u32 RCC_PORT,u32 RCC_STATUS);
STD_ERROR RCC_SetAHP_Prescaler(u32 RCC_CFGR_HPRE);
u32 RCC_GetAHP_Prescaler();
STD_ERROR RCC_SetAPB1_Prescaler(u32 RCC_CFGR_PPRE1_HCLK);
u32 RCC_GetAPB1_Prescaler();
STD_ERROR RCC_SetAPB2_Prescaler(u32 RCC_CFGR_PPRE2_HCLK);
u32 RCC_GetAPB2_Prescaler();
STD_ERROR RCC_SetADC_Prescaler(u32 RCC_CFGR_ADC_PCLK);
STD_ERROR RCC_SetPLL_Divisor(u32 RCC_CFGR_PLLXTPRE);
STD_ERROR RCC_SetUSB_Prescaler(u32 RCC_CFGR_USBPRE_PLL);
STD_ERROR RCC_SetMCO(u32 RCC_CFGR_MCO);
u32 RCC_GetPLL_MUL_Factor();
STD_ERROR RCC_EnableAHP_PeripheralClock(u32 RCC_AHBENR );
STD_ERROR RCC_DisableAHP_PeripheralClock(u32 RCC_AHBENR);
STD_ERROR RCC_EnableAPB1_PeripheralClock(u32 RCC_APB1ENR );
STD_ERROR RCC_DisableAPB1_PeripheralClock(u32 RCC_APB1ENR);
STD_ERROR RCC_EnableAPB2_PeripheralClock(u32 RCC_APB2ENR );
STD_ERROR RCC_DisableAPB2_PeripheralClock(u32 RCC_APB2ENR);
u32 RCC_GetAHP_Speed();
