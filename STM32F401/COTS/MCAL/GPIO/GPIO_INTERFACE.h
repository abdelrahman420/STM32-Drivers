#ifndef GPIO_INTRFACE_H
#define GPIO_INTRFACE_H

#include "../../LIB/STD.h"

typedef enum
{
    GPIO_PORTA,
    GPIO_PORTB,
    GPIO_PORTC

}GPIO_PORT_t;

typedef enum
{
    GPIO_PIN0,
    GPIO_PIN1,
    GPIO_PIN2, 
    GPIO_PIN3,
    GPIO_PIN4,
    GPIO_PIN5, 
    GPIO_PIN6,
    GPIO_PIN7,
    GPIO_PIN8,
    GPIO_PIN9,
    GPIO_PIN10,
    GPIO_PIN11,
    GPIO_PIN12,
    GPIO_PIN13,
    GPIO_PIN14,
    GPIO_PIN15

}GPIO_PIN_t;

typedef enum
{
    GPIO_INPUT,
    GPIO_OUTPUT,
    GPIO_AF,
    GPIO_Analog
}GPIO_Mode_t;

typedef enum
{
    LOW_Speed,
    MEDUIM_Speed,
    HIGH_Speed,
    VHigh_Speed
}GPIO_Speed_t;


typedef enum
{
	GPIO_SYSTEM,
	GPIO_TIM1_2,
	GPIO_TIM3_5,
	GPIO_TIM9_11,
	GPIO_I2C1_3,
	GPIO_SPI1_4,
	GPIO_SPI3,
	GPIO_USART1_2,
	GPIO_USART6,
	GPIO_I2C2_3,
	GPIO_OTG_FS,
	GPIO_SDIO = 12,
	GPIO_EVENOUT = 15,

}AF_Select_t;

#define  push_pull  0
#define  open_drain 1


#define NO_PULL		 	0
#define PULL_UP         1
#define PULL_DOWN       2

#define GPIO_LOW   0
#define GPIO_HIGH  1

typedef struct
{
	GPIO_PORT_t 			Port 		;
	GPIO_PIN_t  			Pin  		;
	GPIO_Mode_t		        Mode 		;
	u8 						OutputType	;
	GPIO_Speed_t 	        OutputSpeed	;
	u8 						PullState 	;

}GPIO_Config;

void GPIO_voidSetPinMode(GPIO_PORT_t Copy_GPIOPortID,GPIO_PIN_t Copy_GPIOPinID,GPIO_Mode_t Copy_GPIOMode);
void GPIO_voidSetPinOutputType(GPIO_PORT_t Copy_GPIOPortID,GPIO_PIN_t Copy_GPIOPinID,u8 Copy_u8OutputType);
void GPIO_voidSetPinOutputSpeed(GPIO_PORT_t Copy_GPIOPortID,GPIO_PIN_t Copy_GPIOPinID,GPIO_Speed_t Copy_OutputSpeed);
void GPIO_voidSetPinPull(GPIO_PORT_t Copy_GPIOPortID,GPIO_PIN_t Copy_GPIOPinID,u8 Copy_u8Pull);
u8 GPIO_u8GetPinValue (GPIO_PORT_t Copy_GPIOPortID,GPIO_PIN_t Copy_GPIOPinID);
void GPIO_voidSetPinValue (GPIO_PORT_t Copy_GPIOPortID,GPIO_PIN_t Copy_GPIOPinID,u8 Copy_u8PValue);
void GPIO_voidSetPinValueAtomic (GPIO_PORT_t Copy_GPIOPortID,GPIO_PIN_t Copy_GPIOPinID,u8 Copy_u8PValue);
void GPIO_voidSetAlternative(GPIO_PORT_t Copy_GPIOPortID,GPIO_PIN_t Copy_GPIOPinID,AF_Select_t Copy_Alternative);
void GPIO_voidSetByteValue (GPIO_PORT_t Copy_GPIOPortID,u8 Copy_u8PValue);
void GPIO_voidInit(GPIO_Config	*config);
#endif
