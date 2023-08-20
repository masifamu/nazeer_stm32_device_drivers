/*
 * stm32f0xx.h
 *
 *  Created on: Aug 19, 2023
 *      Author: masifamu
 */

#ifndef INC_STM32F0XX_H_
#define INC_STM32F0XX_H_

#include <stdint.h>

// some generic helper macros
#define TRUE		1
#define FALSE		0
#define ENABLE		1
#define DISABLE		0
#define SET			1
#define RESET		0
#define HIGH		1
#define LOW			0

// memory addresses
#define NAZEER_FLASH_BASEADDR				0x08000000U
#define NAZEER_SRAM_BASEADDR				0x20000000U
#define NAZEER_ROM_BASEADDR					0x1FFFEC00U			//also called as system memory


// AHB and APB peripheral base addresses
#define NAZEER_PERIPH_BASEADDR				0x40000000U
#define NAZEER_APB1_PERIPH_BASEADDR			NAZEER_PERIPH_BASEADDR
#define NAZEER_APB2_PERIPH_BASEADDR			0x40010000U
#define NAZEER_AHB1_PERIPH_BASEADDR			0x40020000U
#define NAZEER_AHB2_PERIPH_BASEADDR			0x48000000U

/**
 * APB1 peripheral
 */
#define NAZEER_TIM2_PERIPH_BASEADDR			(NAZEER_APB1_PERIPH_BASEADDR + 0x000U)
#define NAZEER_TIM3_PERIPH_BASEADDR			(NAZEER_APB1_PERIPH_BASEADDR + 0x400U)
//for more peripherals on this bus: go to RM0091 pg-50

/**
 * APB2 peripheral
 */
#define NAZEER_EXTI_PERIPH_BASEADDR			(NAZEER_APB2_PERIPH_BASEADDR + 0x400U)
//got to RM0091 pg-49

/**
 * AHB1 peripheral
 */
#define NAZEER_RCC_PERIPH_BASEADDR			(NAZEER_AHB1_PERIPH_BASEADDR + 0x1000U)

/**
 * AHB2 peripheral
 */
#define NAZEER_GPIOA_PERIPH_BASEADDR			(NAZEER_AHB2_PERIPH_BASEADDR + 0x0000U)
#define NAZEER_GPIOB_PERIPH_BASEADDR			(NAZEER_AHB2_PERIPH_BASEADDR + 0x0400U)
#define NAZEER_GPIOC_PERIPH_BASEADDR			(NAZEER_AHB2_PERIPH_BASEADDR + 0x0800U)
#define NAZEER_GPIOD_PERIPH_BASEADDR			(NAZEER_AHB2_PERIPH_BASEADDR + 0x0C00U)
#define NAZEER_GPIOE_PERIPH_BASEADDR			(NAZEER_AHB2_PERIPH_BASEADDR + 0x1000U)
#define NAZEER_GPIOF_PERIPH_BASEADDR			(NAZEER_AHB2_PERIPH_BASEADDR + 0x1400U)

//defining data structure for GPIO
typedef struct{
	volatile uint32_t MODER; 			//0x00 offset
	volatile uint32_t OTYPER;			//0x04 offset
	volatile uint32_t OSPEEDR;			//0x08 offset
	volatile uint32_t PUPDR;			//0x0C offset
	volatile uint32_t IDR;				//0x10 offset
	volatile uint32_t ODR;				//0x14 offset
	volatile uint32_t BSRR;				//0x18 offset
	volatile uint32_t LCKR;				//0x1C offset
	volatile uint32_t AFRL;				//0x20 offset
	volatile uint32_t AFRH;				//0x24 offset
	volatile uint32_t BRR;				//0x28 offset
}NAZEER_GPIO_RegDef_t;

#define NAZEER_GPIOA		((NAZEER_GPIO_RegDef_t *)NAZEER_GPIOA_PERIPH_BASEADDR)
#define NAZEER_GPIOB		((NAZEER_GPIO_RegDef_t *)NAZEER_GPIOB_PERIPH_BASEADDR)
#define NAZEER_GPIOC		((NAZEER_GPIO_RegDef_t *)NAZEER_GPIOC_PERIPH_BASEADDR)
#define NAZEER_GPIOD		((NAZEER_GPIO_RegDef_t *)NAZEER_GPIOD_PERIPH_BASEADDR)
#define NAZEER_GPIOE		((NAZEER_GPIO_RegDef_t *)NAZEER_GPIOE_PERIPH_BASEADDR)
#define NAZEER_GPIOF		((NAZEER_GPIO_RegDef_t *)NAZEER_GPIOF_PERIPH_BASEADDR)


