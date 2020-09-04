################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/sensors_sources/analog_sensors.c \
../Core/Src/sensors_sources/buzzer.c \
../Core/Src/sensors_sources/dht11.c \
../Core/Src/sensors_sources/esp8266.c 

OBJS += \
./Core/Src/sensors_sources/analog_sensors.o \
./Core/Src/sensors_sources/buzzer.o \
./Core/Src/sensors_sources/dht11.o \
./Core/Src/sensors_sources/esp8266.o 

C_DEPS += \
./Core/Src/sensors_sources/analog_sensors.d \
./Core/Src/sensors_sources/buzzer.d \
./Core/Src/sensors_sources/dht11.d \
./Core/Src/sensors_sources/esp8266.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/sensors_sources/analog_sensors.o: ../Core/Src/sensors_sources/analog_sensors.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DCORE_CM7 -DDEBUG -DSTM32H755xx -c -I../Core/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../Drivers/CMSIS/Include -I../../Middlewares/Third_Party/ARM_CMSIS/CMSIS/Core/Include/ -I../../Middlewares/Third_Party/ARM_CMSIS/CMSIS/Core_A/Include/ -I../../Drivers/CMSIS/Driver/Include -I../../Middlewares/ST/ARM/DSP/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/sensors_sources/analog_sensors.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/Src/sensors_sources/buzzer.o: ../Core/Src/sensors_sources/buzzer.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DCORE_CM7 -DDEBUG -DSTM32H755xx -c -I../Core/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../Drivers/CMSIS/Include -I../../Middlewares/Third_Party/ARM_CMSIS/CMSIS/Core/Include/ -I../../Middlewares/Third_Party/ARM_CMSIS/CMSIS/Core_A/Include/ -I../../Drivers/CMSIS/Driver/Include -I../../Middlewares/ST/ARM/DSP/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/sensors_sources/buzzer.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/Src/sensors_sources/dht11.o: ../Core/Src/sensors_sources/dht11.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DCORE_CM7 -DDEBUG -DSTM32H755xx -c -I../Core/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../Drivers/CMSIS/Include -I../../Middlewares/Third_Party/ARM_CMSIS/CMSIS/Core/Include/ -I../../Middlewares/Third_Party/ARM_CMSIS/CMSIS/Core_A/Include/ -I../../Drivers/CMSIS/Driver/Include -I../../Middlewares/ST/ARM/DSP/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/sensors_sources/dht11.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/Src/sensors_sources/esp8266.o: ../Core/Src/sensors_sources/esp8266.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DCORE_CM7 -DDEBUG -DSTM32H755xx -c -I../Core/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../Drivers/CMSIS/Include -I../../Middlewares/Third_Party/ARM_CMSIS/CMSIS/Core/Include/ -I../../Middlewares/Third_Party/ARM_CMSIS/CMSIS/Core_A/Include/ -I../../Drivers/CMSIS/Driver/Include -I../../Middlewares/ST/ARM/DSP/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/sensors_sources/esp8266.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

