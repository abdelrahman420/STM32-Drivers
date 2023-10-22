/*
 * STP_PROGRAM.c
 *
 *  Created on: 12Sep.,2023
 *      Author: abdel
 */
#include "../../LIB/STD.h"
#include "../../LIB/BitMath.h"

#include "../../MCAL/RCC/RCC_INTERFACE.h"
#include "../../MCAL/GPIO/GPIO_INTERFACE.h"
#include "../../MCAL/SYSTICK/SYSTICK_INTERFACE.h"
#include"STP_INTERFACE.h"
#include"STP_CONFIG.h"


extern GPIO_Config STP_DataSerial;
extern GPIO_Config STP_Shift;
extern GPIO_Config STP_Store;

void S2P_voidInit(void)
{
	/*Select serial Data Port and Pin*/
	GPIO_voidInit(&STP_DataSerial);
	GPIO_voidInit(&STP_Shift);
	GPIO_voidInit(&STP_Store);

}
void S2P_voidSendData(u32 Copy_u32Data)
{
	for(u8 i = 0;i <(8 * NUMBER_OF_REGISTER);i++)
	{
		GPIO_voidSetPinValue(STP_DataSerial.Port,STP_DataSerial.Pin,GET_BIT(Copy_u32Data,i));
		/* Shift */
		S2P_voidShift();
	}
	S2P_voidLatch();
}
/*void S2P_voidSendData(u8 *Copy_u8DataPtr,u8 Copy_u8Size)
{
	for(u8 i = 0;i < (8 * Copy_u8Size);i++)
	{
		GPIO_voidSetPinValue(STP_DataSerial.Port,STP_DataSerial.Pin,GET_BIT(Copy_u8DataPtr[i/8],i%8));
		//Shift
		S2P_voidShift();
	}
	S2P_voidLatch();

}*/
S2P_voidShift()
{
	GPIO_voidSetPinValue(STP_Shift.Port,STP_Shift.Pin,GPIO_HIGH);
	/* Delay */
	SYSTICK_voidSetBusyWait(10);
	GPIO_voidSetPinValue(STP_Shift.Port,STP_Shift.Pin,GPIO_LOW);
}
S2P_voidLatch()
{
	GPIO_voidSetPinValue(STP_Store.Port,STP_Store.Pin,GPIO_HIGH);
	/* Delay */
	SYSTICK_voidSetBusyWait(10);
	GPIO_voidSetPinValue(STP_Store.Port,STP_Store.Pin,GPIO_LOW);
}

