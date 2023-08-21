################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../drivers/src/nazeer_stm32f0xx_exti_driver.c \
../drivers/src/nazeer_stm32f0xx_gpio_driver.c 

OBJS += \
./drivers/src/nazeer_stm32f0xx_exti_driver.o \
./drivers/src/nazeer_stm32f0xx_gpio_driver.o 

C_DEPS += \
./drivers/src/nazeer_stm32f0xx_exti_driver.d \
./drivers/src/nazeer_stm32f0xx_gpio_driver.d 


# Each subdirectory must supply rules for building sources it contributes
drivers/src/%.o drivers/src/%.su drivers/src/%.cyclo: ../drivers/src/%.c drivers/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F0 -DSTM32F051R8Tx -c -I../Inc -I"/home/syntiant_0005/STM32CubeIDE/workspace_1.13.1/nazeer_stm32f0xx_drivers/drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-drivers-2f-src

clean-drivers-2f-src:
	-$(RM) ./drivers/src/nazeer_stm32f0xx_exti_driver.cyclo ./drivers/src/nazeer_stm32f0xx_exti_driver.d ./drivers/src/nazeer_stm32f0xx_exti_driver.o ./drivers/src/nazeer_stm32f0xx_exti_driver.su ./drivers/src/nazeer_stm32f0xx_gpio_driver.cyclo ./drivers/src/nazeer_stm32f0xx_gpio_driver.d ./drivers/src/nazeer_stm32f0xx_gpio_driver.o ./drivers/src/nazeer_stm32f0xx_gpio_driver.su

.PHONY: clean-drivers-2f-src

