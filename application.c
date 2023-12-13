/**
 * @file application.c
 * @author Ahmed Nabil (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-10-14
 *
 * @copyright Copyright (c) 2023
 *
 */

/*------------------------section includes---------------------------*/
#include "./application.h"

/*-------------------------------------------------------------------*/
/*----------------------------Global Variables-----------------------*/
Std_ReturnType ret;
spi_t spi_obj =
    {
        .spi_mode = SPI_MASTER_MODE,
        .spi_mode_cfg = SPI_MASTER_WITH_CLK_DIV_04,
        .spi_transmit_mode = SPI_TRANSMIT_FROM_IDLE_TO_ACTIVE,
        .spi_clk_polarity = SPI_CLOCK_LOW_POLARITY,
        .master_sample_bit = SPI_MASTER_MIDDLE_SAMPLE_BIT,
        .ss_pin.pin = PIN0,
        .ss_pin.port = PORTD_INDEX,
        .ss_pin.direction = OUTPUT,
        .ss_pin.logic = HIGH,
};
pin_config_t _pin2 =
    {
        .direction = OUTPUT,
        .logic = HIGH,
        .pin = PIN1,
        .port = PORTD_INDEX,
};

pin_config_t _pin3 =
    {
        .direction = OUTPUT,
        .logic = HIGH,
        .pin = PIN2,
        .port = PORTD_INDEX,
};

pin_config_t _pin4 =
    {
        .direction = OUTPUT,
        .logic = HIGH,
        .pin = PIN3,
        .port = PORTD_INDEX,
};
uint8 receivedData;
/*-------------------------------------------------------------------*/
int main()
{
  ret = MSSP_SPI_Init(&spi_obj);
  while (1)
  {
    ret = MSSP_SPI_Send_Data_default_ss_Blocking(&spi_obj, 'a', &receivedData);
    ret = MSSP_SPI_Send_Data_specific_ss_Blocking(&spi_obj, &_pin2, 'a', &receivedData);
    ret = MSSP_SPI_Send_Data_specific_ss_Blocking(&spi_obj, &_pin3, 'a', &receivedData);
    ret = MSSP_SPI_Send_Data_specific_ss_Blocking(&spi_obj, &_pin4, 'a', &receivedData);
  }
  return (EXIT_SUCCESS);
}