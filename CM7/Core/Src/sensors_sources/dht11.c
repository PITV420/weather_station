/*
 * dht11.c
 *
 *  Created on: 31 Aug 2020
 *      Author: piotrcieslik
 */


#include "sensors_headers/dht11.h"

void delay(TIM_HandleTypeDef tim, uint8_t ms){
	__HAL_TIM_SET_COUNTER(&tim, 0);
	while(__HAL_TIM_GET_COUNTER(&tim)<ms);
}
void set_gpio_output(GPIO_TypeDef* gpio_port, uint8_t gpio_pin){
	GPIO_InitTypeDef GPIO_InitStruct = {0};
	GPIO_InitStruct.Pin = gpio_pin;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(gpio_port, &GPIO_InitStruct);
}
void set_gpio_input_pullup(GPIO_TypeDef* gpio_port, uint8_t gpio_pin){
	GPIO_InitTypeDef GPIO_InitStruct = {0};
	GPIO_InitStruct.Pin = gpio_pin;
	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	GPIO_InitStruct.Pull = GPIO_PULLUP;
	HAL_GPIO_Init(gpio_port, &GPIO_InitStruct);
}
void set_gpio_input_nopull(GPIO_TypeDef* gpio_port, uint8_t gpio_pin){
	GPIO_InitTypeDef GPIO_InitStruct = {0};
	GPIO_InitStruct.Pin = gpio_pin;
	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	HAL_GPIO_Init(gpio_port, &GPIO_InitStruct);
}
void set_gpio_input_pulldown(GPIO_TypeDef* gpio_port, uint8_t gpio_pin){
	GPIO_InitTypeDef GPIO_InitStruct = {0};
	GPIO_InitStruct.Pin = gpio_pin;
	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	GPIO_InitStruct.Pull = GPIO_PULLDOWN;
	HAL_GPIO_Init(gpio_port, &GPIO_InitStruct);
}
void dht11_init(TIM_HandleTypeDef tim, GPIO_TypeDef* gpio_port, uint8_t gpio_pin){
	set_gpio_output(gpio_port, gpio_pin);
	HAL_GPIO_WritePin(gpio_port, gpio_pin, GPIO_PIN_SET);
	HAL_Delay(20);
	HAL_GPIO_WritePin(gpio_port, gpio_pin, GPIO_PIN_RESET);
	HAL_Delay(20);
	HAL_GPIO_WritePin(gpio_port, gpio_pin, GPIO_PIN_SET);
	delay(tim, 30);
	set_gpio_input_nopull(gpio_port, gpio_pin);
}
uint8_t dht11_response(TIM_HandleTypeDef tim, GPIO_TypeDef* gpio_port, uint8_t gpio_pin){
	uint8_t resp = 0;
	if(!HAL_GPIO_ReadPin(gpio_port, gpio_pin)){
		delay(tim, 80);
		if(HAL_GPIO_ReadPin(gpio_port, gpio_pin)){
			resp = 1;
		}
		else{
			resp = -1;
		}
	}
	delay(tim, 80);
	return resp;
}
uint8_t dht11_read(TIM_HandleTypeDef tim, GPIO_TypeDef* gpio_port, uint8_t gpio_pin){
	uint8_t data = 0;
	for (int i=0; i<8; i++){
		while(!HAL_GPIO_ReadPin(gpio_port, gpio_pin));
		delay(tim, 40);
		if(HAL_GPIO_ReadPin(gpio_port, gpio_pin)){
			data |= (1<<(7-i));
		}
		else{
			data &= ~(1<<(7-i));
		}
		while(HAL_GPIO_ReadPin(gpio_port, gpio_pin));
	}
	return data;
}
void dht11_run(TIM_HandleTypeDef tim, GPIO_TypeDef* gpio_port, uint8_t gpio_pin, double* data){
	HAL_TIM_Base_Start(&tim);
	uint8_t temp_byte_1 = 0, temp_byte_2 = 0, hum_byte_1 = 0, hum_byte_2 = 0;
	dht11_init(tim, gpio_port, gpio_pin);
	if(dht11_response(tim, gpio_port, gpio_pin)){
		hum_byte_1 = dht11_read(tim, gpio_port, gpio_pin);
		hum_byte_2 = dht11_read(tim, gpio_port, gpio_pin);
		temp_byte_1 = dht11_read(tim, gpio_port, gpio_pin);
		temp_byte_2 = dht11_read(tim, gpio_port, gpio_pin);
	}
	data[0] = temp_byte_1 + temp_byte_2/10.0;
	data[1] = hum_byte_1 + hum_byte_2/10.0;
}
