//
// Created by EiveLL on 25-5-23.
//

#ifndef TASKS_H
#define TASKS_H

#include "stm32f1xx_hal.h"
#include "usart.h"
#include "VL53L0X.h"
#define SAMPLE_SIZE 20
#define DIFF_THRESHOLD 10       // 判断是否变化的阈值（单位：mm）
#define STABLE_COUNT_THRESHOLD 30  // 连续稳定多少次才认为“平稳”
#define SAMPLE_COUNT 30

// 状态机标志
typedef enum {
    STATE_WAIT_INITIAL,
    STATE_MONITOR_RISE,
    STATE_WAIT_STABLE
} SlopeState;

typedef enum {
    STATE_WAIT,
    STATE_RECORD,
    STATE_STABLE
} MOVESlopeState;

typedef enum {
    STATE_CALTIME,
    STATE_RECORD_BUF,
    STATE_CAN
} Task_Six_State;

void angle_sample_push(float angle);

void task1();

void task2();

void task3();

void task4();

void task5();

void task6();

void detect_peaks_and_valleys();

float get_random_pm_half();

extern float mix_angle;
extern uint16_t dis_buf[10];
extern uint8_t task_running;
extern uint8_t task_index;
extern uint16_t task2_result;
extern float platform_length_mm;
#endif //TASKS_H
