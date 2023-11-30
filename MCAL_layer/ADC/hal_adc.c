/**
 * @file hal_adc.c
 * @author Ahmed Nabil (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-11-19
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "./hal_adc.h"

#if ADC_INTERRUPT_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE
static void (*ADC_INTERRUPT_HANDELER)(void) = NULL;
#endif

static inline Std_ReturnType adc_input_channel_port_configure(adc_channel_t channel);

Std_ReturnType ADC_Init(const adc_config_t *_adc)
{
    Std_ReturnType ret = E_OK;
    if (NULL == _adc)
    {
        ret = E_NOT_OK;
    }
    else
    {
        /*Disable ADC*/
        ADC_CONVERTER_DISABLE();

        /*Configure the Acquisition time*/
        ADCON2bits.ACQT = _adc->acq_time;

        /*Configure the conversion clock */
        ADCON2bits.ADCS = _adc->conv_clk;

        /*configure the default channel */
        ADCON0bits.CHS = _adc->channel;
        ret = adc_input_channel_port_configure(_adc->channel);

/*configure the interrupt*/
#if ADC_INTERRUPT_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE
        ADC_INTERRUPT_HANDELER = _adc->ADC_InterruptHandler;

#if INTERRUPT_PRIORITY_LEVELS_ENABLE == INTERRUPT_FEATURE_ENABLE
        switch (_adc->priority)
        {
        case INTERRUPT_LOW_PRIORITY:
            INTERRUPT_GlobalInterruptLowEnable();
            ADC_InterruptSetLowPriority();

            break;

        case INTERRUPT_HIGH_PRIORITY:
            INTERRUPT_GlobalInterruptHighEnable();
            ADC_InterruptSetHighPriority();
            break;
        }
#else
        INTERRUPT_GlobalInterruptEnable();
        INTERRUPT_PeripheralInterruptEnable();
#endif
        ADC_InterruptEnable();
        ADC_InterruptClearFlag();
#endif

        /*configure the result format*/
        switch (_adc->result_format)
        {
        case ADC_RESULT_RIGHT:
            ADC_RESULT_RIGHT_FORMAT();
            break;
        case ADC_RESULT_LEFT:
            ADC_RESULT_LEFT_FORMAT();
            break;
        }

        /*configure the voltage reference*/
        switch (_adc->voltage_ref)
        {
        case ADC_VOLTAGE_REFERANCE_ENABLED:
            ADC_ENABLE_VOLTAGE_REFERANCE();
            break;

        case ADC_VOLTAGE_REFERANCE_DISABLED:
            ADC_DISABLE_VOLTAGE_REFERANCE();
            break;
        }

        /*enable ADC*/
        ADC_CONVERTER_ENABLE();
    }
    return ret;
}

#if ADC_INTERRUPT_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE
void ADC_ISR()
{
    // clear the falg
    ADC_InterruptClearFlag();
    if (NULL != ADC_INTERRUPT_HANDELER)
    {
        ADC_INTERRUPT_HANDELER();
    }
}
#endif
Std_ReturnType ADC_DeInit(const adc_config_t *_adc)
{
    Std_ReturnType ret = E_OK;
    if (NULL == _adc)
    {
        ret = E_NOT_OK;
    }
    else
    {
        /*disable the module*/
        ADC_CONVERTER_DISABLE();

/*disable interrupt*/
#if ADC_INTERRUPT_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE
        ADC_InterruptDisable();
#endif
    }
    return ret;
}
Std_ReturnType ADC_SelectChannel(const adc_config_t *_adc, adc_channel_t channel)
{
    Std_ReturnType ret = E_OK;
    if (NULL == _adc)
    {
        ret = E_NOT_OK;
    }
    else
    {
        ADCON0bits.CHS = channel;
        ret = adc_input_channel_port_configure(channel);
    }
    return ret;
}

