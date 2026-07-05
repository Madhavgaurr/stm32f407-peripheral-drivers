/*
 * stm32f407xx_gpio_driver.c
 *
 *  Created on: May 16, 2026
 *      Author: madhav-gaur
 */

#include "stm32f407xx_spi_driver.h"
#include "stm32f407xx.h"
#include <stdbool.h>

/*
 *  Peripheral Clock Setup
 */

/*******************************************************************************
 * @fn                         -  SPI_PeriClockControl
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


void SPI_PeriClockControl(SPI_RegDef_t *pSPIx , uint8_t EnorDi)
{
    if(EnorDi == ENABLE )
   {
	       if(pSPIx == SPI1)
	       {
		       SPI1_PCLK_EN() ; 
	       }else if(pSPIx == SPI2)
	       {
		       SPI2_PCLK_EN() ;
	       }else if(pSPIx == SPI3)
	       {
		       SPI3_PCLK_EN() ;
	       }else if(pSPIx == SPI4)
	       {
		       SPI4_PCLK_EN() ;
	       }else if(pSPIx == SPI5)
	       {
		       SPI5_PCLK_EN() ;
	       }else if(pSPIx == SPI6)
	       {
		       SPI6_PCLK_EN() ;
	       }
   }
   else
   {
      if(pSPIx == SPI1)
	       {
		       SPI1_PCLK_DI() ; 
	       }else if(pSPIx == SPI2)
	       {
		       SPI2_PCLK_DI() ;
	       }else if(pSPIx == SPI3)
	       {
		       SPI3_PCLK_DI() ;
	       }else if(pSPIx == SPI4)
	       {
		       SPI4_PCLK_DI() ;
	       }else if(pSPIx == SPI5)
	       {
		       SPI5_PCLK_DI() ;
	       }else if(pSPIx == SPI6)
	       {
		       SPI6_PCLK_DI() ;
	       }
   }
} 

/*
 *  SPI Init Setup
 */

/*******************************************************************************
 * @fn                         -  SPI_Init
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
 * Status Registers are house for status flag , they flag different events by either providing 0
 * or 1 over the repected bit 
 * Error Event
 * Bus Idle Event
 * Etc 
 ********************************************************************************/

void SPI_Init(SPI_Handle_t *pSPIHandle)
{   

	SPI_PeriClockControl(pSPIHandle->pSpix,ENABLE) ;
	// Configuring the SPI_CR1 Register

	// 1 . Configuring the Mode of the Device 

	uint32_t tempreg  = 0 ;
	
	tempreg |=   pSPIHandle->SPIConfig.SPI_DeviceMode << 2 ;

	// 2 . Configuring the Bus Config

	if(pSPIHandle->SPIConfig.SPI_BusConfig==SPI_BUS_CONFIG_FULL_DUPLEX)
	{
		// BIDI mode should be cleared
		tempreg     &= ~(1<<15) ;
	}else if(pSPIHandle->SPIConfig.SPI_BusConfig==SPI_BUS_CONFIG_HALF_DUPLEX)
	{
		// BIDI mode should be set
		tempreg     |=  (1<<15) ;
	}else if(pSPIHandle->SPIConfig.SPI_BusConfig==SPI_BUS_CONFIG_SIMPLEX_RX_ONLY)
	{
		// BIDI mode should be cleared
		tempreg     &= ~(1<<15) ;

		// RX_ONLY bit must be set

		tempreg     |=  (1<<10) ;
	}


	// 3 . Configuring the SPI serial clock (baud rate) .

	pSPIHandle->pSpix->CR1     &= ~(7<<SPI_CR1_BR) ;

	tempreg         |=   pSPIHandle->SPIConfig.SPI_SclkSpeed <<  SPI_CR1_BR   ;

	// 4 . Configuring the DFF (Data frame format) .

	tempreg         |=   pSPIHandle->SPIConfig.SPI_DFF       <<  SPI_CR1_DFF  ;

	// 5 . Configuring the CPOL (Clock Polarity)

	tempreg         |=   pSPIHandle->SPIConfig.SPI_CPOL      <<  SPI_CR1_CPOL ;

	// 6 . Configuring the CPHA (Clock Phase)

	tempreg         |=   pSPIHandle->SPIConfig.SPI_CPHA      <<  SPI_CR1_CPHA ;


	// 7 . Configuring the SSM (Software Slave Management)

	tempreg         |=   pSPIHandle->SPIConfig.SPI_SSM       <<  SPI_CR1_SSM  ;




	pSPIHandle->pSpix->CR1    |= tempreg    ;

}


/*
 *  SPI DeInit Setup
 */

