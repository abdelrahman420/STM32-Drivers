#include "../../LIB/STD.h"
#include "../../LIB/BitMath.h"

#include "GPIO_INTERFACE.h"
#include"GPIO_PRIVATE.h"
#include"GPIO_CONFIG.h"

void GPIO_voidSetPinMode(GPIO_PORT_t Copy_GPIOPortID,GPIO_PIN_t Copy_GPIOPinID,GPIO_Mode_t Copy_GPIOMode)
{
	switch(Copy_GPIOPortID)
	{
	case GPIO_PORTA:
	{
		GPIOA->MODER &= ~(0b11 << (Copy_GPIOPinID * 2));
		GPIOA->MODER |= (Copy_GPIOMode << (Copy_GPIOPinID * 2));
	}
	break;
	case GPIO_PORTB:
	{
		GPIOB->MODER &= ~(0b11 << (Copy_GPIOPinID * 2));
		GPIOB->MODER |= (Copy_GPIOMode << (Copy_GPIOPinID * 2));
	}
	break;
	case GPIO_PORTC:
	{
		GPIOC->MODER &= ~(0b11 << (Copy_GPIOPinID * 2));
		GPIOC->MODER |= (Copy_GPIOMode << (Copy_GPIOPinID * 2));
	}
	break;
	default:
		break;
	}
}
void GPIO_voidSetPinOutputType(GPIO_PORT_t Copy_GPIOPortID,GPIO_PIN_t Copy_GPIOPinID,u8 Copy_u8OutputType)
{
	switch(Copy_GPIOPortID)
	{
	case GPIO_PORTA:
	{
		switch(Copy_u8OutputType)
		{
		case push_pull:
		{
			CLR_BIT(GPIOA->OTYPER, Copy_GPIOPinID);
		}
		break;
		case open_drain:
		{
			SET_BIT(GPIOA->OTYPER, Copy_GPIOPinID);
		}
		break;
		default:
			break;
		}
	}
	break;
	case GPIO_PORTB:
	{
		switch(Copy_u8OutputType)
		{
		case push_pull:
		{
			CLR_BIT(GPIOB->OTYPER, Copy_GPIOPinID);
		}
		break;
		case open_drain:
		{
			SET_BIT(GPIOB->OTYPER, Copy_GPIOPinID);
		}
		break;
		default:
			break;
		}
	}
	break;
	case GPIO_PORTC:
	{
		switch(Copy_u8OutputType)
		{
		case push_pull:
		{
			CLR_BIT(GPIOC->OTYPER, Copy_GPIOPinID);
		}
		break;
		case open_drain:
		{
			SET_BIT(GPIOC->OTYPER, Copy_GPIOPinID);
		}
		break;
		default:
			break;
		}
	}
	break;
	default:
		break;
	}
}
void GPIO_voidSetPinOutputSpeed(GPIO_PORT_t Copy_GPIOPortID,GPIO_PIN_t Copy_GPIOPinID,GPIO_Speed_t Copy_OutputSpeed)
{
	switch(Copy_GPIOPortID)
	{
	case GPIO_PORTA:
	{
		GPIOA->OSPEEDR &= ~(0b11 << (Copy_GPIOPinID * 2));
		GPIOA->OSPEEDR |= (Copy_OutputSpeed << (Copy_GPIOPinID * 2));
	}
	break;
	case GPIO_PORTB:
	{
		GPIOB->OSPEEDR &= ~(0b11 << (Copy_GPIOPinID * 2));
		GPIOB->OSPEEDR |= (Copy_OutputSpeed << (Copy_GPIOPinID * 2));
	}
	break;
	case GPIO_PORTC:
	{
		GPIOC->OSPEEDR &= ~(0b11 << (Copy_GPIOPinID * 2));
		GPIOC->OSPEEDR |= (Copy_OutputSpeed << (Copy_GPIOPinID * 2));
	}
	break;
	default:
		break;
	}
}
void GPIO_voidSetPinPull(GPIO_PORT_t Copy_GPIOPortID,GPIO_PIN_t Copy_GPIOPinID,u8 Copy_u8Pull)
{
	switch(Copy_GPIOPortID)
	{
	case GPIO_PORTA:
	{
		GPIOA->PUPDR &= ~(0b11 << (Copy_GPIOPinID * 2));
		GPIOA->PUPDR |= (Copy_u8Pull << (Copy_GPIOPinID * 2));
	}
	break;
	case GPIO_PORTB:
	{
		GPIOB->PUPDR &= ~(0b11 << (Copy_GPIOPinID * 2));
		GPIOB->PUPDR |= (Copy_u8Pull << (Copy_GPIOPinID * 2));
	}
	break;
	case GPIO_PORTC:
	{
		GPIOC->PUPDR &= ~(0b11 << (Copy_GPIOPinID * 2));
		GPIOC->PUPDR |= (Copy_u8Pull << (Copy_GPIOPinID * 2));
	}
	break;
	default:
		break;
	}

}
u8 GPIO_u8GetPinValue (GPIO_PORT_t Copy_GPIOPortID,GPIO_PIN_t Copy_GPIOPinID)
{
	u8 Copy_u8ReturnedValue;
	switch(Copy_GPIOPortID)
	{
	case GPIO_PORTA:
	{
		Copy_u8ReturnedValue = GET_BIT(GPIOA->IDR,Copy_GPIOPinID);
	}
	break;
	case GPIO_PORTB:
	{
		Copy_u8ReturnedValue = GET_BIT(GPIOC->IDR,Copy_GPIOPinID);
	}
	break;
	case GPIO_PORTC:
	{
		Copy_u8ReturnedValue = GET_BIT(GPIOC->IDR,Copy_GPIOPinID);
	}
	break;
	}
	return Copy_u8ReturnedValue;
}
void GPIO_voidSetPinValue (GPIO_PORT_t Copy_GPIOPortID,GPIO_PIN_t Copy_GPIOPinID,u8 Copy_u8PValue)
{
	switch(Copy_GPIOPortID)
	{
	case GPIO_PORTA:
	{
		switch(Copy_u8PValue)
		{
		case GPIO_LOW:
		{
			CLR_BIT(GPIOA->ODR,Copy_GPIOPinID);
		}
		break;
		case GPIO_HIGH:
		{
			SET_BIT(GPIOA->ODR,Copy_GPIOPinID);
		}
		break;
		default:
			break;
		}

	}
	break;
	case GPIO_PORTB:
	{
		switch(Copy_u8PValue)
		{
		case GPIO_LOW:
		{
			CLR_BIT(GPIOB->ODR,Copy_GPIOPinID);
		}
		break;
		case GPIO_HIGH:
		{
			SET_BIT(GPIOB->ODR,Copy_GPIOPinID);
		}
		break;
		default:
			break;
		}
	}
	break;
	case GPIO_PORTC:
	{
		switch(Copy_u8PValue)
		{
		case GPIO_LOW:
		{
			CLR_BIT(GPIOC->ODR,Copy_GPIOPinID);
		}
		break;
		case GPIO_HIGH:
		{
			SET_BIT(GPIOC->ODR,Copy_GPIOPinID);
		}
		break;
		default:
			break;
		}
	}
	break;
	default:
		break;
	}
}
void GPIO_voidSetPinValueAtomic (GPIO_PORT_t Copy_GPIOPortID,GPIO_PIN_t Copy_GPIOPinID,u8 Copy_u8PValue)
{
	switch(Copy_GPIOPortID)
	{
	case GPIO_PORTA:
	{
		switch(Copy_u8PValue)
		{
		case GPIO_LOW:
		{
			GPIOA->BSRR = (1 << (16 + Copy_GPIOPinID));
		}
		break;
		case GPIO_HIGH:
		{
			GPIOA->BSRR = (1 << (Copy_GPIOPinID));
		}
		break;
		default:
			break;
		}

	}
	break;
	case GPIO_PORTB:
	{
		switch(Copy_u8PValue)
		{
		case GPIO_LOW:
		{
			GPIOB->BSRR = (1 << (16 + Copy_GPIOPinID));
		}
		break;
		case GPIO_HIGH:
		{
			GPIOC->BSRR = (1 << (Copy_GPIOPinID));
		}
		break;
		default:
			break;
		}
	}
	break;
	case GPIO_PORTC:
	{
		switch(Copy_u8PValue)
		{
		case GPIO_LOW:
		{
			GPIOC->BSRR = (1 << (16 + Copy_GPIOPinID));
		}
		break;
		case GPIO_HIGH:
		{
			GPIOC->BSRR = (1 << (Copy_GPIOPinID));
		}
		break;
		default:
			break;
		}
	}
	break;
	default:
		break;
	}
}
void GPIO_voidSetAlternative(GPIO_PORT_t Copy_GPIOPortID,GPIO_PIN_t Copy_GPIOPinID,AF_Select_t Copy_Alternative)
{
	if(Copy_GPIOPinID < 8)
	{
		switch(Copy_GPIOPortID)
		{
		case GPIO_PORTA:
		{
			GPIOA->AFRL &= ~((0b1111)<<(Copy_GPIOPinID*4));
			GPIOA->AFRL |= ((Copy_Alternative)<<(Copy_GPIOPinID*4));
		}
		break;
		case GPIO_PORTB:
		{
			GPIOB->AFRL &= ~((0b1111)<<(Copy_GPIOPinID*4));
			GPIOB->AFRL |= ((Copy_Alternative)<<(Copy_GPIOPinID*4));
		}
		break;
		case GPIO_PORTC:
		{
			GPIOC->AFRL &= ~((0b1111)<<(Copy_GPIOPinID*4));
			GPIOC->AFRL |= ((Copy_Alternative)<<(Copy_GPIOPinID*4));
		}
		break;
		default:
			break;
		}
	}
	else if(Copy_GPIOPinID < 16)
	{
		switch(Copy_GPIOPortID)
		{
		case GPIO_PORTA:
		{
			GPIOA->AFRH &= ~((0b1111)<< (Copy_GPIOPinID-8) * 4 );
			GPIOA->AFRH |= ((Copy_Alternative)<<(Copy_GPIOPinID-8) * 4);
		}
		break;
		case GPIO_PORTB:
		{
			GPIOB->AFRH &= ~((0b1111)<<(Copy_GPIOPinID-8) * 4);
			GPIOB->AFRH |= ((Copy_Alternative)<<(Copy_GPIOPinID-8) * 4);
		}
		break;
		case GPIO_PORTC:
		{
			GPIOC->AFRH &= ~((0b1111)<<(Copy_GPIOPinID-8) * 4);
			GPIOC->AFRH |= ((Copy_Alternative)<<(Copy_GPIOPinID-8) * 4);
		}
		break;
		default:
			break;
		}
	}
}

void GPIO_voidSetByteValue (GPIO_PORT_t Copy_GPIOPortID,u8 Copy_u8PValue)
{
	switch(Copy_GPIOPortID)
	{
	case GPIO_PORTA:
		GPIOA->ODR &= 0xFFFFFF00;
		GPIOA->ODR |=Copy_u8PValue;
		break;
	case GPIO_PORTB:
		GPIOB->ODR &= 0xFFFFFF00;
		GPIOB->ODR |= Copy_u8PValue;
		break;
	case GPIO_PORTC:
		GPIOC->ODR &= 0xFFFFFF00;
		GPIOC->ODR |= Copy_u8PValue;
		break;
	}
}
void GPIO_voidInit (GPIO_Config	*config)
{
	GPIO_voidSetPinMode(config->Port , config->Pin , config->Mode);
	GPIO_voidSetPinOutputType(config->Port , config->Pin , config->OutputType);
	GPIO_voidSetPinOutputSpeed(config->Port , config->Pin , config->OutputSpeed);
	GPIO_voidSetPinPull(config->Port , config->Pin , config->PullState);
}
