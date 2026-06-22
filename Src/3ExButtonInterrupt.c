#include "stm32f407xx.h"






int main()
{
    GPIO_Handle_t GpioLed    ;
    GPIO_Handle_t GpioButton ;


    SYSCFG_PCLK_EN () ;
    

	GpioLed.pGPIOx = GPIOD;

	printf("Hello , World\n") ;




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
    GpioButton.GPIO_PinConfig.GPIO_PinMode     = GPIO_MODE_IT_FT   ;
    GpioButton.GPIO_PinConfig.GPIO_PinSpeed    = GPIO_SPEED_FAST   ;
    GpioButton.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_PIN_PU     ;


    
    GPIO_PeriClockControl(GPIOB, ENABLE);
	GPIO_Init(&GpioButton);

	GPIO_WriteToOutputPin(GPIOD,GPIO_PIN_NO_12, DISABLE) ;




    // IRQ Configuration 
    
   GPIO_IRQPriorityConfig(IRQ_NO_EXTI15_10 ,NVIC_IRQ_PRIO15) ;
   GPIO_IRQInterruptConfig(IRQ_NO_EXTI15_10,ENABLE)          ;




    while(1) ;


}


//void EXTI9_5_IRQHandler(void)
//{
//    GPIO_IRQHandling(GPIO_PIN_NO_5)            ;
//    GPIO_ToggleOutputPin(GPIOD,GPIO_PIN_NO_12) ;
//}

void EXTI15_10_IRQHandler(void)
{
     GPIO_IRQHandling(GPIO_PIN_NO_12)            ;
     GPIO_ToggleOutputPin(GPIOD,GPIO_PIN_NO_12)  ;
}

/*                                       
                                    Debugging the Interrupt
                                    pb5 , pb12

*/
