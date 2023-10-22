/*
 * BH1750_program.c
 *
 *  Created on: 10Oct.,2023
 *      Author: abdel
 */


#include "../../LIB/STD.h"
#include "../../LIB/BitMath.h"

#include "../../MCAL/I2C/I2C_Interface.h"
#include "../../MCAL/SYSTICK/SYSTICK_INTERFACE.h"

#include"BH1750_interface.h"

u8 buff[2];
void BH1750_Init()
{
	/*
	 * 1-Set Power On
	 * 2-Set Measurement Mode
	 */

	I2C_Start();
	I2C_Address(BH1750_ADDRESS << 1);  //0100011
	I2C_Write(BH1750_PowerOn);
	I2C_Stop();
	I2C_Start();
	I2C_Address(BH1750_ADDRESS << 1);
	I2C_Write(BH1750_CONT_HRES);//00010000
	I2C_Stop();

}
u16 BH1750_Read(void)
{
	u16 Local_u16Value = 0;
	I2C_Start();
	I2C_Read(((BH1750_ADDRESS << 1)|0x01),buff,2);
	I2C_Stop();
	Local_u16Value=((buff[0]<<8)|buff[1])/1.2;
	return Local_u16Value;

}

