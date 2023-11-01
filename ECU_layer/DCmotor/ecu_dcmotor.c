/**
 * @file ecu_dcmotor.c
 * @author Ahmed Nabil (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-10-29
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "./ecu_dcmotor.h"

Std_ReturnType dc_motor_initialize(const dc_motor_t *_motor)
{
    Std_ReturnType ret=E_OK;
    if(NULL == _motor)
    {
        ret=E_NOT_OK;
    }
    else
    {
        pin_config_t pin1={
            .logic=_motor->dc_motor[0].dc_motor_status,
            .direction=OUTPUT,
            .port=_motor->dc_motor[0].dc_motor_port,
            .pin=_motor->dc_motor[0].dc_motor_pin,
        };
        pin_config_t pin2={
            .logic=_motor->dc_motor[1].dc_motor_status,
            .direction=OUTPUT,
            .port=_motor->dc_motor[1].dc_motor_port,
            .pin=_motor->dc_motor[1].dc_motor_pin,
        };
        ret=gpio_pin_initalize(&pin1);
        ret=gpio_pin_initalize(&pin2);
    }
    return ret;
}
Std_ReturnType dc_motor_move_right(const dc_motor_t *_motor)
{
    Std_ReturnType ret=E_OK;
    if(NULL == _motor)
    {
        ret=E_NOT_OK;
    }
    else
    {
        pin_config_t pin1 = {
            .logic = _motor->dc_motor[0].dc_motor_status,
            .direction = OUTPUT,
            .port = _motor->dc_motor[0].dc_motor_port,
            .pin = _motor->dc_motor[0].dc_motor_pin,
        };
        pin_config_t pin2 = {
            .logic = _motor->dc_motor[1].dc_motor_status,
            .direction = OUTPUT,
            .port = _motor->dc_motor[1].dc_motor_port,
            .pin = _motor->dc_motor[1].dc_motor_pin,
        };
        ret=gpio_pin_write_logic(&pin1,HIGH);
        ret=gpio_pin_write_logic(&pin2,LOW);
    }
    return ret;
}
Std_ReturnType dc_motor_move_left(const dc_motor_t *_motor)
{
    Std_ReturnType ret=E_OK;
    if(NULL == _motor)
    {
        ret=E_NOT_OK;
    }
    else
    {
        pin_config_t pin1 = {
            .logic = _motor->dc_motor[0].dc_motor_status,
            .direction = OUTPUT,
            .port = _motor->dc_motor[0].dc_motor_port,
            .pin = _motor->dc_motor[0].dc_motor_pin,
        };
        pin_config_t pin2 = {
            .logic = _motor->dc_motor[1].dc_motor_status,
            .direction = OUTPUT,
            .port = _motor->dc_motor[1].dc_motor_port,
            .pin = _motor->dc_motor[1].dc_motor_pin,
        };
        ret=gpio_pin_write_logic(&pin1,LOW);
        ret=gpio_pin_write_logic(&pin2,HIGH);

    }
    return ret;
}
Std_ReturnType dc_motor_stop(const dc_motor_t *_motor)
{
    Std_ReturnType ret=E_OK;
    if(NULL == _motor)
    {
        ret=E_NOT_OK;
    }
    else
    {
        pin_config_t pin1 = {
            .logic = _motor->dc_motor[0].dc_motor_status,
            .direction = OUTPUT,
            .port = _motor->dc_motor[0].dc_motor_port,
            .pin = _motor->dc_motor[0].dc_motor_pin,
        };
        pin_config_t pin2 = {
            .logic = _motor->dc_motor[1].dc_motor_status,
            .direction = OUTPUT,
            .port = _motor->dc_motor[1].dc_motor_port,
            .pin = _motor->dc_motor[1].dc_motor_pin,
        };
        ret = gpio_pin_write_logic(&pin1, LOW);
        ret = gpio_pin_write_logic(&pin2, LOW);
    }
    return ret;
}
