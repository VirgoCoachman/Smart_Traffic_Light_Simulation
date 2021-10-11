/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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

#include "led.h"
#include "lcd16x2.h"
#include "traffic_manager.h"

/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

int queue_a, queue_b, queue_c, queue_d;
int priority[2] = {0};
//static uint8_t lastButton_A_Status = GPIO_PIN_RESET;
int quota = 0; //nombre de vÃ©hicule qui doit libÃ©rer la voie avant de basculer


void show_quota(){
//	lcd16x2_clear();
	lcd16x2_setCursor(0, 0);
//	lcd16x2_1stLine();
	lcd16x2_printf("a:%d/b:%d/c:%d/d:%d", queue_a, queue_b, queue_c, queue_d);
//	lcd16x2_2ndLine();
	lcd16x2_setCursor(1,0);
	lcd16x2_printf("quota : %d      ", quota);
//	HAL_Delay(50);
//	lcd16x2_clear();
//	lcd16x2_cursorShow(1);
}

int check_value(int value)
{
	if(value < 0 || value >= 250)
		value = 0;
	return value;
}

void reanalyse(void){
	if(quota == 2){
		 blink_orange_led(priority);
		 show_quota();
	 }else if(quota == 0){
		 quota = analyse_queues_situation(&queue_a, &queue_b, &queue_c, &queue_d, priority);
	 }
}

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  /* USER CODE BEGIN 2 */
  lcd16x2_init_4bits(RS_GPIO_Port, RS_Pin, EN_Pin,
		  D4_GPIO_Port, D4_Pin, D5_Pin, D6_Pin, D7_Pin);
  lcd16x2_twoLines();
  lcd16x2_cursorShow(0);

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */

  queue_a =0, queue_b =0, queue_c = 0, queue_d = 0;

  while (1)
  {
	  show_quota();
//	  HAL_Delay(150);
	  if(queue_a == 0 && queue_b==0 && queue_c==0 && queue_d==0){
		  blink_led_off();
		  lcd16x2_clear();
		  lcd16x2_printf("Standby mode");
		  HAL_Delay(250);
	  } else{
		  if(quota == 0){
			  quota = analyse_queues_situation(&queue_a, &queue_b, &queue_c, &queue_d, priority);
		  }
		  show_quota();
	  }

    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */

	  quota = check_value(quota);
	  queue_a = check_value(queue_a);
	  queue_b = check_value(queue_b);
	  queue_c = check_value(queue_c);
	  queue_d = check_value(queue_d);
//
//	  HAL_Delay(50);
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE2);
  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 8;
  RCC_OscInitStruct.PLL.PLLN = 84;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 4;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

void alert_empty_queue_error() {
	lcd16x2_1stLine();
	lcd16x2_printf("ERROR MESSAGE");
	lcd16x2_2ndLine();
	lcd16x2_printf("empty queue");
}

/* USER CODE BEGIN 4 */
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	UNUSED(GPIO_Pin);

	if(GPIO_Pin == btn_enqueue_a_Pin){
		++queue_a;
	}

	if(GPIO_Pin == btn_dequeue_a_Pin){
		if(queue_a > 0 ){
			--queue_a;
			--quota;
			reanalyse();
		} else{
			alert_empty_queue_error();
		}
	}

	if(GPIO_Pin == btn_enqueue_b_Pin){
		++queue_b;
	}

	if(GPIO_Pin == btn_dequeue_b_Pin){
		if(queue_b > 0){
			--queue_b;
			--quota;
			reanalyse();
		}else{
			alert_empty_queue_error();
		}
	}

	if(GPIO_Pin == btn_enqueue_c_Pin){
		++queue_c;
	}

	if(GPIO_Pin == btn_dequeue_c_Pin){
		if(queue_c > 0){
			--queue_c;
			--quota;
			reanalyse();
		}else{
			alert_empty_queue_error();
		}
	}

	if(GPIO_Pin == btn_enqueue_d_Pin){
		++queue_d;
	}

	if(GPIO_Pin == btn_dequeue_d_Pin){
		if(queue_d > 0){
			--queue_d;
			--quota;
			reanalyse();
		}else{
			alert_empty_queue_error();
		}
	}

}
/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
