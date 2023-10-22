/*
 * STP_CONFIG.c
 *
 *  Created on: 12Sep.,2023
 *      Author: abdel
 */
#include "../../LIB/STD.h"
#include "../../LIB/BitMath.h"

#include "../../MCAL/GPIO/GPIO_INTERFACE.h"

#include"STP_CONFIG.h"

GPIO_Config STP_DataSerial =
{
		.Mode = GPIO_OUTPUT,
		.Port = GPIO_PORTA,
		.Pin = GPIO_PIN0,
		.OutputType = push_pull,
		.OutputSpeed = LOW_Speed,
		.PullState =NO_PULL
};

GPIO_Config STP_Shift =
{
		.Mode = GPIO_OUTPUT,
		.Port = GPIO_PORTA,
		.Pin = GPIO_PIN1,
		.OutputType = push_pull,
		.OutputSpeed = LOW_Speed,
		.PullState =NO_PULL
};

GPIO_Config STP_Store =
{
		.Mode = GPIO_OUTPUT,
		.Port = GPIO_PORTA,
		.Pin = GPIO_PIN2,
		.OutputType = push_pull,
		.OutputSpeed = LOW_Speed,
		.PullState =NO_PULL
};

