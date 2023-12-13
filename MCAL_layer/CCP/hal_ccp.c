/**
 * @file hal_ccp.c
 * @author Ahmed Nabil (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-11-26
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "./hal_ccp.h"

/*-----------------------------------Static functions-------------------------------------------*/
static void (*CCP1_OVF_INTERRUPT_HANDELER)(void) = NULL;
static void (*CCP2_OVF_INTERRUPT_HANDELER)(void) = NULL;
static inline void ccp_set_priority(const ccp_t *_ccp);
static void ccp_capture_mode_timer_select(const ccp_t *_ccp);
/*----------------------------------------------------------------------------------------------*/

Std_ReturnType CCP_Init(const ccp_t *_ccp_obj)
{
    Std_ReturnType ret = E_OK;
    if (NULL == _ccp_obj)
    {
        ret = E_NOT_OK;
    }
    else
    {
        /*
        note:
        ==> that CCP1 at PIN02 at PORTC

        ==> And CCP2 at PIN01 at PORTC or at PIN03 at PORTB
        and this depend on configurations bits
        */

        /*CCP module disabled*/
        switch (_ccp_obj->ccp_inst)
        {
        case CCP1_INST:
            CCP1_SET_MODE(CCP_MODULE_DISABLED);
            break;
        case CCP2_INST:
            CCP2_SET_MODE(CCP_MODULE_DISABLED);
            break;
        }

        if (CCP_CAPTURE_MODE_SELECTED == _ccp_obj->ccp_mode)
        {
            ccp_capture_mode_timer_select(&_ccp_obj);
            switch (_ccp_obj->ccp_inst)
            {

            case CCP1_INST:
                switch (_ccp_obj->ccp_mode_variant)
                {
                case CCP_CAPTURE_MODE_FALLING_EDGE:
                    CCP1_SET_MODE(CCP_CAPTURE_MODE_FALLING_EDGE);
                    break;
                case CCP_CAPTURE_MODE_RISING_EDGE:
                    CCP1_SET_MODE(CCP_CAPTURE_MODE_RISING_EDGE);
                    break;
                case CCP_CAPTURE_MODE_4_RISING_EDGE:
                    CCP1_SET_MODE(CCP_CAPTURE_MODE_4_RISING_EDGE);
                    break;
                case CCP_CAPTURE_MODE_16_RISING_EDGE:
                    CCP1_SET_MODE(CCP_CAPTURE_MODE_16_RISING_EDGE);
                    break;
                }
                TRISCbits.RC2 = INPUT;
                break;

            case CCP2_INST:
                switch (_ccp_obj->ccp_mode_variant)
                {
                case CCP_CAPTURE_MODE_FALLING_EDGE:
                    CCP2_SET_MODE(CCP_CAPTURE_MODE_FALLING_EDGE);
                    break;
                case CCP_CAPTURE_MODE_RISING_EDGE:
                    CCP2_SET_MODE(CCP_CAPTURE_MODE_RISING_EDGE);
                    break;
                case CCP_CAPTURE_MODE_4_RISING_EDGE:
                    CCP2_SET_MODE(CCP_CAPTURE_MODE_4_RISING_EDGE);
                    break;
                case CCP_CAPTURE_MODE_16_RISING_EDGE:
                    CCP2_SET_MODE(CCP_CAPTURE_MODE_16_RISING_EDGE);
                    break;
                }
                TRISCbits.RC1 = INPUT;
                break;
            }
        }
        else if (CCP_COMPARE_MODE_SELECTED == _ccp_obj->ccp_mode)
        {
            ccp_capture_mode_timer_select(&_ccp_obj);
            switch (_ccp_obj->ccp_inst)
            {

            case CCP1_INST:
                switch (_ccp_obj->ccp_mode_variant)
                {
                case CCP_COMPARE_MODE_TOGGLE_ON_MATCH:
                    CCP1_SET_MODE(CCP_COMPARE_MODE_TOGGLE_ON_MATCH);
                    break;
                case CCP_COMPARE_MODE_SET_PIN_LOW:
                    CCP1_SET_MODE(CCP_COMPARE_MODE_SET_PIN_LOW);
                    break;
                case CCP_COMPARE_MODE_SET_PIN_HIGH:
                    CCP1_SET_MODE(CCP_COMPARE_MODE_SET_PIN_HIGH);
                    break;
                case CCP_COMPARE_MODE_SW_INTERRUPT:
                    CCP1_SET_MODE(CCP_COMPARE_MODE_SW_INTERRUPT);
                    break;
                case CCP_COMPARE_MODE_GEN_EVENT:
                    CCP1_SET_MODE(CCP_COMPARE_MODE_GEN_EVENT);
                    break;
                }
                TRISCbits.RC2 = OUTPUT;
                break;

            case CCP2_INST:
                switch (_ccp_obj->ccp_mode_variant)
                {
                case CCP_COMPARE_MODE_TOGGLE_ON_MATCH:
                    CCP2_SET_MODE(CCP_COMPARE_MODE_TOGGLE_ON_MATCH);
                    break;
                case CCP_COMPARE_MODE_SET_PIN_LOW:
                    CCP2_SET_MODE(CCP_COMPARE_MODE_SET_PIN_LOW);
                    break;
                case CCP_COMPARE_MODE_SET_PIN_HIGH:
                    CCP2_SET_MODE(CCP_COMPARE_MODE_SET_PIN_HIGH);
                    break;
                case CCP_COMPARE_MODE_SW_INTERRUPT:
                    CCP2_SET_MODE(CCP_COMPARE_MODE_SW_INTERRUPT);
                    break;
                case CCP_COMPARE_MODE_GEN_EVENT:
                    CCP2_SET_MODE(CCP_COMPARE_MODE_GEN_EVENT);
                    break;
                }
                TRISCbits.RC1 = OUTPUT;
                break;
            }
        }
        else if (CCP_PWM_MODE_SELECTED == _ccp_obj->ccp_mode)
        {

            switch (_ccp_obj->ccp_inst)
            {
            case CCP1_INST:
                TRISCbits.RC2 = OUTPUT;
            case CCP2_INST:
                TRISCbits.RC1 = OUTPUT;
            }
            PR2 = (uint8)((_XTAL_FREQ / (_ccp_obj->PWM_Freq * 4.0 * _ccp_obj->timer2_prescaler_value * _ccp_obj->timer2_postscaler_value)) - 1);
        }
        else
        {
            /*nothing*/
        }

        /*interrupt configurations*/
        switch (_ccp_obj->ccp_inst)
        {
        case CCP1_INST:
#if CCP1_INTERRUPT_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE

            /*set call back*/
            CCP1_OVF_INTERRUPT_HANDELER = _ccp_obj->CCP_InterruptHandler;

            /*Clear flag*/
            CCP1_InterruptClearFlag();

            /*interrupt enable*/
            CCP1_InterruptEnable();

#if INTERRUPT_PRIORITY_LEVELS_ENABLE == INTERRUPT_PRIORITY_ENABLE
            ccp_set_priority(_ccp_obj);
#else
            /*enable global interrupt*/
            INTERRUPT_GlobalInterruptEnable();

            /*enable peripheral*/
            INTERRUPT_PeripheralInterruptEnable();
#endif
#endif

            break;

        case CCP2_INST:
#if CCP2_INTERRUPT_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE

            /*set call back*/
            CCP2_OVF_INTERRUPT_HANDELER = _ccp_obj->CCP_InterruptHandler;
            /*Clear flag*/
            CCP2_InterruptClearFlag();
            /*interrupt enable*/
            CCP2_InterruptEnable();

#if INTERRUPT_PRIORITY_LEVELS_ENABLE == INTERRUPT_PRIORITY_ENABLE
            ccp_set_priority(_ccp_obj);
#else
            /*enable global interrupt*/
            INTERRUPT_GlobalInterruptEnable();

            /*enable peripheral*/
            INTERRUPT_PeripheralInterruptEnable();
#endif
#endif

            break;
        }
    }
    return ret;
}

