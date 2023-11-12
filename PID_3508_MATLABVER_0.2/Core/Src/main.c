/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "can.h"
#include "tim.h"
#include "gpio.h"


/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "PID_MODEL.h"
#include "arm_math.h"
#include "bsp_can.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */
extern motor_measure_t   *motor_data[4];
/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
double YAW_TGT = 90;
double PITCH_TGT = 2000;

int yaw_output = 0;
int pitch_output = 0;

int ANG_TGT = 0 ; 
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
  MX_CAN1_Init();
  MX_TIM10_Init();
  /* USER CODE BEGIN 2 */
	PID_MODEL_initialize();
	
	HAL_TIM_Base_Start_IT(&htim10); // ÖÐ¶Ï
	
	can_filter_init();
	HAL_CAN_Start(&hcan1); 
	HAL_CAN_ActivateNotification(&hcan1, CAN_IT_RX_FIFO0_MSG_PENDING);
  
	
	/* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
		// SPD 
		rtP.Kp_s = 0.5 ;
		rtP.Ki_s = 0.3 ;
		rtP.Kd_s   = 0 ;
	
	  //ANG
		rtP.Kp_a = 0.5 ;
		rtP.Ki_a = 0.3 ;
		rtP.Kd_a   = 0.1 ;
		
    
    //3508
    rtP.Kp_s_3508 = 0.5;
    rtP.Ki_s_3508 = 0.3;
    rtP.Kd_s_3508 = 0;
    
		// other things
		rtP.DeadBand = 700;
		rtP.trans  = 1;
	
	while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
//    HAL_Delay(3000);
//    YAW_TGT = -YAW_TGT;
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
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 8;
  RCC_OscInitStruct.PLL.PLLN = 168;
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
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	 
	
	if(htim == &htim10)
	{
		
		/* SPD TEST */
		
		
    rtU.pitch_status    = 1 ;// speed
    rtU.pitch_speed_rpm = motor_data[0]->speed_rpm;
    rtU.pitch_ecd       = motor_data[0]->ecd;
    rtU.pitch_last_ecd  = motor_data[0]->last_ecd;
    rtU.pitch_target    = PITCH_TGT;
    rtU.pitch_circle    = 0;
//  
    pitch_output = rtY.pitch_SPD_OUT ; 
		

    /* ANG TEST */
		ANG_TGT  = YAW_TGT * 36 * 8191* 47  / (17*360) ;
		
		rtU.yaw_status    = 2 ;// ANG
		rtU.yaw_speed_rpm = motor_data[1]->speed_rpm;
		rtU.yaw_ecd       = motor_data[1]->ecd;
		rtU.yaw_last_ecd  = motor_data[1]->last_ecd;
		rtU.yaw_target    = ANG_TGT;
		rtU.yaw_circle    = motor_data[1]->circle;
		
		yaw_output = rtY.yaw_ANG_OUT ;

    /* OUT PUT */	
		motor_data[1]->circle = rtU.yaw_circle;
    
    PID_MODEL_step();
		
		CAN_cmd_chassis(pitch_output, yaw_output,0,0);
	
		
		
		
		// data update
		motor_state_update();
	
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
