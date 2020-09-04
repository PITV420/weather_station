/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32h7xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "sensors_headers/dht11.h"
#include "sensors_headers/buzzer.h"
#include "sensors_headers/analog_sensors.h"
/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define B1_Pin GPIO_PIN_13
#define B1_GPIO_Port GPIOC
#define LIGHT_ADC_Pin GPIO_PIN_6
#define LIGHT_ADC_GPIO_Port GPIOF
#define WIFI_GPIO_0_Pin GPIO_PIN_0
#define WIFI_GPIO_0_GPIO_Port GPIOC
#define WIFI_GPIO_2_Pin GPIO_PIN_3
#define WIFI_GPIO_2_GPIO_Port GPIOC
#define BAT_ADC_Pin GPIO_PIN_2
#define BAT_ADC_GPIO_Port GPIOA
#define WIFI_TX_Pin GPIO_PIN_3
#define WIFI_TX_GPIO_Port GPIOA
#define LD1_Pin GPIO_PIN_0
#define LD1_GPIO_Port GPIOB
#define WIFI_EN_Pin GPIO_PIN_1
#define WIFI_EN_GPIO_Port GPIOB
#define TEMP_HUM_Pin GPIO_PIN_7
#define TEMP_HUM_GPIO_Port GPIOE
#define BUZZ_PWM_Pin GPIO_PIN_9
#define BUZZ_PWM_GPIO_Port GPIOE
#define LD3_Pin GPIO_PIN_14
#define LD3_GPIO_Port GPIOB
#define STLINK_RX_Pin GPIO_PIN_8
#define STLINK_RX_GPIO_Port GPIOD
#define STLINK_TX_Pin GPIO_PIN_9
#define STLINK_TX_GPIO_Port GPIOD
#define USB_OTG_FS_PWR_EN_Pin GPIO_PIN_10
#define USB_OTG_FS_PWR_EN_GPIO_Port GPIOD
#define WIFI_RST_Pin GPIO_PIN_3
#define WIFI_RST_GPIO_Port GPIOD
#define WIFI_RX_Pin GPIO_PIN_5
#define WIFI_RX_GPIO_Port GPIOD
#define BAR_INT_Pin GPIO_PIN_14
#define BAR_INT_GPIO_Port GPIOG
#define LD2_Pin GPIO_PIN_1
#define LD2_GPIO_Port GPIOE
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