Std_ReturnType CCP_DeInit(const ccp_t *_ccp_obj)
{
    Std_ReturnType ret = E_OK;
    if (NULL == _ccp_obj)
    {
        ret = E_NOT_OK;
    }
    else
    {
        switch (_ccp_obj->ccp_inst)
        {
        case CCP1_INST:
            /*disable module*/
            CCP1_SET_MODE(CCP_MODULE_DISABLED);

            /*disable interrupt*/
#if CCP1_INTERRUPT_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE
            CCP1_InterruptDisable();
#endif
            break;

        case CCP2_INST:
            /*disable module*/
            CCP2_SET_MODE(CCP_MODULE_DISABLED);

            /*disable interrupt*/
#if CCP2_INTERRUPT_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE
            CCP2_InterruptDisable();
#endif
            break;

        default:
            break;
        }
    }
    return ret;
}

Std_ReturnType CCP_isCaptureDataReady(const ccp_t *_ccp_obj, uint8 *_capture_status)
{
    Std_ReturnType ret = E_OK;
    if (NULL == _capture_status || NULL == _ccp_obj)
    {
        ret = E_NOT_OK;
    }
    else
    {
        switch (_ccp_obj->ccp_inst)
        {
        case CCP1_INST:
            if (CCP_CAPTURE_READY == PIR1bits.CCP1IF)
            {
                *_capture_status = CCP_CAPTURE_READY;
                CCP1_InterruptClearFlag();
            }
            else
            {
                *_capture_status = CCP_CAPTURE_NOT_READY;
            }
            break;

        case CCP2_INST:
            if (CCP_CAPTURE_READY == PIR2bits.CCP2IF)
            {
                *_capture_status = CCP_CAPTURE_READY;
                CCP2_InterruptClearFlag();
            }
            else
            {
                *_capture_status = CCP_CAPTURE_NOT_READY;
            }
            break;

        default:
            break;
        }
    }
    return ret;
}

