/*Author :Mohamed Ibrahem */
/*Date :9 March 2020      */
/*Version :1.0            */

#ifndef UART_INTERFACE_H
#define UART_INTERFACE_H

#define RXC_BIT     7
#define TXC_BIT     6
#define UDRE_BIT    5
#define FE_BIT      4
#define DOR_BIT     3
#define PE_BIT      2
#define U2X_BIT     1
#define MPCM_BIT    0



void UART_Init(void);
STD_Error UART_TransimitDataSync(u8 Data);
STD_Error UART_TransimitDataAsync(u8 Data,void (*ptr)(void));
STD_Error UART_RecieveSync(u8 *value);
void UART_RecieveAsynch(void (*ptr)(u8));






#endif
