/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
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
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

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
#define btn_enqueue_a_Pin GPIO_PIN_1
#define btn_enqueue_a_GPIO_Port GPIOA
#define btn_enqueue_a_EXTI_IRQn EXTI1_IRQn
#define btn_dequeue_a_Pin GPIO_PIN_2
#define btn_dequeue_a_GPIO_Port GPIOA
#define btn_dequeue_a_EXTI_IRQn EXTI2_IRQn
#define btn_enqueue_b_Pin GPIO_PIN_3
#define btn_enqueue_b_GPIO_Port GPIOA
#define btn_enqueue_b_EXTI_IRQn EXTI3_IRQn
#define btn_dequeue_b_Pin GPIO_PIN_4
#define btn_dequeue_b_GPIO_Port GPIOA
#define btn_dequeue_b_EXTI_IRQn EXTI4_IRQn
#define btn_enqueue_c_Pin GPIO_PIN_5
#define btn_enqueue_c_GPIO_Port GPIOA
#define btn_enqueue_c_EXTI_IRQn EXTI9_5_IRQn
#define btn_dequeue_c_Pin GPIO_PIN_6
#define btn_dequeue_c_GPIO_Port GPIOA
#define btn_dequeue_c_EXTI_IRQn EXTI9_5_IRQn
#define btn_enqueue_d_Pin GPIO_PIN_7
#define btn_enqueue_d_GPIO_Port GPIOA
#define btn_enqueue_d_EXTI_IRQn EXTI9_5_IRQn
#define D0_Pin GPIO_PIN_0
#define D0_GPIO_Port GPIOB
#define D1_Pin GPIO_PIN_1
#define D1_GPIO_Port GPIOB
#define D2_Pin GPIO_PIN_2
#define D2_GPIO_Port GPIOB
#define RS_Pin GPIO_PIN_10
#define RS_GPIO_Port GPIOB
#define btn_dequeue_d_Pin GPIO_PIN_8
#define btn_dequeue_d_GPIO_Port GPIOA
#define btn_dequeue_d_EXTI_IRQn EXTI9_5_IRQn
#define green_led_1_Pin GPIO_PIN_1
#define green_led_1_GPIO_Port GPIOD
#define orange_led_1_Pin GPIO_PIN_2
#define orange_led_1_GPIO_Port GPIOD
#define red_led_1_Pin GPIO_PIN_3
#define red_led_1_GPIO_Port GPIOD
#define green_led_2_Pin GPIO_PIN_4
#define green_led_2_GPIO_Port GPIOD
#define orange_led_2_Pin GPIO_PIN_5
#define orange_led_2_GPIO_Port GPIOD
#define red_led_2_Pin GPIO_PIN_6
#define red_led_2_GPIO_Port GPIOD
#define D3_Pin GPIO_PIN_3
#define D3_GPIO_Port GPIOB
#define D4_Pin GPIO_PIN_4
#define D4_GPIO_Port GPIOB
#define D5_Pin GPIO_PIN_5
#define D5_GPIO_Port GPIOB
#define D6_Pin GPIO_PIN_6
#define D6_GPIO_Port GPIOB
#define D7_Pin GPIO_PIN_7
#define D7_GPIO_Port GPIOB
#define EN_Pin GPIO_PIN_9
#define EN_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
