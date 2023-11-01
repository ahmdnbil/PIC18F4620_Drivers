/**
 * @file ecu_led.h
 * @author Ahmed Nabil (you@domain.com)
 * @brief
 * @version 0.1
 * @date October 11, 2023, 8:53 PM
 *
 * @copyright Copyright (c) 2023
 *
 */


#ifndef ECU_LED_H
#define	ECU_LED_H

/* section includes*/
#include "./../../MCAL_layer/GPIO/hal_gpio.h"
#include "./ecu_led_cfg.h"


/* MACRO Declarations */

/* MACRO function declarations */

/* Data types*/
typedef enum {
LED_OFF,
LED_ON
}led_status_t;

typedef struct{
    uint8 port_name:4;
    uint8 pin:3;
    uint8 led_status:1;
}led_t;
/*function declarations */

/**
 * @brief 
 * 
 * @param led 
 * @return Std_ReturnType 
 */
Std_ReturnType led_initalize(const led_t*led);
/**
 * @brief 
 * 
 * @param led 
 * @return Std_ReturnType 
 */
Std_ReturnType led_turn_on(const led_t*led);
/**
 * @brief 
 * 
 * @param led 
 * @return Std_ReturnType 
 */
Std_ReturnType led_turn_off(const led_t*led);
/**
 * @brief 
 * 
 * @param led 
 * @return Std_ReturnType 
 */
Std_ReturnType led_toggle(const led_t*led);

#endif	/* ECU_LED_H */

