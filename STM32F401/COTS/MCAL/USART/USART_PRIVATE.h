/*
 * UART_PRIVATE.h
 *
 *  Created on: 17Sep.,2023
 *      Author: abdel
 */

#ifndef COTS_MCAL_USART_USART_PRIVATE_H_
#define COTS_MCAL_USART_USART_PRIVATE_H_

#define USART1_BASE_ADDRESS  0x40011000
#define USART2_BASE_ADDRESS  0x40004400
#define USART6_BASE_ADDRESS  0x40011400
typedef struct
{
    volatile u32     SR   	 ;
    volatile u32     DR  	 ;
    volatile u32     BRR 	 ;
    volatile u32     CR1	 ;
    volatile u32     CR2     ;
    volatile u32     CR3     ;
    volatile u32     GTPR    ;

}USART_MemMap_t;


#define USART1          ((volatile USART_MemMap_t *)USART1_BASE_ADDRESS)
#define USART2          ((volatile USART_MemMap_t *)USART2_BASE_ADDRESS)
#define USART6          ((volatile USART_MemMap_t *)USART6_BASE_ADDRESS)


#endif /* COTS_MCAL_USART_USART_PRIVATE_H_ */