Std_ReturnType CCP_Capture_mode_read_value(const ccp_t *_ccp_obj, uint16 *capture_value)
{
    Std_ReturnType ret = E_OK;
    if (NULL == _ccp_obj || NULL == capture_value)
    {
        ret = E_NOT_OK;
    }
    else
    {

        *capture_value = (((uint16)(TMR3H << 8)) | ((uint16)(TMR3L)));
    }
    return ret;
}

Std_ReturnType CCP_isCompareComplete(const ccp_t *_ccp_obj, uint8 *_compare_status)
{
    Std_ReturnType ret = E_OK;
    if (NULL == _compare_status || NULL == _ccp_obj)
    {
        ret = E_NOT_OK;
    }
    else
    {
        switch (_ccp_obj->ccp_inst)
        {
        case CCP1_INST:
            if (CCP_COMPARE_READY == PIR1bits.CCP1IF)
            {
                *_compare_status = CCP_COMPARE_READY;
                CCP1_InterruptClearFlag();
            }
            else
            {
                *_compare_status = CCP_COMPARE_NOT_READY;
            }
            break;

        case CCP2_INST:
            if (CCP_COMPARE_READY == PIR2bits.CCP2IF)
            {
                *_compare_status = CCP_COMPARE_READY;
                CCP2_InterruptClearFlag();
            }
            else
            {
                *_compare_status = CCP_COMPARE_NOT_READY;
            }
            break;

        default:
            break;
        }
    }
    return ret;
}
Std_ReturnType CCP_Compare_Mode_Set_Value(const ccp_t *_ccp_obj, uint16 compare_value)
{
    Std_ReturnType ret = E_OK;
    if (NULL == _ccp_obj)
    {
        ret = E_NOT_OK;
    }
    else
    {
        switch (_ccp_obj->ccp_inst)
        {
        case CCP1_INST:
            CCPR1L = (uint8)(compare_value);
            CCPR1H = compare_value >> 8;
            break;

        case CCP2_INST:
            CCPR2L = (uint8)(compare_value);
            CCPR2H = compare_value >> 8;
            break;

        default:
            break;
        }
    }

    return ret;
}

