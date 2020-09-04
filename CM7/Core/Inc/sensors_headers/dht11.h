/*
 * dht11.h
 *
 *  Created on: 31 Aug 2020
 *      Author: piotrcieslik
 */

#ifndef INC_SENSORS_HEADERS_DHT11_H_
#define INC_SENSORS_HEADERS_DHT11_H_

#include "stm32h7xx_hal.h"
#include "gpio.h"
#include "tim.h"
#include "math.h"

void delay(TIM_HandleTypeDef tim, uint8_t ms);
void set_gpio_output(GPIO_TypeDef* gpio_port, uint8_t gpio_pin);
void set_gpio_input_pullup(GPIO_TypeDef* gpio_port, uint8_t gpio_pin);
void set_gpio_input_nopull(GPIO_TypeDef* gpio_port, uint8_t gpio_pin);
void set_gpio_input_pulldown(GPIO_TypeDef* gpio_port, uint8_t gpio_pin);
void dht11_init(TIM_HandleTypeDef tim, GPIO_TypeDef* gpio_port, uint8_t gpio_pin);
uint8_t dht11_response(TIM_HandleTypeDef tim, GPIO_TypeDef* gpio_port, uint8_t gpio_pin);
uint8_t dht11_read(TIM_HandleTypeDef tim, GPIO_TypeDef* gpio_port, uint8_t gpio_pin);
void dht11_run(TIM_HandleTypeDef tim, GPIO_TypeDef* gpio_port, uint8_t gpio_pin, double* data);

#endif /* INC_SENSORS_HEADERS_DHT11_H_ */
