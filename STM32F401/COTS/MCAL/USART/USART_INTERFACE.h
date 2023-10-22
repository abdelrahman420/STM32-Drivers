/*
 * UART_INTERFACE.h
 *
 *  Created on: 17Sep.,2023
 *      Author: abdel
 */

#ifndef COTS_MCAL_USART_USART_INTERFACE_H_
#define COTS_MCAL_USART_USART_INTERFACE_H_

typedef enum
{
	Baud_9600 = 0xA2C,
	Baud_115200 = 0xD9
}BaudRate_t;

void USART_voidInit(BaudRate_t Baud);
void USART_voidSendData(u8 Copy_u8Data);
void USART_voidSendString(u8 *copy_u8String);
u8 USART_voidReceiveData(void);
void USART_voidRecieveString(u8 *copy_u8String);
void USART_voidSetCallback(void (*PF) (void));




#endif /* COTS_MCAL_USART_USART_INTERFACE_H_ */
