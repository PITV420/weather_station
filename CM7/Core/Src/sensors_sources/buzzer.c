/*
 * buzzer.c
 *
 *  Created on: Aug 31, 2020
 *      Author: piotrcieslik
 */

#include "sensors_headers/buzzer.h"

void buzzer_init(TIM_HandleTypeDef tim, uint8_t channel){
	HAL_TIM_PWM_Start(&tim, channel);
}
void buzzer_run(TIM_HandleTypeDef tim, uint8_t channel, uint8_t time){
	buzzer_init(tim, channel);
	uint8_t numbers = 0, value = 0;
	  while(numbers<time*10){
		  tim.Instance->CCR1 = value;
		  value += 100;
		  HAL_Delay(100);
		  numbers+=1;
	  }
	  value = 0;
	  numbers = 0;
	  HAL_TIM_PWM_Stop(&tim, channel);
}
