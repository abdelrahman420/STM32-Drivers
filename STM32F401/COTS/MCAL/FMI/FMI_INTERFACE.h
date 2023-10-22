/*
 * FIM_INTERFACE.h
 *
 *  Created on: 25Sep.,2023
 *      Author: abdel
 */

#ifndef COTS_MCAL_FMI_FMI_INTERFACE_H_
#define COTS_MCAL_FMI_FMI_INTERFACE_H_

typedef enum
{
	FMI_Sector0,
	FMI_Sector1,
	FMI_Sector2,
	FMI_Sector3,
	FMI_Sector4,
	FMI_Sector5

}FMI_Sector_t;



void FMI_voidEraseSector(FMI_Sector_t Sector_ID);
void FMI_voidFlashData(u32 Copy_u32Address,u16 *Copy_u16Data, u32 Copy_u32NumOfElements);




#endif /* COTS_MCAL_FMI_FMI_INTERFACE_H_ */
