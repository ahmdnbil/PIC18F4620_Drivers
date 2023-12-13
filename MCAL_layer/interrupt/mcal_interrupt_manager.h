/**
 * @file mcal_interrupt_manager.h
 * @author Ahmed Nabil (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-11-10
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef MCAL_INTERRUPT_MANAGER_H
#define MCAL_INTERRUPT_MANAGER_H
/*-------------------------------------section includes---------------------------------------*/
#include "./mcal_interrupt_cfg.h"
/*---------------------------------------MACRO Declarations-----------------------------------*/
/*---------------------------------------MACRO function declarations--------------------------*/
/*---------------------------------------Data types-------------------------------------------*/
/*---------------------------------------function declarations--------------------------------*/
void EXTI0_ISR(void);
void EXTI1_ISR(void);
void EXTI2_ISR(void);
void RB4_ISR(uint8 RB4_Int);
void RB5_ISR(uint8 RB5_Int);
void RB6_ISR(uint8 RB6_Int);
void RB7_ISR(uint8 RB7_Int);

void ADC_ISR();
void TIMER0_ISR(void);
void TIMER1_OVF_ISR(void);
void TIMER2_COMP_ISR(void);
void TIMER3_OVF_ISR(void);
void CCP1_ISR();
void CCP2_ISR();
void EUSART_TX_ISR();
void EUSART_RX_ISR();
void MSSP_I2C_ISR();
void MSSP_I2C_BC_ISR();

#endif /* MCAL_INTERRUPT_MANAGER_H */
