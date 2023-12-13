/**
 * @file hal_usart.c
 * @author Ahmed Nabil (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-12-04
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "./hal_usart.h"

/*----------------------------------Helper Functions-------------------------------------*/
static void EUSART_Baud_Rate_Calculation(const usart_t *_usart);
static void EUSART_ASYNC_TX_Init(const usart_t *_usart);
static void EUSART_ASYNC_RX_Init(const usart_t *_usart);
static void (*EUSART_TX_INTERRUPT_HANDLER)(void) = NULL;
static void (*EUSART_RX_INTERRUPT_HANDLER)(void) = NULL;
static void (*EUSART_FRAMING_ERROR_HANDLER)(void) = NULL;
static void (*EUSART_OVERRUN_ERROR_HANDLER)(void) = NULL;
/*---------------------------------------------------------------------------------------*/
Std_ReturnType
EUSART_ASYNC_Init(const usart_t *_usart)
{
    Std_ReturnType ret = E_OK;
    if (NULL == _usart)
    {
        ret = E_NOT_OK;
    }
    else
    {
        /*disable module*/
        EUSART_ModuleDisable();

        /*Baud rate configurations*/
        EUSART_Baud_Rate_Calculation(_usart);

        /*RX configurations*/
        TRISCbits.RC7 = 1;
        EUSART_ASYNC_RX_Init(_usart);

        /*TX configurations*/
        TRISCbits.RC6 = 1;
        EUSART_ASYNC_TX_Init(_usart);

        /*enable module*/
        EUSART_ModuleEnable();
    }
    return ret;
}

Std_ReturnType EUSART_DeInit(const usart_t *_usart)
{
    Std_ReturnType ret = E_OK;
    if (NULL == _usart)
    {
        ret = E_NOT_OK;
    }
    else
    {
        /*disable module*/
        EUSART_ModuleDisable();

        /*disable receive interrupt*/
#if USART_RX_INTERRUPT_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE
        USART_RxInterruptDisable();
#endif

        /*disable transmit interrupt*/
#if USART_TX_INTERRUPT_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE
        USART_TxInterruptDisable();
#endif
    }
    return ret;
}

Std_ReturnType EUSART_ReadByteBlocking(const usart_t *_usart, uint8 *_data)
{
    Std_ReturnType ret = E_OK;
    if (NULL == _usart || NULL == _data)
    {
        ret = E_NOT_OK;
    }
    else
    {
        while (!(PIR1bits.RCIF))
            ;
        *_data = RCREG;
    }
    return ret;
}
Std_ReturnType EUSART_WriteByteBlocking(const usart_t *_usart, uint8 _data)
{
    Std_ReturnType ret = E_OK;
    if (NULL == _usart)
    {
        ret = E_NOT_OK;
    }
    else
    {
        while (!(TXSTAbits.TRMT))
            ;
        TXREG = _data;
    }
    return ret;
}

Std_ReturnType EUSART_SendStringBlocking(const usart_t *_usart, uint8 *_data)
{
    Std_ReturnType ret = E_OK;
    uint8 l_counter = 0;
    while ('\0' != _data[l_counter])
    {
        ret = EUSART_WriteByteBlocking(_usart, _data[l_counter]);
        l_counter++;
    }
}

Std_ReturnType EUSART_ReadByteNonBlocking(const usart_t *_usart, uint8 *_data)
{
    Std_ReturnType ret = E_OK;
    if (NULL == _usart || NULL == _data)
    {
        ret = E_NOT_OK;
    }
    else
    {
        if (PIR1bits.RCIF)
        {
            *_data = RCREG;
        }
    }
    return ret;
}
Std_ReturnType EUSART_WriteByteNonBlocking(const usart_t *_usart, uint8 _data)
{
    Std_ReturnType ret = E_OK;
    if (NULL == _usart || NULL == _data)
    {
        ret = E_NOT_OK;
    }
    else
    {
    }
    return ret;
}

