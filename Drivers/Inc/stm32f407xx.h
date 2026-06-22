/*
 * stm32f407xx.h
 *
 *  Created on: May 15, 2026
 *      Author: madhav-gaur
 */


 
#ifndef INC_STM32F407XX_H_
#define INC_STM32F407XX_H_

#define __vo volatile
#include <stdint.h>
#include <stdio.h>

/************************************************************************************************
 ***************************************ARM Cortex Processor Specific Details*********************
 *************************************************************************************************/

 #define NVIC_ISER0                  (*( __vo uint32_t*)0xE000E100)
 #define NVIC_ISER1                  (*( __vo uint32_t*)0xE000E104)
 #define NVIC_ISER2                  (*( __vo uint32_t*)0xE000E108)
 #define NVIC_ISER3                  (*( __vo uint32_t*)0xE000E10C)



 #define NVIC_ICER0                  (*( __vo uint32_t*)0xE000E180)
 #define NVIC_ICER1                  (*( __vo uint32_t*)0xE000E184)
 #define NVIC_ICER2                  (*( __vo uint32_t*)0xE000E188)
 #define NVIC_ICER3                  (*( __vo uint32_t*)0xE000E18C)





 #define NVIC_IPR_BASE_ADDR          (( __vo uint32_t*)0xE000E400)

 #define NO_PR_BITS_IMPLEMENTED      4 




 /********************************************************************************************** */


#define FLASH_BASE_ADDR                  0x08000000UL
#define SRAM1_BASE_ADDR                  0x20000000UL
#define SRAM2_BASE_ADDR                  0x2001C000UL
#define ROM_BASE_ADDR                    0x1FFF0000UL
#define SRAM                             SRAM1_BASE_ADDR


#define PERIPH_BASE_ADDR                 0x40000000UL
#define APB1PERIPH_BASE_ADDR             0x40000000UL
#define APB2PERIPH_BASE_ADDR             0x40010000UL
#define AHB1PERIPH_BASE_ADDR             0x40020000UL
#define AHB2PERIPH_BASE_ADDR             0x50000000UL


/*Base Address of peripherals which are hanging on AHB1 bus */

#define GPIOA_BASE_ADDR                  (AHB1PERIPH_BASE_ADDR + 0x0000)
#define GPIOB_BASE_ADDR                  (AHB1PERIPH_BASE_ADDR + 0x0400)
#define GPIOC_BASE_ADDR                  (AHB1PERIPH_BASE_ADDR + 0x0800)
#define GPIOD_BASE_ADDR                  (AHB1PERIPH_BASE_ADDR + 0x0C00)
#define GPIOE_BASE_ADDR                  (AHB1PERIPH_BASE_ADDR + 0x1000)
#define GPIOF_BASE_ADDR                  (AHB1PERIPH_BASE_ADDR + 0x1400)
#define GPIOG_BASE_ADDR                  (AHB1PERIPH_BASE_ADDR + 0x1800)
#define GPIOH_BASE_ADDR                  (AHB1PERIPH_BASE_ADDR + 0x1C00)
#define GPIOI_BASE_ADDR                  (AHB1PERIPH_BASE_ADDR + 0x2000)
#define GPIOJ_BASE_ADDR                  (AHB1PERIPH_BASE_ADDR + 0x2400)
#define GPIOK_BASE_ADDR                  (AHB1PERIPH_BASE_ADDR + 0x2800)
#define CRC_BASE_ADDR                    (AHB1PERIPH_BASE_ADDR + 0x3000)
#define RCC_BASE_ADDR                    (AHB1PERIPH_BASE_ADDR + 0x3800)
#define FLASHINTERFACEREG_BASE_ADDR      (AHB1PERIPH_BASE_ADDR + 0x3C00)
#define BKPSRAM_BASE_ADDR                (AHB1PERIPH_BASE_ADDR + 0x4000)
#define DMA1_BASE_ADDR                   (AHB1PERIPH_BASE_ADDR + 0x6000)
#define DMA2_BASE_ADDR                   (AHB1PERIPH_BASE_ADDR + 0x6400)
#define ETHERNET_MAC_BASE_ADDR           (AHB1PERIPH_BASE_ADDR + 0x8000)
#define DMA2D_BASE_ADDR                  (AHB1PERIPH_BASE_ADDR + 0xB000)

