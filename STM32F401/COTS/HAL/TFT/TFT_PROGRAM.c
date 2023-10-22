/*
 * TFT_PROGRAM.c
 *
 *  Created on: 19Sep.,2023
 *      Author: abdel
 */
#include "../../LIB/STD.h"
#include "../../LIB/BitMath.h"


#include "../../MCAL/GPIO/GPIO_INTERFACE.h"
#include "../../MCAL/SYSTICK/SYSTICK_INTERFACE.h"
#include "../../MCAL/SPI/SPI_INTERFACE.h"

#include"TFT_INTERFACE.h"
#include"TFT_PRIVATE.h"
#include"TFT_CONFIG.h"

GPIO_Config SPI_MOSI=
{
		.Mode = GPIO_AF,
		.Port = GPIO_PORTA,
		.Pin =GPIO_PIN7,
		.OutputType = push_pull,
		.OutputSpeed = LOW_Speed,
		.PullState =NO_PULL,
};
GPIO_Config SPI_MISO=
{
		.Mode = GPIO_AF,
		.Port = GPIO_PORTA,
		.Pin =GPIO_PIN6,
		.OutputType = push_pull,
		.OutputSpeed = LOW_Speed,
		.PullState =NO_PULL,
};
GPIO_Config CLK=
{
		.Mode = GPIO_AF,
		.Port = GPIO_PORTA,
		.Pin =GPIO_PIN5,
		.OutputType = push_pull,
		.OutputSpeed = LOW_Speed,
		.PullState =NO_PULL,
};


static void TFT_voidSendCommad(u8 Copy_u8Command)
{
	GPIO_voidSetPinValue(GPIO_PORTA,GPIO_PIN2,GPIO_LOW);
	SPI_voidTranSeiveData(Copy_u8Command);
}
static void TFT_voidSendData(u8 Copy_u8Data)
{
	GPIO_voidSetPinValue(GPIO_PORTA,GPIO_PIN2,GPIO_HIGH);
	SPI_voidTranSeiveData(Copy_u8Data);
}

void TFT_voidInit(void)
{
	GPIO_voidInit(&SPI_MOSI);
	GPIO_voidInit(&SPI_MISO);
	GPIO_voidInit(&CLK);
	GPIO_voidSetAlternative(SPI_MOSI.Port,SPI_MOSI.Pin,GPIO_SPI1_4);
	GPIO_voidSetAlternative(SPI_MISO.Port,SPI_MISO.Pin,GPIO_SPI1_4);
	GPIO_voidSetAlternative(CLK.Port,CLK.Pin,GPIO_SPI1_4);

	GPIO_voidSetPinValue(GPIO_PORTA,GPIO_PIN1,GPIO_HIGH);
	SYSTICK_voidSetBusyWait(100);
	GPIO_voidSetPinValue(GPIO_PORTA,GPIO_PIN1,GPIO_LOW);
	SYSTICK_voidSetBusyWait(10);
	GPIO_voidSetPinValue(GPIO_PORTA,GPIO_PIN1,GPIO_HIGH);
	SYSTICK_voidSetBusyWait(100);
	GPIO_voidSetPinValue(GPIO_PORTA,GPIO_PIN1,GPIO_LOW);
	SYSTICK_voidSetBusyWait(100);
	GPIO_voidSetPinValue(GPIO_PORTA,GPIO_PIN1,GPIO_HIGH);
	SYSTICK_voidSetBusyWait(120000);
	/* Sleep Out */
	TFT_voidSendCommad(0x11);
	/* wait 150 ms*/
	SYSTICK_voidSetBusyWait(150000);

	/* COLOR mode */
	TFT_voidSendCommad(0x3A);
	TFT_voidSendData(0x05);
	//SendData(0x06);
	/* display on */
	TFT_voidSendCommad(0x29);


}
void TFT_voidDisplayImage(const u16* PtrImage)
{
	u8 data;
	u16 counter;
	/* set x address */
	TFT_voidSendCommad(0x2A);
	TFT_voidSendData(0);
	TFT_voidSendData(0);
	TFT_voidSendData(0);
	TFT_voidSendData(127);

	/* set y address */
	TFT_voidSendCommad(0x2B);
	TFT_voidSendData(0);
	TFT_voidSendData(0);
	TFT_voidSendData(0);
	TFT_voidSendData(159);

	/* RAM write */
	TFT_voidSendCommad(0x2C);

	for(counter=0; counter<20480; counter++)
	{
		data = PtrImage[counter] >> 8;
		TFT_voidSendData(data);

		data = PtrImage[counter] & 0xFF; // for low part
		TFT_voidSendData(data);
	}

}
void TFT_voidFillerColor(u16 Copy_u16Color)
{
	u8 data;
	u16 counter;
	/* set x address */
	TFT_voidSendCommad(0x2A);
	TFT_voidSendData(0);
	TFT_voidSendData(0);
	TFT_voidSendData(0);
	TFT_voidSendData(127);

	/* set y address */
	TFT_voidSendCommad(0x2B);
	TFT_voidSendData(0);
	TFT_voidSendData(0);
	TFT_voidSendData(0);
	TFT_voidSendData(159);

	/* RAM write */
	TFT_voidSendCommad(0x2C);

	for(counter=0; counter<20480; counter++)
	{
		data = Copy_u16Color >> 8;
		TFT_voidSendData(data);

		data = Copy_u16Color & 0xFF; // for low part
		TFT_voidSendData(data);
	}

}

void TFT_voidDrawRect(u8 Copy_u8Xstart, u8 Copy_u8Xend, u8 Copy_u8Ystart, u8 Copy_u8Yend, u16 Copy_u16Color)
{
	u8 data;
	u16 counter;
	u16 Local_u16Size = (Copy_u8Xend - Copy_u8Xstart) * (Copy_u8Yend - Copy_u8Ystart) ;
	/* set x address */
	TFT_voidSendCommad(0x2A);
	TFT_voidSendData(0);
	TFT_voidSendData(Copy_u8Xstart);
	TFT_voidSendData(0);
	TFT_voidSendData(Copy_u8Xend);

	/* set y address */
	TFT_voidSendCommad(0x2B);
	TFT_voidSendData(0);
	TFT_voidSendData(Copy_u8Ystart);
	TFT_voidSendData(0);
	TFT_voidSendData(Copy_u8Yend);

	/* RAM write */
	TFT_voidSendCommad(0x2C);

	for(counter=0; counter<Local_u16Size; counter++)
	{
		data = Copy_u16Color  >> 8;
		TFT_voidSendData(data);

		data = Copy_u16Color  & 0xFF; // for low part
		TFT_voidSendData(data);
	}
}
