#include "../../LIB/STD.h"
#include "../../LIB/BitMath.h"

#include"NVIC_INTERFACE.h"
#include"NVIC_PRIVATE.h"
#include"NVIC_CONFIG.h"

static u32 NVIC_Glosu32GroupConf = 0 ;

void NVIC_voidEnablePeripehral(u8 Copy_u8IntID)
{
    NVIC->ISER[Copy_u8IntID / 32] = 1 << (Copy_u8IntID % 32);
}
void NVIC_voidDisblePeripehral(u8 Copy_u8IntID)
{
    NVIC->ICER[Copy_u8IntID / 32] = 1 << (Copy_u8IntID % 32);
}
void NVIC_voidSetPendingFlag(u8 Copy_u8IntID)
{
    NVIC->ISPR[Copy_u8IntID / 32] = 1 << (Copy_u8IntID % 32);
}
void NVIC_voidClearPendingFlag(u8 Copy_u8IntID)
{
    NVIC->ICPR[Copy_u8IntID / 32] = 1 << (Copy_u8IntID % 32);
}
u8 NVIC_u8GetActive(u8 Copy_u8IntID)
{
    u8 Local_u8State = 255;
    Local_u8State = GET_BIT(NVIC->IABR[Copy_u8IntID / 32],(Copy_u8IntID % 32));
    return Local_u8State;
}
void NVIC_voidSetPriorityConfig(u8 Copy_u8PriorityOption)
{
	NVIC_Glosu32GroupConf = VECT_KEY | ( Copy_u8PriorityOption << 8);	// 0x0f5A xxxx
	SCB->AIRCR = NVIC_Glosu32GroupConf ;
}
void NVIC_voidSetPriority(s8 Copy_s8IntID,u8 Copy_u8GroupPriority,u8 Copy_u8SubPriority)
{
	u8 Local_u8Priority = Copy_u8SubPriority | (Copy_u8GroupPriority << ((NVIC_Glosu32GroupConf - 0x05FA0300)/256));

		if(Copy_s8IntID < 0)
		{
			if(Copy_s8IntID == MEMORY_MANAGE || Copy_s8IntID == BUS_FAULT || Copy_s8IntID == USAGE_FAULT)
			{
				Copy_s8IntID += 3 ;
				SCB->SHPR1 = (Local_u8Priority)<< ((8* Copy_s8IntID) +4);
			}
			else if(Copy_s8IntID == SV_CALL)
			{
				Copy_s8IntID +=7 ;
				SCB->SHPR2 = (Local_u8Priority) << ((8 * Copy_s8IntID) + 4 );
			}
			else if ( Copy_u8GroupPriority == PEND_SV)
			{
				Copy_s8IntID += 8 ;
				SCB->SHPR3 = (Local_u8Priority) << ((8*Copy_s8IntID) + 4 );
			}
		}
		else if ( Copy_s8IntID >= 0)
		{
			NVIC->IPR[Copy_s8IntID] = Local_u8Priority << 4 ;
		}
}
