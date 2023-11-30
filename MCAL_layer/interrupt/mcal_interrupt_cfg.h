/**
 * @file mcal_interrupt_cfg.h
 * @author Ahmed Nabil (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-11-10
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef MCAL_INTERRUPT_CFG_H
#define MCAL_INTERRUPT_CFG_H
/*-------------------------------------section includes---------------------------------------*/
#include "./../proc/pic18f4620.h"
#include "./../mcal_std_types.h"
#include "./mcal_interrupt_gen_cfg.h"
#include "./../GPIO/hal_gpio.h"

/*---------------------------------------MACRO Declarations-----------------------------------*/
#define INTERRUPT_ENABLE 1U
#define INTERRUPT_DISABLE 0U

#define INTERRUPT_OCCUR 1U
#define INTERRUPT_NOT_OCCUR 0U

/*---------------------------------------MACRO function declarations--------------------------*/

#if INTERRUPT_PRIORITY_LEVELS_ENABLE == INTERRUPT_FEATURE_ENABLE
/*Enable Priority  Level*/
#define INTERRUPT_PriorityLevelsEnable() (RCONbits.IPEN=1)
/*Disable Priority  Level*/
#define INTERRUPT_PriorityLevelsDisable() (RCONbits.IPEN=0)

#define INTERRUPT_GlobalInterruptHighEnable() (INTCONbits.GIEH=1)
#define INTERRUPT_GlobalInterruptHighDisable() (INTCONbits.GIEH=0)
#define INTERRUPT_GlobalInterruptLowEnable() (INTCONbits.GIEL=1)
#define INTERRUPT_GlobalInterruptLowDisable() (INTCONbits.GIEL=0)


#else
#define INTERRUPT_GlobalInterruptEnable() (INTCONbits.GIE=1)
#define INTERRUPT_GlobalInterruptDisable() (INTCONbits.GIE=0)

#define INTERRUPT_PeripheralInterruptEnable() (INTCONbits.PEIE=1)
#define INTERRUPT_PeripheralInterruptDisable() (INTCONbits.PEIE=0)

#endif
/*---------------------------------------Data types-------------------------------------------*/

typedef enum
{
    INTERRUPT_LOW_PRIORITY=0,
    INTERRUPT_HIGH_PRIORITY
}interrupt_priority_cfg;

/*---------------------------------------function declarations--------------------------------*/

#endif /* MCAL_INTERRUPT_CFG_H */