/*Base Address of peripherals which are hanging on AHB2 bus */

#define USBOTGFS_BASE_ADDR               (AHB2PERIPH_BASE_ADDR + 0x0000)
#define DCMI_BASE_ADDR                   (AHB2PERIPH_BASE_ADDR + 0x50000)
#define CRYP_BASE_ADDR                   (AHB2PERIPH_BASE_ADDR + 0x60000)
#define HASH_BASE_ADDR                   (AHB2PERIPH_BASE_ADDR + 0x60400)
#define RNG_BASE_ADDR                    (AHB2PERIPH_BASE_ADDR + 0x60800)


/*Base Address of peripherals which are hanging on APB1 bus */

#define TIM2_BASE_ADDR                   (APB1PERIPH_BASE_ADDR + 0x0000)
#define TIM3_BASE_ADDR                   (APB1PERIPH_BASE_ADDR + 0x0400)
#define TIM4_BASE_ADDR                   (APB1PERIPH_BASE_ADDR + 0x0800)
#define TIM5_BASE_ADDR                   (APB1PERIPH_BASE_ADDR + 0x0C00)
#define TIM6_BASE_ADDR                   (APB1PERIPH_BASE_ADDR + 0x1000)
#define TIM7_BASE_ADDR                   (APB1PERIPH_BASE_ADDR + 0x1400)
#define TIM12_BASE_ADDR                  (APB1PERIPH_BASE_ADDR + 0x1800)
#define TIM13_BASE_ADDR                  (APB1PERIPH_BASE_ADDR + 0x1C00)
#define TIM14_BASE_ADDR                  (APB1PERIPH_BASE_ADDR + 0x2000)
#define RTC_BKP_REG_BASE_ADDR            (APB1PERIPH_BASE_ADDR + 0x2800)
#define WWDG_BASE_ADDR                   (APB1PERIPH_BASE_ADDR + 0x2C00)
#define IWDG_BASE_ADDR                   (APB1PERIPH_BASE_ADDR + 0x3000)
#define I2S2ext_BASE_ADDR                (APB1PERIPH_BASE_ADDR + 0x3400)
#define SPI2_BASE_ADDR                   (APB1PERIPH_BASE_ADDR + 0x3800)
#define SPI3_BASE_ADDR                   (APB1PERIPH_BASE_ADDR + 0x3C00)
#define I2S3ext_BASE_ADDR                (APB1PERIPH_BASE_ADDR + 0x4000)
#define USART2_BASE_ADDR                 (APB1PERIPH_BASE_ADDR + 0x4400)
#define USART3_BASE_ADDR                 (APB1PERIPH_BASE_ADDR + 0x4800)
#define UART4_BASE_ADDR                  (APB1PERIPH_BASE_ADDR + 0x4C00)
#define UART5_BASE_ADDR                  (APB1PERIPH_BASE_ADDR + 0x5000)
#define I2C1_BASE_ADDR                   (APB1PERIPH_BASE_ADDR + 0x5400)
#define I2C2_BASE_ADDR                   (APB1PERIPH_BASE_ADDR + 0x5800)
#define I2C3_BASE_ADDR                   (APB1PERIPH_BASE_ADDR + 0x5C00)
#define CAN1_BASE_ADDR                   (APB1PERIPH_BASE_ADDR + 0x6400)
#define CAN2_BASE_ADDR                   (APB1PERIPH_BASE_ADDR + 0x6800)
#define PWR_BASE_ADDR                    (APB1PERIPH_BASE_ADDR + 0x7000)
#define DAC_BASE_ADDR                    (APB1PERIPH_BASE_ADDR + 0x7400)
#define UART7_BASE_ADDR                  (APB1PERIPH_BASE_ADDR + 0x7800)
#define UART8_BASE_ADDR                  (APB1PERIPH_BASE_ADDR + 0x7C00)

