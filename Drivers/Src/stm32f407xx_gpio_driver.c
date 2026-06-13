/*
 * stm32f407xx_gpio_driver.c
 *
 *  Created on: May 16, 2026
 *      Author: madhav-gaur
 */

#include "stm32f407xx_gpio_driver.h"
#include "stm32f407xx.h"

/*
 *  Peripheral Clock Setup
 */

/*******************************************************************************
 * @fn                         -  GPIO_PeriClockControl
 *
 * @brief                      -  This function enables or disables peripheral clock for the given GPIO port
 *
 * @param[in]                  -  Base address of the gpio peripheral
 * @param[in]                  -  Enable or Disable macros
 * @param[in]                  -
 *
 * @return                     -
 *
 * @note                       -
 *
 *
 ********************************************************************************/

void GPIO_PeriClockControl(GPIO_RegDef_t  *pGPIOx , uint8_t EnorDi  )
{
   if(EnorDi == ENABLE )
   {
	       if(pGPIOx == GPIOA)
	       {
		       GPIOA_PCLK_EN();
	       }else if(pGPIOx == GPIOB)
	       {
		       GPIOB_PCLK_EN();
	       }else if(pGPIOx == GPIOC)
	       {
		       GPIOC_PCLK_EN();
	       }else if(pGPIOx == GPIOD)
	       {
		       GPIOD_PCLK_EN();
	       }else if(pGPIOx == GPIOE)
	       {
		       GPIOE_PCLK_EN();
	       }else if(pGPIOx == GPIOF)
	       {
		       GPIOF_PCLK_EN();
	       }else if(pGPIOx == GPIOG)
	       {
		       GPIOG_PCLK_EN();
	       }else if(pGPIOx == GPIOH)
	       {
		       GPIOH_PCLK_EN();
	       }else if(pGPIOx == GPIOI)
	       {
		       GPIOI_PCLK_EN();
	       }else if(pGPIOx == GPIOJ)
	       {
		       GPIOJ_PCLK_EN();
	       }else if(pGPIOx == GPIOK)
	       {
		       GPIOK_PCLK_EN();
	       }
   }
   else
   {
	   if(pGPIOx == GPIOA)
	 	   {
	 		   GPIOA_PCLK_DI();
	 	   }else if(pGPIOx == GPIOB)
	 	   {
	 		   GPIOB_PCLK_DI();
	 	   }else if(pGPIOx == GPIOC)
	 	   {
	 		   GPIOC_PCLK_DI();
	 	   }else if(pGPIOx == GPIOD)
	 	   {
	 		   GPIOD_PCLK_DI();
	 	   }else if(pGPIOx == GPIOE)
	 	   {
	 		   GPIOE_PCLK_DI();
	 	   }else if(pGPIOx == GPIOF)
	 	   {
	 		   GPIOF_PCLK_DI();
	 	   }else if(pGPIOx == GPIOG)
	 	   {
	 		   GPIOG_PCLK_DI();
	 	   }else if(pGPIOx == GPIOH)
	 	   {
	 		   GPIOH_PCLK_DI();
	 	   }else if(pGPIOx == GPIOI)
	 	   {
	 		   GPIOI_PCLK_DI();
	 	   }else if(pGPIOx == GPIOJ)
	 	   {
	 		   GPIOJ_PCLK_DI();
	 	   }else if(pGPIOx == GPIOK)
	 	   {
	 		   GPIOK_PCLK_DI();
	 	   }
   }
}

/*
 *  Init and De-init
 */

