/**
 * @file hal_timer2.c
 * @author Ahmed Nabil (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-11-24
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "./hal_timer2.h"

/*-----------------------------------Static functions-------------------------------------------*/
static void (*TIMER2_COMP_INTERRUPT_HANDELER)(void) = NULL;
static inline void timer2_set_priority(const timer2_t *_timer);
/*----------------------------------------------------------------------------------------------*/

/*-----------------------------------Global Static functions------------------------------------*/
static uint8 GlobalPreLoad = 0;
/*----------------------------------------------------------------------------------------------*/

Std_ReturnType timer2_Intit(const timer2_t *_timer)
{
    Std_ReturnType ret = E_OK;
    if (NULL == _timer)
    {
        ret = E_NOT_OK;
    }
    else
    {
        /*disable module*/
        TIMER2_MODULE_DISABLE();

        /*post-scaler configurations*/
        TIMER2_SET_POSTSCALER(_timer->postscaler);

        /*pre-scaler configurations*/
        TIMER2_SET_PRESCALER(_timer->prescaler);

        /*Set pre-load Value*/
        GlobalPreLoad = _timer->tiemr2_preload;
        TMR2 = _timer->tiemr2_preload;

        /*interrupt configurations*/
#if TIMER2_COMP_INTERRUPT_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE

        /*set call back*/
        TIMER2_COMP_INTERRUPT_HANDELER = _timer->Timer2_interruptHandeler;

        /*Clear flag*/
        TIMER2_COMPInterruptClearFlag();

        /*interrupt enable*/
        TIMER2_COMPInterruptEnable();

#if INTERRUPT_PRIORITY_LEVELS_ENABLE == INTERRUPT_PRIORITY_ENABLE
        timer2_set_priority(_timer);
#else
        /*enable global interrupt*/
        INTERRUPT_GlobalInterruptEnable();

        /*enable peripheral*/
        INTERRUPT_PeripheralInterruptEnable();
#endif
#endif

        /*enable module*/
        TIMER2_MODULE_ENABLE();
    }
    return ret;
}

#if TIMER2_COMP_INTERRUPT_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE
void TIMER2_COMP_ISR(void)
{
    /*clear flag*/
    TIMER2_COMPInterruptClearFlag();

    /*Set pre-load*/
    TMR2 = GlobalPreLoad;

    if (NULL != TIMER2_COMP_INTERRUPT_HANDELER)
    {
        TIMER2_COMP_INTERRUPT_HANDELER();
    }
}
#endif

Std_ReturnType timer2_DeIntit(const timer2_t *_timer)
{
    Std_ReturnType ret = E_OK;
    if (NULL == _timer)
    {
        ret = E_NOT_OK;
    }
    else
    {
        /*disable module*/
        TIMER2_MODULE_DISABLE();

        /*disable interrupt*/
#if TIMER2_COMP_INTERRUPT_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE
        TIMER2_COMPInterruptDisable();
#endif
    }
    return ret;
}
Std_ReturnType timer2_read_value(const timer2_t *_timer, uint8 *value)
{
    Std_ReturnType ret = E_OK;
    if (NULL == _timer || NULL == value)
    {
        ret = E_NOT_OK;
    }
    else
    {
        *value = TMR2;
    }
    return ret;
}
Std_ReturnType timer2_write_value(const timer2_t *_timer, uint8 value)
{
    Std_ReturnType ret = E_OK;
    if (NULL == _timer)
    {
        ret = E_NOT_OK;
    }
    else
    {
        TMR2 = value;
    }
    return ret;
}

/*-----------------------------------Static functions-------------------------------------------*/
#if INTERRUPT_PRIORITY_LEVELS_ENABLE == INTERRUPT_PRIORITY_ENABLE
static inline void timer2_set_priority(const timer2_t *_timer)
{
    INTERRUPT_PriorityLevelsEnable();
    switch (_timer->priority)
    {
    case INTERRUPT_HIGH_PRIORITY:
        INTERRUPT_GlobalInterruptHighEnable();
        TIMER2_COMPInterruptSetHighPriority();
        break;

    case INTERRUPT_LOW_PRIORITY:
        INTERRUPT_GlobalInterruptLowEnable();
        TIMER2_COMPInterruptSetLowPriority();
        break;

    default:
        break;
    }
}
#endif
/*----------------------------------------------------------------------------------------------*/
