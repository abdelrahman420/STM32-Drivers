/*
 * SPI_PROGRAM.c
 *
 *  Created on: 18Sep.,2023
 *      Author: abdel
 */
#include "../../LIB/STD.h"
#include "../../LIB/BitMath.h"

#include "SPI_CONFIG.h"
#include "SPI_INTERFACE.h"
#include "SPI_PRIVATE.h"


void SPI_voidInit(void)
{
	u16 CR1Reg_u16Value = 0 ;
	/* Set clock phase and polarity*/
	SET_BIT(CR1Reg_u16Value,0);
	SET_BIT(CR1Reg_u16Value,1);
	/*Select master or slave*/
	SET_BIT(CR1Reg_u16Value,2);
	/*Select Clock*/
	CR1Reg_u16Value &= ~((0b111) << 3);
	CR1Reg_u16Value |= ((0b000) << 3);
	/*Enable SPI*/
	SET_BIT(CR1Reg_u16Value,6);
	/* Select LSB format*/
	CLR_BIT(CR1Reg_u16Value,7);
	/*SELECT SSL bit*/
	SET_BIT(CR1Reg_u16Value,8);
	/*SELECT SSL bit*/
	SET_BIT(CR1Reg_u16Value,9);
	/*Select Data Frame Format*/
	CLR_BIT(CR1Reg_u16Value,11);


	SPI1->CR1 = CR1Reg_u16Value;
}

u16 SPI_voidTranSeiveData(u16 Copy_u16Data)
{
	SPI1->DR = Copy_u16Data;
	while(GET_BIT(SPI1->SR,7)==1);
	return (SPI1->DR);
}
