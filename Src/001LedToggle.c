/*
* 001LedToggle.c
*
* Created on : Jun 14, 2026
* Author     : Madhav Gaur
*
* Demonstrates:
* 1. LED blinking using Push-Pull output mode.
* 2. LED blinking using Open-Drain output mode.
*
* Select the desired example by enabling the corresponding macros below.
*/

//#define LedBlink

/*----------------------------------------------------------
* Select one of the following configurations
*---------------------------------------------------------*/

// LED toggling using Push-Pull output configuration
#define TogglingLedWithPullUpPullDown

// LED toggling using Open-Drain output configuration
//#define TogglingLedWithOpenDrain

#include "stm32f407xx.h"

/*
* Simple software delay.
* Used only for demonstration purposes.
*/
//void delay(void)
//{
//	for(uint32_t i = 0; i < 50000; i++);
//}

#ifdef LedBlink

int main(void)
{
#ifdef TogglingLedWithPullUpPullDown

	/*------------------------------------------------------
	 * Push-Pull Configuration
	 *
	 * In Push-Pull mode, the GPIO pin can actively drive
	 * both HIGH and LOW levels.
	 *
	 * LED State:
	 *   HIGH -> LED ON
	 *   LOW  -> LED OFF
	 *-----------------------------------------------------*/

	GPIO_Handle_t GpioLed;

	GpioLed.pGPIOx = GPIOD;

	GpioLed.GPIO_PinConfig.GPIO_PinNumber      = GPIO_PIN_NO_12;
	GpioLed.GPIO_PinConfig.GPIO_PinMode        = GPIO_MODE_OUTPUT;
	GpioLed.GPIO_PinConfig.GPIO_PinSpeed       = GPIO_SPEED_FAST;
	GpioLed.GPIO_PinConfig.GPIO_PinOPType      = GPIO_OP_TYPE_PP;
	GpioLed.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;

	GPIO_PeriClockControl(GPIOD, ENABLE);
	GPIO_Init(&GpioLed);

	while(1)
	{
		GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_12);
		delay();
	}

#endif


#ifdef TogglingLedWithOpenDrain

	/*------------------------------------------------------
	 * Open-Drain Configuration
	 *
	 * In Open-Drain mode, the GPIO pin can:
	 *   1. Pull the line LOW
	 *   2. Leave the line floating (High-Z)
	 *
	 * It cannot actively drive the line HIGH.
	 *
	 * Why an external pull-up is usually required:
	 *
	 * The STM32 internal pull-up resistor is relatively
	 * weak (typically 30–50 kΩ). As a result, only a very
	 * small current can flow through the circuit.
	 *
	 * This current is generally insufficient to drive an
	 * LED with visible brightness.
	 *
	 * Therefore, an external pull-up resistor with a much
	 * lower resistance value (typically 220 Ω to 4.7 kΩ,
	 * depending on the application) is required to provide
	 * enough current for the LED to turn ON and blink
	 * properly.
	 *
	 * This is also the reason why interfaces such as I²C
	 * commonly use Open-Drain outputs together with
	 * external pull-up resistors.
	 *-----------------------------------------------------*/

	GPIO_Handle_t GpioLed;

	GpioLed.pGPIOx = GPIOD;

	GpioLed.GPIO_PinConfig.GPIO_PinNumber      = GPIO_PIN_NO_12;
	GpioLed.GPIO_PinConfig.GPIO_PinMode        = GPIO_MODE_OUTPUT;
	GpioLed.GPIO_PinConfig.GPIO_PinSpeed       = GPIO_SPEED_FAST;
	GpioLed.GPIO_PinConfig.GPIO_PinOPType      = GPIO_OP_TYPE_OD;
	GpioLed.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_PIN_PU;

	GPIO_PeriClockControl(GPIOD, ENABLE);
	GPIO_Init(&GpioLed);

	while(1)
	{
		GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_12);
		delay();
	}

#endif

	return 0;
}

#endif

