/*
 * FMI_PROGRAM.c
 *
 *  Created on: 25Sep.,2023
 *      Author: abdel
 */

#include "../../LIB/STD.h"
#include "../../LIB/BitMath.h"

#include "FMI_INTERFACE.h"
#include "FMI_PRIVATE.h"
#include "FMI_CONFIG.h"


void FMI_voidEraseSector(FMI_Sector_t Sector_ID)
{
	/*Wait Busy Flag*/
	while(GET_BIT(FMI->SR,16) == 1);
	/*Send Key */
	while(GET_BIT(FMI->CR,31) == 1)
	{
		FMI->KEYR = KEY1;
		FMI->KEYR = KEY2;
	}
	/*Select Sector*/
	FMI->CR  &= (~((0b1111)<<3));
	FMI->CR  |=  ((Sector_ID)<<3);
	/*Erase Sector*/
	SET_BIT(FMI->CR,1);
	/*Start*/
	SET_BIT(FMI->CR,16);
	while(GET_BIT(FMI->SR,16) == 1);
	CLR_BIT(FMI->CR,1);
	CLR_BIT(FMI->CR,16);
	SET_BIT(FMI->SR,0);
}
void FMI_voidFlashData(u32 Copy_u32Address,u16 *Copy_u16Data, u32 Copy_u32NumOfElements)
{
	/*Wait Busy Flag*/
	while(GET_BIT(FMI->SR,16) == 1);
	/*Send Key */
	while(GET_BIT(FMI->CR,31) == 1)
	{
		FMI->KEYR = KEY1;
		FMI->KEYR = KEY2;
	}
	/*Set P size*/
	FMI->CR  &= ~((0b11)<<8);
	FMI->CR  |=  ((0b01)<<8);
	/*SET PG */
	SET_BIT(FMI->CR,0);
	for(u32 i = 0;i<Copy_u32NumOfElements;i++)
	{
		*((volatile u16*)(Copy_u32Address)) = Copy_u16Data[i];
		Copy_u32Address+=2;
		while(GET_BIT(FMI->SR,16) == 1);
	}
	CLR_BIT(FMI->CR,0);
	SET_BIT(FMI->SR,0);
}
