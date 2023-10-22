#include "../../LIB/STD.h"
#include "../../LIB/BitMath.h"

#include "../SYSTICK/SYSTICK_CONFIG.h"
#include "../SYSTICK/SYSTICK_INTERFACE.h"
#include "../SYSTICK/SYSTICK_PRIVATE.h"


void (* GS_SYSTICK_CallBack )(void) = NULL;
u8 G_u8SingleFlag;
void SYSTICK_voidInit(void)
{
#if SYSTICK_CLK_SOURCE == SYSTICK_AHB
	SET_BIT(SYSTICK->CTRL,2);
#elif SYSTICK_CLK_SOURCE == SYSTICK_AHB_8
	CLR_BIT(SYSTICK->CTRL,2);
#endif
#if SYSTICK_TECHNIQUE == SYSTICK_POLLING
	CLR_BIT(SYSTICK->CTRL,1);
#elif SYSTICK_TECHNIQUE == SYSTICK_INTERRUPT
	SET_BIT(SYSTICK->CTRL,1);
#endif
}
void SYSTICK_voidStartTimer(u32 Copy_u32LoadValue)
{
	SYSTICK->LOAD = Copy_u32LoadValue;
	SYSTICK->Val = 0x000000;
	SET_BIT(SYSTICK->CTRL,0);
}
void SYSTICK_voidStopTimer(void)
{
	CLR_BIT(SYSTICK->CTRL,0);
}
void SYSTICK_voidSetBusyWait(u32 Copy_u32Ticks)
{
	SYSTICK_voidStartTimer(Copy_u32Ticks * 3.125);
	while(GET_BIT(SYSTICK->CTRL,16) == 0){};
	SYSTICK_voidStopTimer();
}

void SYSTICK_voidSetInterval_Single(u32 Copy_u32LoadValue,void(*CallbackFunction)(void))
{
	GS_SYSTICK_CallBack = CallbackFunction;
	G_u8SingleFlag = 1;
	SYSTICK_voidStartTimer(Copy_u32LoadValue * 3.125);
}
void SYSTICK_voidSetInterval_Periodic(u32 Copy_u32LoadValue,void(*CallbackFunction)(void))
{
	GS_SYSTICK_CallBack = CallbackFunction;
	G_u8SingleFlag = 0;
	SET_BIT(SYSTICK->CTRL , 1 );
	/* 1- reset timer value */
	SYSTICK->Val = 0 ;
	/* 2- Load timer with Value */
	SYSTICK->LOAD = Copy_u32LoadValue * 3.125 ;
	/* 3- Start the timer   */
	SET_BIT(SYSTICK->CTRL, 0);
}

u32 SYSTICK_u32GetElabsedTime(void)
{
	u32 Local_u32ElabsedTime = (SYSTICK->LOAD) -(SYSTICK->Val);
	return Local_u32ElabsedTime;
}
u32 SYSTICK_u32GetRemainingTime(void)
{
	u32 Local_u32RemainingTime = (SYSTICK->Val);
	return Local_u32RemainingTime;
}
void SysTick_Handler(void)
{
	if(GS_SYSTICK_CallBack != NULL)
	{
		GS_SYSTICK_CallBack();
		if(G_u8SingleFlag == 1)
		{
			SYSTICK_voidStopTimer();
		}
		else{};

	}

}
