/*
 * SPI_PRIVATE.h
 *
 *  Created on: 18Sep.,2023
 *      Author: abdel
 */

#ifndef COTS_MCAL_SPI_SPI_PRIVATE_H_
#define COTS_MCAL_SPI_SPI_PRIVATE_H_

#define  SPI1_BASE_ADDRESS      0x40013000
#define  SPI2_BASE_ADDRESS      0x40003800
#define  SPI3_BASE_ADDRESS      0x40003C00

#define SPI_BASE_ADDRESS  0x40023800

typedef struct
{
	volatile  u32   CR1;
	volatile  u32   CR2;
	volatile  u32   SR;
	volatile  u32   DR;
	volatile  u32   CRCPR;
	volatile  u32   RXCRCR;
	volatile  u32   TXCRCR;
	volatile  u32   I2SCFGR;
	volatile  u32   I2SPR;
}SPI_MemMap_t;


#define SPI1         ((volatile SPI_MemMap_t*)SPI1_BASE_ADDRESS)
#define SPI2         ((volatile SPI_MemMap_t*)SPI2_BASE_ADDRESS)
#define SPI3         ((volatile SPI_MemMap_t*)SPI3_BASE_ADDRESS)

#endif /* COTS_MCAL_SPI_SPI_PRIVATE_H_ */
