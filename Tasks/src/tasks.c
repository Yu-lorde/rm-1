/*
 * @Author: Yu-lorde Yu-lorde@users.noreply.github.com
 * @Date: 2026-10-03 16:38:34
 * @LastEditors: Yu-lorde Yu-lorde@users.noreply.github.com
 * @LastEditTime: 2026-10-05 16:56:46
 * @FilePath: \test-gpio\Tasks\src\tasks.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "tasks.h"
#include "main.h"
#include "iwdg.h"
#include "tim.h"

volatile uint32_t tick = 0;
void Tasks_Init(void)
{
    // 低电平亮
    HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_RESET);
    HAL_TIM_Base_Start_IT(&htim2);

}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
    if (htim->Instance == TIM2)
    {
        tick++;
    }
}