Std_ReturnType CCP_PWM_Set_Duty(const ccp_t *_ccp_obj, const uint8 _duty)
{
    Std_ReturnType ret = E_OK;
    if (NULL == _ccp_obj)
    {
        ret = E_NOT_OK;
    }
    else
    {
        uint16 reg = (uint16)(4 * (PR2 + 1) * (_duty / 100.0));
        switch (_ccp_obj->ccp_inst)
        {
        case CCP1_INST:
            CCP1CONbits.DC1B = (uint8)(reg & 0x03);
            CCPR1L = (uint8)(reg >> 2);
            break;
        case CCP2_INST:
            CCP2CONbits.DC2B = (uint8)(reg & 0x03);
            CCPR2L = (uint8)(reg >> 2);
            break;
        }
    }

    return ret;
}
Std_ReturnType CCP_PWM_Start(ccp_t const *_ccp_obj)
{
    Std_ReturnType ret = E_OK;
    if (NULL == _ccp_obj)
    {
        ret = E_NOT_OK;
    }
    else
    {
        switch (_ccp_obj->ccp_inst)
        {
        case CCP1_INST:
            CCP1CONbits.CCP1M = CCP_PWM_MODE;
            break;
        case CCP2_INST:
            CCP2CONbits.CCP2M = CCP_PWM_MODE;
            break;
        }
    }

    return ret;
}
Std_ReturnType CCP_PWM_Stop(ccp_t const *_ccp_obj)
{
    Std_ReturnType ret = E_OK;
    if (NULL == _ccp_obj)
    {
        ret = E_NOT_OK;
    }
    {
        switch (_ccp_obj->ccp_inst)
        {
        case CCP1_INST:
            CCP1CONbits.CCP1M = CCP_MODULE_DISABLED;
            break;

        case CCP2_INST:
            CCP2CONbits.CCP2M = CCP_MODULE_DISABLED;
            break;
        }
    }
    return ret;
}

/*-----------------------------------Static functions-------------------------------------------*/
#if INTERRUPT_PRIORITY_LEVELS_ENABLE == INTERRUPT_PRIORITY_ENABLE
static inline void ccp_set_priority(const ccp_t *_ccp)
{
    INTERRUPT_PriorityLevelsEnable();
    switch (_ccp->priority)
    {

    case INTERRUPT_HIGH_PRIORITY:
        INTERRUPT_GlobalInterruptHighEnable();
        switch (_ccp->ccp_inst)
        {
        case CCP1_INST:
            CCP1_InterruptSetHighPriority();
            break;

        case CCP2_INST:
            CCP2_InterruptSetHighPriority();
            break;

        default:
            break;
        }
        break;

    case INTERRUPT_LOW_PRIORITY:
        INTERRUPT_GlobalInterruptLowEnable();
        switch (_ccp->ccp_inst)
        {
        case CCP1_INST:
            CCP1_InterruptSetLowPriority();
            break;

        case CCP2_INST:
            CCP2_InterruptSetLowPriority();
            break;
        }
        break;

    default:
        break;
    }
}
#endif

#if CCP1_INTERRUPT_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE
void CCP1_ISR()
{
    // clear flag
    CCP1_InterruptClearFlag();

    if (NULL != CCP1_OVF_INTERRUPT_HANDELER)
    {
        CCP1_OVF_INTERRUPT_HANDELER();
    }
}
#endif

#if CCP2_INTERRUPT_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE
void CCP2_ISR()
{
    // clear flag
    CCP2_InterruptClearFlag();

    if (NULL != CCP2_OVF_INTERRUPT_HANDELER)
    {
        CCP2_OVF_INTERRUPT_HANDELER();
    }
}
#endif

static void ccp_capture_mode_timer_select(const ccp_t *_ccp)
{
    switch (_ccp->ccp_capture_timer)
    {
    case CCP1_CCP2_T3:
        T3CONbits.T3CCP2 = 1;
        T3CONbits.T3CCP1 = 0;
        break;

    case CCP1_T1_CCP2_T3:
        T3CONbits.T3CCP2 = 0;
        T3CONbits.T3CCP1 = 1;
        break;

    case CCP1_CCP2_T1:
        T3CONbits.T3CCP2 = 0;
        T3CONbits.T3CCP1 = 0;
        break;

    default:
        break;
    }
}
/*----------------------------------------------------------------------------------------------*/