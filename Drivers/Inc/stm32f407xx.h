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

#define RCC      ((RCC_RegDef_t* )(RCC_BASE_ADDR  ))



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


/*
 *
 *  Macros to reset GPIOx peripheral
 *
 */

// do while condition zero loop : This is a technique in 'C' programming to execute multiple c statements once

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

#endif /* INC_STM32F407XX_H_ */
