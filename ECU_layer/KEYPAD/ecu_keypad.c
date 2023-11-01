/**
 * @file ecu_keypad.c
 * @author Ahmed Nabil (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-10-31
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "./ecu_keypad.h"

const uint8 btn_values[ECU_KEYPAD_COLS][ECU_KEYPAD_ROWS]={{'7','8','9','/'},{'4','5','6','*'},{'1','2','3','-'},{'#','0','=','+'}};
Std_ReturnType keypad_initalize(const keypad_t *keypad)
{
    Std_ReturnType ret=E_OK;
    if(NULL == keypad)
    {
        ret=E_NOT_OK;
    }
    else
    {
        ret=gpio_pin_initalize(&(keypad->keypad_row_pins[0]));
        ret=gpio_pin_initalize(&(keypad->keypad_row_pins[1]));
        ret=gpio_pin_initalize(&(keypad->keypad_row_pins[2]));
        ret=gpio_pin_initalize(&(keypad->keypad_row_pins[3]));

        ret = gpio_pin_direction_initalize(&(keypad->keypad_col_pins[0]));
        ret = gpio_pin_direction_initalize(&(keypad->keypad_col_pins[1]));
        ret = gpio_pin_direction_initalize(&(keypad->keypad_col_pins[2]));
        ret = gpio_pin_direction_initalize(&(keypad->keypad_col_pins[3]));
    }
    return ret;
}

Std_ReturnType keypad_get_value(const keypad_t *keypad, uint8 *value)
{
    Std_ReturnType ret = E_OK;
    uint8 rows_counter,cols_counter,l_counter,getValue;
    if (NULL == keypad || NULL == value)
    {
        ret = E_NOT_OK;
    }
    else
    {
        for(rows_counter=0;rows_counter<ECU_KEYPAD_ROWS;rows_counter++)
        {
            //make sure that each row is zero volt
            for(l_counter=0;l_counter<ECU_KEYPAD_ROWS;l_counter++)
            {
                ret=gpio_pin_write_logic(&(keypad->keypad_row_pins[l_counter]),LOW);
            }
            
            //activate the row which all columns will be checked based on
            ret=gpio_pin_write_logic(&(keypad->keypad_row_pins[rows_counter]),HIGH);
            for(cols_counter=0;cols_counter<ECU_KEYPAD_COLS;cols_counter++)
            {
                ret=gpio_pin_read_logic(&(keypad->keypad_col_pins[cols_counter]),&getValue);
                if(HIGH ==getValue)
                {
                    *value=btn_values[rows_counter][cols_counter];
                }
            }
            
        }
    }
    return ret;
}
