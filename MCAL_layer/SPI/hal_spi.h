/**
 * @file hal_spi.h
 * @author Ahmed Nabil (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-12-13
 *
 * @copyright Copyright (c) 2023
 *
 */
#ifndef BE5B54D1_82B4_4863_B45C_C191ACBF7B96
#define BE5B54D1_82B4_4863_B45C_C191ACBF7B96

/*-------------------------------------section includes---------------------------------------*/
#include "./../proc/pic18f4620.h"
#include "./../mcal_std_types.h"
#include "./../interrupt/mcal_internal_interrupt.h"
#include "./../device_config.h"
#include "./../GPIO/hal_gpio.h"

/*---------------------------------------MACRO Declarations-----------------------------------*/
#define SPI_SLAVE_MODE 0x00
#define SPI_MASTER_MODE 0x01

/*----Master Configurations---*/
#define SPI_MASTER_MIDDLE_SAMPLE_BIT 0x00
#define SPI_MASTER_END_SAMPLE_BIT 0x01

#define SPI_RECEIVE_BUFFER_EMPTY 0x00
#define SPI_RECEIVE_BUFFER_FULL 0x01
/*----------------------------*/

/*----Slave Configurations----*/
/*----------------------------*/

#define SPI_TRANSMIT_FROM_ACTIVE_TO_IDLE 0x00
#define SPI_TRANSMIT_FROM_IDLE_TO_ACTIVE 0x01

#define SPI_CLOCK_LOW_POLARITY 0x00
#define SPI_CLOCK_HIGH_POLARITY 0x01

#define SPI_MASTER_WITH_CLK_DIV_04 0b0000
#define SPI_MASTER_WITH_CLK_DIV_16 0b0001
#define SPI_MASTER_WITH_CLK_DIV_64 0b0010
#define SPI_MASTER_WITH_CLK_TMR2_DIV_2 0b0011
#define SPI_SLAVE_SS_ENABLED 0b0100
#define SPI_SLAVE_SS_DISABLED 0b0101

/*---------------------------------------MACRO function declarations--------------------------*/
#define SPI_MODULE_ENABLE() (SSPCON1bits.SSPEN = 1)
#define SPI_MODULE_DISABLE() (SSPCON1bits.SSPEN = 0)
#define SPI_SET_MODE_CFG(_MODE) (SSPCON1bits.SSPM = _MODE)

/*----Master Configurations---*/
#define SPI_MASTER_MIDDLE_SAMPLE_BIT_ENABLE() (SSPSTATbits.SMP = 0)
#define SPI_MASTER_END_SAMPLE_BIT_ENABLE() (SSPSTATbits.SMP = 1)
/*----------------------------*/

/*----Slave Configurations----*/
#define SPI_SLAVE_SAMPLE_BIT_ENABLE() (SSPSTATbits.SMP = 0)
/*----------------------------*/

#define SPI_TRANSMIT_FROM_ACTIVE_TO_IDLE_ENABLE() (SSPSTATbits.CKE = 0)
#define SPI_TRANSMIT_FROM_IDLE_TO_ACTIVE_ENABLE() (SSPSTATbits.CKE = 1)

#define SPI_CLOCK_HIGH_POLARITY_ENABLE() (SSPCON1bits.CKP = 1)
#define SPI_CLOCK_LOW_POLARITY_ENABLE() (SSPCON1bits.CKP = 0)

#define SPI_RECEIVE_BUFFER_STATUS() (SSPSTATbits.BF)

/*---------------------------------------Data types-------------------------------------------*/

typedef struct
{
    uint8 spi_mode : 1;
    uint8 spi_mode_cfg : 4;
    uint8 master_sample_bit : 1;
    uint8 spi_transmit_mode : 1;
    uint8 spi_clk_polarity : 1;
    pin_config_t ss_pin;
} spi_t;
/*---------------------------------------function declarations--------------------------------*/
Std_ReturnType MSSP_SPI_Init(const spi_t *_spi);
Std_ReturnType MSSP_SPI_DeInit(const spi_t *_spi);
Std_ReturnType MSSP_SPI_Transive_default_ss_Blocking(const spi_t *_spi, uint8 data, uint8 *receivedData);
Std_ReturnType MSSP_SPI_Send_Data_specific_ss_Blocking(const spi_t *_spi, const pin_config_t *ss_pin, uint8 data, uint8 *receivedData);

#endif /* BE5B54D1_82B4_4863_B45C_C191ACBF7B96 */
