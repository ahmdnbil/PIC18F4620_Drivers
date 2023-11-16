/**
 * @file hal_gpio.h
 * @author Ahmed Nabil
 * @brief 
 * @version 0.1
 * @date 2023-10-14
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef HAL_GPIO_H
#define	HAL_GPIO_H

/*----------------------------Section includes---------------------------------*/
#include "./../proc/pic18f4620.h"
#include "../mcal_std_types.h"
#include "../device_config.h"
#include "./hal_gpio_cfg.h"





/*----------------------------MACRO Functions----------------------------------*/
#define SET_BIT(reg,bitNo)    (reg|=(BIT_MASK<<bitNo))
#define CLR_BIT(reg,bitNo)    (reg&=~(BIT_MASK<<bitNo))
#define TOGGLE_BIT(reg,bitNo) (reg^=(BIT_MASK<<bitNo))
#define READ_BIT(reg,bitNo)   (reg >> bitNo) & BIT_MASK
/***********************MACRO declarations*******************************/
#define TRISE HWRREG8(0xF96)
#define TRISD HWRREG8(0xF95)
#define TRISC HWRREG8(0xF94)
#define TRISB HWRREG8(0xF93)
#define TRISA HWRREG8(0xF92)

#define LATE  HWRREG8(0xF8D)
#define LATD  HWRREG8(0xF8C)
#define LATC  HWRREG8(0xF8B)
#define LATB  HWRREG8(0xF8A)
#define LATA  HWRREG8(0xF89)

#define PORTE HWRREG8(0xF84)
#define PORTD HWRREG8(0xF83)
#define PORTC HWRREG8(0xF82)
#define PORTB HWRREG8(0xF81)
#define PORTA HWRREG8(0xF80)



#define BIT_MASK                (uint8)0x01
#define PORT_MASK               (uint8)0xFF
#define PORT_PIN_MAX_NUMBER     8
#define PORT_MAX_NUMBER         5
#define PORT_PIN_CONFIGURATIONS CONFIG_ENABLE
#define PORT_CONFIGURATIONS     CONFIG_ENABLE
/***********************Data types***************************************/
typedef enum{
    LOW=0,
    HIGH
}logic_t;

typedef enum{
    OUTPUT=0,
    INPUT
}direction_t;

typedef enum{
    PIN0=0,
    PIN1,
    PIN2,
    PIN3,
    PIN4,
    PIN5,
    PIN6,
    PIN7
}pin_index_t;


typedef enum{
    PORTA_INDEX=0,
    PORTB_INDEX,
    PORTC_INDEX,
    PORTD_INDEX,
    PORTE_INDEX,
}port_index_t;


typedef struct 
{
    uint8 port :3;     /* @ref port_index_t */
    uint8  pin :3;     /* @ref pin_index_t */
    uint8 direction:1; /* @ref direction_t */
    uint8 logic:1;     /* @ref logic_t */
}pin_config_t;

/***********************function declarations****************************/
Std_ReturnType gpio_pin_direction_initalize(const pin_config_t* _pin_config);
Std_ReturnType gpio_pin_get_direction_status(const pin_config_t* _pin_config,direction_t *direction_status);
Std_ReturnType gpio_pin_write_logic(const pin_config_t* _pin_config,logic_t logic);
Std_ReturnType gpio_pin_read_logic(const pin_config_t* _pin_config,logic_t *logic);
Std_ReturnType gpio_pin_toggle_logic(const pin_config_t* _pin_config);
Std_ReturnType gpio_pin_initalize(const pin_config_t* _pin_config);


Std_ReturnType gpio_port_direction_initalize(port_index_t port,uint8 direction);
Std_ReturnType gpio_port_get_direction_status(port_index_t port,uint8 *direction_status);
Std_ReturnType gpio_port_write_logic(port_index_t port,uint8 logic);
Std_ReturnType gpio_port_read_logic(port_index_t port,uint8 *logic);
Std_ReturnType gpio_port_toggle_logic(port_index_t port);


#endif	/* HAL_GPIO_H */

