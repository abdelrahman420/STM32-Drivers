/*
 * STP_INTERFACE.h
 *
 *  Created on: 12Sep.,2023
 *      Author: abdel
 */

#ifndef COTS_HAL_STP_STP_INTERFACE_H_
#define COTS_HAL_STP_STP_INTERFACE_H_


void S2P_voidInit(void);
//void S2P_voidSendData(u8 *Copy_u8DataPtr,u8 Copy_u8Size);
void S2P_voidSendData(u32 Copy_u32Data);
S2P_voidShift();
S2P_voidLatch();
#endif /* COTS_HAL_STP_STP_INTERFACE_H_ */