/*Base Address of peripherals which are hanging on APB2 bus */

#define TIM1_BASE_ADDR                   (APB2PERIPH_BASE_ADDR + 0x0000)
#define TIM8_BASE_ADDR                   (APB2PERIPH_BASE_ADDR + 0x10400)
#define USART1_BASE_ADDR                 (APB2PERIPH_BASE_ADDR + 0x11000)
#define USART6_BASE_ADDR                 (APB2PERIPH_BASE_ADDR + 0x11400)
#define ADC1_ADC2_ADC2_BASE_ADDR         (APB2PERIPH_BASE_ADDR + 0x12000)
#define SDIO_BASE_ADDR                   (APB2PERIPH_BASE_ADDR + 0x12C00)
#define SPI1_BASE_ADDR                   (APB2PERIPH_BASE_ADDR + 0x13000)
#define SPI4_BASE_ADDR                   (APB2PERIPH_BASE_ADDR + 0x13400)
#define SYSCFG_BASE_ADDR                 (APB2PERIPH_BASE_ADDR + 0x13800)
#define EXTI_BASE_ADDR                   (APB2PERIPH_BASE_ADDR + 0x13C00)
#define TIM9_BASE_ADDR                   (APB2PERIPH_BASE_ADDR + 0x14000)
#define TIM10_BASE_ADDR                  (APB2PERIPH_BASE_ADDR + 0x14400)
#define TIM11_BASE_ADDR                  (APB2PERIPH_BASE_ADDR + 0x14800)
#define SPI5_BASE_ADDR                   (APB2PERIPH_BASE_ADDR + 0x15000)
#define SPI6_BASE_ADDR                   (APB2PERIPH_BASE_ADDR + 0x15400)
#define SAI1_BASE_ADDR                   (APB2PERIPH_BASE_ADDR + 0x15800)
#define LCD_TFT_BASE_ADDR                (APB2PERIPH_BASE_ADDR + 0x16800)





/**/


typedef struct{

	__vo uint32_t  MODER    ;
	__vo uint32_t  OTYPER   ;
	__vo uint32_t  OSPEEDR  ;
	__vo uint32_t  PUPDR    ;
	__vo uint32_t  IDR      ;
	__vo uint32_t  ODR      ;
	__vo uint32_t  BSRR     ;
	__vo uint32_t  LCKR     ;
	__vo uint32_t  AFR[2]   ;

}GPIO_RegDef_t;

typedef struct{

	__vo uint32_t  CR         ;
	__vo uint32_t  PLLCFGR    ;
	__vo uint32_t  CFGR       ;
	__vo uint32_t  CIR        ;
	__vo uint32_t  AHB1RSTR   ;
	__vo uint32_t  AHB2RSTR   ;
	__vo uint32_t  AHB3RSTR   ;
	     uint32_t  RESERVED0      ;
	__vo uint32_t  APB1RSTR   ;
	__vo uint32_t  APB2RSTR   ;
         uint32_t  RESERVED1[2]   ;
	__vo uint32_t  AHB1ENR    ;
	__vo uint32_t  AHB2ENR    ;
	__vo uint32_t  AHB3ENR    ;
         uint32_t  RESERVED2      ;
	__vo uint32_t  APB1ENR    ;
	__vo uint32_t  APB2ENR    ;
	     uint32_t  RESERVED3[2]   ;
	__vo uint32_t  AHB1LPENR  ;
	__vo uint32_t  AHB2LPENR  ;
	__vo uint32_t  AHB3LPENR  ;
         uint32_t  RESERVED4      ;
	__vo uint32_t  APB1LPENR  ;
	__vo uint32_t  APB2LPENR  ;
         uint32_t  RESERVED5[2]   ;
	__vo uint32_t  BDCR       ;
	__vo uint32_t  CSR        ;
         uint32_t  RESERVED6[2]   ;
	__vo uint32_t  SSCGR      ;
	__vo uint32_t  PLLI2SCFGR ;
	__vo uint32_t  PLLSAICFGR ;
	__vo uint32_t  DCKCFGR    ;
	__vo uint32_t  CKGATENR   ;
	__vo uint32_t  DCKCFGR2   ;

}RCC_RegDef_t;


