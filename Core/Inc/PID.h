//
// Created by Lenovo on 2026/11/1.
//
#ifndef C_CAN_0_PID_H
#define C_CAN_0_PID_H
#include "stm32f4xx_hal.h"

#define speed_kp 20.0f
#define speed_ki 0.4f
#define speed_kd 0.2f

typedef struct {
    float Kp, Ki, Kd;
    float integral;
    float prev_error;
    float derivative;
} PID_t;

extern volatile int16_t speed,current,temp,position;
extern volatile int16_t target_speed;
extern PID_t Speed_PID,Position_PID;

void PID_Init(PID_t *pid, float kp, float ki, float kd);
float PID_Calc(PID_t *pid, float error);
void Control_Loop(float target_speed);
void PID_reset(PID_t *pid);

#endif //C_CAN_0_PID_H
