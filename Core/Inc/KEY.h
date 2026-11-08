//
// Created by Lenovo on 2026/11/2.
//

#ifndef C_COMBINE_0_KEY_H
#define C_COMBINE_0_KEY_H
#include "stm32f4xx_hal.h"

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin);
extern volatile int distance;
extern volatile int angle;
extern volatile uint8_t KEY_state;

#endif //C_COMBINE_0_KEY_H
