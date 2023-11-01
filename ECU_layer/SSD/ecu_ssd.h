/**
 * @file ecu_ssd.h
 * @author Ahmed Nabil (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-10-31
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef ECU_SSD_H
#define	ECU_SSD_H

/*----------------------Section Includes----------------------------*/

#include "./../../MCAL_layer/GPIO/hal_gpio.h"
#include "./ecu_ssd_cfg.h"
/*----------------------MACRO declarations--------------------------*/
#define SSD_PIN0 0
#define SSD_PIN1 1
#define SSD_PIN2 2
#define SSD_PIN3 3
/*----------------------MACRO Functions-----------------------------*/
/*----------------------Data types----------------------------------*/
typedef enum
{
    SSD_COMMON_ANODE,
    SSD_COMMON_CATHODE
} segment_type_t;

typedef struct
{
    pin_config_t ssd_pins[4];
    segment_type_t ssd_type;
} ssd_t;
/*----------------------Function declarations-----------------------*/
Std_ReturnType ssd_initalize(const ssd_t *ssd);
Std_ReturnType ssd_write_number(const ssd_t *ssd,uint8 number);
#endif	/* ECU_SSD_H */

