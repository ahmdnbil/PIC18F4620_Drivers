/**
 * @file hal_i2c.c
 * @author Ahmed Nabil (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-12-10
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "./hal_i2c.h"

/*----------------------------------Helper Functions-------------------------------------*/
static inline void mssp_i2c_select_mode(const mssp_i2c_t *_i2c);
static inline void mssp_interrupt_handler_cfg(const mssp_i2c_t *_i2c);
static void (*I2C_DEFAULT_INTERRUPT_HANDLER)(void) = NULL;
static void (*I2C_OVERFLOW_INTERRUPT_HANDLER)(void) = NULL;
static void (*I2C_WRITE_COLLISION_INTERRUPT_HANDLER)(void) = NULL;
/*---------------------------------------------------------------------------------------*/

Std_ReturnType MSSP_I2C_Init(const mssp_i2c_t *_i2c)
{
    Std_ReturnType ret = E_OK;
    if (NULL == _i2c)
    {
        ret = E_NOT_OK;
    }
    else
    {
        /*disable MSSP module*/
        MSSP_MODULE_DISABLE();

        /*MSSP I2C select mode*/
        mssp_i2c_select_mode(_i2c);

        /*MSSP I2C Slew Rate Control*/
        switch (_i2c->i2c_config.i2c_slew_rate)
        {
        case I2C_SLEW_RATE_DISABLE:
            I2C_SLEW_RATE_MODE_DISABLE();
            break;

        case I2C_SLEW_RATE_ENBLE:
            I2C_SLEW_RATE_MODE_ENBLE();
            break;

        default:
            break;
        }

        /*MSSP I2C SMBus Control*/
        switch (_i2c->i2c_config.i2c_SMBus_control)
        {
        case I2C_SMBUS_ENABLE:
            I2C_SMBUS_MODE_ENABLE();
            break;

        case I2C_SMBUS_DISABLE:
            I2C_SMBUS_MODE_DISABLE();
            break;

        default:
            break;
        }

        /*Interrupt Configurations*/
        mssp_interrupt_handler_cfg(_i2c);

        /*Enable MSSP I2C Module*/
        MSSP_MODULE_ENABLE();
    }
    return ret;
}
Std_ReturnType MSSP_I2C_DeInit(const mssp_i2c_t *_i2c)
{
    Std_ReturnType ret = E_OK;
    if (NULL == _i2c)
    {
        ret = E_NOT_OK;
    }
    else
    {
        MSSP_MODULE_DISABLE();
#if MSSP_INTERRUPT_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE
        MSSP_InterruptDisable();
        MSSP_BusCollisionInterruptDisable();
#endif
    }
    return ret;
}

