/**
 * @file ecu_button.c
 * @author Ahmed Nabil (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-10-26
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "./ecu_button.h"

Std_ReturnType button_initialize(const button_t *btn)
{
    Std_ReturnType ret=E_OK;
    if(NULL == btn)
    {
        ret=E_NOT_OK;
    }
    else
    {
        ret=gpio_pin_direction_initalize(&(btn->button_pin));

    }
    return ret;

}
Std_ReturnType button_read_state(const button_t *btn, button_status_t *btn_state)
{
    Std_ReturnType ret=E_OK;
    logic_t pin_logic = HIGH;
    if (NULL == btn || NULL == btn_state)
    {
        ret=E_NOT_OK;
    }
    else
    {
        ret=gpio_pin_read_logic(&(btn->button_pin),&pin_logic);
        if(BUTTON_ACTIVE_HIGH ==  btn->button_active)
        {
            if (HIGH == pin_logic) *btn_state= BUTTON_RELEASED;
            else
            {
                *btn_state = BUTTON_PRESSED;
            }
        }
        else
        {
            if (LOW == pin_logic) *btn_state= BUTTON_RELEASED;
            else
            {
                *btn_state = BUTTON_PRESSED;
            }

        }

    }
    return ret;

}