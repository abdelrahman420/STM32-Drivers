#include "../../LIB/STD.h"
#include "../../LIB/BitMath.h"

#include"EXTI_INTERFACE.h"
#include"EXTI_PRIVATE.h"
#include"EXTI_CONFIG.h"

static void (*Global_PFNotif[16]) (void) = {NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
void EXTI_voidInit(u8 Copy_u8Line,u8 Copy_u8SenseControl)
{
    switch(Copy_u8SenseControl)
    {
        case Rising_Edge:
        {
            SET_BIT(EXTI->RTSR,Copy_u8Line);
        }
        break;
        case Falling_Edge:
        {
            SET_BIT(EXTI->FTSR,Copy_u8Line);
        }
        break;
        case On_Change:
        {
            SET_BIT(EXTI->RTSR,Copy_u8Line);
            SET_BIT(EXTI->FTSR,Copy_u8Line);
        }
        break;
        default:
        break;
    }
}
void EXTI_voidEnableLine(u8 Copy_u8Line)
{
    SET_BIT(EXTI->IMR ,Copy_u8Line);
}
void EXTI_voidDisableLine(u8 Copy_u8Line)
{
    SET_BIT(EXTI->IMR ,Copy_u8Line);
}
void EXTI_SetCallback(u8 Copy_u8Line,void (*PF) (void))
{
    if(PF !=NULL)
    {
        Global_PFNotif[Copy_u8Line] = PF;
    }

}
void EXTI_voidSyscfgPort(u8 Copy_u8Line,u8 Copy_u8Port)
{
    SYSCFG->EXTICR[Copy_u8Line/4] &=~(0b1111<<((Copy_u8Line%4)*4));
	SYSCFG->EXTICR[Copy_u8Line/4] |=(Copy_u8Port<<((Copy_u8Line%4)*4));
}
void  EXTI0_IQRHandler(void)
{
    if(Global_PFNotif[0] != NULL)
    {
        Global_PFNotif[0]();
        SET_BIT(EXTI->PR,0);
    }
}
void  EXTI1_IQRHandler(void)
{
    if(Global_PFNotif[1] != NULL)
    {
        Global_PFNotif[1]();
        SET_BIT(EXTI->PR,1);
    }
}
void  EXTI2_IQRHandler(void)
{
    if(Global_PFNotif[2] != NULL)
    {
        Global_PFNotif[2]();
        SET_BIT(EXTI->PR,2);
    }
}
void  EXTI3_IQRHandler(void)
{
    if(Global_PFNotif[3] != NULL)
    {
        Global_PFNotif[3]();
        SET_BIT(EXTI->PR,3);
    }
}
void  EXTI4_IQRHandler(void)
{
    if(Global_PFNotif[4] != NULL)
    {
        Global_PFNotif[4]();
        SET_BIT(EXTI->PR,4);
    }
}
void  EXTI9_5_IQRHandler(void)
{
    for(u8 i = 5;i<=9;i++)
    {
        if(Global_PFNotif[i] != NULL && GET_BIT(EXTI->PR,i) == 1 )
        {
            Global_PFNotif[i]();
            SET_BIT(EXTI->PR,i);
        }
    }
}
void  EXTI15_10_IQRHandler(void)
{
    for(u8 i = 10;i<=15;i++)
    {
        if(Global_PFNotif[i] != NULL && GET_BIT(EXTI->PR,i) == 1 )
        {
            Global_PFNotif[i]();
            SET_BIT(EXTI->PR,i);
        }
    }
    
}