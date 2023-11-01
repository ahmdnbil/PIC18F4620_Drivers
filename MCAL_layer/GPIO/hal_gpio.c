/**
 * @file hal_gpio.c
 * @author Ahmed Nabil
 * @brief 
 * @version 0.1
 * @date 2023-10-14
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "./hal_gpio.h"

// reference to the data direction
volatile uint8 *tris_registers[] ={&TRISA,&TRISB,&TRISC,&TRISD,&TRISE};
volatile uint8 *lat_registers[] ={&LATA,&LATB,&LATC,&LATD,&LATE};
volatile uint8 *port_registers[] ={&PORTA,&PORTB,&PORTC,&PORTD,&PORTE};


/**
 * @brief 
 * it iniate register TRIS with information provided by user as pointer to structure
 * @param _pin_config 
 * @return Std_ReturnType 
 */

#if (PORT_PIN_CONFIGURATIONS == CONFIG_ENABLE)
Std_ReturnType gpio_pin_direction_initalize(const pin_config_t* _pin_config)
{
    Std_ReturnType status=E_OK;
    
    if(NULL==_pin_config || _pin_config->pin > PORT_PIN_MAX_NUMBER-1 || _pin_config->port > PORT_MAX_NUMBER-1)
    {
        status =E_NOT_OK;
    }
    else{
        switch (_pin_config->direction)
        {
            case OUTPUT: CLR_BIT(*tris_registers[_pin_config->port],_pin_config->pin);
            break;
            case INPUT:  SET_BIT(*tris_registers[_pin_config->port],_pin_config->pin);
            break;
            default: status=E_NOT_OK;
            break;
        }
    }
    return status;
}
#endif


/**
 * @brief 
 * it reads the status of pin of register to return one or zeros for input or output
 * @param _pin_config 
 * @param direction_status 
 * @return Std_ReturnType 
 */
#if (PORT_PIN_CONFIGURATIONS == CONFIG_ENABLE)
Std_ReturnType gpio_pin_get_direction_status(const pin_config_t* _pin_config,direction_t *direction_status)
{
    Std_ReturnType status=E_OK;
    if(NULL==_pin_config || NULL ==direction_status || _pin_config->pin > PORT_PIN_MAX_NUMBER-1 || _pin_config->port > PORT_MAX_NUMBER-1)
    {
        status=E_NOT_OK;
    }
    else{
        *direction_status=READ_BIT(*tris_registers[_pin_config->port],_pin_config->pin);
    }
    return status;
}
#endif

#if (PORT_PIN_CONFIGURATIONS == CONFIG_ENABLE)
/**
 * @brief 
 * 
 * @param _pin_config 
 * @param logic 
 * @return Std_ReturnType 
 */
Std_ReturnType gpio_pin_write_logic(const pin_config_t* _pin_config,logic_t logic)
{
    Std_ReturnType status=E_OK;
    if(NULL==_pin_config || _pin_config->pin > PORT_PIN_MAX_NUMBER-1 || _pin_config->port > PORT_MAX_NUMBER-1)
    {
        status=E_NOT_OK;
    }
    else{
        switch(logic)
        {
            case HIGH:
            SET_BIT(*lat_registers[_pin_config->port],_pin_config->pin);
            break;
            
            case LOW:
            CLR_BIT(*lat_registers[_pin_config->port],_pin_config->pin);
            break;
            
            default: status=E_NOT_OK;
            break;
        }
    }
    return status;
}
#endif

#if (PORT_PIN_CONFIGURATIONS == CONFIG_ENABLE)
/**
 * @brief 
 * 
 * @param _pin_config 
 * @param logic 
 * @return Std_ReturnType 
 */
Std_ReturnType gpio_pin_read_logic(const pin_config_t* _pin_config,logic_t *logic)
{
    Std_ReturnType status=E_OK;
    if(NULL==_pin_config || NULL == logic || _pin_config->pin > PORT_PIN_MAX_NUMBER-1 || _pin_config->port > PORT_MAX_NUMBER-1)
    {
        status=E_NOT_OK;
    }
    else{
        *logic=READ_BIT(*port_registers[_pin_config->port],_pin_config->pin);
    }
    return status;
}
#endif

