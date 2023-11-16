/**
 * @file mcal_external_interrupt.h
 * @author Ahmed Nabil (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-11-10
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef MCAL_EXTERNAL_INTERRUPT_H
#define MCAL_EXTERNAL_INTERRUPT_H

/*-------------------------------------section includes---------------------------------------*/
#include "./mcal_interrupt_cfg.h"
/*---------------------------------------MACRO Declarations-----------------------------------*/

#if EXTERNAL_INTERRUPT_INTx_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE

/*EXTI0 MACRO functions*/
#define EXTI0_Enable()(INTCONbits.INT0IE=1)
#define EXTI0_Disable()(INTCONbits.INT0IE=0)
#define EXTI0_ClearFlag() (INTCONbits.INT0IF=0)
#define EXTI0_RisingEdge() (INTCON2bits.INTEDG0=1)
#define EXTI0_FallingEdge() (INTCON2bits.INTEDG0=0)

#define EXTI1_Enable()(INTCON3bits.INT1IE=1)
#define EXTI1_Disable()(INTCON3bits.INT1IE=0)
#define EXTI1_ClearFlag() (INTCON3bits.INT1IF=0)
#define EXTI1_RisingEdge() (INTCON2bits.INTEDG1=1)
#define EXTI1_FallingEdge() (INTCON2bits.INTEDG1=0)

#define EXTI2_Enable()(INTCON3bits.INT2IE=1)
#define EXTI2_Disable()(INTCON3bits.INT2IE=0)
#define EXTI2_ClearFlag() (INTCON3bits.INT2IF=0)
#define EXTI2_RisingEdge() (INTCON2bits.INTEDG2=1)
#define EXTI2_FallingEdge() (INTCON2bits.INTEDG2=0)

#if INTERRUPT_PRIORITY_LEVELS_ENABLE == INTERRUPT_FEATURE_ENABLE
#define EXTI1_SetHighPriority() (INTCON3bits.INT1IP=1)
#define EXTI1_SetLowPriority() (INTCON3bits.INT1IP=0)
#define EXTI2_SetHighPriority() (INTCON3bits.INT2IP=1)
#define EXTI2_SetLowPriority() (INTCON3bits.INT2IP=0)
#endif


#endif

#if EXTERNAL_INTERRUPT_OnChange_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE
#define EXTI_RBx_InterruptEnable() (INTCONbits.RBIE=1)
#define EXTI_RBx_InterruptDisable() (INTCONbits.RBIE=0)
#define EXTI_RBx_InterruptClearFlag() (INTCONbits.RBIF=0)

#if INTERRUPT_PRIORITY_LEVELS_ENABLE == INTERRUPT_FEATURE_ENABLE
#define EXTI_RBx_SetHighPriority() (INTCON2bits.RBIP=1)
#define EXTI_RBx_SetLowPriority() (INTCON2bits.RBIP=0)
#endif

#endif
/*---------------------------------------MACRO function declarations--------------------------*/

/*---------------------------------------Data types-------------------------------------------*/
typedef void (*interruptHandeler)(void);

typedef enum
{
    INTERRUPT_FALLING_EDGE=0,
    INTERRUPT_RISING_EDGE,
    
}interrupt_INTx_edge;
typedef enum
{
    EXTI0=0,
    EXTI1,
    EXTI2,
}interrupt_INTx_src;


typedef struct
{
    void (*pf)(void);
    pin_config_t mcu_pin;
    interrupt_INTx_edge edge;
    interrupt_INTx_src src;
    interrupt_priority_cfg priority;
}interrupt_INTx_t;

typedef struct
{
    void (*pf)(void);
    void (*pf2)(void);
    pin_config_t mcu_pin;
    interrupt_priority_cfg priority;
}interrupt_RBx_t;

/*---------------------------------------function declarations--------------------------------*/
Std_ReturnType interrupt_INTx_Init(const interrupt_INTx_t * int_obj);
Std_ReturnType interrupt_INTx_DeInit(const interrupt_INTx_t * int_obj);

Std_ReturnType interrupt_RBx_Init(const interrupt_RBx_t * int_obj);
Std_ReturnType interrupt_RBx_DeInit(const interrupt_RBx_t * int_obj);

#endif /* MCAL_EXTERNAL_INTERRUPT_H */
