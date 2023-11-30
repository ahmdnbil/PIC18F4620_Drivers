/**
 * @file hal_timer1.c
 * @author Ahmed Nabil (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-11-22
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "./hal_timer1.h"

/*-----------------------------------Static functions-------------------------------------------*/
static void (*TIMER1_OVF_INTERRUPT_HANDELER)(void) = NULL;
static inline void timer1_set_priority(const timer1_t *_timer);
static inline void timer1_oscillator_config(const timer1_t *_timer);
static inline void timer1_clock_config(const timer1_t *_timer);
static inline void timer1_preload_config(const timer1_t *_timer);
/*----------------------------------------------------------------------------------------------*/
static uint16 Timer1Preload = 0;

Std_ReturnType timer1_Intit(const timer1_t *_timer)
{
    Std_ReturnType ret = E_OK;
    if (NULL == _timer)
    {
        ret = E_NOT_OK;
    }
    else
    {
        /*disable module*/
        TIMER1_MODULE_DISABLE();

        /*Clock Configurations*/
        timer1_clock_config(_timer);

        /*Oscillator configurations*/
        timer1_oscillator_config(_timer);

        /*set pre-scaler*/
        TIMER1_SET_PRESCALER(_timer->prescaler);

        /*read format and pre-load value*/
        Timer1Preload = _timer->tiemr1_preload;
        timer1_preload_config(_timer);

        /*interrupt configurations*/
#if TIMER1_OVF_INTERRUPT_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE

        /*set call back*/
        TIMER1_OVF_INTERRUPT_HANDELER = _timer->Timer1_interruptHandeler;

        /*Clear flag*/
        TIMER1_OVFInterruptClearFlag();

        /*interrupt enable*/
        TIMER1_OVFInterruptEnable();

#if INTERRUPT_PRIORITY_LEVELS_ENABLE == INTERRUPT_PRIORITY_ENABLE
        timer1_set_priority(_timer);
#else
        /*enable global interrupt*/
        INTERRUPT_GlobalInterruptEnable();

        /*enable peripheral*/
        INTERRUPT_PeripheralInterruptEnable();
#endif
#endif
        /*enable module*/
        TIMER1_MODULE_ENABLE();
    }
    return ret;
}

#if TIMER1_OVF_INTERRUPT_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE
void TIMER1_OVF_ISR(void)
{
    /*clear flag*/
    TIMER1_OVFInterruptClearFlag();

    /*Set pre-load*/
    TMR1H = Timer1Preload >> 8;
    TMR1L = (uint8)(Timer1Preload);

    if (NULL != TIMER1_OVF_INTERRUPT_HANDELER)
    {
        TIMER1_OVF_INTERRUPT_HANDELER();
    }
}
#endif

Std_ReturnType timer1_DeIntit(const timer1_t *_timer)
{
    Std_ReturnType ret = E_OK;
    if (NULL == _timer)
    {
        ret = E_NOT_OK;
    }
    else
    {
        /*disable module*/
        TIMER1_MODULE_DISABLE();

        /*disable interrupt*/
#if TIMER1_OVF_INTERRUPT_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE
        TIMER1_OVFInterruptDisable();
#endif
    }
    return ret;
}

Std_ReturnType timer1_write_value(const timer1_t *_timer, uint16 value)
{
    Std_ReturnType ret = E_OK;
    if (NULL == _timer)
    {
        ret = E_NOT_OK;
    }
    else
    {
        /*Write value*/
        TMR1H = value >> 8;
        TMR1L = (uint8)(value);
    }
    return ret;
}
Std_ReturnType timer1_read_value(const timer1_t *_timer, uint16 *value)
{
    Std_ReturnType ret = E_OK;
    if (NULL == _timer || NULL == value)
    {
        ret = E_NOT_OK;
    }
    else
    {
        *value = 0;
        *value |= (((uint16)(TMR1H << 8)) | ((uint16)(TMR1L)));
    }
    return ret;
}

/*-----------------------------------Static functions-------------------------------------------*/
#if INTERRUPT_PRIORITY_LEVELS_ENABLE == INTERRUPT_PRIORITY_ENABLE
static inline void timer1_set_priority(const timer1_t *_timer)
{
    INTERRUPT_PriorityLevelsEnable();
    switch (_timer->priority)
    {
    case INTERRUPT_HIGH_PRIORITY:
        INTERRUPT_GlobalInterruptHighEnable();
        TIMER1_OVFInterruptSetHighPriority();
        break;

    case INTERRUPT_LOW_PRIORITY:
        INTERRUPT_GlobalInterruptLowEnable();
        TIMER1_OVFInterruptSetLowPriority();
        break;

    default:
        break;
    }
}
#endif

static inline void timer1_oscillator_config(const timer1_t *_timer)
{
    switch (_timer->oscillator_mode)
    {
    case TIEMR1_OSCILLATOR_ENABLE:
        TIEMR1_OSCILLATOR_MODE_ENABLE();
        break;

    case TIEMR1_OSCILLATOR_DISABLE:
        TIEMR1_OSCILLATOR_MODE_DISABLE();
        break;
    }
}
static inline void timer1_clock_config(const timer1_t *_timer)
{
    switch (_timer->timer1_mdoe)
    {
    case TIMER1_COUNTER_MODE:
        TIMER1_COUNTER_MODE_ENABLE();
        switch (_timer->timer1_synch)
        {
        case TIMER1_SYNCH_MODE:
            TIMER1_SYNCH_MODE_ENABLE();
            break;

        case TIMER1_ASYNCH_MODE:
            TIMER1_ASYNCH_MODE_ENABLE();
            break;
        }
        break;

    case TIMER1_TIMER_MODE:
        TIMER1_TIMER_MODE_ENABLE();
        break;

    default:
        break;
    }
}

static inline void timer1_preload_config(const timer1_t *_timer)
{
    switch (_timer->read_format)
    {
    case TIMER1_READ_WRITE_16BIT:
        TIMER1_READ_WRITE_16BIT_ENABLE();
        break;

    case TIMER1_READ_WRITE_8BIT:
        TIMER1_READ_WRITE_8BIT_ENABLE();
        TMR1H = _timer->tiemr1_preload >> 8;
        TMR1L = (uint8)(_timer->tiemr1_preload);
        break;
    }
}
/*----------------------------------------------------------------------------------------------*/