/*
 * DMA_PRIVATE.h
 *
 *  Created on: 20Sep.,2023
 *      Author: abdel
 */

#ifndef COTS_MCAL_DMA_DMA_PRIVATE_H_
#define COTS_MCAL_DMA_DMA_PRIVATE_H_

#define DMA1_BASE_ADDRESS  0x40026000
#define DMA2_BASE_ADDRESS  0x40026400

typedef struct
{
	volatile u32 	SCR		;
	volatile u32 	SNDTR	;
	volatile u32 	SPAR	;
	volatile u32 	SM0AR	;
	volatile u32 	SM1AR	;
	volatile u32 	SFCR	;

}DMA_StreamReg_t;
typedef struct
{
	volatile u32 		LISR			 ;
	volatile u32 		HISR			 ;
	volatile u32 		LIFCR			 ;
	volatile u32 		HIFCR			 ;
	DMA_StreamReg_t 	arrayofStrems[8] ;

}DMA_MemMap_t;

#define DMA1 		((volatile DMA_MemMap_t *)DMA1_BASE_ADDRESS)
#define DMA2        ((volatile DMA_MemMap_t *)DMA2_BASE_ADDRESS)

#endif /* COTS_MCAL_DMA_DMA_PRIVATE_H_ */
