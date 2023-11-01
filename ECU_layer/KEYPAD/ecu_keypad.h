/**
 * @file ecu_keypad.h
 * @author Ahmed Nabil (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-10-31
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef ECU_KEYPAD_H
#define	ECU_KEYPAD_H

/*----------------------Section Includes----------------------------*/
#include "./../../MCAL_layer/GPIO/hal_gpio.h"
#include "./ecu_keypad.h"

/*----------------------MACRO declarations--------------------------*/
#define NOT_PRESSED 0x00U
/*----------------------MACRO Functions-----------------------------*/
#define ECU_KEYPAD_ROWS 4
#define ECU_KEYPAD_COLS 4
/*----------------------Data types----------------------------------*/
typedef struct
{
    pin_config_t keypad_row_pins[ECU_KEYPAD_ROWS];
    pin_config_t keypad_col_pins[ECU_KEYPAD_COLS];
}keypad_t;
/*----------------------Function declarations-----------------------*/
Std_ReturnType keypad_initalize(const keypad_t * keypad);
Std_ReturnType keypad_get_value(const keypad_t *keypad,uint8 *value);
#endif	/* ECU_KEYPAD_H */

