/**
 * @file application.h
 * @author Ahmed Nabil (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-10-29
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef APPLICATION_H
#define	APPLICATION_H


/* section includes*/

#include "./ECU_layer/ecu_layer_init.h"
#include "./MCAL_layer/interrupt/mcal_external_interrupt.h"
/* MACRO Declarations */
#define _XTAL_FREQ 4000000UL
/* MACRO function declarations */

/* Data types*/
//extern keypad_t keypad;
extern lcd_8bit_t lcd_8bit;
extern lcd_4bit_t lcd_4bit;

/*function declarations */

#endif	/* APPLICATION_H */