typedef struct{

	__vo uint32_t  IMR        ;
	__vo uint32_t  EMR        ;
    __vo uint32_t  RTSR       ;
	__vo uint32_t  FTSR       ;
	__vo uint32_t  SWIER      ;
	__vo uint32_t  PR         ;
}EXTI_RegDef_t ;


typedef struct{
	__vo uint32_t  MEMRMP        ;
	__vo uint32_t  PMC           ;
	__vo uint32_t  EXTICR[4]     ;
	__vo uint32_t  CMPCR         ;
}SYSCFG_RegDef_t ;





/* Peripheral Definition */

#define GPIOA    ((GPIO_RegDef_t*)(GPIOA_BASE_ADDR))
#define GPIOB    ((GPIO_RegDef_t*)(GPIOB_BASE_ADDR))
#define GPIOC    ((GPIO_RegDef_t*)(GPIOC_BASE_ADDR))
#define GPIOD    ((GPIO_RegDef_t*)(GPIOD_BASE_ADDR))
#define GPIOE    ((GPIO_RegDef_t*)(GPIOE_BASE_ADDR))
#define GPIOF    ((GPIO_RegDef_t*)(GPIOF_BASE_ADDR))
#define GPIOG    ((GPIO_RegDef_t*)(GPIOG_BASE_ADDR))
#define GPIOH    ((GPIO_RegDef_t*)(GPIOH_BASE_ADDR))
#define GPIOI    ((GPIO_RegDef_t*)(GPIOI_BASE_ADDR))
#define GPIOJ    ((GPIO_RegDef_t*)(GPIOJ_BASE_ADDR))
#define GPIOK    ((GPIO_RegDef_t*)(GPIOK_BASE_ADDR))

#define RCC      ((RCC_RegDef_t* )(RCC_BASE_ADDR     ))
#define EXTI     ((EXTI_RegDef_t*)(EXTI_BASE_ADDR    ))
#define SYSCFG   ((SYSCFG_RegDef_t*)(SYSCFG_BASE_ADDR))



/*
 * Clock Enable Macros for GPIOx peripheral
 */

#define GPIOA_PCLK_EN()      ( RCC->AHB1ENR |=  (1<<0) )
#define GPIOB_PCLK_EN()      ( RCC->AHB1ENR |=  (1<<1) )
#define GPIOC_PCLK_EN()      ( RCC->AHB1ENR |=  (1<<2) )
#define GPIOD_PCLK_EN()      ( RCC->AHB1ENR |=  (1<<3) )
#define GPIOE_PCLK_EN()      ( RCC->AHB1ENR |=  (1<<4) )
#define GPIOF_PCLK_EN()      ( RCC->AHB1ENR |=  (1<<5) )
#define GPIOG_PCLK_EN()      ( RCC->AHB1ENR |=  (1<<6) )
#define GPIOH_PCLK_EN()      ( RCC->AHB1ENR |=  (1<<7) )
#define GPIOI_PCLK_EN()      ( RCC->AHB1ENR |=  (1<<8) )
#define GPIOJ_PCLK_EN()      ( RCC->AHB1ENR |=  (1<<9) )
#define GPIOK_PCLK_EN()      ( RCC->AHB1ENR |=  (1<<10))