/*******************************************************************************
 * @fn                         -  SPI_DeInit
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
 * Status Registers are house for status flag , they flag different events by either providing 0
 * or 1 over the repected bit 
 * Error Event
 * Bus Idle Event
 * Etc 
 ********************************************************************************/


void SPI_DeInit(SPI_RegDef_t  *pSPIx)
{
}



/*
 *  SPI SendData Setup
 */

/*******************************************************************************
 * @fn                         -  SPI_SendData
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
 * SPI_SendData()
 *
 * Blocking SPI transmit API.
 * The function returns only after all bytes have been loaded into the Tx buffer.
 *
 * Parameters:
 *  pTxBuffer : Pointer to transmit data.
 *  Len       : Number of bytes to transmit.
 *
 * Flow:
 *  1. Repeat until Len becomes 0.
 *  2. Wait until TXE (Tx buffer empty) flag is set.
 *  3. Write data to the SPI_DR register.
 *     - DFF = 0 : Transmit 8 bits (1 byte).
 *     - DFF = 1 : Transmit 16 bits (2 bytes).
 *  4. Update buffer pointer and remaining length.
 *
 * Note:
 *  Writing to SPI_DR loads the Tx buffer.
 *  Reading SPI_DR returns data from the Rx buffer.
 ********************************************************************************/


uint8_t   SPI_GetFlagStatus(SPI_RegDef_t *pSPIx , uint32_t FlagName)
{           
	        if(pSPIx->SR  & FlagName)
			{
				return FLAG_SET ;
			}
            return FLAG_RESET ;
}

void SPI_SendData(SPI_RegDef_t  *pSPIx    , uint8_t *pTxBuffer , uint32_t Len)
{
	while(Len!=0)
	{   
		// 1 . Wait until TXE flag is set    , need watchdogs in case of failure 
		//while(!(pSPIx->SR  & (1 << SPI_SR_TXE))) ;

		while(SPI_GetFlagStatus(pSPIx,SPI_TXE_FLAG) == FLAG_RESET );

		// 2 . 

		if(pSPIx->CR1 & (1<<SPI_CR1_DFF))
		{
            // 16 bit DFF
			pSPIx->DR   = *((uint16_t*)pTxBuffer) ;
			Len -=    2                           ;
			(uint16_t*)pTxBuffer++                ;
		}else{
			// 8  bit DFF 

			pSPIx->DR   = *(pTxBuffer) ;
			Len -=    1                ;
			pTxBuffer++                ;
		}
	}
}

/*
 *  SPI ReceiveData Setup
 */

/*******************************************************************************
 * @fn                         -  SPI_SendData
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
 * SPI_SendData()
 *
 * Blocking SPI transmit API.
 * The function returns only after all bytes have been loaded into the Tx buffer.
 *
 * Parameters:
 *  pTxBuffer : Pointer to transmit data.
 *  Len       : Number of bytes to transmit.
 *
 * Flow:
 *  1. Repeat until Len becomes 0.
 *  2. Wait until TXE (Tx buffer empty) flag is set.
 *  3. Write data to the SPI_DR register.
 *     - DFF = 0 : Transmit 8 bits (1 byte).
 *     - DFF = 1 : Transmit 16 bits (2 bytes).
 *  4. Update buffer pointer and remaining length.
 *
 * Note:
 *  Writing to SPI_DR loads the Tx buffer.
 *  Reading SPI_DR returns data from the Rx buffer.
 ********************************************************************************/

void SPI_ReceiveData(SPI_RegDef_t  *pSPIx    , uint8_t *pRxBuffer , uint32_t Len)
{
	while(Len!=0)
	{   
		// 1 . Wait until RXNE flag is set    , need watchdogs in case of failure 
		//while(!(pSPIx->SR  & (1 << SPI_SR_TXE))) ;

		while(SPI_GetFlagStatus(pSPIx,SPI_RXNE_FLAG) == FLAG_RESET );

		// 2 . 

		if(pSPIx->CR1 & (1<<SPI_CR1_DFF))
		{
            // 16 bit DFF
			*((uint16_t*)pRxBuffer) = pSPIx->DR ;
			Len -=    2                           ;
			(uint16_t*)pRxBuffer++                ;
		}else{
			// 8  bit DFF 

			*(pRxBuffer) = pSPIx->DR  ;
			Len -=    1                ;
			pRxBuffer++                ;
		}
	}
}


void SPI_PeripheralControl(SPI_RegDef_t *pSPIx , uint8_t Enordi)
{   

	if(Enordi == ENABLE)
	{
		pSPIx->CR1   |=   (1<<SPI_CR1_SPE) ;
	}else{
		pSPIx->CR1   &=  ~(1<<SPI_CR1_SPE) ;
	}
     
}

