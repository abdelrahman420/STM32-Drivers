/*
 * LedMatrix_PROGRAM.c
 *
 *  Created on: 14Sep.,2023
 *      Author: abdel
 */
#include "../../LIB/STD.h"
#include "../../LIB/BitMath.h"

#include "../../MCAL/GPIO/GPIO_INTERFACE.h"
#include "../../MCAL/SYSTICK/SYSTICK_INTERFACE.h"

#include"LedMatrix_INTERFACE.h"
#include"LedMatrix_PRIVATE.h"
#include"LedMatrix_CONFIG.h"




GPIO_Config Rows;
GPIO_Config Cols;
GPIO_Config Col0;
GPIO_Config Col1;
void LedMatrix_DisableColumns(void)
{
	/*Disable all columns by writing 1*/
	for(u8 k = 0; k < 8;k++)
	{
		if(k < 2)
		{
			GPIO_voidSetPinValue(Cols.Port,k,GPIO_HIGH);
		}
		else
		{
			GPIO_voidSetPinValue(Cols.Port,k+3,GPIO_HIGH);
		}
	}
}
void LedMatrix_Init(void)
{
	for(u8 j=0;j<8;j++)
	{
		Rows.Mode = GPIO_OUTPUT;
		Rows.Port = GPIO_PORTA;
		Rows.Pin = j;
		Rows.OutputType = push_pull;
		Rows.OutputSpeed = LOW_Speed;
		Rows.PullState =NO_PULL;
		GPIO_voidInit(&Rows);
	}

	for(u8 j=0;j< 8;j++)
	{
		Cols.Mode = GPIO_OUTPUT;
		Cols.Port = GPIO_PORTB;
		if(j < 2)
		{
			Cols.Pin = j;
		}
		else
		{
			Cols.Pin = j+3;
		}
		Cols.OutputType = push_pull;
		Cols.OutputSpeed = LOW_Speed;
		Cols.PullState =NO_PULL;
		GPIO_voidInit(&Cols);
	}

}
void LedMatrix_voidDisplay(u8 *Copy_CharArr)
{
	for(u8 i = 0; i<50 ;i++)
	{
		for(u8 j = 0 ;j<8 ;j++)
		{
			LedMatrix_DisableColumns();
			GPIO_voidSetQuarterPortValue(Rows.Port,Copy_CharArr[j]);
			if(j <2)
			{
				GPIO_voidSetPinValue(Cols.Port,j,GPIO_LOW);
			}
			else
			{
				GPIO_voidSetPinValue(Cols.Port,j+3,GPIO_LOW);
			}
			SYSTICK_voidSetBusyWait(2500);
		}
	}
}
