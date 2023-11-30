/**
 * @file hal_timer0.c
 * @author Ahmed Nabil (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-11-21
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "./hal_timer0.h"

/*------------------------- Static helper functions ----------------------------------*/
static void (*TIMER0_INTERRUTP_HANDELER)(void) = NULL;
static inline void timer0_prescaler_config(const timer0_t *_timer);
static inline void timer0_mode_config(const timer0_t *_timer);
static inline void timer0_reg_size_config(const timer0_t *_timer);
/*------------------------------------------------------------------------------------*/
/*---------------------------- Global variables---------------------------------------*/
volatile static uint16 preloadValue = 0;
/*------------------------------------------------------------------------------------*/

Std_ReturnType timer0_Init(const timer0_t *_timer)
{
    Std_ReturnType ret = E_OK;
    if (NULL == _timer)
    {
        ret = E_NOT_OK;
    }
    else
    {
        preloadValue = _timer->timer0_preload;
        /*Disable Timer0 module*/
        TIMER0_MODULE_DISABLE();

        /*configure pre-scaler*/
        timer0_prescaler_config(_timer);

        /*timer or counter mode and if counter mode select the edge*/
        timer0_mode_config(_timer);

        /*timer register size*/
        timer0_reg_size_config(_timer);

        /*Set pre-load value*/
        TMR0H = _timer->timer0_preload >> 8;
        TMR0L = (uint8)(_timer->timer0_preload);

        /*interrupt configuration*/
#if TIMER0_INTERRUPT_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE
        TIMER0_INTERRUTP_HANDELER = _timer->tiemr0_InterruptHandeler;
        /*clear flag*/
        TIMER0_InterruptClearFlag();
        /*enable interrupt*/
        TIMER0_InterruptEnable();
#if INTERRUPT_PRIORITY_LEVELS_ENABLE == INTERRUPT_PRIORITY_ENABLE
        INTERRUPT_PriorityLevelsEnable();
        switch (_timer->priority)
        {
        case INTERRUPT_HIGH_PRIORITY:
            /*enable high global interrupt*/
            INTERRUPT_GlobalInterruptHighEnable();
            /*set timer0 as high priority*/
            TIMER0_InterruptSetHighPriority();
            break;

        case INTERRUPT_LOW_PRIORITY:
            /*enable low global interrupt*/
            INTERRUPT_GlobalInterruptLowEnable();
            /*set timer0 as low priority*/
            TIMER0_InterruptSetLowPriority();
            break;

        default:
            break;
        }
#else
        /*enable global interrupt*/
        INTERRUPT_GlobalInterruptEnable();
        /*peripheral interrupt enable*/
        INTERRUPT_PeripheralInterruptEnable();
#endif
#endif
        /**/
        /*enable Timer0 module*/
        TIMER0_MODULE_ENABLE();
    }
    return ret;
}

#if (TIMER0_INTERRUPT_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE)
void TIMER0_ISR(void)
{
    /*Clear flag*/
    TIMER0_InterruptClearFlag();

    /*Set pre-load value*/
    TMR0H = preloadValue >> 8;
    TMR0L = (uint8)(preloadValue);

    if (NULL != TIMER0_INTERRUTP_HANDELER)
    {
        TIMER0_INTERRUTP_HANDELER();
    }
}
#endif

Std_ReturnType timer0_DeInit(const timer0_t *_timer)
{
    Std_ReturnType ret = E_OK;
    if (NULL == _timer)
    {
        ret = E_NOT_OK;
    }
    else
    {
        /*disable module*/
        TIMER0_MODULE_DISABLE();
        /*disable interrupt*/
#if TIMER0_INTERRUPT_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE
        TIMER0_InterruptDisable();
#endif
    }
    return ret;
}
Std_ReturnType timer0_Wirte_value(const timer0_t *_timer, uint16 value)
{
    Std_ReturnType ret = E_OK;
    if (NULL == _timer)
    {
        ret = E_NOT_OK;
    }
    else
    {
        /*Set pre-load value*/
        TMR0H = value >> 8;
        TMR0L = (uint8)(value);
    }
    return ret;
}
Std_ReturnType timer0_Read_value(const timer0_t *_timer, uint16 *value)
{
    Std_ReturnType ret = E_OK;
    if (NULL == _timer || NULL == value)
    {
        ret = E_NOT_OK;
    }
    else
    {
        *value = 0;
        *value |= (((uint16)(TMR0H << 8)) | ((uint16)(TMR0L)));
    }
    return ret;
}

/*------------------------- Static helper functions ----------------------------------*/
static inline void timer0_prescaler_config(const timer0_t *_timer)
{
    switch (_timer->prescaler_enable)
    {
    case TIMER0_PRESCALER_FEATURE_ENABLE:
        TIMER0_PRESCALER_ENABLE();
        T0CONbits.T0PS = _timer->prescaler;
        break;

    case TIMER0_PRESCALER_FEATURE_DISABLE:
        TIMER0_PRESCALER_DISABLE();

        break;

    default:
        break;
    }
}

static inline void timer0_mode_config(const timer0_t *_timer)
{
    switch (_timer->tiemr0_mode)
    {
    case TIMER0_COUNTER_MODE:
        TIMER0_COUNTER_MODE_ENABLE();
        switch (_timer->counter_edge_select)
        {
        case TIMER0_RISING_EDGE:
            TIMER0_RISING_EDGE_ENABLE();
            break;

        case TIMER0_FALLING_EDGE:
            TIMER0_FALLING_EDGE_ENABLE();
            break;
        }
        break;

    case TIMER0_TIMER_MODE:
        TIMER0_TIMER_MODE_ENABLE();
        break;

    default:
        break;
    }
}

static inline void timer0_reg_size_config(const timer0_t *_timer)
{
    switch (_timer->timer0_reg_size)
    {
    case TIMER0_16BIT_MODE:
        TIMER0_16BIT_MODE_ENABLE();
        break;

    case TIMER0_8BIT_MODE:
        TIMER0_8BIT_MODE_ENABLE();
        break;

    default:
        break;
    }
}
/*------------------------------------------------------------------------------------*/