/*----------------------------------Helper Functions-------------------------------------*/
static void EUSART_Baud_Rate_Calculation(const usart_t *_usart)
{
    float baud_rate_temp = 0;
    switch (_usart->baudrate_gen_cfg)
    {
    case BAUDRATE_ASYN_8BIT_LOW_SPEED:
        TXSTAbits.BRGH = EUSART_ASYNCHRONOUS_LOW_SPEED;
        TXSTAbits.SYNC = EUSART_ASYNCHRONOUS_MODE;
        BAUDCONbits.BRG16 = EUSART_08BIT_BAUDRATE_GEN;
        baud_rate_temp = ((_XTAL_FREQ / (float)_usart->baudrate) / 64) - 1;
        break;

    case BAUDRATE_ASYN_8BIT_HIGH_SPEED:
        TXSTAbits.BRGH = EUSART_ASYNCHRONOUS_HIGH_SPEED;
        TXSTAbits.SYNC = EUSART_ASYNCHRONOUS_MODE;
        BAUDCONbits.BRG16 = EUSART_08BIT_BAUDRATE_GEN;
        baud_rate_temp = ((_XTAL_FREQ / _usart->baudrate) / 16) - 1;
        break;

    case BAUDRATE_ASYN_16BIT_LOW_SPEED:
        TXSTAbits.BRGH = EUSART_ASYNCHRONOUS_LOW_SPEED;
        TXSTAbits.SYNC = EUSART_ASYNCHRONOUS_MODE;
        BAUDCONbits.BRG16 = EUSART_16BIT_BAUDRATE_GEN;
        baud_rate_temp = ((_XTAL_FREQ / _usart->baudrate) / 16) - 1;
        break;

    case BAUDRATE_ASYN_16BIT_HIGH_SPEED:
        TXSTAbits.BRGH = EUSART_ASYNCHRONOUS_HIGH_SPEED;
        TXSTAbits.SYNC = EUSART_ASYNCHRONOUS_MODE;
        BAUDCONbits.BRG16 = EUSART_16BIT_BAUDRATE_GEN;
        baud_rate_temp = ((_XTAL_FREQ / _usart->baudrate) / 4) - 1;
        break;

    case BAUDRATE_SYN_8BIT:
        TXSTAbits.BRGH = EUSART_ASYNCHRONOUS_LOW_SPEED;
        TXSTAbits.SYNC = EUSART_SYNCHRONOUS_MODE;
        BAUDCONbits.BRG16 = EUSART_08BIT_BAUDRATE_GEN;
        baud_rate_temp = ((_XTAL_FREQ / _usart->baudrate) / 4) - 1;
        break;

    case BAUDRATE_SYN_16BIT:
        TXSTAbits.BRGH = EUSART_ASYNCHRONOUS_LOW_SPEED;
        TXSTAbits.SYNC = EUSART_SYNCHRONOUS_MODE;
        BAUDCONbits.BRG16 = EUSART_16BIT_BAUDRATE_GEN;
        baud_rate_temp = ((_XTAL_FREQ / _usart->baudrate) / 4) - 1;
        break;

    default:
        break;
    }
    SPBRG = (uint8)((uint32)baud_rate_temp);
    SPBRGH = (uint8)(((uint32)baud_rate_temp) >> 8);
}

static void EUSART_ASYNC_TX_Init(const usart_t *_usart)
{
    if (EUSART_ASYNCHRONOUS_TX_ENABLE == _usart->usart_tx_cfg.usart_tx_enable)
    {
        /*Enable Transmit mode*/
        TXSTAbits.TXEN = EUSART_ASYNCHRONOUS_TX_ENABLE;

#if USART_TX_INTERRUPT_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE

        /*set call back*/
        EUSART_TX_INTERRUPT_HANDLER = _usart->EUSART_TxDefaultInterruptHandler;

        /*enable receive interrupt*/
        USART_TxInterruptEnable();

#if INTERRUPT_PRIORITY_LEVELS_ENABLE == INTERRUPT_PRIORITY_ENABLE
        INTERRUPT_PriorityLevelsEnable();
        switch (_usart->Tx_interruptPriority)
        {
        case INTERRUPT_HIGH_PRIORITY:
            INTERRUPT_GlobalInterruptHighEnable();
            USART_TxInterruptSetHighPriority();
            break;

        case INTERRUPT_LOW_PRIORITY:
            INTERRUPT_GlobalInterruptLowEnable();
            USART_TxInterruptSetLowPriority();
            break;

        default:
            break;
        }
#else
        /*enable global interrupt*/
        INTERRUPT_GlobalInterruptEnable();

        /*enable peripheral*/
        INTERRUPT_PeripheralInterruptEnable();
#endif
#endif
        switch (_usart->usart_tx_cfg.usart_tx_9bit_enable)
        {
        case EUSART_ASYNCHRONOUS_9BIT_TX_ENABLE:
            TXSTAbits.TX9 = EUSART_ASYNCHRONOUS_9BIT_TX_ENABLE;
            break;

        case EUSART_ASYNCHRONOUS_9BIT_TX_DISABLE:
            TXSTAbits.TX9 = EUSART_ASYNCHRONOUS_9BIT_TX_DISABLE;
            break;

        default:
            break;
        }
    }
    else
    {
        TXSTAbits.TXEN = EUSART_ASYNCHRONOUS_TX_DISABLE;
    }
}

