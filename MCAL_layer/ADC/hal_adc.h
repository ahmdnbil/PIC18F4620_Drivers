/**
 * @file hal_adc.h
 * @author Ahmed Nabil (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-11-19
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef HAL_ADC_H
#define HAL_ADC_H

/*-------------------------------------section includes---------------------------------------*/
#include "./../proc/pic18f4620.h"
#include "./../mcal_std_types.h"
#include "./../device_config.h"
#include "./../GPIO/hal_gpio.h"
#include "./../interrupt/mcal_internal_interrupt.h"
#include "./hal_adc_cfg.h"

/*---------------------------------------MACRO Declarations-----------------------------------*/
#define _13_PIN_ANALOG_00_DIGITAL 0b0010
#define _12_PIN_ANALOG_01_DIGITAL 0b0011
#define _11_PIN_ANALOG_02_DIGITAL 0b0100
#define _10_PIN_ANALOG_03_DIGITAL 0b0101
#define _09_PIN_ANALOG_04_DIGITAL 0b0110
#define _08_PIN_ANALOG_05_DIGITAL 0b0111
#define _07_PIN_ANALOG_06_DIGITAL 0b1000
#define _06_PIN_ANALOG_07_DIGITAL 0b1001
#define _05_PIN_ANALOG_08_DIGITAL 0b1010
#define _04_PIN_ANALOG_09_DIGITAL 0b1011
#define _03_PIN_ANALOG_10_DIGITAL 0b1100
#define _02_PIN_ANALOG_11_DIGITAL 0b1101
#define _01_PIN_ANALOG_12_DIGITAL 0b1110
#define _00_PIN_ANALOG_13_DIGITAL 0b1111

#define ADC_RESULT_RIGHT 0x01U
#define ADC_RESULT_LEFT 0x00U

#define ADC_VOLTAGE_REFERANCE_ENABLED 0x01U
#define ADC_VOLTAGE_REFERANCE_DISABLED 0x00U

#define ADC_CONVERSION_DONE 0x01U
#define ADC_CONVERSION_INPROGRESS 0x00U

/*---------------------------------------MACRO function declarations--------------------------*/
#define ADC_CONVERSION_STATUS() (ADCON0bits.GODONE)
#define ADC_START_CONVERSION() (ADCON0bits.GODONE = 1)

#define ADC_CONVERTER_ENABLE() (ADCON0bits.ADON = 1)
#define ADC_CONVERTER_DISABLE() (ADCON0bits.ADON = 0)

#define ADC_DISABLE_VOLTAGE_REFERANCE() \
  do                                    \
  {                                     \
    ADCON1bits.VCFG0 = 0;               \
    ADCON1bits.VCFG1 = 0;               \
  } while (0)

#define ADC_ENABLE_VOLTAGE_REFERANCE() \
  do                                   \
  {                                    \
    ADCON1bits.VCFG0 = 1;              \
    ADCON1bits.VCFG1 = 1;              \
  } while (0)



#define ADC_ANALOG_DIGITAL_PORT_CONFIG(_CONFIG) (ADCON1bits.PCFG = _CONFIG)

#define ADC_RESULT_RIGHT_FORMAT() (ADCON2bits.ADFM = 1)
#define ADC_RESULT_LEFT_FORMAT() (ADCON2bits.ADFM = 0)

/*---------------------------------------Data types-------------------------------------------*/
typedef enum
{
  ADC_CHANNEL_AN0,
  ADC_CHANNEL_AN1,
  ADC_CHANNEL_AN2,
  ADC_CHANNEL_AN3,
  ADC_CHANNEL_AN4,
  ADC_CHANNEL_AN5,
  ADC_CHANNEL_AN6,
  ADC_CHANNEL_AN7,
  ADC_CHANNEL_AN8,
  ADC_CHANNEL_AN9,
  ADC_CHANNEL_AN10,
  ADC_CHANNEL_AN11,
  ADC_CHANNEL_AN12,
} adc_channel_t;

typedef enum
{
  ADC_0_TAD,
  ADC_2_TAD,
  ADC_4_TAD,
  ADC_6_TAD,
  ADC_8_TAD,
  ADC_12_TAD,
  ADC_16_TAD,
  ADC_20_TAD,
} adc_acquisition_time_t;

typedef enum
{
  ADC_CONVERSION_CLOCK_FOSC_DIV_2,
  ADC_CONVERSION_CLOCK_FOSC_DIV_8,
  ADC_CONVERSION_CLOCK_FOSC_DIV_32,
  ADC_CONVERSION_CLOCK_FOSC_DIV_FRC,
  ADC_CONVERSION_CLOCK_FOSC_DIV_4,
  ADC_CONVERSION_CLOCK_FOSC_DIV_16,
  ADC_CONVERSION_CLOCK_FOSC_DIV_64,
} adc_conversion_clock_t;

typedef struct
{
  void (*ADC_InterruptHandler)(void);
  interrupt_priority_cfg priority;
  adc_acquisition_time_t acq_time;
  adc_conversion_clock_t conv_clk;
  adc_channel_t channel;
  uint8 voltage_ref : 1;
  uint8 result_format : 1;
  uint8 : 6;

} adc_config_t;
/*---------------------------------------function declarations--------------------------------*/

Std_ReturnType ADC_Init(const adc_config_t *_adc);
Std_ReturnType ADC_DeInit(const adc_config_t *_adc);
Std_ReturnType ADC_SelectChannel(const adc_config_t *_adc, adc_channel_t channel);
Std_ReturnType ADC_StartConversion(const adc_config_t *_adc);
Std_ReturnType ADC_IsConversionDone(const adc_config_t *_adc, uint8 *conversion_status);
Std_ReturnType ADC_GetConversionResult(const adc_config_t *_adc, uint16 *reading);
Std_ReturnType ADC_GetConversion_Blocking(const adc_config_t *_adc, adc_channel_t channel, uint16 *reading);
Std_ReturnType ADC_StartConversion_Interrupt(const adc_config_t *_adc, adc_channel_t channel);
#endif /* HAL_ADC_H */
