/*
 * FMI_PRIVATE.h
 *
 *  Created on: 25Sep.,2023
 *      Author: abdel
 */

#ifndef COTS_MCAL_FMI_FMI_PRIVATE_H_
#define COTS_MCAL_FMI_FMI_PRIVATE_H_


#define KEY1  	0x45670123
#define KEY2	0xCDEF89AB

#define FMI_BASE_ADDRESS  0x40023C00

typedef struct
{
	volatile u32 ACR		;
	volatile u32 KEYR		;
	volatile u32 OPTKEYR	;
	volatile u32 SR			;
	volatile u32 CR			;
	volatile u32 OPTCR		;

}FMI_MemMap_t;

#define FMI         ((volatile FMI_MemMap_t *)FMI_BASE_ADDRESS)

#endif /* COTS_MCAL_FMI_FMI_PRIVATE_H_ */