static void EUSART_ASYNC_RX_Init(const usart_t *_usart)
{
    if (EUSART_ASYNCHRONOUS_RX_ENABLE == _usart->usart_tx_cfg.usart_tx_enable)
    {
        /*Enable Receive mode*/
        RCSTAbits.CREN = EUSART_ASYNCHRONOUS_RX_ENABLE;

#if USART_RX_INTERRUPT_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE
        /*set call back*/
        EUSART_RX_INTERRUPT_HANDLER = _usart->EUSART_RxDefaultInterruptHandler;
        EUSART_FRAMING_ERROR_HANDLER = _usart->EUSART_FramingErrorHandler;
        EUSART_OVERRUN_ERROR_HANDLER = _usart->EUSART_OverrunErrorHandler;

        /*enable receive interrupt*/
        USART_RxInterruptEnable();

#if INTERRUPT_PRIORITY_LEVELS_ENABLE == INTERRUPT_PRIORITY_ENABLE
        INTERRUPT_PriorityLevelsEnable();
        switch (_usart->Rx_interruptPriority)
        {
        case INTERRUPT_HIGH_PRIORITY:
            INTERRUPT_GlobalInterruptHighEnable();
            USART_RxInterruptSetHighPriority();
            break;

        case INTERRUPT_LOW_PRIORITY:
            INTERRUPT_GlobalInterruptLowEnable();
            USART_RxInterruptSetLowPriority();
            break;

        default:
            break;
        }
#else
        /*enable global interrupt*/
        INTERRUPT_GlobalInterruptEnable();

        /*enable peripheral*/
        INTERRUPT_PeripheralInterruptEnable();
#endif
#endif
        switch (_usart->usart_rx_cfg.usart_rx_9bit_enable)
        {
        case EUSART_ASYNCHRONOUS_9BIT_RX_ENABLE:
            RCSTAbits.RX9 = EUSART_ASYNCHRONOUS_9BIT_RX_ENABLE;
            break;

        case EUSART_ASYNCHRONOUS_9BIT_TX_DISABLE:
            RCSTAbits.RX9 = EUSART_ASYNCHRONOUS_9BIT_RX_DISABLE;
            break;

        default:
            break;
        }
    }
    else
    {
        RCSTAbits.CREN = EUSART_ASYNCHRONOUS_RX_DISABLE;
    }
}

void EUSART_TX_ISR()
{
    if (NULL != EUSART_TX_INTERRUPT_HANDLER)
    {
        EUSART_TX_INTERRUPT_HANDLER();
    }
}

void EUSART_RX_ISR()
{
    if (NULL != EUSART_RX_INTERRUPT_HANDLER)
    {
        EUSART_RX_INTERRUPT_HANDLER();
    }
    if (NULL != EUSART_OVERRUN_ERROR_HANDLER)
    {
        EUSART_OVERRUN_ERROR_HANDLER();
    }
    if (NULL != EUSART_FRAMING_ERROR_HANDLER)
    {
        EUSART_FRAMING_ERROR_HANDLER();
    }
}
/*---------------------------------------------------------------------------------------*/