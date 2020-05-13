/*Author :Mohamed Ibrahem */
/*Date :9 March 2020      */
/*Version :1.0            */

#ifndef UART_CONFIG_H
#define UART_CONFIG_H

/*UART_PARITY_DIABLE */
/*UART_PARITY_ODD     */
/*UART_PARITY_EVEN    */

#define UART_PARITY UART_PARITY_DIABLE

/*UART_BAUD_4800    */
/*UART_BAUD_9600    */
/*UART_BAUD_115200  */

#define UART_BAUD_RATE    UART_BAUD_4800

/*UART_STOP_1_BIT*/
/*UART_STOP_2_BIT*/

#define UART_STOP_BIT     UART_STOP_1_BIT


/*UART_SYS_FREQ_8M  */
/*UART_SYS_FREQ_12M */
/*UART_SYS_FREQ_8M  */

#define UART_SYS_FREQ  UART_SYS_FREQ_8M


/*Time threshold for transmiter    */
#define UART_TIME_OUT_TH          100000U

#endif