Std_ReturnType MSSP_I2C_Master_Send_Start(const mssp_i2c_t *_i2c)
{
    Std_ReturnType ret = E_OK;
    if (NULL == _i2c)
    {
        ret = E_NOT_OK;
    }
    else
    {
        /*Initiates Start Condition on SDA And SCL pins*/
        SSPCON2bits.SEN = 1;
        /*wait for the completion of the Start Condition*/
        while (SSPCON2bits.SEN)
            ;
        /*clear MSSP interrupt*/
        PIR1bits.SSPIF = 0;
        /*Report the Start Condition Detection*/
        if (I2C_START_BIT_DETECTED == I2C_START_BIT_STATUS())
        {
            ret = E_OK;
        }
        else
        {
            ret = E_NOT_OK;
        }
    }
    return ret;
}
Std_ReturnType MSSP_I2C_Master_Send_Repeated_Start(const mssp_i2c_t *_i2c)
{
    Std_ReturnType ret = E_OK;
    if (NULL == _i2c)
    {
        ret = E_NOT_OK;
    }
    else
    {
        /*Initiates Start Condition on SDA And SCL pins*/
        SSPCON2bits.RSEN = 1;
        /*wait for the completion of the Start Condition*/
        while (SSPCON2bits.RSEN)
            ;
        /*clear MSSP interrupt*/
        PIR1bits.SSPIF = 0;
    }
    return ret;
}
Std_ReturnType MSSP_I2C_Master_Send_Stop(const mssp_i2c_t *_i2c)
{
    Std_ReturnType ret = E_OK;
    if (NULL == _i2c)
    {
        ret = E_NOT_OK;
    }
    else
    {
        /*Initiates Stop Condition on SDA And SCL pins*/
        SSPCON2bits.PEN = 1;
        /*wait for the completion of the Stop Condition*/
        while (SSPCON2bits.PEN)
            ;
        /*clear MSSP interrupt*/
        PIR1bits.SSPIF = 0;
        /*Report the Stop Condition Detection*/
        if (I2C_STOP_BIT_DETECTED == I2C_STOP_BIT_STATUS())
        {
            ret = E_OK;
        }
        else
        {
            ret = E_NOT_OK;
        }
    }
    return ret;
}
Std_ReturnType MSSP_I2C_Master_Write_Blocking(const mssp_i2c_t *_i2c, uint8 data, uint8 *ack)
{
    Std_ReturnType ret = E_OK;
    if (NULL == _i2c)
    {
        ret = E_NOT_OK;
    }
    else
    {
        /*Write Data to the data register*/
        SSPBUF = data;
        /*Wait transmission to be completed*/
        while (!PIR1bits.SSPIF)
            ;
        /*Clear MSSP interrupt flag*/
        PIR1bits.SSPIF = 0;
        /*report data*/
        if (MSSP_MASTER_RECEIVE_ACK == SSPCON2bits.ACKSTAT)
        {
            *ack = MSSP_MASTER_RECEIVE_ACK;
            ret = E_OK;
        }
        else
        {
            *ack = MSSP_MASTER_RECEIVE_NOT_ACK;
            ret = E_NOT_OK;
        }
    }
    return ret;
}
Std_ReturnType MSSP_I2C_Master_Read_Blocking(const mssp_i2c_t *_i2c, uint8 ack, uint8 *data)
{
    Std_ReturnType ret = E_OK;
    if (NULL == _i2c || NULL == data)
    {
        ret = E_NOT_OK;
    }
    else
    {
        /*Master mode Receive Enable*/
        switch (_i2c->i2c_config.i2c_master_rec_mode)
        {
        case I2C_RECEIVE_ENABLE:
            I2C_RECEIVE_MODE_ENABLE();
            break;

        case I2C_RECEIVE_DISABLE:
            I2C_RECEIVE_MODE_DISABLE();
            break;
        }

        /*Wait for buffer full flag*/
        while (!I2C_BUFFER_FULL_STATUS())
            ;

        /*copy the data register to buffer variables*/
        *data = SSPBUF;

        /*Send ACK or NACK after read*/
        switch (ack)
        {
        case MSSP_MASTER_RECEIVE_MODE_SEND_ACK:
            SSPCON2bits.ACKEN = MSSP_MASTER_SEND_ACK_ENABLE;
            SSPCON2bits.ACKDT = MSSP_MASTER_RECEIVE_MODE_SEND_ACK;
            break;

        default:
            SSPCON2bits.ACKEN = MSSP_MASTER_SEND_ACK_ENABLE;
            SSPCON2bits.ACKDT = MSSP_MASTER_RECEIVE_MODE_SEND_NACK;
            break;
        }
    }
    return ret;
}

