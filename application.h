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
#include "./MCAL_layer/EEPROM/hal_eeprom.h"
#include "./MCAL_layer/ADC/hal_adc.h"
#include "./MCAL_layer/TIMER0/hal_timer0.h"
#include "./MCAL_layer/TIMER1/hal_timer1.h"
#include "./MCAL_layer/TIMER2/hal_timer2.h"
#include "./MCAL_layer/TIMER3/hal_timer3.h"
#include "MCAL_layer/CCP/hal_ccp.h"
#include "./MCAL_layer/USART/hal_usart.h"
#include "./MCAL_layer/I2C/hal_i2c.h"
#include "./MCAL_layer/SPI/hal_spi.h"
/* MACRO Declarations */
/* MACRO function declarations */

/* Data types*/
//extern keypad_t keypad;
extern lcd_8bit_t lcd_8bit;
extern lcd_4bit_t lcd_4bit;

/*function declarations */

#endif	/* APPLICATION_H */

