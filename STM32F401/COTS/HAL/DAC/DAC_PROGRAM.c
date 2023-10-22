/*
 * DAC_PROGRAM.c
 *
 *  Created on: 13Sep.,2023
 *      Author: abdel
 */
#include "../../LIB/STD.h"
#include "../../LIB/BitMath.h"

#include"DAC_INTERFACE.h"
#include"DAC_PRIVATE.h"
#include"DAC_CONFIG.h"
#include "../../MCAL/GPIO/GPIO_INTERFACE.h"
#include "song.h"

void DAC_voidSend()
{
	static u32 i = 0;
	GPIO_voidSetQuarterPortValue(GPIO_PORTA,song_raw[i]);
	i++;
	if(i == song_raw_len)
	{
		i = 0;
	}
}

