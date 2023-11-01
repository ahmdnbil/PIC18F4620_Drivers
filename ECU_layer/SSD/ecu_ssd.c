/**
 * @file ecu_ssd.c
 * @author Ahmed Nabil (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-10-31
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "./ecu_ssd.h"

Std_ReturnType ssd_initalize(const ssd_t *ssd)
{
    Std_ReturnType ret=E_OK;
    if(NULL == ssd)
    {
        ret=E_NOT_OK;
    }
    else
    {
        ret=gpio_pin_initalize(&(ssd->ssd_pins[SSD_PIN0]));
        ret=gpio_pin_initalize(&(ssd->ssd_pins[SSD_PIN1]));
        ret=gpio_pin_initalize(&(ssd->ssd_pins[SSD_PIN2]));
        ret=gpio_pin_initalize(&(ssd->ssd_pins[SSD_PIN3]));


    }
    return ret;
}
Std_ReturnType ssd_write_number(const ssd_t *ssd, uint8 number)
{
    Std_ReturnType ret=E_OK;
    if((NULL == ssd) || (number<=9))
    {
        ret=E_NOT_OK;
    }
    else
    {
        ret = gpio_pin_write_logic(&(ssd->ssd_pins[SSD_PIN0]), READ_BIT(number, SSD_PIN0));
        ret = gpio_pin_write_logic(&(ssd->ssd_pins[SSD_PIN1]), READ_BIT(number, SSD_PIN1));
        ret = gpio_pin_write_logic(&(ssd->ssd_pins[SSD_PIN2]), READ_BIT(number, SSD_PIN2));
        ret = gpio_pin_write_logic(&(ssd->ssd_pins[SSD_PIN3]), READ_BIT(number, SSD_PIN3));
    }
    return ret;
}
