/**
 * @file mcal_interrupt_gen_cfg.h
 * @author Ahmed Nabil (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-11-10
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef MCAL_INTERRUPT_GEN_CFG_H
#define MCAL_INTERRUPT_GEN_CFG_H

/*-------------------------------------section includes---------------------------------------*/
/*---------------------------------------MACRO Declarations-----------------------------------*/

#define  INTERRUPT_FEATURE_ENABLE 1U
#define  INTERRUPT_FEATURE_DISABLE 0U

#define INTERRUPT_PRIORITY_ENABLE 1
#define INTERRUPT_PRIORITY_DISABLE 0

#define INTERRUPT_PRIORITY_LEVELS_ENABLE INTERRUPT_PRIORITY_DISABLE

/*---------external interrupts configuration-----*/
#define EXTERNAL_INTERRUPT_INTx_FEATURE_ENABLE INTERRUPT_FEATURE_ENABLE
#define EXTERNAL_INTERRUPT_OnChange_FEATURE_ENABLE INTERRUPT_FEATURE_ENABLE
/*-----------------------------------------------*/

/*---------internal interrupts configuration-----*/
/*ADC interrupt*/
#define ADC_INTERRUPT_FEATURE_ENABLE INTERRUPT_FEATURE_DISABLE
/*Timer0 OVF interrupt*/
#define TIMER0_INTERRUPT_FEATURE_ENABLE INTERRUPT_FEATURE_ENABLE
/*Timer1 OVF interrupt*/
#define TIMER1_OVF_INTERRUPT_FEATURE_ENABLE INTERRUPT_FEATURE_ENABLE
/*Timer2 COMP interrupt*/
#define TIMER2_COMP_INTERRUPT_FEATURE_ENABLE INTERRUPT_FEATURE_DISABLE
/*Timer3 OVF interrupt*/
#define TIMER3_OVF_INTERRUPT_FEATURE_ENABLE INTERRUPT_FEATURE_ENABLE
/*CCP1 interrupt*/
#define CCP1_INTERRUPT_FEATURE_ENABLE INTERRUPT_FEATURE_ENABLE
/*CCP2 interrupt*/
#define CCP2_INTERRUPT_FEATURE_ENABLE INTERRUPT_FEATURE_ENABLE
/*USART Transmit interrupt*/
#define USART_TX_INTERRUPT_FEATURE_ENABLE INTERRUPT_FEATURE_ENABLE
/*USART Receive interrupt*/
#define USART_RX_INTERRUPT_FEATURE_ENABLE INTERRUPT_FEATURE_ENABLE
/*SSP master synchronous interrupt*/
#define MSSP_INTERRUPT_FEATURE_ENABLE INTERRUPT_FEATURE_ENABLE

/*-----------------------------------------------*/

/*---------------------------------------MACRO function declarations--------------------------*/
/*---------------------------------------Data types-------------------------------------------*/
/*---------------------------------------function declarations--------------------------------*/

#endif /* MCAL_INTERRUPT_GEN_CFG_H */
