/* 
 * File:   ecu_led.h
 * Author: User
 *
 * Created on October 11, 2023, 9:26 PM
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

