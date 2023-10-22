/*
 * ADC_private.h
 *
 *  Created on: 8Oct.,2023
 *      Author: abdel
 */

#ifndef COTS_MCAL_ADC_ADC_PRIVATE_H_
#define COTS_MCAL_ADC_ADC_PRIVATE_H_

#define ADC1_BASE_ADDRESS   0x40012000

#define ADC1_CCR 	*((volatile u32*)0x40012304)


typedef struct
{
	volatile u32 		SR;
	volatile u32 		CR[2];
	volatile u32 		SMPR[2];
	volatile u32 		JOFR[4];
	volatile u32 		HTR;
	volatile u32 		LTR;
	volatile u32 		SQR[3];
	volatile u32 		JSQR;
	volatile u32 		JDR[4];
	volatile u32 		DR;

}ADC_MemMap_t;

#define ADC1  	((volatile ADC_MemMap_t*)ADC1_BASE_ADDRESS)

#endif /* COTS_MCAL_ADC_ADC_PRIVATE_H_ */
