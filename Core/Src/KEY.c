#include "stm32f4xx_hal.h"
#include "KEY.h"

volatile int distance = 1;
volatile int angle = 500;
volatile uint8_t KEY_state = 0;

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
    if (GPIO_Pin == GPIO_PIN_0) {
        if (KEY_state == 0) {
            static uint32_t last_time = 0;
            uint32_t now = HAL_GetTick();

            // 200ms 内只认第一次按下，彻底消除机械抖动
            if (now - last_time > 200) {
                KEY_state = 1;
                last_time = now;
            }
        }
    }
}//
// Created by Lenovo on 2026/11/2.
//
