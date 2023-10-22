/*
 * UART_PROGRAM.c
 *
 *  Created on: 17Sep.,2023
 *      Author: abdel
 */
#include "../../LIB/STD.h"
#include "../../LIB/BitMath.h"

#include "../USART/USART_CONFIG.h"
#include "../USART/USART_INTERFACE.h"
#include "../USART/USART_PRIVATE.h"

void (*GlopalPtr) (void) = {NULL};

void USART_voidInit(BaudRate_t Baud)
{
	if(Baud == Baud_9600)
		USART1->BRR = Baud_9600;
	else if(Baud == Baud_115200)
		USART1->BRR = Baud_115200;
	SET_BIT(USART1->CR1,6);
	SET_BIT(USART1->CR1,7);
	SET_BIT(USART1->CR1,3);
	SET_BIT(USART1->CR1,2);
	SET_BIT(USART1->CR1,13);
}

void USART_voidSendData(u8 Copy_u8Data)
{
	while(GET_BIT(USART1->SR,6) == 0);
	USART1->DR = Copy_u8Data;
}

u8 USART_voidReceiveData(void)
{
	u8 Local_returnedData = 0;
	u32 timeout = 0;

	while(GET_BIT(USART1->SR,5) == 0)
	{
		timeout++;
		if(timeout == 10000)
		{
			Local_returnedData = 128;
			break;
		}
	}
	if(Local_returnedData == 0)
		Local_returnedData = USART1->DR;

	return Local_returnedData;
}

void USART_voidSendString(u8 *copy_u8String)
{
	u8 i = 0;
	while(copy_u8String[i] != '\0')
	{
		USART_voidSendData(copy_u8String[i]);
		i++;
	}
}

void USART_voidRecieveString(u8 *copy_u8String)
{
	u8 i = 0;
	while(copy_u8String[i] != '\r' || copy_u8String[i] != '\n' || copy_u8String[i] != '\0' )
	{
		copy_u8String[i] = USART_voidReceiveData();
		i++;
	}
}

