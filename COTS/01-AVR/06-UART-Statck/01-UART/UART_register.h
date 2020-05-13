#ifndef UART_REGISTER_H
#define UART_REGISTER_H


#define UBRRH           *((u8 *) 0x40)
#define UCSRC           *((u8 *) 0x40)
#define UDR_R           *((u8 *) 0x2C)
#define UDR_T           *((u8 *) 0x2C)
#define UCSRA           *((u8 *) 0x2B)
#define UCSRB           *((u8 *) 0x2A)
#define UBRRL           *((u8 *) 0x29)


#endif
