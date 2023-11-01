/**
 * @file ecu_relay.c
 * @author Ahmed Nabil (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-10-28
 * 
 * @copyright Copyright (c) 2023
 * 
 */


#include "./ecu_relay.h"

Std_ReturnType relay_initialize(const relay_t *_relay)
{
    Std_ReturnType ret=E_OK;
    if(NULL == _relay)
    {
        ret=E_NOT_OK;
    }
    else
    {
        pin_config_t pin=
        {
            .direction=OUTPUT,
            .logic=_relay->relay_status,
            .pin=_relay->relay_pin,
            .port=_relay->relay_port
        };
        ret=gpio_pin_initalize(&pin);
    }
    return ret;
}
Std_ReturnType relay_turn_on(const relay_t *_relay)
{
    Std_ReturnType ret=E_OK;
    if(NULL == _relay)
    {
        ret=E_NOT_OK;
    }
    else
    {
        pin_config_t pin=
        {
            .direction=OUTPUT,
            .logic=_relay->relay_status,
            .pin=_relay->relay_pin,
            .port=_relay->relay_port
        };
        ret=gpio_pin_write_logic(&pin,HIGH);
    }
    return ret;
}
Std_ReturnType relay_turn_off(const relay_t *_relay)
{
    Std_ReturnType ret=E_OK;
    if(NULL == _relay)
    {
        ret=E_NOT_OK;
    }
    else
    {
        pin_config_t pin=
        {
            .direction=OUTPUT,
            .logic=_relay->relay_status,
            .pin=_relay->relay_pin,
            .port=_relay->relay_port
        };
        ret=gpio_pin_write_logic(&pin,LOW);
    }
    return ret;
}
