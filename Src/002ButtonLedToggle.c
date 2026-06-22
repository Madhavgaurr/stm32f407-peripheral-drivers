#include "stm32f407xx.h"


void delay(void)
{
	for(uint32_t i = 0; i < 50000; i++);
}


int main()
{
    GPIO_Handle_t GpioLed    ;
    GPIO_Handle_t GpioButton ;

	GpioLed.pGPIOx = GPIOD;


	GpioLed.GPIO_PinConfig.GPIO_PinNumber      = GPIO_PIN_NO_12    ;
	GpioLed.GPIO_PinConfig.GPIO_PinMode        = GPIO_MODE_OUTPUT  ;
	GpioLed.GPIO_PinConfig.GPIO_PinSpeed       = GPIO_SPEED_FAST   ;
	GpioLed.GPIO_PinConfig.GPIO_PinOPType      = GPIO_OP_TYPE_PP   ;
	GpioLed.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD      ;

	GPIO_PeriClockControl(GPIOD, ENABLE);
	GPIO_Init(&GpioLed);

    // Button Configuration 

    GpioButton.pGPIOx = GPIOB ;

    GpioButton.GPIO_PinConfig.GPIO_PinNumber   = GPIO_PIN_NO_12     ; 
    GpioButton.GPIO_PinConfig.GPIO_PinMode     = GPIO_MODE_INPUT   ;
    GpioButton.GPIO_PinConfig.GPIO_PinSpeed    = GPIO_SPEED_FAST   ;
    GpioButton.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD    ;

    GPIO_PeriClockControl(GPIOB, ENABLE);
	GPIO_Init(&GpioButton);



	while(1)
	{
		   if(GPIO_ReadFromInputPin(GPIOB,GPIO_PIN_NO_12)){
		      GPIO_ToggleOutputPin(GPIOD,GPIO_PIN_NO_12) ;
			  delay() ;
		   }else{
			  GPIO_WriteToOutputPin(GPIOD,GPIO_PIN_NO_12,DISABLE) ;
		   }
	}
}