#if (PORT_PIN_CONFIGURATIONS == CONFIG_ENABLE)
/**
 * @brief 
 * 
 * @param _pin_config 
 * @return Std_ReturnType 
 */
Std_ReturnType gpio_pin_toggle_logic(const pin_config_t* _pin_config)
{
    Std_ReturnType status=E_OK;
    if(NULL==_pin_config || _pin_config->pin > PORT_PIN_MAX_NUMBER-1 || _pin_config->port > PORT_MAX_NUMBER-1)
    {
        status=E_NOT_OK;
    }
    else{
        TOGGLE_BIT(*lat_registers[_pin_config->port],_pin_config->pin);
    }
    return status;
}
#endif


#if (PORT_PIN_CONFIGURATIONS == CONFIG_ENABLE)
/**
 * @brief 
 * 
 * @param _pin_config 
 * @return Std_ReturnType 
 */
Std_ReturnType gpio_pin_initalize(const pin_config_t* _pin_config)
{
    Std_ReturnType ret=E_OK;
    if(NULL == _pin_config)
    {
        ret=E_NOT_OK;
    }
    else
    {
        ret=gpio_pin_direction_initalize(_pin_config);
        ret=gpio_pin_write_logic(_pin_config,_pin_config->logic);
    }
    return ret;
}
#endif


#if PORT_CONFIGURATIONS == CONFIG_ENABLE
/**
 * @brief 
 * 
 * @param port 
 * @param direction 
 * @return Std_ReturnType 
 */
Std_ReturnType gpio_port_direction_initalize(port_index_t port,uint8 direction)
{
    Std_ReturnType status=E_OK;
    if(port > PORT_MAX_NUMBER-1)
    {
        status=E_NOT_OK;
    }
    else
    {
        *tris_registers[port]=direction;
    }
    return status;
}
#endif

#if PORT_CONFIGURATIONS == CONFIG_ENABLE
/**
 * @brief 
 * 
 * @param port 
 * @param direction_status 
 * @return Std_ReturnType 
 */
Std_ReturnType gpio_port_get_direction_status(port_index_t port,uint8 *direction_status)
{
    Std_ReturnType status=E_OK;
    if(NULL ==direction_status || port > PORT_MAX_NUMBER -1)
    {
        status=E_NOT_OK;
    }
    else{
        *direction_status = *tris_registers[port];
    }
    return status;
}
#endif

#if PORT_CONFIGURATIONS == CONFIG_ENABLE
/**
 * @brief 
 * 
 * @param port 
 * @param logic 
 * @return Std_ReturnType 
 */
Std_ReturnType gpio_port_write_logic(port_index_t port,uint8 logic)
{
    Std_ReturnType status=E_OK;
    if(port > PORT_MAX_NUMBER -1)
    {
        status = E_NOT_OK;
    }
    else
    {
        *lat_registers[port]=logic;
    }
    return status;
}
#endif

#if PORT_CONFIGURATIONS == CONFIG_ENABLE
/**
 * @brief 
 * 
 * @param port 
 * @param logic 
 * @return Std_ReturnType 
 */
Std_ReturnType gpio_port_read_logic(port_index_t port,uint8 *logic)
{
    Std_ReturnType status=E_OK;
    if(NULL ==logic || port > PORT_MAX_NUMBER -1)
    {
        status=E_NOT_OK;
    }
    else{
        *logic=*lat_registers[port];
    }
    return status;
}
#endif


#if PORT_CONFIGURATIONS == CONFIG_ENABLE
/**
 * @brief 
 * 
 * @param port 
 * @return Std_ReturnType 
 */
Std_ReturnType gpio_port_toggle_logic(port_index_t port)
{
    Std_ReturnType status=E_OK;
    if(port>PORT_MAX_NUMBER-1)
    {
        status=E_NOT_OK;
    }
    else
    {
        *lat_registers[port]^=PORT_MASK;
    }
    return status;
}
#endif