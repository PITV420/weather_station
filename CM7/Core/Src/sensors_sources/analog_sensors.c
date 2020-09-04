/*
 * analog_sensors.c
 *
 *  Created on: Aug 31, 2020
 *      Author: piotrcieslik
 */


#include "sensors_headers/analog_sensors.h"

double analog_sensor(ADC_HandleTypeDef* adc, int max_value){
	double result = 0;
	uint16_t temp = 0;
	HAL_ADC_Start(adc);
	HAL_ADC_PollForConversion(adc, HAL_MAX_DELAY);
	temp = HAL_ADC_GetValue(adc);
	result = ((double)temp)*max_value/65535;
	return result;
}
void battery_level(ADC_HandleTypeDef* adc, char* level, double ref_value){
	uint8_t approx_level = 0;
	double vbat = 0;
	HAL_ADC_Start(adc);
	HAL_ADC_PollForConversion(adc, HAL_MAX_DELAY);
	uint16_t bat_adc = 0;
	bat_adc = HAL_ADC_GetValue(adc);
	vbat = bat_adc*ref_value/65535;

	if(vbat>3.7){
		approx_level = 100;
	}
	if(vbat<=3.7 && vbat>3.6){
		approx_level = 90;
	}
	if(vbat<=3.6 && vbat>3.55){
		approx_level = 70;
	}
	if(vbat<=3.55 && vbat>3.5){
		approx_level = 50;
	}
	if(vbat<=3.5 && vbat>3.45){
		approx_level = 30;
	}
	if(vbat<=3.45 && vbat>3.4){
		approx_level = 20;
	}
	if(vbat<=3.4 && vbat>3.3){
		approx_level = 5;
	}

	if (approx_level>70){
		sprintf(level, "Battery level high, at: %u%s", approx_level, "%");
	}
	else if(approx_level<=70 && approx_level>30){
		sprintf(level, "Battery level mid, at: %u%s", approx_level, "%");
	}
	else{
		printf(level, "Battery level low, at: %u%s", approx_level, "%");
	}
}
