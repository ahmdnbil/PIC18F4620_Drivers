/**
 * @file mcal_interrupt_manager.c
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-11-10
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "./mcal_interrupt_manager.h"

/*
    - why these variables are volatile?

    - because the compiler will see that function of interrupt is never called in main function
    so it will optimize the code and remove this variable
*/
static volatile uint8 RB4_enter = 1, RB5_enter = 1, RB6_enter = 1, RB7_enter = 1;
#if INTERRUPT_PRIORITY_LEVELS_ENABLE == INTERRUPT_FEATURE_ENABLE
void __interrupt() InterruptManagerHigh(void)
{
    if ((INTERRUPT_ENABLE == INTCONbits.INT0IE) && (INTERRUPT_OCCUR == INTCONbits.INT0IF))
    {
        EXTI0_ISR();
    }
    else
    {
    }
    if ((INTERRUPT_ENABLE == INTCON3bits.INT1IE) && (INTERRUPT_OCCUR == INTCON3bits.INT1IF))
    {
        EXTI1_ISR();
    }
    else
    {
    }
}

void __interrupt(low_priority) InterruptManagerLow(void)
{
    if ((INTERRUPT_ENABLE == INTCON3bits.INT2IE) && (INTERRUPT_OCCUR == INTCON3bits.INT2IF))
    {
        EXTI2_ISR();
    }
    else
    {
    }
}
#else
void __interrupt() InterruptManagerHigh(void)
{
    if ((INTCONbits.INT0IE == INTERRUPT_ENABLE) && (INTCONbits.INT0IF == INTERRUPT_OCCUR))
    {
        EXTI0_ISR();
    }
    else if ((INTCON3bits.INT1E == INTERRUPT_ENABLE) && (INTCON3bits.INT1F == INTERRUPT_OCCUR))
    {
        EXTI1_ISR();
    }
    else if ((INTCON3bits.INT2E == INTERRUPT_ENABLE) && (INTCON3bits.INT2F == INTERRUPT_OCCUR))
    {
        EXTI2_ISR();
    }
    /*--------------------------RBx Interrupts----------------------------------------*/

    else if ((INTERRUPT_ENABLE == INTCONbits.RBIE) && (INTERRUPT_OCCUR == INTCONbits.RBIF) && (PORTBbits.RB4 == HIGH) && (1 == RB4_enter))
    {
        RB4_ISR(1);
        RB4_enter = 0;
    }
    else if ((INTERRUPT_ENABLE == INTCONbits.RBIE) && (INTERRUPT_OCCUR == INTCONbits.RBIF) && (PORTBbits.RB4 == LOW) && (0 == RB4_enter))
    {
        RB4_ISR(0);
        RB4_enter = 1;
    }

    else if ((INTERRUPT_ENABLE == INTCONbits.RBIE) && (INTERRUPT_OCCUR == INTCONbits.RBIF) && (PORTBbits.RB5 == HIGH) && (1 == RB5_enter))
    {
        RB5_ISR(1);
        RB5_enter = 0;
    }
    else if ((INTERRUPT_ENABLE == INTCONbits.RBIE) && (INTERRUPT_OCCUR == INTCONbits.RBIF) && (PORTBbits.RB5 == LOW) && (0 == RB5_enter))
    {
        RB5_ISR(0);
        RB5_enter = 1;
    }

    else if ((INTERRUPT_ENABLE == INTCONbits.RBIE) && (INTERRUPT_OCCUR == INTCONbits.RBIF) && (PORTBbits.RB6 == HIGH) && (1 == RB6_enter))
    {
        RB6_ISR(1);
        RB6_enter = 0;
    }
    else if ((INTERRUPT_ENABLE == INTCONbits.RBIE) && (INTERRUPT_OCCUR == INTCONbits.RBIF) && (PORTBbits.RB6 == LOW) && (0 == RB6_enter))
    {
        RB6_ISR(0);
        RB6_enter = 1;
    }

    else if ((INTERRUPT_ENABLE == INTCONbits.RBIE) && (INTERRUPT_OCCUR == INTCONbits.RBIF) && (PORTBbits.RB7 == HIGH) && (1 == RB7_enter))
    {
        RB7_ISR(1);
        RB7_enter = 0;
    }
    else if ((INTERRUPT_ENABLE == INTCONbits.RBIE) && (INTERRUPT_OCCUR == INTCONbits.RBIF) && (PORTBbits.RB7 == LOW) && (0 == RB7_enter))
    {
        RB7_ISR(0);
        RB7_enter = 1;
    }
    /*--------------------------------------------------------------------------------*/
}
#endif