// defining data structure to handle the RCC clocks and all.
typedef struct{
	volatile uint32_t CR;				//0X00
	volatile uint32_t CFGR;				//0x04
	volatile uint32_t CIR;				//0x08
	volatile uint32_t APB2RSTR;			//0x0C
	volatile uint32_t APB1RSTR;			//0x10
	volatile uint32_t AHBENR;			//0x14
	volatile uint32_t APB2ENR;			//0x18
	volatile uint32_t APB1ENR;			//0x1C
	volatile uint32_t BDCR;				//0x20
	volatile uint32_t CSR;				//0x24
	volatile uint32_t AHBRSTR;			//0x28
	volatile uint32_t CFGR2;			//0x2C
	volatile uint32_t CFGR3;			//0x30
	volatile uint32_t CR2;				//0x34
}NAZEER_RCC_RegDef_t;

#define NAZEER_RCC 			((NAZEER_RCC_RegDef_t *)NAZEER_RCC_PERIPH_BASEADDR)

//peripheral clock enable and disable macros
#define NAZEER_GPIOA_PCLK_EN()			(NAZEER_RCC->AHBENR |= (1 << 17))
#define NAZEER_GPIOA_PCLK_DI()			(NAZEER_RCC->AHBENR &= ~(1 << 17))
#define NAZEER_GPIOB_PCLK_EN()			(NAZEER_RCC->AHBENR |= (1 << 18))
#define NAZEER_GPIOB_PCLK_DI()			(NAZEER_RCC->AHBENR &= ~(1 << 18))
#define NAZEER_GPIOC_PCLK_EN()			(NAZEER_RCC->AHBENR |= (1 << 19))
#define NAZEER_GPIOC_PCLK_DI()			(NAZEER_RCC->AHBENR &= ~(1 << 19))
#define NAZEER_GPIOD_PCLK_EN()			(NAZEER_RCC->AHBENR |= (1 << 20))
#define NAZEER_GPIOD_PCLK_DI()			(NAZEER_RCC->AHBENR &= ~(1 << 20))
#define NAZEER_GPIOE_PCLK_EN()			(NAZEER_RCC->AHBENR |= (1 << 21))
#define NAZEER_GPIOE_PCLK_DI()			(NAZEER_RCC->AHBENR &= ~(1 << 21))
#define NAZEER_GPIOF_PCLK_EN()			(NAZEER_RCC->AHBENR |= (1 << 22))
#define NAZEER_GPIOF_PCLK_DI()			(NAZEER_RCC->AHBENR &= ~(1 << 22))

//peripheral reset macros, use do while to include multiple lines in one macros.
//remember the bit in RCC AHBRSTR should be changed from low to high and then high to low
//else your peripheral will always be in reset mode.
#define NAZEER_GPIOA_RST()				do{ (NAZEER_RCC->AHBRSTR |= (1 << 17)); (NAZEER_RCC->AHBRSTR &= ~(1 << 17)); }while(0)
#define NAZEER_GPIOB_RST()				do{ (NAZEER_RCC->AHBRSTR |= (1 << 18)); (NAZEER_RCC->AHBRSTR &= ~(1 << 18)); }while(0)
#define NAZEER_GPIOC_RST()				do{ (NAZEER_RCC->AHBRSTR |= (1 << 19)); (NAZEER_RCC->AHBRSTR &= ~(1 << 19)); }while(0)
#define NAZEER_GPIOD_RST()				do{ (NAZEER_RCC->AHBRSTR |= (1 << 20)); (NAZEER_RCC->AHBRSTR &= ~(1 << 20)); }while(0)
#define NAZEER_GPIOE_RST()				do{ (NAZEER_RCC->AHBRSTR |= (1 << 21)); (NAZEER_RCC->AHBRSTR &= ~(1 << 21)); }while(0)
#define NAZEER_GPIOF_RST()				do{ (NAZEER_RCC->AHBRSTR |= (1 << 22)); (NAZEER_RCC->AHBRSTR &= ~(1 << 22)); }while(0)

#endif /* INC_STM32F0XX_H_ */
