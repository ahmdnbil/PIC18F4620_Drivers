/* 
 * File:   ecu_led.c
 * Author: Ahmed Nabil
 *
 * Created on October 11, 2023, 8:53 PM
 */


#include "ecu_led.h"

Std_ReturnType led_initalize(const led_t *led)
{
    Std_ReturnType status=E_OK;
    if(NULL == led)
    {
        status=E_NOT_OK;
    }
    else
    {
        pin_config_t pin_init={
            .port=led->port_name,
            .pin=led->pin,
            .direction=OUTPUT,
            .logic=led->led_status
        };
        gpio_pin_initalize(&pin_init);
    }
    return status;
}
Std_ReturnType led_turn_on(const led_t *led)
{
    Std_ReturnType status=E_OK;
    if(NULL == led)
    {
        status = E_NOT_OK;
    }
    else
    {
        pin_config_t pin_init = {
            .port = led->port_name,
            .pin = led->pin,
            .direction = OUTPUT,
            .logic = led->led_status
        };
        gpio_pin_write_logic(&pin_init,HIGH);
    }
    return status;
}

Std_ReturnType led_turn_off(const led_t *led)
{
    Std_ReturnType status = E_OK;
    if (NULL == led)
    {
        status = E_NOT_OK;
    }
    else
    {
        pin_config_t pin_init = {
            .port = led->port_name,
            .pin = led->pin,
            .direction = OUTPUT,
            .logic = led->led_status};
        gpio_pin_write_logic(&pin_init, LOW);
    }
    return status;
}

Std_ReturnType led_toggle(const led_t *led)
{
    Std_ReturnType status = E_OK;
    if (NULL == led)
    {
        status = E_NOT_OK;
    }
    else
    {
        pin_config_t pin_init = {
            .port = led->port_name,
            .pin = led->pin,
            .direction = OUTPUT,
            .logic = led->led_status};
        gpio_pin_toggle_logic(&pin_init);
    }
    return status;
}
