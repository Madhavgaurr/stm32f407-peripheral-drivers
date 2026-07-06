/*
 * stm32f407xx_adc_driver.h
 *
 *  Created on: May 16, 2026
 *      Author: madhav-gaur
 */

#ifndef INC_STM32F407XX_ADC_DRIVER_H_
#define INC_STM32F407XX_ADC_DRIVER_H_

#include "stm32f407xx.h"

typedef struct 
{
    uint8_t   ADC_Resolution ; 
}ADC_Config_t;


typedef struct 
{
    ADC_RegDef_t  *pADCx     ; 
    ADC_Config_t  ADC_Config ;  
}ADC_Handle_t;   





void ADC_PeriClockControl(ADC_RegDef_t  *pGPIOx , uint8_t EnorDi  ) ;





#endif /* INC_STM32F407XX_GPIO_DRIVER_H_ */
