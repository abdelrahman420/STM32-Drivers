#ifndef SYSTICK_INTERFACE_H
#define SYSTICK_INTERFACE_H


#define SYSTICK_POLLING     0
#define SYSTICK_INTERRUPT   1

#define SYSTICK_AHB_8   0
#define SYSTICK_AHB     1

void SYSTICK_voidInit(void);
void SYSTICK_voidStartTimer(u32 Copy_u32LoadValue);
void SYSTICK_voidStopTimer(void);
void SYSTICK_voidSetBusyWait(u32 Copy_u32Ticks);
void SYSTICK_voidSetInterval_Single(u32 Copy_u32LoadValue,void(*CallbackFunction)(void));
void SYSTICK_voidSetInterval_Periodic(u32 Copy_u32LoadValue,void(*CallbackFunction)(void));

u32 SYSTICK_u32GetElabsedTime(void);
u32 SYSTICK_u32GetRemainingTime(void);

#endif
