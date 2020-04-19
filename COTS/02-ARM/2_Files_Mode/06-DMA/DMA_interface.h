/**********************************************************************************************
Author :Mohamed Ibrahem
Version:1.0
Date:5 April 2020
Description:This Header file is used to interface with the DMA module in STM32f10x evaluation kit
 ***********************************************************************************************/

#ifndef DMA_INTERFACE_H
#define DMA_INTERFACE_H




#define DMA_CHANNEL_1     (u8)(0)
#define DMA_CHANNEL_2     (u8)(1)
#define DMA_CHANNEL_3     (u8)(2)
#define DMA_CHANNEL_4     (u8)(3)
#define DMA_CHANNEL_5     (u8)(4)
#define DMA_CHANNEL_6     (u8)(5)
#define DMA_CHANNEL_7     (u8)(6)


#define NUM_CHANNELS       (7)
/*********************************ISR Masks***********************/



/*Channel transfer error flag                                    */

#define DMA_ISR_TEIF_CH_1         0x00000008
#define DMA_ISR_TEIF_CH_2         0x00000080
#define DMA_ISR_TEIF_CH_3         0x00000800
#define DMA_ISR_TEIF_CH_4         0x00008000
#define DMA_ISR_TEIF_CH_5         0x00080000
#define DMA_ISR_TEIF_CH_6         0x00800000
#define DMA_ISR_TEIF_CH_7         0x08000000

#define DMA_ISR_TEIF_ALL          0x08888888

/*Channel half transfer flag                                     */
#define DMA_ISR_HTIF_CH_1         0x00000004
#define DMA_ISR_HTIF_CH_2         0x00000040
#define DMA_ISR_HTIF_CH_3         0x00000400
#define DMA_ISR_HTIF_CH_4         0x00004000
#define DMA_ISR_HTIF_CH_5         0x00040000
#define DMA_ISR_HTIF_CH_6         0x00400000
#define DMA_ISR_HTIF_CH_7         0x04000000
#define DMA_ISR_HTIF_ALL          0x04444444



/*channel transfer complete falg                               */
#define DMA_ISR_TCIF_CH_1         0x00000002
#define DMA_ISR_TCIF_CH_2         0x00000020
#define DMA_ISR_TCIF_CH_3         0x00000200
#define DMA_ISR_TCIF_CH_4         0x00002000
#define DMA_ISR_TCIF_CH_5         0x00020000
#define DMA_ISR_TCIF_CH_6         0x00200000
#define DMA_ISR_TCIF_CH_7         0x02000000


/*Channel global interrupt flag                                */
#define DMA_ISR_GIF_CH_1          0x00000001
#define DMA_ISR_GIF_CH_2          0x00000010  
#define DMA_ISR_GIF_CH_3          0x00000100
#define DMA_ISR_GIF_CH_4          0x00001000
#define DMA_ISR_GIF_CH_5          0x00010000
#define DMA_ISR_GIF_CH_6          0x00100000
#define DMA_ISR_GIF_CH_7          0x01000000


/*********************************IFCR Masks**********************/

/*Channel transfer error clear                                  */
#define DMA_IFCR_CTEIF_CH_1        0x00000008
#define DMA_IFCR_CTEIF_CH_2        0x00000080
#define DMA_IFCR_CTEIF_CH_3        0x00000800
#define DMA_IFCR_CTEIF_CH_4        0x00008000
#define DMA_IFCR_CTEIF_CH_5        0x00080000
#define DMA_IFCR_CTEIF_CH_6        0x00800000
#define DMA_IFCR_CTEIF_CH_7        0x08000000


/*Channel half transfer clear                                   */
#define DMA_IFCR_CHTIF_CH_1        0x00000004
#define DMA_IFCR_CHTIF_CH_2        0x00000040
#define DMA_IFCR_CHTIF_CH_3        0x00000400
#define DMA_IFCR_CHTIF_CH_4        0x00004000
#define DMA_IFCR_CHTIF_CH_5        0x00040000
#define DMA_IFCR_CHTIF_CH_6        0x00400000
#define DMA_IFCR_CHTIF_CH_7        0x04000000


/*Channel complete Clear                                         */
#define DMA_IFCR_CTCIF_CH_1        0x00000002 
#define DMA_IFCR_CTCIF_CH_2        0x00000020
#define DMA_IFCR_CTCIF_CH_3        0x00000200
#define DMA_IFCR_CTCIF_CH_4        0x00002000
#define DMA_IFCR_CTCIF_CH_5        0x00020000
#define DMA_IFCR_CTCIF_CH_6        0x00200000
#define DMA_IFCR_CTCIF_CH_7        0x02000000


/*Channel global interrupt Clear                                */
#define DMA_IFCR_CGIF_CH_1         0x00000001
#define DMA_IFCR_CGIF_CH_2         0x00000010
#define DMA_IFCR_CGIF_CH_3         0x00000100
#define DMA_IFCR_CGIF_CH_4         0x00001000
#define DMA_IFCR_CGIF_CH_5         0x00010000
#define DMA_IFCR_CGIF_CH_6         0x00100000
#define DMA_IFCR_CGIF_CH_7         0x01000000



