/*
 * nazeer_stm32f0xx_gpio_driver.h
 *
 *  Created on: Aug 19, 2023
 *      Author: masifamu
 */

#ifndef INC_NAZEER_STM32F0XX_GPIO_DRIVER_H_
#define INC_NAZEER_STM32F0XX_GPIO_DRIVER_H_

#include "stm32f0xx.h"

//GPIO possible modes
#define NAZEER_GPIO_MODE_IN				0x00U
#define NAZEER_GPIO_MODE_OUT			0x01U
#define NAZEER_GPIO_MODE_ALTFN			0x10U
#define NAZEER_GPIO_MODE_ANALOG			0x11U
//GPIO output type
#define NAZEER_GPIO_OTYPE_PP			0x0U
#define NAZEER_GPIO_OTYPE_OD			0x1U
//GPIO possible speeds
#define NAZEER_GPIO_OSPEED_LOW			0x00U
#define NAZEER_GPIO_OSPEED_MEDIUM		0x01U
#define NAZEER_GPIO_OSPEED_HIGH			0x11U
//GPIO PUPD options
#define NAZEER_GPIO_PUPD_NO				0x00U
#define NAZEER_GPIO_PUPD_PU				0x01U
#define NAZEER_GPIO_PUPD_PD				0x10U
//GPIO ALT func options
#define NAZEER_GPIO_ALTF_AF0			0x0000U
#define NAZEER_GPIO_ALTF_AF1			0x0001U
#define NAZEER_GPIO_ALTF_AF2			0x0010U
#define NAZEER_GPIO_ALTF_AF3			0x0011U
#define NAZEER_GPIO_ALTF_AF4			0x0100U
#define NAZEER_GPIO_ALTF_AF5			0x0101U
#define NAZEER_GPIO_ALTF_AF6			0x0110U
#define NAZEER_GPIO_ALTF_AF7			0x0111U
//handle structures
typedef struct{
	uint8_t pinNumber;
	uint8_t pinMode;
	uint8_t pinSpeed;
	uint8_t pinPuPdControl;
	uint8_t pinOType;
	uint8_t pinAltFuncMode;
}NAZEER_GPIO_PinConfig_t;

typedef struct{
	NAZEER_GPIO_RegDef_t *pGPIOx;
	NAZEER_GPIO_PinConfig_t GPIO_PinConfig;
}NAZEER_GPIO_Handle_t;

//API functions
//init related
void NAZEER_GPIO_Init(NAZEER_GPIO_Handle_t *pGPIOHandle);
void NAZEER_GPIO_DeInit(NAZEER_GPIO_RegDef_t *pGPIOx);
//read/write related
uint8_t NAZEER_GPIO_ReadPin(NAZEER_GPIO_RegDef_t *pGPIOx, uint8_t pinNum);
uint16_t NAZEER_GPIO_ReadPort(NAZEER_GPIO_RegDef_t *pGPIOx);
void NAZEER_GPIO_WritePin(NAZEER_GPIO_RegDef_t *pGPIOx, uint8_t pinNum, uint8_t ENorDI);
void NAZEER_GPIO_WritePort(NAZEER_GPIO_RegDef_t *pGPIOx, uint16_t val);
void NAZEER_GPIO_TogglePin(NAZEER_GPIO_RegDef_t *pGPIOx, uint8_t pinNum);
//clock related
void NAZEER_GPIO_PCLKControl(NAZEER_GPIO_RegDef_t *pGPIOx, uint8_t ENorDI);

#endif /* INC_NAZEER_STM32F0XX_GPIO_DRIVER_H_ */
