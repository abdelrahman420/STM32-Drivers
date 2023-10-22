/*
 * BH1750_interface.h
 *
 *  Created on: 10Oct.,2023
 *      Author: abdel
 */

#ifndef COTS_HAL_BH1750_BH1750_INTERFACE_H_
#define COTS_HAL_BH1750_BH1750_INTERFACE_H_

#define BH1750_ADDRESS 		0x23

#define BH1750_PowerOff     0x00
#define BH1750_PowerOn      0x01
#define BH1750_RESET        0x07
#define BH1750_CONT_HRES    0x10
#define BH1750_CONT_HRES2   0x11
#define BH1750_CONT_LRES    0x13
#define BH1750_ONE_HRES     0x20
#define BH1750_ONE_HRES2    0x21
#define BH1750_ONE_LRES     0x23


void BH1750_Init();
u16 BH1750_Read(void);


#endif /* COTS_HAL_BH1750_BH1750_INTERFACE_H_ */
