/*
 * TFT_INTERFACE.h
 *
 *  Created on: 19Sep.,2023
 *      Author: abdel
 */

#ifndef COTS_HAL_TFT_TFT_INTERFACE_H_
#define COTS_HAL_TFT_TFT_INTERFACE_H_

void TFT_voidInit(void);

void TFT_voidDisplayImage(const u16* PtrImage);

void TFT_voidFillerColor(u16 Copy_u16Color);

void TFT_voidDrawRect(u8 Copy_u8Xstart, u8 Copy_u8Xend, u8 Copy_u8Ystart, u8 Copy_u8Yend, u16 Copy_u16Color);
#endif /* COTS_HAL_TFT_TFT_INTERFACE_H_ */
