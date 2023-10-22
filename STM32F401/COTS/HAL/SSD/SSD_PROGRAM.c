

#include "../../MCAL/GPIO/GPIO_INTERFACE.h"


#include "SSD_INTERFACE.h"
#include "SSD_PRIVATE.h"
#include "SSD_CONFIG.h"

void SSD_voidInit(SSD_t * Copy_Ptr_SSD)
{
	for(u8 i = 0; i<8;i++)
	{
		GPIO_Config MySSD =
		{
				.Port = Copy_Ptr_SSD->Port,
				.Pin = i,
				.Mode = GPIO_OUTPUT,
				.OutputSpeed = LOW_Speed,
				.OutputType = push_pull,
				.PullState = NO_PULL
		};
		GPIO_voidInit(&MySSD);
	}
	switch(Copy_Ptr_SSD->CommonState)
		{
		case SSD_COMMON_CATHODE:GPIO_voidSetQuarterPortValue(Copy_Ptr_SSD->Port,0x00);
		break;
		case SSD_COMMON_ANODE:GPIO_voidSetQuarterPortValue(Copy_Ptr_SSD->Port,0xFF);
		break;
		default:
			break;
		}
}
void SSD_voidEnable(SSD_t * Copy_Ptr_SSD ,u8 Copy_u8Number )
{
	switch(Copy_Ptr_SSD->CommonState)
	{
	case SSD_COMMON_CATHODE:
		GPIO_voidSetQuarterPortValue(Copy_Ptr_SSD->Port,ArrayNumbers[Copy_u8Number]);
	break;
	case SSD_COMMON_ANODE:
		GPIO_voidSetQuarterPortValue(Copy_Ptr_SSD->Port,ArrayNumbers[Copy_u8Number]);
	break;
	default:
		break;
	}
}
void SSD_voidDisable(SSD_t * Copy_Ptr_SSD)
{
	for(u8 i = 0; i<8;i++)
	{
		GPIO_Config MySSD =
		{
				.Port = Copy_Ptr_SSD->Port,
				.Pin = i,
				.Mode = GPIO_OUTPUT,
				.OutputSpeed = LOW_Speed,
				.OutputType = push_pull,
				.PullState = NO_PULL
		};
		GPIO_voidInit(&MySSD);
	}
	switch(Copy_Ptr_SSD->CommonState)
	{
	case SSD_COMMON_CATHODE: GPIO_voidSetQuarterPortValue(Copy_Ptr_SSD->Port,0x00);
	break;
	case SSD_COMMON_ANODE:GPIO_voidSetQuarterPortValue(Copy_Ptr_SSD->Port,0xFF);
	break;
	default:
		break;
	}
}
