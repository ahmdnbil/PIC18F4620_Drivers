/**
 * @file hal_usart.h
 * @author Ahmed Nabil (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-12-04
 *
 * @copyright Copyright (c) 2023
 *
 */
#ifndef F5850A7B_FCB7_4ACD_B58F_906B979A935A
#define F5850A7B_FCB7_4ACD_B58F_906B979A935A

/*-------------------------------------section includes---------------------------------------*/
#include "./hal_usart_cfg.h"
#include "./../interrupt/mcal_internal_interrupt.h"
#include "./../device_config.h"
#include "./../mcal_std_types.h"
#include "./../proc/pic18f4620.h"
#include "./../GPIO/hal_gpio.h"
/*---------------------------------------MACRO Declarations-----------------------------------*/

/* Selecting EUSART Working Mode */
#define EUSART_SYNCHRONOUS_MODE 1
#define EUSART_ASYNCHRONOUS_MODE 0
/* Baud rate Generator Asynchronous Speed Mode */
#define EUSART_ASYNCHRONOUS_HIGH_SPEED 1
#define EUSART_ASYNCHRONOUS_LOW_SPEED 0
/*Baud Rate Generator Register size */
#define EUSART_16BIT_BAUDRATE_GEN 1
#define EUSART_08BIT_BAUDRATE_GEN 0

/* EUSART Transmit Enable */
#define EUSART_ASYNCHRONOUS_TX_ENABLE 1
#define EUSART_ASYNCHRONOUS_TX_DISABLE 0
/* EUSART Transmit Interrupt Enable */
#define EUSART_ASYNCHRONOUS_INTERRUPT_TX_ENABLE 1
#define EUSART_ASYNCHRONOUS_INTERRUPT_TX_DISABLE 0
/* EUSART 9-bit Transmit Enable */
#define EUSART_ASYNCHRONOUS_9BIT_TX_ENABLE 1
#define EUSART_ASYNCHRONOUS_9BIT_TX_DISABLE 0

/* EUSART Reseiver Enable */
#define EUSART_ASYNCHRONOUS_RX_ENABLE 1
#define EUSART_ASYNCHRONOUS_RX_DISABLE 0
/* EUSART Reseiver Interrupt Enable */
#define EUSART_ASYNCHRONOUS_INTERRUPT_RX_ENABLE 1
#define EUSART_ASYNCHRONOUS_INTERRUPT_RX_DISABLE 0
/* EUSART 9-bit Reseiver Enable */
#define EUSART_ASYNCHRONOUS_9BIT_RX_ENABLE 1
#define EUSART_ASYNCHRONOUS_9BIT_RX_DISABLE 0

/*Framing Error*/
#define EUSART_FRAMING_ERROR_DETECED 1
#define EUSART_FRAMING_ERROR_CLEARED 0
/*Overrun Error*/
#define EUSART_OVERRUN_ERROR_DETECED 1
#define EUSART_OVERRUN_ERROR_CLEARED 0

/*---------------------------------------MACRO function declarations--------------------------*/
#define EUSART_ModuleEnable() (RCSTAbits.SPEN = 1)
#define EUSART_ModuleDisable() (RCSTAbits.SPEN = 0)

/*---------------------------------------Data types-------------------------------------------*/
typedef enum
{
    BAUDRATE_ASYN_8BIT_LOW_SPEED,
    BAUDRATE_ASYN_8BIT_HIGH_SPEED,
    BAUDRATE_ASYN_16BIT_LOW_SPEED,
    BAUDRATE_ASYN_16BIT_HIGH_SPEED,
    BAUDRATE_SYN_8BIT,
    BAUDRATE_SYN_16BIT,
} baudrate_gen_t;

typedef struct
{
    uint8 : 6;
    uint8 usart_tx_enable : 1;
    uint8 usart_tx_9bit_enable : 1;
} usart_tx_cfg_t;

typedef struct
{
    uint8 : 6;
    uint8 usart_rx_enable : 1;
    uint8 usart_rx_9bit_enable : 1;
} usart_rx_cfg_t;

typedef union
{
    struct
    {
        uint8 : 6;
        uint8 usart_ferr : 1;
        uint8 usart_oerr : 1;
    };
    uint8 status;
} usart_error_status_t;

typedef struct
{
    uint32 baudrate;
    baudrate_gen_t baudrate_gen_cfg;
    usart_tx_cfg_t usart_tx_cfg;
    usart_rx_cfg_t usart_rx_cfg;
    usart_error_status_t error_status;

    interrupt_priority_cfg Tx_interruptPriority;
    void (*EUSART_TxDefaultInterruptHandler)(void);

    interrupt_priority_cfg Rx_interruptPriority;
    void (*EUSART_RxDefaultInterruptHandler)(void);

    void (*EUSART_FramingErrorHandler)(void);
    void (*EUSART_OverrunErrorHandler)(void);

} usart_t;

/*---------------------------------------function declarations--------------------------------*/
Std_ReturnType EUSART_ASYNC_Init(const usart_t *_usart);
Std_ReturnType EUSART_DeInit(const usart_t *_usart);
Std_ReturnType EUSART_ReadByteBlocking(const usart_t *_usart, uint8 *_data);
Std_ReturnType EUSART_WriteByteBlocking(const usart_t *_usart, uint8 _data);
Std_ReturnType EUSART_ReadByteNonBlocking(const usart_t *_usart, uint8 *_data);
Std_ReturnType EUSART_WriteByteNonBlocking(const usart_t *_usart, uint8 _data);
Std_ReturnType EUSART_SendStringBlocking(const usart_t *_usart, uint8 *_data);

#endif /* F5850A7B_FCB7_4ACD_B58F_906B979A935A */