/*********************************CCR Masks***********************/

/*DMA Enabel                                                    */
#define DMA_CCR_ENABLE                        0x00000001
#define DMA_CCR_DISABLE                       0xFFFFFFFE

/*Transfer complete interrupt Enable                            */
#define DMA_CCR_INTERRUPT_TCIE                   0x00000002
/*Half transfer interrupt enable                                */
#define DMA_CCR_INTERRUPT_HTIE                   0x00000004
/*Transfer error interrupt enable                               */
#define DMA_CCR_INTERRUPT_TEIE                   0x00000008

#define DMA_CCR_INTERRUPT_ALL                    0x0000000E

/*Data transfer direction                                       */
#define DMA_CCR_DIR_MASK			     0xFFFFFFEF
#define DMA_CCR_DIR_FROM_MEMORY		     0x00000010
#define DMA_CCR_DIR_FROM_PERIPHERAL      0x00000000

/*Circular Mode                                                 */
#define DMA_CCR_CIRC_ENABLE            0x00000020
#define DMA_CCR_CIRC_DISABLE           0xFFFFFFDF

/*Peripheral increment mode                                     */
#define DMA_CCR_PINC_MASK               0xFFFFFFBF
#define DMA_CCR_PINC_ENABLE             0x00000040
#define DMA_CCR_PINC_DISABLE            0x00000000

/*Memory increment mode                                         */
#define DMA_CCR_MINC_MASK              0xFFFFFF7F
#define DMA_CCR_MINC_ENABLE            0x00000080
#define DMA_CCR_MINC_DISABLE           0x00000000

/*Peripheral size                                               */
#define DMA_CCR_PSIZE_MASK             0xFFFFFCFF
#define  DMA_CCR_PSIZE_8_BITS           0x00000000
#define  DMA_CCR_PSIZE_16_BITS          0x00000100 
#define  DMA_CCR_PSIZE_32_BITS          0x00000200 


/*Memory size                                                   */
#define DMA_CCR_MSIZE_MASK             0xFFFFF3FF
                                        
#define  DMA_CCR_MSIZE_8_BITS           0x00000000
#define  DMA_CCR_MSIZE_16_BITS          0x00000400 
#define  DMA_CCR_MSIZE_32_BITS          0x00000800  



/*Channel priority level                                         */
#define DMA_CCR_PL_MASK                  0xFFFFCFFF
#define  DMA_CCR_PL_LOW                  0xFFFFCFFF
#define  DMA_CCR_PL_MED                  0x00001000 
#define  DMA_CCR_PL_HIGH                 0x00002000 
#define  DMA_CCR_PL_VERY_HIGH            0x00003000 




/*Memory to memory enable                                        */
#define DMA_CCR_MEM2MEM_ENABLE          0x00004000
#define DMA_CCR_MEM2MEM_DISABLE         0xFFFFBFFF

/*                                  Functions Prototypes         */
void DMA_init(void);
STD_ERROR DMA_enableChannel(u8 DMA_CHANNEL);
STD_ERROR DMA_disableChannel(u8 DMA_CHANNEL);
STD_ERROR DMA_setCBF_EndOfTransfer(u8 DMA_CHANNEL,void(*CBF)(void));
STD_ERROR DMA_setCBF_HalfOfTransfer(u8 DMA_CHANNEL,void(*CBF)(void));
STD_ERROR DMA_setCBF_ErrorInTransfer(u8 DMA_CHANNEL,void(*CBF)(void));
STD_ERROR DMA_SetChannelPriority(u8 DMA_CHANNEL,u32 DMA_CCR_PL);
STD_ERROR DMA_configureChannel(u8 DMA_CHANNEL,u32 DMA_CCR_PSIZE,u32 DMA_CCR_PINC,u32 DMA_CCR_MSIZE,u32 DMA_CCR_MINC);
STD_ERROR DMA_enableInterrupt(u8 DMA_CHANNEL,u32 DMA_CCR_INTERRUPT);
STD_ERROR DMA_disableInterrupt(u8 DMA_CHANNEL,u32 DMA_CCR_INTERRUPT);
STD_ERROR DMA_enableCircular(u8 DMA_CHANNEL );
STD_ERROR DMA_disableCircular(u8 DMA_CHANNEL);
STD_ERROR DMA_setDirction(u8 DMA_CHANNEL,u32 DMA_CCR_DIR_FROM);
STD_ERROR DMA_enableMem2Mem(u8 DMA_CHANNEL );
STD_ERROR DMA_disableMem2Mem(u8 DMA_CHANNEL);
STD_ERROR DMA_setNumberOfDataTransfer(u8 DMA_CHANNEL,u32 CopyNumber_Transfer);
STD_ERROR DMA_setPeripheralAddress(u8 DMA_CHANNEL,u32 CopyPeripheralAddr);
STD_ERROR DMA_setMemoryAddress(u8 DMA_CHANNEL,u32 CopyMemokryAddr);


#endif
