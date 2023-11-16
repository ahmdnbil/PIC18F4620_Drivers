/**
 * @file ecu_relay.h
 * @author Ahmed Nabil (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-10-28
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef ECU_RELAY_H
#define	ECU_RELAY_H

/*-------------------------------------section includes---------------------------------------*/
#include "./../../MCAL_layer/GPIO/hal_gpio.h"
#include "./ecu_relay_cfg.h"

/*---------------------------------------MACRO Declarations-----------------------------------*/
#define REALY_ON_STATUS  0x01U
#define REALY_OFF_STATUS 0x00U

/*---------------------------------------MACRO function declarations--------------------------*/

/*---------------------------------------Data types-------------------------------------------*/
typedef struct
{
    uint8 relay_port:4;
    uint8 relay_pin:3;
    uint8 relay_status:1;
}relay_t;

/*---------------------------------------function declarations--------------------------------*/
/**
 * @brief
 *      it will initiate the relay module for the specified pin
 * @param _relay
 * @return Std_ReturnType
 */
Std_ReturnType relay_initialize(const relay_t * _relay);
/**
 * @brief 
 * 
 * @param _relay 
 * @return Std_ReturnType 
 */
Std_ReturnType relay_turn_on(const relay_t * _relay);
/**
 * @brief 
 * 
 * @param _relay 
 * @return Std_ReturnType 
 */
Std_ReturnType relay_turn_off(const relay_t *_relay);
#endif	/* ECU_RELAY_H */

