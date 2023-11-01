/* 
 * File:   ecu_button.h
 * Author: User
 *
 * Created on October 26, 2023, 12:44 PM
 */

#ifndef ECU_BUTTON_H
#define	ECU_BUTTON_H

/* section includes*/
#include "./../../MCAL_layer/GPIO/hal_gpio.h"
#include "./ecu_button_cfg.h"

/* MACRO Declarations */

/* MACRO function declarations */

/* Data types*/
typedef enum 
{
    BUTTON_PRESSED,
    BUTTON_RELEASED
}button_status_t;

typedef enum
{
    BUTTON_ACTIVE_HIGH,
    BUTTON_ACTIVE_LOW
}button_active_t;

typedef struct
{
    pin_config_t button_pin;
    button_status_t button_staus;
    button_active_t button_active;
}button_t;

/*function declarations */

/**
 * @brief 
 * 
 * @param btn 
 * @return Std_ReturnType 
 */
Std_ReturnType button_initialize(const button_t* btn);
/**
 * @brief 
 * 
 * @param btn 
 * @return Std_ReturnType 
 */
Std_ReturnType button_read_state(const button_t*btn,button_status_t *btn_state);

#endif	/* ECU_BUTTON_H */

