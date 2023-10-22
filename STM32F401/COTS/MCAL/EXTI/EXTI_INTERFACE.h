#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H


#define Rising_Edge   0
#define Falling_Edge  1
#define On_Change     2

#define EXTI_PORTA    0
#define EXTI_PORTA    1
#define EXTI_PORTA    2

void EXTI_voidInit(u8 Copy_u8Line,u8 Copy_u8SenseControl);
void EXTI_voidEnableLine(u8 Copy_u8Line);
void EXTI_voidDisableLine(u8 Copy_u8Line);
void EXTI_SetCallback(u8 Copy_u8Line,void (*PF) (void));
void EXTI_voidSyscfgPort(u8 Copy_u8Line,u8 Copy_u8Port);

#endif