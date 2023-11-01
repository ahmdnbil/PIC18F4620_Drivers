/**
 * @file ecu_layer_init.c
 * @author Ahmed Nabil (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-11-01
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "./ecu_layer_init.h"

keypad_t keypad =
    {
        .keypad_row_pins[0].direction = OUTPUT,
        .keypad_row_pins[0].logic = LOW,
        .keypad_row_pins[0].port = PORTC_INDEX,
        .keypad_row_pins[0].pin = PIN0,

        .keypad_row_pins[1].direction = OUTPUT,
        .keypad_row_pins[1].logic = LOW,
        .keypad_row_pins[1].port = PORTC_INDEX,
        .keypad_row_pins[1].pin = PIN1,

        .keypad_row_pins[2].direction = OUTPUT,
        .keypad_row_pins[2].logic = LOW,
        .keypad_row_pins[2].port = PORTC_INDEX,
        .keypad_row_pins[2].pin = PIN2,

        .keypad_row_pins[3].direction = OUTPUT,
        .keypad_row_pins[3].logic = LOW,
        .keypad_row_pins[3].port = PORTC_INDEX,
        .keypad_row_pins[3].pin = PIN3,

        .keypad_col_pins[0].direction = INPUT,
        .keypad_col_pins[0].logic = LOW,
        .keypad_col_pins[0].port = PORTC_INDEX,
        .keypad_col_pins[0].pin = PIN4,

        .keypad_col_pins[1].direction = INPUT,
        .keypad_col_pins[1].logic = LOW,
        .keypad_col_pins[1].port = PORTC_INDEX,
        .keypad_col_pins[1].pin = PIN5,

        .keypad_col_pins[2].direction = INPUT,
        .keypad_col_pins[2].logic = LOW,
        .keypad_col_pins[2].port = PORTC_INDEX,
        .keypad_col_pins[2].pin = PIN6,

        .keypad_col_pins[3].direction = INPUT,
        .keypad_col_pins[3].logic = LOW,
        .keypad_col_pins[3].port = PORTC_INDEX,
        .keypad_col_pins[3].pin = PIN7,
};