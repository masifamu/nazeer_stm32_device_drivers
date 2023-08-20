/*
 * nazeer_stm32f0xx_gpio_driver.c
 *
 *  Created on: Aug 19, 2023
 *      Author: masifamu
 */
#include "nazeer_stm32f0xx_gpio_driver.h"

void NAZEER_GPIO_Init(NAZEER_GPIO_Handle_t *pGPIOHandle){
	// mode
	pGPIOHandle->pGPIOx->MODER |= (pGPIOHandle->GPIO_PinConfig.pinMode << (2 * pGPIOHandle->GPIO_PinConfig.pinNumber));
	// ospeed
	pGPIOHandle->pGPIOx->OSPEEDR |= (pGPIOHandle->GPIO_PinConfig.pinSpeed << (2 * pGPIOHandle->GPIO_PinConfig.pinNumber));
	// pupd
	pGPIOHandle->pGPIOx->PUPDR |= (pGPIOHandle->GPIO_PinConfig.pinPuPdControl << (2 * pGPIOHandle->GPIO_PinConfig.pinNumber));
	// optype
	pGPIOHandle->pGPIOx->OTYPER |= (pGPIOHandle->GPIO_PinConfig.pinOType << pGPIOHandle->GPIO_PinConfig.pinNumber);
	// alt func
	//This line should be executed only when mode=alt function selected.
	if(pGPIOHandle->GPIO_PinConfig.pinMode == NAZEER_GPIO_MODE_ALTFN){
		if(pGPIOHandle->GPIO_PinConfig.pinNumber < 8){
			pGPIOHandle->pGPIOx->AFRL |= (pGPIOHandle->GPIO_PinConfig.pinAltFuncMode << (4*pGPIOHandle->GPIO_PinConfig.pinNumber));
		}else if(pGPIOHandle->GPIO_PinConfig.pinNumber >=8){
			pGPIOHandle->pGPIOx->AFRH |= (pGPIOHandle->GPIO_PinConfig.pinAltFuncMode << (4*pGPIOHandle->GPIO_PinConfig.pinNumber));
		}
	}
}
void NAZEER_GPIO_DeInit(NAZEER_GPIO_RegDef_t *pGPIOx){
	//In order to reset a GPIO peripheral there is a register in RCC domain called as
	if(pGPIOx == NAZEER_GPIOA){
		NAZEER_GPIOA_RST();
	}else if(pGPIOx == NAZEER_GPIOB){
		NAZEER_GPIOB_RST();
	}else if(pGPIOx == NAZEER_GPIOC){
		NAZEER_GPIOC_RST();
	}else if(pGPIOx == NAZEER_GPIOD){
		NAZEER_GPIOD_RST();
	}else if(pGPIOx == NAZEER_GPIOE){
		NAZEER_GPIOE_RST();
	}else if(pGPIOx == NAZEER_GPIOF){
		NAZEER_GPIOF_RST();
	}
}
//read/write related
uint8_t NAZEER_GPIO_ReadPin(NAZEER_GPIO_RegDef_t *pGPIOx, uint8_t pinNum){
	return ((pGPIOx->IDR & pinNum) >> pinNum);
}
uint16_t NAZEER_GPIO_ReadPort(NAZEER_GPIO_RegDef_t *pGPIOx){
	return (pGPIOx->IDR);
}
void NAZEER_GPIO_WritePin(NAZEER_GPIO_RegDef_t *pGPIOx, uint8_t pinNum, uint8_t ENorDI){
	if(ENorDI == HIGH){
		pGPIOx->ODR |= (1 << pinNum);
	}else if(ENorDI == LOW){
		pGPIOx->ODR &= ~(1 << pinNum);
	}
}
void NAZEER_GPIO_WritePort(NAZEER_GPIO_RegDef_t *pGPIOx, uint16_t val){
	pGPIOx->ODR = val;
}
void NAZEER_GPIO_TogglePin(NAZEER_GPIO_RegDef_t *pGPIOx, uint8_t pinNum){
	pGPIOx->ODR ^= (1 << pinNum);
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
