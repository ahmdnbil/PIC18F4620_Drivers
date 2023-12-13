/**
 * @file mcal_internal_interrupt.h
 * @author Ahmed Nabil (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-11-10
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef MCAL_INTERNAL_INTERRUPT_H
#define MCAL_INTERNAL_INTERRUPT_H

/*-------------------------------------section includes---------------------------------------*/
#include "./mcal_interrupt_cfg.h"
/*---------------------------------------MACRO Declarations-----------------------------------*/

/*---------------------------------------MACRO function declarations--------------------------*/

/*-------------------ADC INT configurations----------------*/
#if ADC_INTERRUPT_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE
#define ADC_InterruptEnable() (PIE1bits.ADIE = 1)
#define ADC_InterruptDisable() (PIE1bits.ADIE = 0)
#define ADC_InterruptClearFlag() (PIR1bits.ADIF = 0)

#if INTERRUPT_PRIORITY_LEVELS_ENABLE == INTERRUPT_FEATURE_ENABLE
#define ADC_InterruptSetHighPriority() (IPR1bits.ADIP = 1)
#define ADC_InterruptSetLowPriority() (IPR1bits.ADIP = 0)
#endif

#endif

/*-------------------TIMER0 INT configurations----------------*/
#if TIMER0_INTERRUPT_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE
#define TIMER0_InterruptEnable() (INTCONbits.T0IE = 1)
#define TIMER0_InterruptDisable() (INTCONbits.T0IE = 0)
#define TIMER0_InterruptClearFlag() (INTCONbits.T0IF = 0)

#if INTERRUPT_PRIORITY_LEVELS_ENABLE == INTERRUPT_FEATURE_ENABLE
#define TIMER0_InterruptSetHighPriority() (INTCON2bits.TMR0IP = 1)
#define TIMER0_InterruptSetLowPriority() (INTCON2bits.TMR0IP = 0)
#endif

#endif

/*-------------------TIMER1 OverFlow INT configurations----------------*/
#if TIMER1_OVF_INTERRUPT_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE
#define TIMER1_OVFInterruptEnable() (PIE1bits.TMR1IE = 1)
#define TIMER1_OVFInterruptDisable() (PIE1bits.TMR1IE = 0)
#define TIMER1_OVFInterruptClearFlag() (PIR1bits.TMR1IF = 0)

#if INTERRUPT_PRIORITY_LEVELS_ENABLE == INTERRUPT_FEATURE_ENABLE
#define TIMER1_OVFInterruptSetHighPriority() (IPR1bits.TMR1IP = 1)
#define TIMER1_OVFInterruptSetLowPriority() (IPR1bits.TMR1IP = 0)
#endif

#endif

/*-------------------TIMER2 Compare INT configurations----------------*/
#if TIMER2_COMP_INTERRUPT_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE
#define TIMER2_COMPInterruptEnable() (PIE1bits.TMR2IE = 1)
#define TIMER2_COMPInterruptDisable() (PIE1bits.TMR2IE = 0)
#define TIMER2_COMPInterruptClearFlag() (PIR1bits.TMR2IF = 0)

#if INTERRUPT_PRIORITY_LEVELS_ENABLE == INTERRUPT_FEATURE_ENABLE
#define TIMER2_COMPInterruptSetHighPriority() (IPR1bits.TMR2IP = 1)
#define TIMER2_COMPInterruptSetLowPriority() (IPR1bits.TMR2IP = 0)
#endif

#endif

/*-------------------TIMER3 OVF INT configurations----------------*/
#if TIMER3_OVF_INTERRUPT_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE
#define TIMER3_OVFInterruptEnable() (PIE2bits.TMR3IE = 1)
#define TIMER3_OVFInterruptDisable() (PIE2bits.TMR3IE = 0)
#define TIMER3_OVFInterruptClearFlag() (PIR2bits.TMR3IF = 0)

#if INTERRUPT_PRIORITY_LEVELS_ENABLE == INTERRUPT_FEATURE_ENABLE
#define TIMER3_OVFInterruptSetHighPriority() (IPR2bits.TMR3IP = 1)
#define TIMER3_OVFInterruptSetLowPriority() (IPR2bits.TMR3IP = 0)
#endif

