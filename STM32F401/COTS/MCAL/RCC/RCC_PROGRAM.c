
#include "../../LIB/STD.h"
#include "../../LIB/BitMath.h"

#include "RCC_INTERFACE.h"
#include"RCC_PRIVATE.h"
#include"RCC_CONFIG.h"



void RCC_voidInit(void)
{
    /* Enable CSS */
    SET_BIT(RCC->CR , CSSON);
    /*BYPASS select*/
    /*NOT BYPASS*/
    CLR_BIT(RCC->CR,HSEBYP);

    /* Enable clock source */
    #if  RCC_HSI_ENABLE == ENABLE
    SET_BIT(RCC->CR,0);
    #elif RCC_HSI_ENABLE == DISABLE
    CLR_BIT(RCC->CR,0);
    #endif
    #if RCC_HSE_ENABLE == ENABLE
    SET_BIT(RCC->CR,HSEON);
    #elif RCC_HSE_ENABLE == DISABLE
    CLR_BIT(RCC->CR,HSEON);
    #endif
    /* Select clock source */
    #if RCC_CLOCK_SOURCE == RCC_HSI_SELECT
    CLR_BIT( RCC->CFGR , SW0 );
    CLR_BIT( RCC->CFGR , SW1 );
    #elif RCC_CLOCK_SOURCE == RCC_HSE_SELECT
    SET_BIT( RCC->CFGR , SW0 );
    CLR_BIT( RCC->CFGR , SW1 );
    #elif RCC_CLOCK_SOURCE == RCC_PLL_SELECT
    CLR_BIT( RCC->CFGR , SW0 );
    SET_BIT( RCC->CFGR , SW1 );
    #endif
}
ErrorState_t RCC_ErrorStateEnablePeripheralClock (u8 Copy_u8BusID,u8 Copy_u8PerID)
{
    ErrorState_t Local_ErrorState = STD_TYPES_OK;
    if((Copy_u8BusID <= RCC_APB2) &&(Copy_u8PerID < 32))
    {
        switch(Copy_u8BusID)
        {
            case RCC_AHB1 :
                    SET_BIT(RCC->AHB1ENR , Copy_u8PerID );
            break ;
            case RCC_APB1 :
                    SET_BIT(RCC->APB1ENR , Copy_u8PerID);
            break ;
            case RCC_APB2 :
                    SET_BIT(RCC->APB2ENR , Copy_u8PerID);
            break ;
            default :
                Local_ErrorState = STD_TYPES_NOK ; 
            break;
        }
    }
    else
    {
        Local_ErrorState = STD_TYPES_NOK ; 
    }

    return Local_ErrorState;
}
ErrorState_t RCC_ErrorStateDisablePeripheralClock(u8 Copy_u8BusID,u8 Copy_u8PerID)
{
    ErrorState_t Local_ErrorState = STD_TYPES_OK;
    if((Copy_u8BusID <= RCC_APB2) &&(Copy_u8PerID < 32))
    {
        switch(Copy_u8BusID)
        {
            case RCC_AHB1 :
                    CLR_BIT(RCC->AHB1ENR , Copy_u8PerID );
            break ;
            case RCC_APB1 :
                    CLR_BIT(RCC->APB1ENR , Copy_u8PerID);
            break ;
            case RCC_APB2 :
                    CLR_BIT(RCC->APB2ENR , Copy_u8PerID);
            break ;
            default :
                Local_ErrorState = STD_TYPES_NOK ; 
            break;
        }
    }
    else
    {
        Local_ErrorState = STD_TYPES_NOK ; 
    }

    return Local_ErrorState;
}
