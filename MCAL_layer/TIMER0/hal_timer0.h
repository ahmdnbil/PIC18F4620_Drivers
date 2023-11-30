/**
 * @file hal_timer0.h
 * @author Ahmed Nabil (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-11-21
 *
 * @copyright Copyright (c) 2023
 *
 */
#ifndef HAL_TIMER0_H
#define HAL_TIMER0_H

/*-------------------------------------section includes---------------------------------------*/
#include "./../interrupt/mcal_internal_interrupt.h"
#include "./../mcal_std_types.h"
#include "./../proc/pic18f4620.h"
#include "./../GPIO/hal_gpio.h"

/*---------------------------------------MACRO Declarations-----------------------------------*/
#define TIMER0_PRESCALER_FEATURE_ENABLE 0x01U
#define TIMER0_PRESCALER_FEATURE_DISABLE 0x00U

#define TIMER0_RISING_EDGE 0x01U
#define TIMER0_FALLING_EDGE 0x00U

#define TIMER0_TIMER_MODE 0x01U
#define TIMER0_COUNTER_MODE 0x00U

#define TIMER0_16BIT_MODE 0x00U
#define TIMER0_8BIT_MODE 0x01U
/*---------------------------------------MACRO function declarations--------------------------*/
#define TIMER0_PRESCALER_ENABLE() (T0CONbits.PSA = 0)
#define TIMER0_PRESCALER_DISABLE() (T0CONbits.PSA = 1)

#define TIMER0_RISING_EDGE_ENABLE() (T0CONbits.T0SE = 0)
#define TIMER0_FALLING_EDGE_ENABLE() (T0CONbits.T0SE = 1)

#define TIMER0_TIMER_MODE_ENABLE() (T0CONbits.T0CS = 0)
#define TIMER0_COUNTER_MODE_ENABLE() (T0CONbits.T0CS = 1)

#define TIMER0_16BIT_MODE_ENABLE() (T0CONbits.T08BIT = 0)
#define TIMER0_8BIT_MODE_ENABLE() (T0CONbits.T08BIT = 1)

#define TIMER0_MODULE_DISABLE() (T0CONbits.TMR0ON = 0)
#define TIMER0_MODULE_ENABLE() (T0CONbits.TMR0ON = 1)
/*---------------------------------------Data types-------------------------------------------*/
typedef enum
{
    T0_PRESCALER_2,
    T0_PRESCALER_4,
    T0_PRESCALER_8,
    T0_PRESCALER_16,
    T0_PRESCALER_32,
    T0_PRESCALER_64,
    T0_PRESCALER_128,
    T0_PRESCALER_256
} Timer0_Prescaler_Select_t;

typedef struct
{
    void (*tiemr0_InterruptHandeler)(void);
    interrupt_priority_cfg priority;
    Timer0_Prescaler_Select_t prescaler;
    uint16 timer0_preload;
    uint8 prescaler_enable : 1;
    uint8 counter_edge_select : 1;
    uint8 tiemr0_mode : 1;
    uint8 timer0_reg_size : 1;
    uint8 : 4;
} timer0_t;

/*---------------------------------------function declarations--------------------------------*/
Std_ReturnType timer0_Init(const timer0_t *_timer);
Std_ReturnType timer0_DeInit(const timer0_t *_timer);
Std_ReturnType timer0_Wirte_value(const timer0_t *_timer, uint16 value);
Std_ReturnType timer0_Read_value(const timer0_t *_timer, uint16 *value);
#endif /* HAL_TIMER0_H */
