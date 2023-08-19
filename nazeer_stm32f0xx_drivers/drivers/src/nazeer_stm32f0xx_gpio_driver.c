/*
 * nazeer_stm32f0xx_gpio_driver.c
 *
 *  Created on: Aug 19, 2023
 *      Author: masifamu
 */
#include "nazeer_stm32f0xx_gpio_driver.h"

void NAZEER_GPIO_Init(NAZEER_GPIO_Handle_t *pGPIOHandle){
	// mode
//	pGPIOHandle->
	// speed
	// pupd
	// optype
	// alt func
}
void NAZEER_GPIO_DeInit(NAZEER_GPIO_RegDef_t *pGPIOx){

}
//read/write related
void NAZEER_GPIO_ReadPin(NAZEER_GPIO_RegDef_t *pGPIOx, uint8_t pinNum){

}
uint16_t NAZEER_GPIO_ReadPort(NAZEER_GPIO_RegDef_t *pGPIOx){
	return 0;
}
void NAZEER_GPIO_WritePin(NAZEER_GPIO_RegDef_t *pGPIOx, uint8_t pinNum, uint8_t ENorDI){

}
void NAZEER_GPIO_WritePort(NAZEER_GPIO_RegDef_t *pGPIOx, uint16_t val){

}
void NAZEER_GPIO_TogglePin(NAZEER_GPIO_RegDef_t *pGPIOx, uint8_t pinNum){

}
//IRQ related
void NAZEER_GPIO_IRQConfig(uint8_t IRQNum,uint8_t IRQPrio, uint8_t ENorDI){

}
void NAZEER_GPIO_IRQHandler(void){

}
//clock related
void NAZEER_GPIO_PCLKControl(NAZEER_GPIO_RegDef_t *pGPIOx, uint8_t ENorDI){
	if(ENorDI == ENABLE){
		if(pGPIOx == NAZEER_GPIOA){
			NAZEER_GPIOA_PCLK_EN();
		}else if(pGPIOx == NAZEER_GPIOB){
			NAZEER_GPIOB_PCLK_EN();
		}else if(pGPIOx == NAZEER_GPIOC){
			NAZEER_GPIOC_PCLK_EN();
		}else if(pGPIOx == NAZEER_GPIOD){
			NAZEER_GPIOD_PCLK_EN();
		}else if(pGPIOx == NAZEER_GPIOE){
			NAZEER_GPIOE_PCLK_EN();
		}else if(pGPIOx == NAZEER_GPIOF){
			NAZEER_GPIOF_PCLK_EN();
		}
	}else if(ENorDI == DISABLE){
		if(pGPIOx == NAZEER_GPIOA){
			NAZEER_GPIOA_PCLK_DI();
		}else if(pGPIOx == NAZEER_GPIOB){
			NAZEER_GPIOB_PCLK_DI();
		}else if(pGPIOx == NAZEER_GPIOC){
			NAZEER_GPIOC_PCLK_DI();
		}else if(pGPIOx == NAZEER_GPIOD){
			NAZEER_GPIOD_PCLK_DI();
		}else if(pGPIOx == NAZEER_GPIOE){
			NAZEER_GPIOE_PCLK_DI();
		}else if(pGPIOx == NAZEER_GPIOF){
			NAZEER_GPIOF_PCLK_DI();
		}
	}else{
		//not a valid control input
	}
}
