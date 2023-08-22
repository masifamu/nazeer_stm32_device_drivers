/**
 ******************************************************************************
 * @file           : main.c
 * @author         : masifamu
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include <stdint.h>
#include <stdio.h>
#include "stm32f0xx.h"
#include "nazeer_stm32f0xx_gpio_driver.h"


extern void initialise_monitor_handles(void);

void delay(){
	for(uint32_t i = 0; i < 500000; i++);
}
int main(void)
{
	initialise_monitor_handles();
	printf("Hello Asif, This is semihosting test\n");
	NAZEER_GPIO_Handle_t gpioLEDHandle;
	gpioLEDHandle.pGPIOx = 							NAZEER_GPIOC;
	gpioLEDHandle.GPIO_PinConfig.pinNumber = 		9;
	gpioLEDHandle.GPIO_PinConfig.pinMode = 			NAZEER_GPIO_MODE_OUT;
	gpioLEDHandle.GPIO_PinConfig.pinOType = 		NAZEER_GPIO_OTYPE_PP;
	gpioLEDHandle.GPIO_PinConfig.pinPuPdControl = 	NAZEER_GPIO_PUPD_NO;
	gpioLEDHandle.GPIO_PinConfig.pinSpeed = 		NAZEER_GPIO_OSPEED_HIGH;

	NAZEER_GPIO_PCLKControl(NAZEER_GPIOC, ENABLE);
	//always enable the clock before peripheral init to enable the register circuitry of periph
	NAZEER_GPIO_Init(&gpioLEDHandle);
	gpioLEDHandle.GPIO_PinConfig.pinNumber = 8;
	NAZEER_GPIO_Init(&gpioLEDHandle);

    /* Loop forever */
	for(;;){
		printf("Hello Asif, This is semihosting test\n");
		NAZEER_GPIO_TogglePin(NAZEER_GPIOC, 9);
		delay();
		NAZEER_GPIO_TogglePin(NAZEER_GPIOC, 8);
	}
}
