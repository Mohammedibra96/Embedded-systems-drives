/*Author :Mohamed Ibrahem */
/*Date :9 March 2020      */
/*Version :1.0            */


#ifndef UART_PRIVATE_H
#define UART_PRIVATE_H



#define UART_PARITY_DIABLE    0U
#define UART_PARITY_ODD       3U
#define UART_PARITY_EVEN      2U



#define UART_BAUD_4800         1U 
#define UART_BAUD_9600         2U 
#define UART_BAUD_115200       3U 



#define UART_STOP_1_BIT       0U
#define UART_STOP_2_BIT       2U



#define UART_SYS_FREQ_8M    0U
#define UART_SYS_FREQ_12M   1U  
#define UART_SYS_FREQ_16M    2U



void __vector_13(void) __attribute__((signal,used));
void __vector_14(void) __attribute__((signal,used));


#endif