/*
 * Clock Disable Macros for GPIOx peripheral
 */

#define GPIOA_PCLK_DI()      ( RCC->AHB1ENR &=  ~(1<<0) )
#define GPIOB_PCLK_DI()      ( RCC->AHB1ENR &=  ~(1<<1) )
#define GPIOC_PCLK_DI()      ( RCC->AHB1ENR &=  ~(1<<2) )
#define GPIOD_PCLK_DI()      ( RCC->AHB1ENR &=  ~(1<<3) )
#define GPIOE_PCLK_DI()      ( RCC->AHB1ENR &=  ~(1<<4) )
#define GPIOF_PCLK_DI()      ( RCC->AHB1ENR &=  ~(1<<5) )
#define GPIOG_PCLK_DI()      ( RCC->AHB1ENR &=  ~(1<<6) )
#define GPIOH_PCLK_DI()      ( RCC->AHB1ENR &=  ~(1<<7) )
#define GPIOI_PCLK_DI()      ( RCC->AHB1ENR &=  ~(1<<8) )
#define GPIOJ_PCLK_DI()      ( RCC->AHB1ENR &=  ~(1<<9) )
#define GPIOK_PCLK_DI()      ( RCC->AHB1ENR &=  ~(1<<10))



/*
 * Clock Enable Macros for I2Cx   peripheral
 */

#define I2C1_PCLK_EN()      ( RCC->APB1ENR |=  (1<<21) )
#define I2C2_PCLK_EN()      ( RCC->APB1ENR |=  (1<<22) )
#define I2C3_PCLK_EN()      ( RCC->APB1ENR |=  (1<<23) )

/*
 * Clock Enable Macros for SPIx   peripheral
 */

#define SPI1_PCLK_EN()      ( RCC->APB2ENR |=  (1<<12) )
#define SPI2_PCLK_EN()      ( RCC->APB1ENR |=  (1<<14) )
#define SPI3_PCLK_EN()      ( RCC->APB1ENR |=  (1<<15) )
#define SPI4_PCLK_EN()      ( RCC->APB2ENR |=  (1<<13) )
#define SPI5_PCLK_EN()      ( RCC->APB2ENR |=  (1<<20) )
#define SPI6_PCLK_EN()      ( RCC->APB2ENR |=  (1<<21) )

/*
 * Clock Enable Macros for USARTx peripheral
 */

/*
 * Clock Enable Macros for SYSCFG peripheral
 */

#define SYSCFG_PCLK_EN()    ( RCC->APB2ENR |=  (1<<14) )


/*
 *
 *  Macros to reset GPIOx peripheral
 *
 */

// do while condition zero loop : This is a technique in 'C' programming to execute multiple 'C' statements using single 'C' macro

#define    GPIOA_REG_RESET()    do{ RCC->AHB1RSTR |= (1<<0)  ; RCC->AHB1RSTR &= ~(1<<0)  ;  }while(0)
#define    GPIOB_REG_RESET()    do{ RCC->AHB1RSTR |= (1<<1)  ; RCC->AHB1RSTR &= ~(1<<1)  ;  }while(0)
#define    GPIOC_REG_RESET()    do{ RCC->AHB1RSTR |= (1<<2)  ; RCC->AHB1RSTR &= ~(1<<2)  ;  }while(0)
#define    GPIOD_REG_RESET()    do{ RCC->AHB1RSTR |= (1<<3)  ; RCC->AHB1RSTR &= ~(1<<3)  ;  }while(0)
#define    GPIOE_REG_RESET()    do{ RCC->AHB1RSTR |= (1<<4)  ; RCC->AHB1RSTR &= ~(1<<4)  ;  }while(0)
#define    GPIOF_REG_RESET()    do{ RCC->AHB1RSTR |= (1<<5)  ; RCC->AHB1RSTR &= ~(1<<5)  ;  }while(0)
#define    GPIOG_REG_RESET()    do{ RCC->AHB1RSTR |= (1<<6)  ; RCC->AHB1RSTR &= ~(1<<6)  ;  }while(0)
#define    GPIOH_REG_RESET()    do{ RCC->AHB1RSTR |= (1<<7)  ; RCC->AHB1RSTR &= ~(1<<7)  ;  }while(0)
#define    GPIOI_REG_RESET()    do{ RCC->AHB1RSTR |= (1<<8)  ; RCC->AHB1RSTR &= ~(1<<8)  ;  }while(0)
#define    GPIOJ_REG_RESET()    do{ RCC->AHB1RSTR |= (1<<9)  ; RCC->AHB1RSTR &= ~(1<<9)  ;  }while(0)
#define    GPIOK_REG_RESET()    do{ RCC->AHB1RSTR |= (1<<10) ; RCC->AHB1RSTR &= ~(1<<10) ;  }while(0)



