/**
  ******************************************************************************
  * @file    main.c
  * @author  XPQH
  * @version V1.0
  * @date    2025
  * @brief   Main program body - LED Blink Example for STM32F103C8T6
  *          Based on Jiangke (江科) Video Tutorials
  ******************************************************************************
  * @attention
  *
  * This example demonstrates basic GPIO operations for STM32F103C8T6
  * The onboard LED (PC13) will blink at 1Hz
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x_rcc.h"

/* Private function prototypes -----------------------------------------------*/
void GPIO_Configuration(void);
void Delay(__IO uint32_t nCount);

/**
  * @brief  Main program
  * @param  None
  * @retval None
  */
int main(void)
{
    /* System Initialization */
    SystemInit();
    
    /* Configure GPIO for LED */
    GPIO_Configuration();
    
    /* Infinite loop */
    while (1)
    {
        /* Toggle LED on PC13 */
        GPIO_SetBits(GPIOC, GPIO_Pin_13);
        Delay(500000);  /* Delay ~500ms */
        
        GPIO_ResetBits(GPIOC, GPIO_Pin_13);
        Delay(500000);  /* Delay ~500ms */
    }
}

/**
  * @brief  Configure GPIO PC13 for LED output
  * @param  None
  * @retval None
  */
void GPIO_Configuration(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;
    
    /* Enable GPIOC clock */
    RCC_APB2PeriphClockCmd(RCC_APB2ENR_IOPCEN, ENABLE);
    
    /* Configure PC13 as output push-pull */
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    
    GPIO_Init(GPIOC, &GPIO_InitStructure);
}

/**
  * @brief  Simple delay function
  * @param  nCount: delay count
  * @retval None
  */
void Delay(__IO uint32_t nCount)
{
    for(; nCount != 0; nCount--);
}

/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
#ifdef  USE_FULL_ASSERT
void assert_failed(uint8_t* file, uint32_t line)
{ 
    /* User can add his own implementation to report the file name and line number,
       ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

    /* Infinite loop */
    while (1)
    {
    }
}
#endif