void GPIO_Init(GPIO_Handle_t *pGPIOHandle)
{
	// 1. Configure the mode of the gpio pin

	uint32_t temp = 0 ; // Temporary Register

	if(pGPIOHandle->GPIO_PinConfig.GPIO_PinMode <= GPIO_MODE_ANALOG)
	{
		// The non interrupt mode
		temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinMode << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber)) ;
		pGPIOHandle->pGPIOx->MODER &= ~(0x3 <<  pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber ) ; // Clearing
		pGPIOHandle->pGPIOx->MODER |= temp ;                                                   // Setting
	}else{
		// To be implemented in later phase (Interrupt) .
	}

	// 2. Configure the speed

	temp = 0 ;

    temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinSpeed << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber ) )  ;
    pGPIOHandle->pGPIOx->OSPEEDR &= ~(0x3 <<  pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber ) ; // Clearing
    pGPIOHandle->pGPIOx->OSPEEDR |= temp ;                                                   // Setting

	// 3. Configure the pull up / pull down settings

    temp = 0 ;

    temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinPuPdControl << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber ) )  ;
    pGPIOHandle->pGPIOx->PUPDR &= ~(0x3 <<  pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber ) ; // Clearing
    pGPIOHandle->pGPIOx->PUPDR |= temp ;

	// 4. Configure the output type

    temp = 0 ;

    temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinOPType << (pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber ) )  ;
    pGPIOHandle->pGPIOx->OTYPER &= ~(0x3 <<  pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber ) ; // Clearing
    pGPIOHandle->pGPIOx->OTYPER |= temp ;

	// 5. Configure the alternate functionality

    if(pGPIOHandle->GPIO_PinConfig.GPIO_PinMode == GPIO_MODE_ALTFN )
    {
        // Configure the Alternate function Regsiter

    	/*
    	 * Each GPIO pin configured in Alternate Function (AF) mode uses a 4-bit field
    	 * in either the AFRL or AFRH register.
    	 *
    	 * - AFRL (Alternate Function Low Register) configures pins 0–7.
    	 * - AFRH (Alternate Function High Register) configures pins 8–15.
    	 *
    	 * Register selection:
    	 *      pin / 8 == 0  -> Use AFRL
    	 *      pin / 8 == 1  -> Use AFRH
    	 *
    	 * Bit position calculation:
    	 *      field_index = pin % 8
    	 *      bit_position = field_index * 4
    	 *
    	 * Example 1: Pin 6
    	 *      6 / 8 = 0  -> AFRL selected
    	 *      6 % 8 = 6
    	 *      bit_position = 6 * 4 = 24
    	 *      Therefore, the AF field occupies bits [27:24] of AFRL.
    	 *
    	 * Example 2: Pin 8
    	 *      8 / 8 = 1  -> AFRH selected
    	 *      8 % 8 = 0
    	 *      bit_position = 0 * 4 = 0
    	 *      Therefore, the AF field occupies bits [3:0] of AFRH.
    	 *
    	 * In general:
    	 *      Register      = (pin < 8) ? AFRL : AFRH
    	 *      Bit Position  = (pin % 8) * 4
    	 */

    	uint32_t temp1 , temp2 ;

    	temp1 = pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber/8 ;
    	temp2 = pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber%8 ;
    	pGPIOHandle->pGPIOx->AFR[temp1] &= ~(0xF << ( 4 * temp2 )) ;
    	pGPIOHandle->pGPIOx->AFR[temp1] |=  (pGPIOHandle->GPIO_PinConfig.GPIO_PinAltFunMode << ( 4 * temp2 )) ;
    }
}

void GPIO_DeInit(GPIO_RegDef_t  *pGPIOx)
{
	           if(pGPIOx == GPIOA)
		       {
			       GPIOA_REG_RESET();
		       }else if(pGPIOx == GPIOB)
		       {
			       GPIOB_REG_RESET();
		       }else if(pGPIOx == GPIOC)
		       {
			       GPIOC_REG_RESET();
		       }else if(pGPIOx == GPIOD)
		       {
			       GPIOD_REG_RESET();
		       }else if(pGPIOx == GPIOE)
		       {
			       GPIOE_REG_RESET();
		       }else if(pGPIOx == GPIOF)
		       {
			       GPIOF_REG_RESET();
		       }else if(pGPIOx == GPIOG)
		       {
			       GPIOG_REG_RESET();
		       }else if(pGPIOx == GPIOH)
		       {
			       GPIOH_REG_RESET();
		       }else if(pGPIOx == GPIOI)
		       {
			       GPIOI_REG_RESET();
		       }else if(pGPIOx == GPIOJ)
		       {
			       GPIOJ_REG_RESET();
		       }else if(pGPIOx == GPIOK)
		       {
			       GPIOK_REG_RESET();
		       }
}

/*
 *  Data read and write
 */

uint8_t  GPIO_ReadFromInputPin(GPIO_RegDef_t  *pGPIOx , uint8_t PinNumber)
{

}

uint16_t GPIO_ReadFromInputPort(GPIO_RegDef_t  *pGPIOx)
{

}

void GPIO_WriteToOutputPin(GPIO_RegDef_t  *pGPIOx , uint8_t PinNumber,uint8_t Value)
{

}

void GPIO_WriteToOutputPort(GPIO_RegDef_t  *pGPIOx , uint16_t Value)
{

}

void GPIO_ToggleOutputPin(GPIO_RegDef_t  *pGPIOx , uint8_t PinNumber)
{

}

/*
 *  IRQ configuration and IRQ handling
 */

void GPIO_IRQConfig(uint8_t IRQNumber , uint8_t IRQPriority , uint8_t EnorDi)
{

}

void GPIO_IRQHandling(uint8_t PinNumber)
{

}

