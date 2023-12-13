/**
 * @file hal_ccp.h
 * @author Ahmed Nabil (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-11-26
 *
 * @copyright Copyright (c) 2023
 *
 */
#ifndef A25CCC75_FC61_48EA_B372_590BB06E8AAF
#define A25CCC75_FC61_48EA_B372_590BB06E8AAF

/*----------------------Section Includes----------------------------*/
#include "./../mcal_std_types.h"
#include "./ccp_cfg.h"
#include "./../proc/pic18f4620.h"
#include "./../device_config.h"
#include "./../GPIO/hal_gpio.h"
#include "./../interrupt/mcal_internal_interrupt.h"

/*----------------------MACRO declarations--------------------------*/
#define CCP_MODULE_DISABLED 0x00

#define CCP_CAPTURE_MODE_FALLING_EDGE 0x04
#define CCP_CAPTURE_MODE_RISING_EDGE 0x05
#define CCP_CAPTURE_MODE_4_RISING_EDGE 0x06
#define CCP_CAPTURE_MODE_16_RISING_EDGE 0x07

#define CCP_COMPARE_MODE_SET_PIN_LOW 0x08
#define CCP_COMPARE_MODE_SET_PIN_HIGH 0x09
#define CCP_COMPARE_MODE_TOGGLE_ON_MATCH 0x02
#define CCP_COMPARE_MODE_SW_INTERRUPT 0x0A
#define CCP_COMPARE_MODE_GEN_EVENT 0x0B

#define CCP_PWM_MODE 0x0C

#define CCP_CAPTURE_NOT_READY 0x00
#define CCP_CAPTURE_READY 0x01

#define CCP_COMPARE_NOT_READY 0x00
#define CCP_COMPARE_READY 0x01

/*----------------------MACRO Functions-----------------------------*/
#define CCP1_SET_MODE(_CONFIG) (CCP1CONbits.CCP1M = _CONFIG)
#define CCP2_SET_MODE(_CONFIG) (CCP2CONbits.CCP2M = _CONFIG)

/*----------------------Data types----------------------------------*/
typedef enum
{
    CCP_T2_PRESCALER_1 = 1,
    CCP_T2_PRESCALER_4 = 4,
    CCP_T2_PRESCALER_16 = 16,
} CCP_timer2_prescaler_t;

typedef enum
{
    CCP_T2_POSTSCALER_1 = 1,
    CCP_T2_POSTSCALER_2,
    CCP_T2_POSTSCALER_3,
    CCP_T2_POSTSCALER_4,
    CCP_T2_POSTSCALER_5,
    CCP_T2_POSTSCALER_6,
    CCP_T2_POSTSCALER_7,
    CCP_T2_POSTSCALER_8,
    CCP_T2_POSTSCALER_9,
    CCP_T2_POSTSCALER_10,
    CCP_T2_POSTSCALER_11,
    CCP_T2_POSTSCALER_12,
    CCP_T2_POSTSCALER_13,
    CCP_T2_POSTSCALER_14,
    CCP_T2_POSTSCALER_15,
    CCP_T2_POSTSCALER_16,
} CCP_timer2_postscaler_t;
typedef enum
{
    CCP_CAPTURE_MODE_SELECTED = 0,
    CCP_COMPARE_MODE_SELECTED,
    CCP_PWM_MODE_SELECTED,
} ccp_mode_t;

typedef union
{
    struct
    {
        uint8 ccpr1_low;
        uint8 ccpr1_high;
    };
    struct
    {
        uint16 ccp1;
    };
} CCP_PERIOD_REG_t;

typedef enum
{
    CCP1_INST,
    CCP2_INST,

} ccp_inst_t;

typedef enum
{
    CCP1_CCP2_T3,
    CCP1_T1_CCP2_T3,
    CCP1_CCP2_T1

} ccp_capture_timer_t;
typedef struct
{
    ccp_inst_t ccp_inst;
    ccp_mode_t ccp_mode;
    uint8 ccp_mode_variant;
    void (*CCP_InterruptHandler)(void);
    interrupt_priority_cfg priority;
    ccp_capture_timer_t ccp_capture_timer;
    uint32 PWM_Freq;
    uint8 timer2_postscaler_value : 4;
    uint8 timer2_prescaler_value : 2;
} ccp_t;

/*----------------------Function declarations-----------------------*/
Std_ReturnType CCP_Init(const ccp_t *_ccp_obj);
Std_ReturnType CCP_DeInit(const ccp_t *_ccp_obj);

/*Capture mode functions*/
Std_ReturnType CCP_isCaptureDataReady(const ccp_t *_ccp_obj, uint8 *_capture_status);
Std_ReturnType CCP_Capture_mode_read_value(const ccp_t *_ccp_obj, uint16 *capture_value);

/*Compare mode functions*/
Std_ReturnType CCP_isCompareComplete(const ccp_t *_ccp_obj, uint8 *_compare_status);
Std_ReturnType CCP_Compare_Mode_Set_Value(const ccp_t *_ccp_obj, uint16 compare_value);

/*PWM mode functions*/
Std_ReturnType CCP_PWM_Set_Duty(const ccp_t *_ccp_obj, const uint8 _duty);
Std_ReturnType CCP_PWM_Start(const ccp_t *_ccp_obj);
Std_ReturnType CCP_PWM_Stop(const ccp_t *_ccp_obj);

#endif /* A25CCC75_FC61_48EA_B372_590BB06E8AAF */
