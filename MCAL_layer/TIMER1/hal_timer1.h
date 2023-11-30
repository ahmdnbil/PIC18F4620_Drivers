/**
 * @file hal_timer1.h
 * @author Ahmed Nabil (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-11-22
 *
 * @copyright Copyright (c) 2023
 *
 */
#ifndef HAL_TIMER1_H
#define HAL_TIMER1_H
/*---------------------------------------section includes-----------------------------------*/
#include "./../interrupt/mcal_internal_interrupt.h"
#include "./../mcal_std_types.h"
#include "./../proc/pic18f4620.h"
#include "./../GPIO/hal_gpio.h"
/*---------------------------------------MACRO Declarations-----------------------------------*/
#define TIMER1_TIMER_MODE 0x00U
#define TIMER1_COUNTER_MODE 0x01U

#define TIMER1_SYNCH_MODE 0x00U
#define TIMER1_ASYNCH_MODE 0x01U

#define TIEMR1_OSCILLATOR_DISABLE 0x00U
#define TIEMR1_OSCILLATOR_ENABLE 0x01U

#define TIMER1_READ_WRITE_8BIT 0x00U
#define TIMER1_READ_WRITE_16BIT 0x01U
/*---------------------------------------MACRO function declarations--------------------------*/
#define TIMER1_MODULE_DISABLE() (T1CONbits.TMR1ON = 0)
#define TIMER1_MODULE_ENABLE() (T1CONbits.TMR1ON = 1)

#define TIMER1_TIMER_MODE_ENABLE() (T1CONbits.TMR1CS = 0)
#define TIMER1_COUNTER_MODE_ENABLE() (T1CONbits.TMR1CS = 1)

#define TIMER1_SYNCH_MODE_ENABLE() (T1CONbits.T1SYNC = 0)
#define TIMER1_ASYNCH_MODE_ENABLE() (T1CONbits.T1SYNC = 1)

#define TIEMR1_OSCILLATOR_MODE_DISABLE() (T1CONbits.T1OSCEN = 0)
#define TIEMR1_OSCILLATOR_MODE_ENABLE() (T1CONbits.T1OSCEN = 1)

#define TIMER1_CLK_SRC_STATUS() (T1CONbits.T1RUN)

#define TIMER1_READ_WRITE_8BIT_ENABLE() (T1CONbits.RD16 = 0)
#define TIMER1_READ_WRITE_16BIT_ENABLE() (T1CONbits.RD16 = 1)

#define TIMER1_SET_PRESCALER(_X) (T1CONbits.T1CKPS = _X)
/*---------------------------------------Data types-------------------------------------------*/
typedef enum
{
    T1_NO_PRESCALER,
    T1_PRESCALER_2,
    T1_PRESCALER_4,
    T1_PRESCALER_8,
} TIMER1_prescaler_t;

typedef struct
{
    /*Call back function*/
    void (*Timer1_interruptHandeler)(void);
    /*priority*/
    interrupt_priority_cfg priority;
    /*pre-load*/
    uint16 tiemr1_preload;
    /*Synchronous clock or Asynchronous*/
    uint8 timer1_synch : 1;
    /*Timer or counter clock*/
    uint8 timer1_mdoe : 1;
    /*oscillator mode*/
    uint8 oscillator_mode : 1;
    /*pre-scaler configuration*/
    TIMER1_prescaler_t prescaler;
    /*8bit or 16bit*/
    uint8 read_format : 1;
    /*Reserved for future use*/
    uint8 : 4;
} timer1_t;

/*---------------------------------------function declarations--------------------------------*/

Std_ReturnType timer1_Intit(const timer1_t *_timer);
Std_ReturnType timer1_DeIntit(const timer1_t *_timer);
Std_ReturnType timer1_read_value(const timer1_t *_timer, uint16 *value);
Std_ReturnType timer1_write_value(const timer1_t *_timer, uint16 value);

#endif /* HAL_TIMER1_H */