/*----------------------------------Helper Functions-------------------------------------*/
static inline void mssp_i2c_select_mode(const mssp_i2c_t *_i2c)
{
    switch (_i2c->i2c_config.i2c_mode)
    {
    case MSSP_I2C_MASTER_MODE:
        /*I2C Master mode Clock configurations*/
        SSPADD = (uint8)(((_XTAL_FREQ / 4.0) / _i2c->i2c_clk) - 1);

        /*I2C Master mode Configurations*/
        I2C_SET_MODE(_i2c->i2c_config.i2c_mode_config);
        break;

    case MSSP_I2C_SLAVE_MODE:
        /*I2C Slave mode General Call Configurations*/
        switch (_i2c->i2c_config.i2c_general_call)
        {
        case I2C_GENERAL_CALL_ENABLE:
            I2C_GENERAL_CALL_MODE_ENABLE();
            break;

        case I2C_GENERAL_CALL_DISABLE:
            I2C_GENERAL_CALL_MODE_DISABLE();
            break;

        default:
            break;
        }

        /*write collision Detect*/
        SSPCON1bits.WCOL = I2C_NO_COLLISION;

        /*Clear the receive overflow indicator */
        SSPCON1bits.SSPOV = I2C_NO_OVERFLOW;

        /*release the clock*/
        SSPCON1bits.CKP = I2C_RELEASE_THE_CLOCK;

        /*assign the i2c slave address*/
        SSPADD = _i2c->i2c_config.i2c_slave_address;

        /*I2C Slave mode Configurations*/
        I2C_SET_MODE(_i2c->i2c_config.i2c_mode_config);
        break;

    default:
        break;
    }
    /*I2C GPIO configurations*/
    TRISCbits.RC3 = INPUT;
    TRISCbits.RC4 = INPUT;
}

static inline void mssp_interrupt_handler_cfg(const mssp_i2c_t *_i2c)
{
#if MSSP_INTERRUPT_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE
    I2C_DEFAULT_INTERRUPT_HANDLER = _i2c->I2C_DefaultInterruptHandler;
    I2C_WRITE_COLLISION_INTERRUPT_HANDLER = _i2c->I2C_Report_Write_Collision;
    I2C_OVERFLOW_INTERRUPT_HANDLER = _i2c->I2C_Report_Receive_Overflow;

    MSSP_InterruptClearFlag();
    MSSP_BusCollisionInterruptClearFlag();

    MSSP_InterruptEnable();
    MSSP_BusCollisionInterruptEnable();

#if INTERRUPT_PRIORITY_LEVELS_ENABLE == INTERRUPT_PRIORITY_ENABLE
    INTERRUPT_PriorityLevelsEnable();
    switch (_i2c->I2C_default_interrupt_priority)
    {
    case INTERRUPT_HIGH_PRIORITY:
        INTERRUPT_GlobalInterruptHighEnable();
        MSSP_InterruptSetHighPriority();
        break;

    case INTERRUPT_LOW_PRIORITY:
        INTERRUPT_GlobalInterruptLowEnable();
        MSSP_InterruptSetLowPriority();
        break;

    default:
        break;
    }

    switch (_i2c->I2C_write_collision_interrupt_priority)
    {
    case INTERRUPT_HIGH_PRIORITY:
        MSSP_BusCollisionInterruptSetHighPriority();
        break;

    case INTERRUPT_LOW_PRIORITY:
        MSSP_BusCollisionInterruptSetLowPriority();
        break;

    default:
        break;
    }
#else
    INTERRUPT_PeripheralInterruptEnable();
    INTERRUPT_GlobalInterruptEnable();
#endif
#endif
}

#if MSSP_INTERRUPT_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE
void MSSP_I2C_ISR()
{
    /*clear flag*/
    MSSP_InterruptClearFlag();

    if (NULL != I2C_DEFAULT_INTERRUPT_HANDLER)
    {
        I2C_DEFAULT_INTERRUPT_HANDLER();
    }
}

void MSSP_I2C_BC_ISR()
{
    /*clear flag*/
    MSSP_BusCollisionInterruptClearFlag();

    if (NULL != I2C_WRITE_COLLISION_INTERRUPT_HANDLER)
    {
        I2C_WRITE_COLLISION_INTERRUPT_HANDLER();
    }
}
#endif
/*---------------------------------------------------------------------------------------*/