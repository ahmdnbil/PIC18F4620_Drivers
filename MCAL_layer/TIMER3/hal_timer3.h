/**
 * @file hal_timer3.h
 * @author Ahmed Nabil (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-11-24
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef FCE6B915_316A_458F_A1E1_D2AE3D12C364
#define FCE6B915_316A_458F_A1E1_D2AE3D12C364

/*---------------------------------------section includes-----------------------------------*/
#include "./../interrupt/mcal_internal_interrupt.h"
#include "./../mcal_std_types.h"
#include "./../proc/pic18f4620.h"
#include "./../GPIO/hal_gpio.h"
/*---------------------------------------MACRO Declarations-----------------------------------*/
#define TIMER3_TIMER_MODE 0x00U
#define TIMER3_COUNTER_MODE 0x01U

#define TIMER3_SYNCH_MODE 0x00U
#define TIMER3_ASYNCH_MODE 0x01U

#define TIMER3_READ_WRITE_8BIT 0x00U
#define TIMER3_READ_WRITE_16BIT 0x01U

#define TIEMR3_OSCILLATOR_DISABLE 0x00U
#define TIEMR3_OSCILLATOR_ENABLE 0x01U
/*---------------------------------------MACRO function declarations--------------------------*/
#define TIMER3_MODULE_DISABLE() (T3CONbits.TMR3ON = 0)
#define TIMER3_MODULE_ENABLE() (T3CONbits.TMR3ON = 1)

#define TIMER3_TIMER_MODE_ENABLE() (T3CONbits.TMR3CS = 0)
#define TIMER3_COUNTER_MODE_ENABLE() (T3CONbits.TMR3CS = 1)

#define TIMER3_SYNCH_MODE_ENABLE() (T3CONbits.T3SYNC = 0)
#define TIMER3_ASYNCH_MODE_ENABLE() (T3CONbits.T3SYNC = 1)

#define TIMER3_READ_WRITE_8BIT_ENABLE() (T3CONbits.RD16 = 0)
#define TIMER3_READ_WRITE_16BIT_ENABLE() (T3CONbits.RD16 = 1)

#define TIEMR3_OSCILLATOR_MODE_DISABLE() (T1CONbits.T1OSCEN = 0)
#define TIEMR3_OSCILLATOR_MODE_ENABLE() (T1CONbits.T1OSCEN = 1)

#define TIMER3_SET_PRESCALER(_X) (T3CONbits.T3CKPS = _X)
/*---------------------------------------Data types-------------------------------------------*/
typedef enum
{
    T3_PRESCALER_1,
    T3_PRESCALER_2,
    T3_PRESCALER_4,
    T3_PRESCALER_8,
} TIMER3_prescaler_t;

typedef struct
{
    /*Call back function*/
    void (*Timer3_interruptHandeler)(void);

    /*priority*/
    interrupt_priority_cfg priority;

    /*pre-load*/
    uint16 timer3_preload;

    /*pre-scaler configuration*/
    TIMER3_prescaler_t prescaler;

    /*Synchronous clock or Asynchronous*/
    uint8 timer3_synch : 1;

    /*oscillator mode*/
    uint8 oscillator_mode : 1;

    /*Timer or counter clock*/
    uint8 timer3_mdoe : 1;

    /*8bit or 16bit*/
    uint8 read_format : 1;

    /*Reserved for future use*/
    uint8 : 4;
} timer3_t;

/*---------------------------------------function declarations--------------------------------*/

Std_ReturnType timer3_Intit(const timer3_t *_timer);
Std_ReturnType timer3_DeIntit(const timer3_t *_timer);
Std_ReturnType timer3_read_value(const timer3_t *_timer, uint16 *value);
Std_ReturnType timer3_write_value(const timer3_t *_timer, uint16 value);

#endif /* FCE6B915_316A_458F_A1E1_D2AE3D12C364 */