Std_ReturnType ADC_StartConversion(const adc_config_t *_adc)
{
    Std_ReturnType ret = E_OK;
    if (NULL == _adc)
    {
        ret = E_NOT_OK;
    }
    else
    {
        ADC_START_CONVERSION();
    }
    return ret;
}
Std_ReturnType ADC_IsConversionDone(const adc_config_t *_adc, uint8 *conversion_status)
{
    Std_ReturnType ret = E_OK;
    if (NULL == _adc || NULL == conversion_status)
    {
        ret = E_NOT_OK;
    }
    else
    {
        *conversion_status = !(ADC_CONVERSION_STATUS());
    }
    return ret;
}
Std_ReturnType ADC_GetConversionResult(const adc_config_t *_adc, uint16 *reading)
{
    Std_ReturnType ret = E_OK;
    if ((NULL == _adc) || (NULL == reading))
    {
        ret = E_NOT_OK;
    }
    else
    {
        *reading = 0;
        switch (_adc->result_format)
        {
        case ADC_RESULT_RIGHT:
            *reading |= ((uint16)ADRESL | ((uint16)((ADRESH & 0b11) << 8)));
            break;
        case ADC_RESULT_LEFT:
            *reading |= ((uint16)((ADRESL & 0b11000000) >> 6) | (uint16)(ADRESH << 2));
            break;
        }
    }
    return ret;
}
Std_ReturnType ADC_GetConversion_Blocking(const adc_config_t *_adc, adc_channel_t channel, uint16 *reading)
{
    Std_ReturnType ret = E_OK;
    uint8 conversion_status = 0;
    if ((NULL == _adc) || (NULL == reading))
    {
        ret = E_NOT_OK;
    }
    else
    {
        ret = ADC_SelectChannel(_adc, channel);
        ret = ADC_StartConversion(_adc);
        ret = ADC_IsConversionDone(_adc, &conversion_status);
        while (ADC_CONVERSION_INPROGRESS == conversion_status)
        {
            ret = ADC_IsConversionDone(_adc, &conversion_status);
        }
        ret = ADC_GetConversionResult(_adc, reading);
    }
    return ret;
}

Std_ReturnType ADC_StartConversion_Interrupt(const adc_config_t *_adc, adc_channel_t channel)
{
    Std_ReturnType ret = E_OK;
    if (NULL == _adc)
    {
        ret = E_NOT_OK;
    }
    else
    {
        ret = ADC_SelectChannel(_adc, channel);
        ret = ADC_StartConversion(_adc);
    }
    return ret;
}

static inline Std_ReturnType adc_input_channel_port_configure(adc_channel_t channel)
{
    Std_ReturnType ret = E_OK;
    pin_config_t pin = {
        .direction = INPUT,
        .logic = LOW,
    };
    switch (channel)
    {
    case ADC_CHANNEL_AN0:
        pin.pin = PIN0;
        pin.port = PORTA_INDEX;
        break;

    case ADC_CHANNEL_AN1:
        pin.pin = PIN1;
        pin.port = PORTA_INDEX;
        break;

    case ADC_CHANNEL_AN2:
        pin.pin = PIN2;
        pin.port = PORTA_INDEX;
        break;

    case ADC_CHANNEL_AN3:
        pin.pin = PIN3;
        pin.port = PORTA_INDEX;
        break;

    case ADC_CHANNEL_AN4:
        pin.pin = PIN5;
        pin.port = PORTA_INDEX;
        break;

    case ADC_CHANNEL_AN5:
        pin.pin = PIN0;
        pin.port = PORTE_INDEX;
        break;

    case ADC_CHANNEL_AN6:
        pin.pin = PIN1;
        pin.port = PORTE_INDEX;
        break;

    case ADC_CHANNEL_AN7:
        pin.pin = PIN2;
        pin.port = PORTE_INDEX;
        break;

    case ADC_CHANNEL_AN8:
        pin.pin = PIN2;
        pin.port = PORTB_INDEX;
        break;

    case ADC_CHANNEL_AN9:
        pin.pin = PIN3;
        pin.port = PORTB_INDEX;
        break;

    case ADC_CHANNEL_AN10:
        pin.pin = PIN1;
        pin.port = PORTB_INDEX;
        break;

    case ADC_CHANNEL_AN11:
        pin.pin = PIN4;
        pin.port = PORTB_INDEX;
        break;

    case ADC_CHANNEL_AN12:
        pin.pin = PIN0;
        pin.port = PORTB_INDEX;
        break;
    }
    ret = gpio_pin_direction_initalize(&pin);
    return ret;
}