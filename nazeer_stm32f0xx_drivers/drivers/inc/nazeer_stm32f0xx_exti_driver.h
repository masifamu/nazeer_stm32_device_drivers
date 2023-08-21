/*
 * nazeer_stm32f0xx_exti_driver.h
 *
 *  Created on: Aug 22, 2023
 *      Author: syntiant_0005
 */

#ifndef INC_NAZEER_STM32F0XX_EXTI_DRIVER_H_
#define INC_NAZEER_STM32F0XX_EXTI_DRIVER_H_

#include <stdint.h>
//IRQ related
void NAZEER_EXTI_IRQConfig(uint8_t IRQNum,uint8_t IRQPrio, uint8_t ENorDI);
void NAZEER_EXTI_IRQHandler(void);


#endif /* INC_NAZEER_STM32F0XX_EXTI_DRIVER_H_ */
