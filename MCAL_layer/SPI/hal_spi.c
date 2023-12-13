/**
 * @file hal_spi.c
 * @author Ahmed Nabil (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-12-13
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "./hal_spi.h"

/*-------------------------Helper Functions----------------------------*/
static inline void mssp_spi_clk_polarity_cfg(const spi_t *_spi);
static inline void mssp_spi_clk_phase_cfg(const spi_t *_spi);
static inline void mssp_spi_clk_sample_cfg(const spi_t *_spi);
static inline void mssp_spi_mode_cfg(const spi_t *_spi);
/*---------------------------------------------------------------------*/

Std_ReturnType MSSP_SPI_Init(const spi_t *_spi)
{
    Std_ReturnType ret = E_OK;
    if (NULL == _spi)
    {
        ret = E_NOT_OK;
    }
    else
    {
        /*disable  module*/
        SPI_MODULE_DISABLE();

        /*initate the i/o pin*/
        ret = gpio_pin_initalize(&_spi->ss_pin);

        /*salve or master configurations*/
        mssp_spi_mode_cfg(_spi);

        /*mode configurations*/
        SPI_SET_MODE_CFG(_spi->spi_mode_cfg);

        /*clock polarity Configurations*/
        mssp_spi_clk_polarity_cfg(_spi);

        /*clock phase Configurations*/
        mssp_spi_clk_phase_cfg(_spi);

        /*enable  module*/
        SPI_MODULE_ENABLE();
    }
    return ret;
}
Std_ReturnType MSSP_SPI_DeInit(const spi_t *_spi)
{
    Std_ReturnType ret = E_OK;
    if (NULL == _spi)
    {
        ret = E_NOT_OK;
    }
    else
    {
        /*disable module*/
        SPI_MODULE_DISABLE();
    }
    return ret;
}

Std_ReturnType MSSP_SPI_Transive_default_ss_Blocking(const spi_t *_spi, uint8 data, uint8 *receivedData)
{
    Std_ReturnType ret = E_OK;
    if (NULL == _spi)
    {
        ret = E_NOT_OK;
    }
    else
    {
        /*set i/o to low*/
        ret = gpio_pin_write_logic(&(_spi->ss_pin), LOW);

        /*write data to SSPBUF*/
        SSPBUF = data;

        /*wait until the data in sift register to be ready*/
        while (SPI_RECEIVE_BUFFER_FULL != SPI_RECEIVE_BUFFER_STATUS())
            ;

        /*set i/o to high*/
        ret = gpio_pin_write_logic(&(_spi->ss_pin), HIGH);

        /*clear the buffer*/
        *receivedData = SSPBUF;
    }
    return ret;
}

Std_ReturnType MSSP_SPI_Transive_specific_ss_Blocking(const spi_t *_spi, const pin_config_t *ss_pin, uint8 data, uint8 *receivedData)
{
    Std_ReturnType ret = E_OK;
    if (NULL == _spi)
    {
        ret = E_NOT_OK;
    }
    else
    {
        /*set i/o to low*/
        ret = gpio_pin_initalize(ss_pin);
        ret = gpio_pin_write_logic(ss_pin, LOW);

        /*write data to SSPBUF*/
        SSPBUF = data;

        /*wait until the data in sift register to be ready*/
        while (SPI_RECEIVE_BUFFER_FULL != SPI_RECEIVE_BUFFER_STATUS())
            ;

        /*set i/o to high*/
        ret = gpio_pin_write_logic(ss_pin, HIGH);

        /*clear the buffer*/
        *receivedData = SSPBUF;
    }
    return ret;
}
/*-------------------------Helper Functions----------------------------*/
static inline void mssp_spi_clk_polarity_cfg(const spi_t *_spi)
{
    /*clock polarity*/
    switch (_spi->spi_clk_polarity)
    {
    case SPI_CLOCK_HIGH_POLARITY:
        SPI_CLOCK_HIGH_POLARITY_ENABLE();
        break;

    case SPI_CLOCK_LOW_POLARITY:
        SPI_CLOCK_LOW_POLARITY_ENABLE();
        break;

    default:
        break;
    }
}

static inline void mssp_spi_clk_phase_cfg(const spi_t *_spi)
{
    /*clock polarity*/
    switch (_spi->spi_transmit_mode)
    {
    case SPI_TRANSMIT_FROM_ACTIVE_TO_IDLE:
        SPI_TRANSMIT_FROM_ACTIVE_TO_IDLE_ENABLE();
        break;

    case SPI_TRANSMIT_FROM_IDLE_TO_ACTIVE:
        SPI_TRANSMIT_FROM_IDLE_TO_ACTIVE_ENABLE();
        break;

    default:
        break;
    }
}

static inline void mssp_spi_clk_sample_cfg(const spi_t *_spi)
{
    /*clock polarity*/
    switch (_spi->master_sample_bit)
    {
    case SPI_MASTER_END_SAMPLE_BIT:
        SPI_MASTER_END_SAMPLE_BIT_ENABLE();
        break;

    case SPI_MASTER_MIDDLE_SAMPLE_BIT:
        SPI_MASTER_MIDDLE_SAMPLE_BIT_ENABLE();
        break;

    default:
        break;
    }
}

static inline void mssp_spi_mode_cfg(const spi_t *_spi)
{
    switch (_spi->spi_mode)
    {
    case SPI_MASTER_MODE:
        /*clock sample Configurations*/
        mssp_spi_clk_sample_cfg(_spi);

        /* I/O Configurations*/
        TRISCbits.RC5 = OUTPUT;
        TRISCbits.RC3 = OUTPUT;
        TRISAbits.RA5 = INPUT;
        break;

    case SPI_SLAVE_MODE:
        /*clock sample Configurations*/
        SPI_SLAVE_SAMPLE_BIT_ENABLE();

        /* I/O Configurations*/
        TRISCbits.RC5 = OUTPUT;
        TRISCbits.RC3 = INPUT;
        TRISAbits.RA5 = INPUT;
        break;

    default:
        break;
    }
}
/*---------------------------------------------------------------------*/