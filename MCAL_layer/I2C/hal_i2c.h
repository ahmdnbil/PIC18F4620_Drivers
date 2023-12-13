/**
 * @file hal_i2c.h
 * @author Ahmed Nabil (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-12-10
 *
 * @copyright Copyright (c) 2023
 *
 */
#ifndef E9E7785D_0DAA_4FEF_892A_767B2BB8EA4F
#define E9E7785D_0DAA_4FEF_892A_767B2BB8EA4F

/*-------------------------------------section includes---------------------------------------*/
#include "./../proc/pic18f4620.h"
#include "./../mcal_std_types.h"
#include "./../interrupt/mcal_internal_interrupt.h"
#include "./../device_config.h"
#include "./../GPIO/hal_gpio.h"

/*---------------------------------------MACRO Declarations-----------------------------------*/
#define I2C_SMBUS_ENABLE 0x01
#define I2C_SMBUS_DISABLE 0x00

#define I2C_SLEW_RATE_ENBLE 0x01
#define I2C_SLEW_RATE_DISABLE 0x00

#define I2C_RECEIVE_ENABLE 0x01
#define I2C_RECEIVE_DISABLE 0x00

#define I2C_STOP_BIT_DETECTED 0x01
#define I2C_STOP_BIT_NOT_DETECTED 0x00

#define I2C_START_BIT_DETECTED 0x01
#define I2C_START_BIT_NOT_DETECTED 0x00

#define MSSP_I2C_MASTER_MODE 0x01
#define MSSP_I2C_SLAVE_MODE 0x00

/*-----------------------slave configurations---------------------*/
#define I2C_NO_COLLISION 0x00

#define I2C_NO_OVERFLOW 0x00

#define I2C_RELEASE_THE_CLOCK 0x01

#define I2C_GENERAL_CALL_ENABLE 0x01
#define I2C_GENERAL_CALL_DISABLE 0x00

#define I2C_SLAVE_WRITE_OPERATION 0x00
#define I2C_SLAVE_READ_OPERATION 0x01

#define I2C_lAST_BYTE_DATA 0x01
#define I2C_lAST_BYTE_ADDRESS 0x00
/*-----------------------------------------------------------------*/

/*-----------------------master configurations---------------------*/
#define MSSP_MASTER_RECEIVE_NOT_ACK 0x01
#define MSSP_MASTER_RECEIVE_ACK 0x00

#define MSSP_MASTER_RECEIVE_MODE_SEND_ACK 0x00
#define MSSP_MASTER_RECEIVE_MODE_SEND_NACK 0x01

#define MSSP_MASTER_SEND_ACK_ENABLE 0x01
#define MSSP_MASTER_SEND_ACK_DISABLE 0x00
/*-----------------------------------------------------------------*/

#define I2C_SLAVE_MODE_07_BIT_ADDRESS 0b0110
#define I2C_SLAVE_MODE_10_BIT_ADDRESS 0b0111
#define I2C_MASTER_MODE_WITH_CLK_CFG 0b1000
#define I2C_MASTER_MODE_WITH_FIRMWARE_CFG 0b1011
#define I2C_SLAVE_MODE_10_BIT_ADDRESS_INT_ENABLE 0b1111
#define I2C_SLAVE_MODE_07_BIT_ADDRESS_INT_ENABLE 0b1110

/*---------------------------------------MACRO function declarations--------------------------*/
#define I2C_SLEW_RATE_MODE_ENBLE() (SSPSTATbits.SMP = 0)
#define I2C_SLEW_RATE_MODE_DISABLE() (SSPSTATbits.SMP = 1)

#define I2C_SMBUS_MODE_ENABLE() (SSPSTATbits.CKE = 1)
#define I2C_SMBUS_MODE_DISABLE() (SSPSTATbits.CKE = 0)

#define I2C_lAST_BYTE_DATA_STATUS() (SSPSTATbits.DA)
#define I2C_STOP_BIT_STATUS() (SSPSTATbits.P)
#define I2C_START_BIT_STATUS() (SSPSTATbits.S)
#define I2C_SLAVE_RW_STATUS() (SSPSTATbits.RW)
#define I2C_BUFFER_FULL_STATUS() (SSPSTATbits.BF)

#define I2C_GENERAL_CALL_MODE_ENABLE() (SSPCON2bits.GCEN = 1)
#define I2C_GENERAL_CALL_MODE_DISABLE() (SSPCON2bits.GCEN = 0)

#define I2C_RECEIVE_MODE_ENABLE() (SSPCON2bits.RCEN = 1)
#define I2C_RECEIVE_MODE_DISABLE() (SSPCON2bits.RCEN = 0)

#define I2C_SET_MODE(_MODE) (SSPCON1bits.SSPM = _MODE)

#define MSSP_MODULE_ENABLE() (SSPCON1bits.SSPEN = 1)
#define MSSP_MODULE_DISABLE() (SSPCON1bits.SSPEN = 0)

#define MSSP_I2C_CLOCK_STREATCH_ENABLE() (SSPCON1bits.CKP = 0)
#define MSSP_I2C_CLOCK_STREATCH_DISABLE() (SSPCON1bits.CKP = 1)
/*---------------------------------------Data types-------------------------------------------*/
typedef struct
{
    uint8 i2c_slave_address;
    uint8 i2c_mode_config;
    uint8 i2c_mode : 1;
    uint8 i2c_slew_rate : 1;
    uint8 i2c_SMBus_control : 1;
    uint8 i2c_general_call : 1;
    uint8 i2c_master_rec_mode : 1;
    uint8 : 3;
} i2c_cfg_t;

typedef struct
{
    uint32 i2c_clk;
    void (*I2C_Report_Write_Collision)(void);
    interrupt_priority_cfg I2C_write_collision_interrupt_priority;
    void (*I2C_Report_Receive_Overflow)(void);
    void (*I2C_DefaultInterruptHandler)(void);
    interrupt_priority_cfg I2C_default_interrupt_priority;
    i2c_cfg_t i2c_config;
} mssp_i2c_t;

/*---------------------------------------function declarations--------------------------------*/
Std_ReturnType MSSP_I2C_Init(const mssp_i2c_t *_i2c);
Std_ReturnType MSSP_I2C_DeInit(const mssp_i2c_t *_i2c);
Std_ReturnType MSSP_I2C_Master_Send_Start(const mssp_i2c_t *_i2c);
Std_ReturnType MSSP_I2C_Master_Send_Repeated_Start(const mssp_i2c_t *_i2c);
Std_ReturnType MSSP_I2C_Master_Send_Stop(const mssp_i2c_t *_i2c);
Std_ReturnType MSSP_I2C_Master_Write_Blocking(const mssp_i2c_t *_i2c, uint8 data, uint8 *ack);
Std_ReturnType MSSP_I2C_Read(const mssp_i2c_t *_i2c, uint8 ack, uint8 *data);

#endif /* E9E7785D_0DAA_4FEF_892A_767B2BB8EA4F */
