/*
 * ADC_interface.h
 *
 *  Created on: 8Oct.,2023
 *      Author: abdel
 */

#ifndef COTS_MCAL_ADC_ADC_INTERFACE_H_
#define COTS_MCAL_ADC_ADC_INTERFACE_H_



typedef enum
{
	ADC_CLK_2,
	ADC_CLK_4,
	ADC_CLK_6,
	ADC_CLK_8
}ADC_Prescaler_t;

typedef enum
{
	ADC_RES_12,
	ADC_RES_10,
	ADC_RES_8,
	ADC_RES_6
}ADC_RES_t;

typedef enum
{
	ADC_0,
	ADC_1,
	ADC_2,
	ADC_3,
	ADC_4,
	ADC_5,
	ADC_6,
	ADC_7,
	ADC_8,
	ADC_9
}ADC_Channel_t;

#define  ADC_POLLING   0
#define  ADC_INTERRUPT 1


typedef enum
{
	ADC_SingleConv,
	ADC_ContConv
}ADC_Conversion_t;

typedef enum
{
	ADC_3cycles,
	ADC_15cycles,
	ADC_28cycles,
	ADC_56cycles,
	ADC_84cycles,
	ADC_112cycles,
	ADC_144cycles,
	ADC_480cycles

}ADC_SampleTime_t;
typedef enum
{
	ADC_RightAlign,
	ADC_LeftAlign

}ADC_DataAlign_t;
typedef struct
{
	ADC_Channel_t 		ADC_Channel;
	ADC_RES_t			ADC_RES;
	ADC_Prescaler_t		ADC_Prescaler;
	ADC_Conversion_t	ADC_Conversion;
	ADC_SampleTime_t 	ADC_SampleTime;
	ADC_DataAlign_t		ADC_DataAlign;

}ADC_Config_t;

void ADC_voidInit(ADC_Config_t *ADCptr);
u16 ADC_voidStart(void);
//u16 ADC_readData(void);
//typedef enum{
//	ADC0,
//	ADC1,
//	ADC2,
//	ADC3,
//	ADC4,
//	ADC5,
//	ADC6,
//	ADC7
//}ADC_channel_t;
//typedef enum
//{
//	AREF,
//	AVCC,
//	INT256mv = 3
//
//}ADC_RefSel_t;

//
//typedef struct
//{
//	ADC_RefSel_t Vref;
//	ADC_Prescaler_t Prescaler;
//}ADC_Conf_t;
//void ADC_voidInit(ADC_Conf_t * Ptr_Conf);
//u16 ADC_u16ConvertedValue(ADC_channel_t ChannelNo);



#endif /* COTS_MCAL_ADC_ADC_INTERFACE_H_ */
