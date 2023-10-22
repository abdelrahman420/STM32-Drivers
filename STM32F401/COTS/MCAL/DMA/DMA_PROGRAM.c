/*
 * DMA_PROGRAM.c
 *
 *  Created on: 20Sep.,2023
 *      Author: abdel
 */

#include "../../LIB/STD.h"
#include "../../LIB/BitMath.h"

#include"DMA_INTERFACE.h"
#include"DMA_PRIVATE.h"
#include"DMA_CONFIG.h"

static void (*PF_Notification[8]) (void) ={NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};

void DMA_voidEnable(DMA_Stream_t Stream)
{
	SET_BIT(DMA2->arrayofStrems[Stream].SCR,0);
}
void DMA_voidDisable(DMA_Stream_t Stream)
{
	CLR_BIT(DMA2->arrayofStrems[Stream].SCR,0);
}


void DMA_voidInit(DMA_Config_t *DMA_Ptr)
{
	/*Disable Stream*/
	DMA_voidDisable(DMA_Ptr->DMA_Stream);

	/*Select Channel*/
	DMA2->arrayofStrems[DMA_Ptr->DMA_Stream].SCR &= (~((0b111) << 25));
	DMA2->arrayofStrems[DMA_Ptr->DMA_Stream].SCR |= ( (DMA_Ptr->DMA_Channel) << 25);

	/*Select Burst Size For memory  */
	DMA2->arrayofStrems[DMA_Ptr->DMA_Stream].SCR &= (~((0b11) << 23));
	DMA2->arrayofStrems[DMA_Ptr->DMA_Stream].SCR |= ( (DMA_Ptr->M_Burst) << 23);

	/*Select Burst Size For Peripheral */
	DMA2->arrayofStrems[DMA_Ptr->DMA_Stream].SCR &= (~((0b11) << 21));
	DMA2->arrayofStrems[DMA_Ptr->DMA_Stream].SCR |= ( (DMA_Ptr->P_Burst) << 21);

	/*Select Stream Priority */
	DMA2->arrayofStrems[DMA_Ptr->DMA_Stream].SCR &= (~((0b11) << 16));
	DMA2->arrayofStrems[DMA_Ptr->DMA_Stream].SCR |= ( (DMA_Ptr->StreamPriority) << 16);

	/*Select Memory Date Size */
	DMA2->arrayofStrems[DMA_Ptr->DMA_Stream].SCR &= (~((0b11) << 13));
	DMA2->arrayofStrems[DMA_Ptr->DMA_Stream].SCR |= ( (DMA_Ptr->DMA_MDataSize) << 13);

	/*Select Peripheral Date Size */
	DMA2->arrayofStrems[DMA_Ptr->DMA_Stream].SCR &= (~((0b11) << 11));
	DMA2->arrayofStrems[DMA_Ptr->DMA_Stream].SCR |= ( (DMA_Ptr->DMA_PDataSize) << 11);

	/*Select MINC */
	DMA2->arrayofStrems[DMA_Ptr->DMA_Stream].SCR &= (~((0b1) << 10));
	DMA2->arrayofStrems[DMA_Ptr->DMA_Stream].SCR |= ( (DMA_Ptr->DMA_MINC) << 10);

	/*Select PINC */
	DMA2->arrayofStrems[DMA_Ptr->DMA_Stream].SCR &= (~((0b1) << 9));
	DMA2->arrayofStrems[DMA_Ptr->DMA_Stream].SCR |= ( (DMA_Ptr->DMA_PINC) << 9);

	/*Select Flow Direction OF Data */
	DMA2->arrayofStrems[DMA_Ptr->DMA_Stream].SCR &= (~((0b11) << 6));
	DMA2->arrayofStrems[DMA_Ptr->DMA_Stream].SCR |= ( (DMA_Ptr->DMA_StreamDir) << 6);

	/*If data transfered between memory to memory disable direct mood*/
	if(DMA_Ptr->DMA_StreamDir == M2M )
		SET_BIT((DMA2->arrayofStrems[DMA_Ptr->DMA_Stream].SFCR) , 2 );

	/*Select FIFO threshold */
	DMA2->arrayofStrems[DMA_Ptr->DMA_Stream].SFCR &= (~((0b11) << 0));
	DMA2->arrayofStrems[DMA_Ptr->DMA_Stream].SFCR |= ( (DMA_Ptr->Threshold) << 0);

	/*	Select Block Size or number of Data to be Transferred */
	DMA2->arrayofStrems[DMA_Ptr->DMA_Stream].SNDTR &= 0;
	DMA2->arrayofStrems[DMA_Ptr->DMA_Stream].SNDTR |=DMA_Ptr->BlockSize;

	/*Enable DMA INTERRUPT */
	SET_BIT( (DMA2->arrayofStrems[DMA_Ptr->DMA_Stream].SCR) , 4 ); // complete Int
}
void DMA_SetAddresses(DMA_Stream_t Stream, u32 *Copy_u32SAddress,u32 *Copy_u32DAddress)
{
	DMA2->arrayofStrems[Stream].SM0AR = (u32)Copy_u32DAddress;
	DMA2->arrayofStrems[Stream].SPAR = (u32)Copy_u32SAddress;
}

void DMA_voidCallBack(DMA_Stream_t Stream ,void (*PF) (void))
{
	PF_Notification[Stream] = PF;
}

void DMA2_Stream0_IRQHandler(void)
{
	if(PF_Notification != NULL)
	{
		PF_Notification[0]();
	}

	SET_BIT(DMA2->LIFCR,5); // CLEAR Complete Flag
}

void DMA2_Stream1_IRQHandler(void)
{
	if(PF_Notification != NULL)
	{
		PF_Notification[1]();
	}

	SET_BIT(DMA2->LIFCR,11); // CLEAR Complete Flag
}
void DMA2_Stream2_IRQHandler(void)
{
	if(PF_Notification != NULL)
	{
		PF_Notification[2]();
	}

	SET_BIT(DMA2->LIFCR,21); // CLEAR Complete Flag
}
void DMA2_Stream3_IRQHandler(void)
{
	if(PF_Notification != NULL)
	{
		PF_Notification[3]();
	}

	SET_BIT(DMA2->LIFCR,27); // CLEAR Complete Flag
}
void DMA2_Stream4_IRQHandler(void)
{
	if(PF_Notification != NULL)
	{
		PF_Notification[4]();
	}

	SET_BIT(DMA2->HIFCR,5); // CLEAR Complete Flag
}
void DMA2_Stream5_IRQHandler(void)
{
	if(PF_Notification != NULL)
	{
		PF_Notification[5]();
	}

	SET_BIT(DMA2->HIFCR,11); // CLEAR Complete Flag
}
void DMA2_Stream6_IRQHandler(void)
{
	if(PF_Notification != NULL)
	{
		PF_Notification[6]();
	}

	SET_BIT(DMA2->HIFCR,21); // CLEAR Complete Flag
}
void DMA2_Stream7_IRQHandler(void)
{
	if(PF_Notification != NULL)
	{
		PF_Notification[7]();
	}

	SET_BIT(DMA2->HIFCR,27); // CLEAR Complete Flag
}
