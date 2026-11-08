#include <stdint.h>
#include "can.h"
#include "stm32f4xx_hal_can.h"

#define CAN_GIMBAL_ALL_ID 0x1FF

CAN_TxHeaderTypeDef gimbal_tx_message;

uint8_t gimbal_can_send_data[8];

void CAN_cmd_gimbal(int16_t yaw, int16_t pitch, int16_t shoot, int16_t rev)
{
    uint32_t send_mail_box;
    gimbal_tx_message.StdId = CAN_GIMBAL_ALL_ID;
    gimbal_tx_message.IDE = CAN_ID_STD;
    gimbal_tx_message.RTR = CAN_RTR_DATA;
    gimbal_tx_message.DLC = 0x08;
    gimbal_can_send_data[0] = (yaw >> 8);
    gimbal_can_send_data[1] = yaw;
    gimbal_can_send_data[2] = (pitch >> 8);
    gimbal_can_send_data[3] = pitch;
    gimbal_can_send_data[4] = (shoot >> 8);
    gimbal_can_send_data[5] = shoot;
    gimbal_can_send_data[6] = (rev >> 8);
    gimbal_can_send_data[7] = rev;
    HAL_CAN_AddTxMessage(&hcan1, &gimbal_tx_message,
   gimbal_can_send_data, &send_mail_box);
}
// Created by Lenovo on 2026/10/31.
//
