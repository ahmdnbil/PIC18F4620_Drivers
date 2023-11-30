/**
 * @file hal_timer2.h
 * @author Ahmed Nabil (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-11-24
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef FE2C5513_5827_44F1_BEBC_6AF7A1180FB2
#define FE2C5513_5827_44F1_BEBC_6AF7A1180FB2
/*---------------------------------------section includes-----------------------------------*/
#include "./../interrupt/mcal_internal_interrupt.h"
#include "./../mcal_std_types.h"
#include "./../proc/pic18f4620.h"
#include "./../GPIO/hal_gpio.h"
/*---------------------------------------MACRO Declarations-----------------------------------*/

/*---------------------------------------MACRO function declarations--------------------------*/
#define TIMER2_MODULE_DISABLE() (T2CONbits.TMR2ON = 0)
#define TIMER2_MODULE_ENABLE() (T2CONbits.TMR2ON = 1)

#define TIMER2_SET_PRESCALER(_X) (T2CONbits.T2CKPS = _X)
#define TIMER2_SET_POSTSCALER(_X) (T2CONbits.TOUTPS = _X)
/*---------------------------------------Data types-------------------------------------------*/
typedef enum
{
    T2_PRESCALER_1,
    T2_PRESCALER_4,
    T2_PRESCALER_16,
} TIMER2_prescaler_t;

typedef enum
{
    T2_POSTSCALER_1,
    T2_POSTSCALER_2,
    T2_POSTSCALER_3,
    T2_POSTSCALER_4,
    T2_POSTSCALER_5,
    T2_POSTSCALER_6,
    T2_POSTSCALER_7,
    T2_POSTSCALER_8,
    T2_POSTSCALER_9,
    T2_POSTSCALER_10,
    T2_POSTSCALER_11,
    T2_POSTSCALER_12,
    T2_POSTSCALER_13,
    T2_POSTSCALER_14,
    T2_POSTSCALER_15,
    T2_POSTSCALER_16,
} TIMER2_postscaler_t;

typedef struct
{
    /*Call back function*/
    void (*Timer2_interruptHandeler)(void);
    /*priority*/
    interrupt_priority_cfg priority;
    /*pre-load*/
    uint8 tiemr2_preload;
    /*pre-scaler configuration*/
    TIMER2_prescaler_t prescaler;
    /*post-scaler configuration*/
    TIMER2_postscaler_t postscaler;
} timer2_t;

/*---------------------------------------function declarations--------------------------------*/

Std_ReturnType timer2_Intit(const timer2_t *_timer);
Std_ReturnType timer2_DeIntit(const timer2_t *_timer);
Std_ReturnType timer2_read_value(const timer2_t *_timer, uint8 *value);
Std_ReturnType timer2_write_value(const timer2_t *_timer, uint8 value);

#endif /* FE2C5513_5827_44F1_BEBC_6AF7A1180FB2 */
