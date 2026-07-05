/*
 * 004SpiTxTesting.c
 *
 *  Created on: Jul 3, 2026
 *      Author: madhav-gaur
 */

#include "stm32f407xx.h"

/*
    PB14  ->   SPI2_MISO
	PB15  ->   SPI2_MOSI
	PB13  ->   SPI2_SCK 
	PB12  ->   SPI2_NSS

	ALTFNMODE 5
*/

void Spi2GpioInits()
{
       GPIO_Handle_t  SpiPins   ;

	   SpiPins.pGPIOx  = GPIOB  ;

	   SpiPins.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_ALTFN     ;

	   SpiPins.GPIO_PinConfig.GPIO_PinAltFunMode = 5             ;

	   SpiPins.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP   ;

	   SpiPins.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD ;

	   SpiPins.GPIO_PinConfig.GPIO_PinSpeed    = GPIO_SPEED_FAST ;

	   // Clock 

	   SpiPins.GPIO_PinConfig.GPIO_PinNumber  = GPIO_PIN_NO_13   ;
	   GPIO_Init(&SpiPins) ;

	   // Mosi

	   SpiPins.GPIO_PinConfig.GPIO_PinNumber  = GPIO_PIN_NO_15   ;
	   GPIO_Init(&SpiPins) ;

	   // Miso 

	   // SpiPins.GPIO_PinConfig.GPIO_PinNumber  = GPIO_PIN_NO_14   ;
	   //GPIO_Init(&SpiPins) ;

	   // Nss

	   // SpiPins.GPIO_PinConfig.GPIO_PinNumber  = GPIO_PIN_NO_12   ;
	   // GPIO_Init(&SpiPins) ;

}

void Spi2_Inits()
{
	  SPI_Handle_t  Spi2Handle ;

	  Spi2Handle.pSpix = SPI2 ;
      
      Spi2Handle.SPIConfig.SPI_BusConfig = SPI_BUS_CONFIG_FULL_DUPLEX ;

	  Spi2Handle.SPIConfig.SPI_BusConfig = SPI_DEVICE_MODE_MASTER     ;
      
	  Spi2Handle.SPIConfig.SPI_SclkSpeed = SPI_SCLK_SPEED_DIV2        ;

	  Spi2Handle.SPIConfig.SPI_DFF       = SPI_DFF8BITS               ;

	  Spi2Handle.SPIConfig.SPI_CPOL      = SPI_CPOL_HIGH               ;

	  Spi2Handle.SPIConfig.SPI_CPHA      = SPI_CPHA_LOW               ;

	  Spi2Handle.SPIConfig.SPI_SSM       = SPI_SSM_EN                 ;


	  SPI_Init(&Spi2Handle) ;

}

int main()
{   

	char UserBuffer[] = "Hello , World!" ;

	 Spi2GpioInits() ;

	 Spi2_Inits()    ;

	 SPI_Handle_t Brrerr ;

	 Brrerr.pSpix   = SPI2 ;

	 Brrerr.pSpix->CR1    &= ~(7<<3) ;

	 

     // Makes NSS INternally High and avoid errors


	 SPI_SSIConfig(SPI2,ENABLE) ;

	 

	 // Have to enable the spi peripheral useing spe bit in spi_cr1 register 



     
	 SPI_PeriClockControl(SPI2,ENABLE) ;

	 Brrerr.pSpix->CR1  |= (1<<SPI_CR1_SPE) ;

	 SPI_SendData(SPI2,(uint8_t*)UserBuffer,strlen(UserBuffer)) ;

	 // Have to enable the spi peripheral useing spe bit in spi_cr1 register 


	 SPI_PeriClockControl(SPI2,DISABLE) ;



	 while(1) ;


	 return 0 ;
}

/*
 Error SSI config 
*/


