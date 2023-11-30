/**
 * @file hal_timer3.c
 * @author Ahmed Nabil (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-11-24
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "./hal_timer3.h"

/*-----------------------------------Static functions-------------------------------------------*/
static void (*TIMER3_OVF_INTERRUPT_HANDELER)(void) = NULL;
static inline void timer3_set_priority(const timer3_t *_timer);
static inline void timer3_oscillator_config(const timer3_t *_timer);
static inline void timer3_mode_config(const timer3_t *_timer);
static inline void timer3_preload_config(const timer3_t *_timer);
/*----------------------------------------------------------------------------------------------*/
static uint16 Timer3Preload = 0;

Std_ReturnType timer3_Intit(const timer3_t *_timer)
{
    Std_ReturnType ret = E_OK;
    if (NULL == _timer)
    {
        ret = E_NOT_OK;
    }
    else
    {
        /*disable module*/
        TIMER3_MODULE_DISABLE();

        /*mode Configurations*/
        timer3_mode_config(_timer);

        /*Oscillator configurations*/
        timer3_oscillator_config(_timer);

        /*set pre-scaler*/
        TIMER3_SET_PRESCALER(_timer->prescaler);

        /*read format and pre-load value*/
        Timer3Preload = _timer->timer3_preload;
        timer3_preload_config(_timer);

        /*interrupt configurations*/
#if TIMER3_OVF_INTERRUPT_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE

        /*set call back*/
        TIMER3_OVF_INTERRUPT_HANDELER = _timer->Timer3_interruptHandeler;

        /*Clear flag*/
        TIMER3_OVFInterruptClearFlag();

        /*interrupt enable*/
        TIMER3_OVFInterruptEnable();

#if INTERRUPT_PRIORITY_LEVELS_ENABLE == INTERRUPT_PRIORITY_ENABLE
        timer3_set_priority(_timer);
#else
        /*enable global interrupt*/
        INTERRUPT_GlobalInterruptEnable();

        /*enable peripheral*/
        INTERRUPT_PeripheralInterruptEnable();
#endif
#endif
        /*enable module*/
        TIMER3_MODULE_ENABLE();
    }
    return ret;
}

#if TIMER3_OVF_INTERRUPT_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE
void TIMER3_OVF_ISR(void)
{
    /*clear flag*/
    TIMER3_OVFInterruptClearFlag();

    /*Set pre-load*/
    TMR3H = Timer3Preload >> 8;
    TMR3L = (uint8)(Timer3Preload);

    if (NULL != TIMER3_OVF_INTERRUPT_HANDELER)
    {
        TIMER3_OVF_INTERRUPT_HANDELER();
    }
}
#endif

Std_ReturnType timer3_DeIntit(const timer3_t *_timer)
{
    Std_ReturnType ret = E_OK;
    if (NULL == _timer)
    {
        ret = E_NOT_OK;
    }
    else
    {
        /*disable module*/
        TIMER3_MODULE_DISABLE();

        /*disable interrupt*/
#if TIMER3_OVF_INTERRUPT_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE
        TIMER3_OVFInterruptDisable();
#endif
    }
    return ret;
}
Std_ReturnType timer3_read_value(const timer3_t *_timer, uint16 *value)
{
    Std_ReturnType ret = E_OK;
    if (NULL == _timer || NULL == value)
    {
        ret = E_NOT_OK;
    }
    else
    {
        *value = 0;
        *value |= (((uint16)(TMR3H << 8)) | ((uint16)(TMR3L)));
    }
    return ret;
}

Std_ReturnType timer3_write_value(const timer3_t *_timer, uint16 value)
{
    Std_ReturnType ret = E_OK;
    if (NULL == _timer)
    {
        ret = E_NOT_OK;
    }
    else
    {
        /*Write value*/
        TMR3H = value >> 8;
        TMR3L = (uint8)(value);
    }
    return ret;
}

/*-----------------------------------Static functions-------------------------------------------*/
#if INTERRUPT_PRIORITY_LEVELS_ENABLE == INTERRUPT_PRIORITY_ENABLE
static inline void timer3_set_priority(const timer3_t *_timer)
{
    INTERRUPT_PriorityLevelsEnable();
    switch (_timer->priority)
    {
    case INTERRUPT_HIGH_PRIORITY:
        INTERRUPT_GlobalInterruptHighEnable();
        TIMER3_OVFInterruptSetHighPriority();
        break;

    case INTERRUPT_LOW_PRIORITY:
        INTERRUPT_GlobalInterruptLowEnable();
        TIMER3_OVFInterruptSetLowPriority();
        break;

    default:
        break;
    }
}
#endif

static inline void timer3_oscillator_config(const timer3_t *_timer)
{
    switch (_timer->oscillator_mode)
    {
    case TIEMR3_OSCILLATOR_ENABLE:
        TIEMR3_OSCILLATOR_MODE_ENABLE();
        break;

    case TIEMR3_OSCILLATOR_DISABLE:
        TIEMR3_OSCILLATOR_MODE_DISABLE();
        break;
    }
}

static inline void timer3_mode_config(const timer3_t *_timer)
{
    switch (_timer->timer3_mdoe)
    {
    case TIMER3_COUNTER_MODE:
        TIMER3_COUNTER_MODE_ENABLE();
        switch (_timer->timer3_synch)
        {
        case TIMER3_SYNCH_MODE:
            TIMER3_SYNCH_MODE_ENABLE();
            break;

        case TIMER3_ASYNCH_MODE:
            TIMER3_ASYNCH_MODE_ENABLE();
            break;
        }
        break;

    case TIMER3_TIMER_MODE:
        TIMER3_TIMER_MODE_ENABLE();
        break;

    default:
        break;
    }
}
static inline void timer3_preload_config(const timer3_t *_timer)
{
    switch (_timer->read_format)
    {
    case TIMER3_READ_WRITE_16BIT:
        TIMER3_READ_WRITE_16BIT_ENABLE();
        break;

    case TIMER3_READ_WRITE_8BIT:
        TIMER3_READ_WRITE_8BIT_ENABLE();
        TMR3H = _timer->timer3_preload >> 8;
        TMR3L = (uint8)(_timer->timer3_preload);
        break;
    }
}
/*----------------------------------------------------------------------------------------------*/
