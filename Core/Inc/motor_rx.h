//
// Created by Lenovo on 2026/10/31.
//
#ifndef C_CAN_0_MOTOR_RX_H
#define C_CAN_0_MOTOR_RX_H

#include <stdint.h>
#include "stm32f4xx_hal.h"

#define CAN_PIT_MOTOR_ID 0x206
#define CAN_3508_M1_ID 0x201

typedef struct
{
    int16_t ecd;
    int16_t speed_rpm;
    int16_t given_current;
    uint8_t temperate;
    int16_t last_ecd;
} motor_t;

extern motor_t gimbal;
extern volatile uint32_t last_feed;
void get_motor_measure(motor_t *ptr, const uint8_t *data);

void CAN_Init(CAN_HandleTypeDef *hcan, uint32_t filter_bank);

#endif //C_CAN_0_MOTOR_RX_H
