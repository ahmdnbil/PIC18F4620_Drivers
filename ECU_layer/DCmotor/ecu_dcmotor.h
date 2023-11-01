/**
 * @file ecu_dcmotor.h
 * @author Ahmed Nabil (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-10-29
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef ECU_DCMOTOR_H
#define	ECU_DCMOTOR_H

/***********************Section includes*********************************/
#include "./../../MCAL_layer/GPIO/hal_gpio.h"
#include "./ecu_dcmotor_cfg.h"
/***********************MACRO declarations*******************************/
#define DC_MOTOR_ON  0x01U
#define DC_MOTOR_OFF 0x00U
/***********************MACRO Functions**********************************/
/***********************Data types***************************************/
typedef struct 
{
    uint8 dc_motor_port:4;
    uint8 dc_motor_pin:3;
    uint8 dc_motor_status:1;
    
}dc_motor_pin_t;

typedef struct 
{
    dc_motor_pin_t dc_motor[2];

}dc_motor_t;

/***********************function declarations****************************/
Std_ReturnType dc_motor_initialize(const dc_motor_t * _motor);
Std_ReturnType dc_motor_move_right(const dc_motor_t * _motor);
Std_ReturnType dc_motor_move_left(const dc_motor_t * _motor);
Std_ReturnType dc_motor_stop(const dc_motor_t * _motor);

#endif	/* ECU_DCMOTOR_H */