#endif

/*-------------------CCP1 INT configurations----------------*/
#if CCP1_INTERRUPT_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE
#define CCP1_InterruptEnable() (PIE1bits.CCP1IE = 1)
#define CCP1_InterruptDisable() (PIE1bits.CCP1IE = 0)
#define CCP1_InterruptClearFlag() (PIR1bits.CCP1IF = 0)

#if INTERRUPT_PRIORITY_LEVELS_ENABLE == INTERRUPT_FEATURE_ENABLE
#define CCP1_InterruptSetHighPriority() (IPR1bits.CCP1IP = 1)
#define CCP1_InterruptSetLowPriority() (IPR1bits.CCP1IP = 0)
#endif
#endif

/*-------------------CCP2 INT configurations----------------*/
#if CCP2_INTERRUPT_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE
#define CCP2_InterruptEnable() (PIE2bits.CCP2IE = 1)
#define CCP2_InterruptDisable() (PIE2bits.CCP2IE = 0)
#define CCP2_InterruptClearFlag() (PIR2bits.CCP2IF = 0)

#if INTERRUPT_PRIORITY_LEVELS_ENABLE == INTERRUPT_FEATURE_ENABLE
#define CCP2_InterruptSetHighPriority() (IPR2bits.CCP2IP = 1)
#define CCP2_InterruptSetLowPriority() (IPR2bits.CCP2IP = 0)
#endif
#endif

/*-------------------USART RESEIVE INT configurations-----------*/
#if USART_RX_INTERRUPT_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE
#define USART_RxInterruptEnable() (PIE1bits.RCIE = 1)
#define USART_RxInterruptDisable() (PIE1bits.RCIE = 0)
#define USART_RxInterruptClearFlag() (PIR1bits.RCIF = 0)

#if INTERRUPT_PRIORITY_LEVELS_ENABLE == INTERRUPT_FEATURE_ENABLE
#define USART_RxInterruptSetHighPriority() (IPR1bits.RCIP = 1)
#define USART_RxInterruptSetLowPriority() (IPR1bits.RCIP = 0)
#endif
#endif

/*-------------------USART TRANSMIT INT configurations-----------*/
#if USART_TX_INTERRUPT_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE
#define USART_TxInterruptEnable() (PIE1bits.TXIE = 1)
#define USART_TxInterruptDisable() (PIE1bits.TXIE = 0)

#if INTERRUPT_PRIORITY_LEVELS_ENABLE == INTERRUPT_FEATURE_ENABLE
#define USART_TxInterruptSetHighPriority() (IPR1bits.TXIP = 1)
#define USART_TxInterruptSetLowPriority() (IPR1bits.TXIP = 0)
#endif
#endif

#if MSSP_INTERRUPT_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE
#define MSSP_InterruptEnable() (PIE1bits.SSPIE = 1)
#define MSSP_BusCollisionInterruptEnable() (PIE2bits.BCLIE = 1)

#define MSSP_InterruptDisable() (PIE1bits.SSPIE = 0)
#define MSSP_BusCollisionInterruptDisable() (PIE2bits.BCLIE = 0)

#define MSSP_InterruptClearFlag() (PIR1bits.SSPIF = 0)
#define MSSP_BusCollisionInterruptClearFlag() (PIR2bits.BCLIF = 0)

#if INTERRUPT_PRIORITY_LEVELS_ENABLE == INTERRUPT_FEATURE_ENABLE
#define MSSP_InterruptSetHighPriority() (IPR1bits.SSPIP = 1)
#define MSSP_BusCollisionInterruptSetHighPriority() (IPR2bits.BCLIP = 1)

#define MSSP_InterruptSetLowPriority() (IPR1bits.SSPIP = 0)
#define MSSP_BusCollisionInterruptSetLowPriority() (IPR2bits.BCLIP= 0)
#endif

#endif
/*---------------------------------------Data types-------------------------------------------*/

/*---------------------------------------function declarations--------------------------------*/

#endif /* MCAL_INTERNAL_INTERRUPT_H */
