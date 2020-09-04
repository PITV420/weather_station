/*
 * buzzer.h
 *
 *  Created on: Aug 31, 2020
 *      Author: piotrcieslik
 */

#ifndef INC_SENSORS_HEADERS_BUZZER_H_
#define INC_SENSORS_HEADERS_BUZZER_H_

#include "stm32h7xx_hal.h"
#include "tim.h"

void buzzer_init(TIM_HandleTypeDef tim, uint8_t channel);
void buzzer_run(TIM_HandleTypeDef tim, uint8_t channel, uint8_t time);

#endif /* INC_SENSORS_HEADERS_BUZZER_H_ */
