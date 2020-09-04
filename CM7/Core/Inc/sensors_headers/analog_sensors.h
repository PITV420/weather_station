/*
 * analog_sensors.h
 *
 *  Created on: Aug 31, 2020
 *      Author: piotrcieslik
 */

#ifndef INC_SENSORS_HEADERS_ANALOG_SENSORS_H_
#define INC_SENSORS_HEADERS_ANALOG_SENSORS_H_

#include "stm32h7xx_hal.h"
#include "adc.h"
#include <stdio.h>

double analog_sensor(ADC_HandleTypeDef* adc, int max_value);
void battery_level(ADC_HandleTypeDef* adc, char* level, double ref_value);

#endif /* INC_SENSORS_HEADERS_ANALOG_SENSORS_H_ */
