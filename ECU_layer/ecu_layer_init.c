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

//keypad_t keypad =
//    {
//        .keypad_row_pins[0].direction = OUTPUT,
//        .keypad_row_pins[0].logic = LOW,
//        .keypad_row_pins[0].port = PORTC_INDEX,
//        .keypad_row_pins[0].pin = PIN0,
//
//        .keypad_row_pins[1].direction = OUTPUT,
//        .keypad_row_pins[1].logic = LOW,
//        .keypad_row_pins[1].port = PORTC_INDEX,
//        .keypad_row_pins[1].pin = PIN1,
//
//        .keypad_row_pins[2].direction = OUTPUT,
//        .keypad_row_pins[2].logic = LOW,
//        .keypad_row_pins[2].port = PORTC_INDEX,
//        .keypad_row_pins[2].pin = PIN2,
//
//        .keypad_row_pins[3].direction = OUTPUT,
//        .keypad_row_pins[3].logic = LOW,
//        .keypad_row_pins[3].port = PORTC_INDEX,
//        .keypad_row_pins[3].pin = PIN3,
//
//        .keypad_col_pins[0].direction = INPUT,
//        .keypad_col_pins[0].logic = LOW,
//        .keypad_col_pins[0].port = PORTC_INDEX,
//        .keypad_col_pins[0].pin = PIN4,
//
//        .keypad_col_pins[1].direction = INPUT,
//        .keypad_col_pins[1].logic = LOW,
//        .keypad_col_pins[1].port = PORTC_INDEX,
//        .keypad_col_pins[1].pin = PIN5,
//
//        .keypad_col_pins[2].direction = INPUT,
//        .keypad_col_pins[2].logic = LOW,
//        .keypad_col_pins[2].port = PORTC_INDEX,
//        .keypad_col_pins[2].pin = PIN6,
//
//        .keypad_col_pins[3].direction = INPUT,
//        .keypad_col_pins[3].logic = LOW,
//        .keypad_col_pins[3].port = PORTC_INDEX,
//        .keypad_col_pins[3].pin = PIN7,
//};

lcd_8bit_t lcd_8bit=
{
    .lcd_rs.port=PORTC_INDEX,
    .lcd_rs.pin=PIN6,
    .lcd_rs.direction=OUTPUT,
    .lcd_rs.logic=LOW,
    
    .lcd_en.port=PORTC_INDEX,
    .lcd_en.pin=PIN7,
    .lcd_en.direction=OUTPUT,
    .lcd_en.logic=LOW,
    
    .lcd_data[0].port=PORTD_INDEX,
    .lcd_data[0].pin=PIN0,
    .lcd_data[0].direction=OUTPUT,
    .lcd_data[0].logic=LOW,
    
    .lcd_data[1].port=PORTD_INDEX,
    .lcd_data[1].pin=PIN1,
    .lcd_data[1].direction=OUTPUT,
    .lcd_data[1].logic=LOW,
    
    .lcd_data[2].port=PORTD_INDEX,
    .lcd_data[2].pin=PIN2,
    .lcd_data[2].direction=OUTPUT,
    .lcd_data[2].logic=LOW,
    
    .lcd_data[3].port=PORTD_INDEX,
    .lcd_data[3].pin=PIN3,
    .lcd_data[3].direction=OUTPUT,
    .lcd_data[3].logic=LOW,
    
    .lcd_data[4].port=PORTD_INDEX,
    .lcd_data[4].pin=PIN4,
    .lcd_data[4].direction=OUTPUT,
    .lcd_data[4].logic=LOW,
    
    .lcd_data[5].port=PORTD_INDEX,
    .lcd_data[5].pin=PIN5,
    .lcd_data[5].direction=OUTPUT,
    .lcd_data[5].logic=LOW,
    
    .lcd_data[6].port=PORTD_INDEX,
    .lcd_data[6].pin=PIN6,
    .lcd_data[6].direction=OUTPUT,
    .lcd_data[6].logic=LOW,
    
    .lcd_data[7].port=PORTD_INDEX,
    .lcd_data[7].pin=PIN7,
    .lcd_data[7].direction=OUTPUT,
    .lcd_data[7].logic=LOW
};

lcd_4bit_t lcd_4bit=
{
    .lcd_rs.port=PORTC_INDEX,
    .lcd_rs.pin=PIN0,
    .lcd_rs.direction=OUTPUT,
    .lcd_rs.logic=LOW,
    
    .lcd_en.port=PORTC_INDEX,
    .lcd_en.pin=PIN1,
    .lcd_en.direction=OUTPUT,
    .lcd_en.logic=LOW,
    
    .lcd_data[0].port=PORTC_INDEX,
    .lcd_data[0].pin=PIN2,
    .lcd_data[0].direction=OUTPUT,
    .lcd_data[0].logic=LOW,
    
    .lcd_data[1].port=PORTC_INDEX,
    .lcd_data[1].pin=PIN3,
    .lcd_data[1].direction=OUTPUT,
    .lcd_data[1].logic=LOW,
    
    .lcd_data[2].port=PORTC_INDEX,
    .lcd_data[2].pin=PIN4,
    .lcd_data[2].direction=OUTPUT,
    .lcd_data[2].logic=LOW,
    
    .lcd_data[3].port=PORTC_INDEX,
    .lcd_data[3].pin=PIN5,
    .lcd_data[3].direction=OUTPUT,
    .lcd_data[3].logic=LOW,
};