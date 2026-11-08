
// Created by Lenovo on 2026/10/31.
//

#ifndef C_CAN_0_GIMBAL_TX_H
#define C_CAN_0_GIMBAL_TX_H

#include <stdint.h>

#define CAN_GIMBAL_ALL_ID 0x1FF

void CAN_cmd_gimbal(int16_t yaw, int16_t pitch, int16_t shoot, int16_t rev);

#endif //C_CAN_0_GIMBAL_TX_H
