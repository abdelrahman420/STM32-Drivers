/*
 * ADC_program.c
 *
 *  Created on: 8Oct.,2023
 *      Author: abdel
 */
#include "../../LIB/STD.h"
#include "../../LIB/BitMath.h"

#include"ADC_interface.h"
#include"ADC_private.h"
#include"ADC_config.h"


volatile u16 ADC_Data = 0;
void ADC_voidInit(ADC_Config_t *ADCptr)
{

	//Set Resolution
	ADC1->CR[0] &= ~((0b11)<<24);
	ADC1->CR[0] |=  ((ADCptr->ADC_RES)<<24);

	//Set the ADC to sleep

	CLR_BIT(ADC1->CR[1],0);

	//Set Channel
	/*
	 * 1-Enable Scan Mood
	 * 2-Select the Sequence Channel for single sequence we set first sequence with the desired Channel
	 */
    SET_BIT(ADC1->CR[0],8); //Scan Mood Enabled
	ADC1->SQR[2] &= ~((0b11111)<<0);
	ADC1->SQR[2] |= ((ADCptr->ADC_Channel)<<0); //Sequence one is set



	//Set prescaler
	ADC1_CCR &= ~((0b11)<<16);
	ADC1_CCR |= ((ADCptr->ADC_Prescaler)<<16);

	//set Conversion type
	if(ADCptr->ADC_Conversion == ADC_SingleConv)
	{
		CLR_BIT(ADC1->CR[1],1);
	}
	else if(ADCptr->ADC_Conversion == ADC_ContConv)
	{
		SET_BIT(ADC1->CR[1],1);
	}


	//set Data alignment
	ADC1->CR[1] &= ~((0b1)<<11);
	ADC1->CR[1] |= ((ADCptr->ADC_DataAlign)<<11);

	//set Sample Time for channel 1
	if(ADCptr->ADC_Channel >= 10 && ADCptr->ADC_Channel <= 18)
	{
		ADC1->SMPR[0] &= ~((0b111)<<(ADCptr->ADC_Channel * 3));
		ADC1->SMPR[0] |= ((ADCptr->ADC_SampleTime)<<(ADCptr->ADC_Channel * 3));
	}
	else if(ADCptr->ADC_Channel >= 0 && ADCptr->ADC_Channel <= 9)
	{
		ADC1->SMPR[1] &= ~((0b111)<<(ADCptr->ADC_Channel * 3));
		ADC1->SMPR[1] |= ((ADCptr->ADC_SampleTime)<<(ADCptr->ADC_Channel * 3));
	}

	//choose interrupt
	SET_BIT(ADC1->CR[0],5);

	//set ADon
	SET_BIT(ADC1->CR[1],0);

}
u16 ADC_voidStart(void)
{
		//start conversion
		SET_BIT(ADC1->CR[1],30);

		return ADC_Data;
}


void ADC_IRQHandler(void)
{
	if(GET_BIT(ADC1->SR,1) == 1 )
	{
		ADC_Data = ADC1->DR;
	}
}