/******************************************* Some Generic Macros ************************************************/

#define ENABLE  1
#define DISABLE 0

#define SET     ENABLE
#define RESET   DISABLE

#define GPIO_PIN_SET    SET
#define GPIO_PIN_RESET  RESET

// Implementation of  GPIO_BASEADDR_TO_CODE

#define GPIO_BASEADDR_TO_CODE(x)     ( (x==GPIOA) ? 0 :\
                                       (x==GPIOB) ? 1 :\
									   (x==GPIOC) ? 2 :\
									   (x==GPIOD) ? 3 :\
									   (x==GPIOE) ? 4 :\
									   (x==GPIOF) ? 5 :\
									   (x==GPIOG) ? 6 :\
									   (x==GPIOH) ? 7 :0)
                                

//


//  In STM32, an Interrupt Request Number (IRQ Number) is the number used by the NVIC 
// (Nested Vector Interrupt Controller) to identify a particular interrupt source.

// Think of it like this:

// Peripheral/Event
//       ↓
// Generates Interrupt
//       ↓
// Assigned IRQ Number
//       ↓
// NVIC uses IRQ Number
//       ↓
// Corresponding ISR executes

// For EXTI, the mapping is not always 1-to-1.

// EXTI Line → IRQ Number Mapping (STM32F4)
// EXTI Line	IRQ Name	IRQ Number
// EXTI0	EXTI0_IRQn	6
// EXTI1	EXTI1_IRQn	7
// EXTI2	EXTI2_IRQn	8
// EXTI3	EXTI3_IRQn	9
// EXTI4	EXTI4_IRQn	10
// EXTI5-9	EXTI9_5_IRQn	23
// EXTI10-15	EXTI15_10_IRQn	40

#define IRQ_NO_EXTI0         6
#define IRQ_NO_EXTI1         7
#define IRQ_NO_EXTI2         8
#define IRQ_NO_EXTI3         9
#define IRQ_NO_EXTI4         10
#define IRQ_NO_EXTI9_5       23
#define IRQ_NO_EXTI15_10     40



// Priority Levels
#define NVIC_IRQ_PRIO0       0
#define NVIC_IRQ_PRIO1       1
#define NVIC_IRQ_PRIO2       2
#define NVIC_IRQ_PRIO3       3
#define NVIC_IRQ_PRIO4       4
#define NVIC_IRQ_PRIO5       5
#define NVIC_IRQ_PRIO6       6
#define NVIC_IRQ_PRIO7       7
#define NVIC_IRQ_PRIO8       8
#define NVIC_IRQ_PRIO9       9
#define NVIC_IRQ_PRIO10      10
#define NVIC_IRQ_PRIO11      11
#define NVIC_IRQ_PRIO12      12
#define NVIC_IRQ_PRIO13      13
#define NVIC_IRQ_PRIO14      14
#define NVIC_IRQ_PRIO15      15


#include "stm32f407xx_gpio_driver.h"

#endif /* INC_STM32F407XX_H_ */