void SPI_SSIConfig(SPI_RegDef_t  *pSPIx , uint8_t EnorDi  )
{
	if(EnorDi == ENABLE)
	{
		pSPIx->CR1   |=   (1<<SPI_CR1_SSI) ;
	}else{
		pSPIx->CR1   &=  ~(1<<SPI_CR1_SSI) ;
	}
}

/*
                                         SPI Interrupts 
*/

void SPI_IRQInterruptConfig(uint8_t IRQNumber ,  uint8_t EnorDi)
{
	if(EnorDi==ENABLE)
	{
        if(IRQNumber<=31)
		{

			// Program ISER0 Register

			NVIC_ISER0  |= ( 1 << IRQNumber ) ;

		}else if( IRQNumber>31  && IRQNumber<64 )
		{

			// Program ISER1 Register

			NVIC_ISER1  |= ( 1 << (IRQNumber%32) ) ;

		}else if( IRQNumber>=64 && IRQNumber<96 ){

			// Program ISER2 Register

            NVIC_ISER2  |= ( 1 << (IRQNumber%64) ) ;
		}
	}else{
        if(IRQNumber<=31)
		{

        	// Program ICER0 Register

			NVIC_ICER0  |= ( 1 << IRQNumber ) ;

		}else if( IRQNumber>31  && IRQNumber<64 )
		{

			// Program ICER1 Register

			NVIC_ICER1  |= ( 1 << ( IRQNumber % 32 ) ) ;

		}else if( IRQNumber>=64 && IRQNumber<96 ){

			// Program ICER2 Register

			NVIC_ICER2  |= ( 1 << ( IRQNumber % 64 ) ) ;

		}
	}
}

void SPI_IRQPriorityConfig(uint8_t IRQNumber , uint8_t IRQPriority)
{
	// 1 . Find out the ipr register 

	uint8_t iprx         = IRQNumber/4     ;
	uint8_t iprx_section = IRQNumber%4     ;

	uint8_t shift_amount =  (8*iprx_section) + (8-NO_PR_BITS_IMPLEMENTED) ;

	*(NVIC_IPR_BASE_ADDR + (iprx))  |=  (IRQPriority << shift_amount)   ;
}

/*
                             # SPI Interrupt-Based Transmission Flow
							           Non-blocking API 


1. Save the **transmit buffer address** and **transmit buffer length** in global (or driver handle)
 variables so that the Interrupt Service Routine (ISR) can access them during transmission.

2. Mark the SPI peripheral state as **Busy in Transmission (SPI_BUSY_IN_TX)**. This prevents any 
other code from taking control of the same SPI peripheral until the current transmission is 
complete.

3. Enable the **TXEIE (Transmit Buffer Empty Interrupt Enable)** bit in the SPI Control Register 
(CR2). Once enabled, whenever the **TXE** flag is set in the SPI Status Register (SR), the SPI 
peripheral generates an interrupt request.

4. The actual data transmission is performed inside the **SPI Interrupt Service Routine (ISR)**. 
Each time the TXE interrupt occurs, the ISR loads the next data into the SPI Data Register (DR).
 This process continues until all data has been transmitted, after which the ISR disables the TXE
  interrupt and marks the SPI peripheral as ready.

*/


uint8_t SPI_SendDataIT(SPI_Handle_t  *pSPIHandle    , uint8_t *pTxBuffer , uint32_t Len )
{   
	uint8_t state = pSPIHandle->TxState ;

	if(state!=SPI_BUSY_IN_TX)
	{
		// 1.

	pSPIHandle->pTxBuffer  = pTxBuffer      ;
	pSPIHandle->TxLen      = Len            ;

	// 2.

	pSPIHandle->TxState    = SPI_BUSY_IN_TX ;

	// 3.

	pSPIHandle->pSpix->CR2  |=  ( 1 << SPI_CR2_TXEIE ) ;
	}

	return state ;
	
}

uint8_t SPI_ReceiveDataIT(SPI_Handle_t  *pSPIHandle , uint8_t *pRxBuffer , uint32_t Len )
{
	uint8_t state = pSPIHandle->RxState ;

	if(state!=SPI_BUSY_IN_RX)
	{
	
	// 1.

	pSPIHandle->pRxBuffer  = pRxBuffer      ;
	pSPIHandle->RxLen      = Len            ;

	// 2.

	pSPIHandle->RxState    = SPI_BUSY_IN_RX ;

	// 3.

	pSPIHandle->pSpix->CR2  |=  ( 1 << SPI_CR2_RXNEIE ) ;
	}

	return state ;
}



void SPI_IRQHandling(SPI_Handle_t  *pHandle)
{
	
}
