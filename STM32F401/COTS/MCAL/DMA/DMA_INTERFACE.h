/*
 * DMA_INTERFACE.h
 *
 *  Created on: 20Sep.,2023
 *      Author: abdel
 */

#ifndef COTS_MCAL_DMA_DMA_INTERFACE_H_
#define COTS_MCAL_DMA_DMA_INTERFACE_H_

typedef enum
{
	DMA_Channel0,
	DMA_Channel1,
	DMA_Channel2,
	DMA_Channel3,
	DMA_Channel4,
	DMA_Channel5,
	DMA_Channel6,
	DMA_Channel7

}DMA_Channel_t;

typedef enum
{
	DMA_Stream0,
	DMA_Stream1,
	DMA_Stream2,
	DMA_Stream3,
	DMA_Stream4,
	DMA_Stream5,
	DMA_Stream6,
	DMA_Stream7

}DMA_Stream_t;

typedef enum
{
	P2M,
	M2P,
	M2M

}DMA_StreamDir_t;

typedef enum
{
	PByte,
	PHalfWord,
	PFullWord

}DMA_P_DataSize_t;

typedef enum
{
	MByte,
	MHalfWord,
	MFullWord

}DMA_M_DataSize_t;

typedef enum
{
	PSingle,
	PINCR4,
	PINCR8,
	PINCR16,
	PINCR32

}DMA_PBurst_t;

typedef enum
{
	MSingle,
	MINCR4,
	MINCR8,
	MINCR16,
	MINCR32

}DMA_MBurst_t;

typedef enum
{
	Low_Priority,
	Meduim_Priority,
	High_Priority,
	VHigh_Priority

}DMA_StreamPriority_t;

typedef enum
{
	DMA_QuarterFIFO,
	DMA_HalfFIFO,
	DMA_3QuartersFullFIFO,
	DMA_FullFIFO
}DMA_ThresholdSelection_t;


typedef enum
{
	DMA_MFixed,
	DMA_MIncrement,
}DMA_MINC_t;

typedef enum
{
	DMA_PFixed,
	DMA_PIncrement,
}DMA_PINC_t;

typedef struct
{
	DMA_Channel_t 				DMA_Channel   ;
	DMA_Stream_t 				DMA_Stream	  ;
	DMA_StreamDir_t 			DMA_StreamDir ;
	DMA_P_DataSize_t 			DMA_PDataSize ;
	DMA_M_DataSize_t			DMA_MDataSize ;
	DMA_PBurst_t				P_Burst		  ;
	DMA_MBurst_t				M_Burst		  ;
	DMA_StreamPriority_t		StreamPriority;
	DMA_ThresholdSelection_t	Threshold	  ;
	DMA_MINC_t					DMA_MINC	  ;
	DMA_PINC_t					DMA_PINC	  ;
	u16 						BlockSize	  ;

}DMA_Config_t;



void DMA_voidInit(DMA_Config_t *DMA_Ptr);
void DMA_voidEnable(DMA_Stream_t Stream);
void DMA_voidDisable(DMA_Stream_t Stream);
void DMA_SetAddresses(DMA_Stream_t Stream, u32 *Copy_u32SAddress,u32 *Copy_u32DAddress);
void DMA_voidCallBack(DMA_Stream_t Stream ,void (*PF) (void));



#endif /* COTS_MCAL_DMA_DMA_INTERFACE_H_ */
