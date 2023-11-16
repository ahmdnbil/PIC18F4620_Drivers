/**
 * @file mcal_external_interrupt.c
 * @author Ahmed Nabil (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-11-10
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "./mcal_external_interrupt.h"

/*-----------------------Static functions------------------------------*/
static interruptHandeler EXTI0_InterruptHandler =NULL;
static interruptHandeler EXTI1_InterruptHandler =NULL;
static interruptHandeler EXTI2_InterruptHandler =NULL;

static interruptHandeler RB4_InterruptHandler_LOW =NULL;
static interruptHandeler RB5_InterruptHandler_LOW =NULL;
static interruptHandeler RB6_InterruptHandler_LOW =NULL;
static interruptHandeler RB7_InterruptHandler_LOW =NULL;
static interruptHandeler RB4_InterruptHandler_HIGH =NULL;
static interruptHandeler RB5_InterruptHandler_HIGH =NULL;
static interruptHandeler RB6_InterruptHandler_HIGH =NULL;
static interruptHandeler RB7_InterruptHandler_HIGH =NULL;

static Std_ReturnType Interrupt_INTx_Edge_Init(const interrupt_INTx_t * int_obj);
static Std_ReturnType Interrupt_INTx_Pin_Init(const interrupt_INTx_t * int_obj);
static Std_ReturnType Interrupt_INTx_Priority_Init(const interrupt_INTx_t * int_obj);
static Std_ReturnType Interrupt_INTx_Disable(const interrupt_INTx_t * int_obj);
static Std_ReturnType Interrupt_INTx_Enable(const interrupt_INTx_t * int_obj);
static Std_ReturnType Interrupt_INTx_Clear_Flag(const interrupt_INTx_t *int_obj);

static Std_ReturnType EXTI0_SetInterruptHandler(void (*pf)(void));
static Std_ReturnType EXTI1_SetInterruptHandler(void (*pf)(void));
static Std_ReturnType EXTI2_SetInterruptHandler(void (*pf)(void));
static Std_ReturnType Interrupt_INTx_SetInterruptHandler(const interrupt_INTx_t * int_obj);

static Std_ReturnType RBx_SetInterruptHandler(void (*pf)(void));
/*---------------------------------------------------------------------*/

Std_ReturnType interrupt_INTx_Init(const interrupt_INTx_t * int_obj)
{
    Std_ReturnType ret=E_OK;
    if(NULL == int_obj)
    {
        ret=E_NOT_OK;
    }
    else
    {
        //Disable External Interrupt
        ret=Interrupt_INTx_Disable(int_obj);
        //clear flag
        ret=Interrupt_INTx_Clear_Flag(int_obj);
        //configure edge
        ret=Interrupt_INTx_Edge_Init(int_obj);

        #if INTERRUPT_PRIORITY_LEVELS_ENABLE == INTERRUPT_FEATURE_ENABLE
        //configure priority
        ret=Interrupt_INTx_Priority_Init(int_obj);
        #endif

        //configure pin
        ret=Interrupt_INTx_Pin_Init(int_obj);
        //set call back function
        ret=Interrupt_INTx_SetInterruptHandler(int_obj);
        //Enable External Interrupt
        ret=Interrupt_INTx_Enable(int_obj);
        
    }
    return ret;
}
Std_ReturnType interrupt_INTx_DeInit(const interrupt_INTx_t * int_obj)
{
    Std_ReturnType ret=E_OK;
    if(NULL == int_obj)
    {
        ret=E_NOT_OK;
    }
    else
    {  
        ret=Interrupt_INTx_Disable(int_obj);
    }
    return ret;
}

Std_ReturnType interrupt_RBx_Init(const interrupt_RBx_t * int_obj)
{
    Std_ReturnType ret=E_OK;
    if(NULL == int_obj)
    {
        ret=E_NOT_OK;
    }
    else
    {
        //Disable External Interrupt
        EXTI_RBx_InterruptDisable();
        //clear flag
        EXTI_RBx_InterruptClearFlag();

        #if INTERRUPT_PRIORITY_LEVELS_ENABLE == INTERRUPT_FEATURE_ENABLE
        //configure priority
        INTERRUPT_PriorityLevelsEnable();
        switch(int_obj->priority)
        {
            case INTERRUPT_HIGH_PRIORITY:
            INTERRUPT_GlobalInterruptHighEnable();
            EXTI_RBx_SetHighPriority();
            break;

            case INTERRUPT_LOW_PRIORITY:
            INTERRUPT_GlobalInterruptLowEnable();
            EXTI_RBx_SetLowPriority();
            break;

            default:
            break;
        }
        #else
        INTERRUPT_GlobalInterruptEnable();
        INTERRUPT_PeripheralInterruptEnable();
        #endif
        switch(int_obj->mcu_pin.pin)
        {
            case PIN4:
            RB4_InterruptHandler_LOW=int_obj->pf;
            RB4_InterruptHandler_HIGH=int_obj->pf2;
            break;

            case PIN5:
            RB5_InterruptHandler_LOW=int_obj->pf;
            RB5_InterruptHandler_HIGH=int_obj->pf2;
            break;

            case PIN6:
            RB6_InterruptHandler_LOW=int_obj->pf;
            RB6_InterruptHandler_HIGH=int_obj->pf2;
            break;

            case PIN7:
            RB7_InterruptHandler_LOW=int_obj->pf;
            RB7_InterruptHandler_HIGH=int_obj->pf2;
            break;
        }
        //configure pin
        ret=gpio_pin_direction_initalize(&(int_obj->mcu_pin));
        //set call back function
        //Enable External Interrupt
        EXTI_RBx_InterruptEnable();
    
    }
    return ret;
}


Std_ReturnType interrupt_RBx_DeInit(const interrupt_RBx_t * int_obj)
{
    Std_ReturnType ret=E_OK;
    if(NULL == int_obj)
    {
        ret=E_NOT_OK;
    }
    else
    {
        //Disable External Interrupt
        EXTI_RBx_InterruptDisable();
    }
    return ret;
}

/*--------------------------EXTI INTx helper functions-----------------------------*/

static Std_ReturnType Interrupt_INTx_Enable(const interrupt_INTx_t * int_obj)
{
    Std_ReturnType ret=E_OK;
    if (NULL == int_obj)
    {
        ret=E_NOT_OK;
    }
    else
    {
        switch(int_obj->src)
        {
            case EXTI0:
            #if INTERRUPT_PRIORITY_LEVELS_ENABLE == INTERRUPT_FEATURE_ENABLE 
            INTERRUPT_PriorityLevelsEnable();           
            INTERRUPT_GlobalInterruptHighEnable();
            #else
            INTERRUPT_GlobalInterruptEnable();
            INTERRUPT_PeripheralInterruptEnable();
            #endif
            EXTI0_Enable();
            break;
            
            case EXTI1:
            #if INTERRUPT_PRIORITY_LEVELS_ENABLE == INTERRUPT_FEATURE_ENABLE
            INTERRUPT_PriorityLevelsEnable();           
            switch(int_obj->priority)
            {
                case INTERRUPT_LOW_PRIORITY:
                INTERRUPT_GlobalInterruptLowEnable();
                break;
                
                case INTERRUPT_HIGH_PRIORITY:
                INTERRUPT_GlobalInterruptHighEnable();
                break;
            }
            #else
            INTERRUPT_GlobalInterruptEnable();
            INTERRUPT_PeripheralInterruptEnable();
            #endif
            EXTI1_Enable();
            break;
            
            case EXTI2:
            #if INTERRUPT_PRIORITY_LEVELS_ENABLE == INTERRUPT_FEATURE_ENABLE
            INTERRUPT_PriorityLevelsEnable();           
            switch(int_obj->priority)
            {
                case INTERRUPT_LOW_PRIORITY:
                INTERRUPT_GlobalInterruptLowEnable();
                break;
                
                case INTERRUPT_HIGH_PRIORITY:
                INTERRUPT_GlobalInterruptHighEnable();
                break;
            }
            #else
            INTERRUPT_GlobalInterruptEnable();
            INTERRUPT_PeripheralInterruptEnable();
            #endif
            EXTI2_Enable();
            break;

            default:
            ret=E_NOT_OK;
            break;
        }

    }
    return ret;
}

static Std_ReturnType Interrupt_INTx_Disable(const interrupt_INTx_t * int_obj)
{
    Std_ReturnType ret=E_OK;
    if (NULL == int_obj)
    {
        ret=E_NOT_OK;
    }
    else
    {
        switch(int_obj->src)
        {
            case EXTI0:
            EXTI0_Disable();
            break;
            
            case EXTI1:
            EXTI1_Disable();
            break;
            
            case EXTI2:
            EXTI2_Disable();
            break;

            default:
            ret=E_NOT_OK;
            break;
        }  

    }
    return ret;
}


#if INTERRUPT_PRIORITY_LEVELS_ENABLE == INTERRUPT_FEATURE_ENABLE
static Std_ReturnType Interrupt_INTx_Priority_Init(const interrupt_INTx_t * int_obj)
{
    Std_ReturnType ret=E_OK;
    if (NULL == int_obj)
    {
        ret=E_NOT_OK;
    }
    else
    {
        switch (int_obj->src)
        {
            case EXTI1:
                switch(int_obj->priority)
                {
                    case INTERRUPT_LOW_PRIORITY:
                    EXTI1_SetLowPriority();
                    break;

                    case INTERRUPT_HIGH_PRIORITY:
                    EXTI1_SetHighPriority();
                    break;
                }
            break;

            case EXTI2:
                switch(int_obj->priority)
                {
                    case INTERRUPT_LOW_PRIORITY:
                    EXTI2_SetLowPriority();
                    break;

                    case INTERRUPT_HIGH_PRIORITY:
                    EXTI2_SetHighPriority();
                    break;
                }
            break;
        
            default:
            break;
        }
    }
    return ret;
}
#endif

static Std_ReturnType Interrupt_INTx_Edge_Init(const interrupt_INTx_t * int_obj)
{
    Std_ReturnType ret=E_OK;
    if (NULL == int_obj)
    {
        ret=E_NOT_OK;
    }
    else
    {
        switch (int_obj->src)
        {
            case EXTI0:
                switch(int_obj->edge)
                {
                    case INTERRUPT_FALLING_EDGE:
                    EXTI0_FallingEdge();
                    break;

                    case INTERRUPT_RISING_EDGE:
                    EXTI0_RisingEdge();
                    break;
                }
            break;

            case EXTI1:
                switch(int_obj->edge)
                {
                    case INTERRUPT_FALLING_EDGE:
                    EXTI1_FallingEdge();
                    break;

                    case INTERRUPT_RISING_EDGE:
                    EXTI1_RisingEdge();
                    break;
                }
            break;

            case EXTI2:
                switch(int_obj->edge)
                {
                    case INTERRUPT_FALLING_EDGE:
                    EXTI2_FallingEdge();
                    break;

                    case INTERRUPT_RISING_EDGE:
                    EXTI2_RisingEdge();
                    break;
                }
            break;
        
            default:
            break;
        }
    }
    return ret;
}

static Std_ReturnType Interrupt_INTx_Pin_Init(const interrupt_INTx_t * int_obj)
{
    Std_ReturnType ret=E_OK;
    if (NULL == int_obj)
    {
        ret=E_NOT_OK;
    }
    else
    {
        ret=gpio_pin_direction_initalize(&(int_obj->mcu_pin));

    }
    return ret;
}

static Std_ReturnType Interrupt_INTx_Clear_Flag(const interrupt_INTx_t *int_obj)
{
    Std_ReturnType ret=E_OK;
    if(NULL == int_obj)
    {
        ret=E_NOT_OK;

    }
    else
    {
        switch (int_obj->src)
        {
            case EXTI0:
            EXTI0_ClearFlag();
            break;

            case EXTI1:
            EXTI1_ClearFlag();
            break;

            case EXTI2:
            EXTI2_ClearFlag();
            break;
        
            default:
            break;
        }

    }
    return ret;

}

/*----------Call back function Section --------------*/

static Std_ReturnType EXTI0_SetInterruptHandler(void (*pf)(void))
{
    Std_ReturnType ret=E_OK;
    if(NULL == pf)
    {
        ret=E_NOT_OK;
    }
    else
    {
        EXTI0_InterruptHandler=pf;
    }
    return ret;
}
static Std_ReturnType EXTI1_SetInterruptHandler(void (*pf)(void))
{
    Std_ReturnType ret=E_OK;
    if(NULL == pf)
    {
        ret=E_NOT_OK;
    }
    else
    {
        EXTI1_InterruptHandler=pf;

    }
    return ret;
}
static Std_ReturnType EXTI2_SetInterruptHandler(void (*pf)(void))
{
    Std_ReturnType ret=E_OK;
    if(NULL == pf)
    {
        ret=E_NOT_OK;
    }
    else
    {

        EXTI2_InterruptHandler=pf;
    }
    return ret;
}
static Std_ReturnType Interrupt_INTx_SetInterruptHandler(const interrupt_INTx_t * int_obj)
{
    Std_ReturnType ret=E_OK;
    if(NULL == int_obj)
    {
        ret=E_NOT_OK;
    }
    else
    {
        switch(int_obj->src)
        {
            case EXTI0:
            EXTI0_SetInterruptHandler(int_obj->pf);
            break;
            case EXTI1:
            EXTI1_SetInterruptHandler(int_obj->pf);
            break;
            case EXTI2:
            EXTI2_SetInterruptHandler(int_obj->pf);
            break;
        }
    }
    return ret;
}

void EXTI0_ISR(void)
{
    //clear flag
    EXTI0_ClearFlag();
    //code
    // call back function
    if(NULL != EXTI0_InterruptHandler)
    {

        EXTI0_InterruptHandler();
    }
}

void EXTI1_ISR(void)
{
    //clear flag
    EXTI1_ClearFlag();
    //code
    // call back function
    if(NULL != EXTI1_InterruptHandler)
    {

        EXTI1_InterruptHandler();
    }
}
void EXTI2_ISR(void)
{
    //clear flag
    EXTI2_ClearFlag();
    //code
    // call back function
    if(NULL != EXTI2_InterruptHandler)
    {

        EXTI2_InterruptHandler();
    }
}

void RB4_ISR(uint8 RB4_Int)
{
    //clear flag
    EXTI_RBx_InterruptClearFlag();
    switch(RB4_Int)
    {
        case 0:
        if(NULL != RB4_InterruptHandler_LOW)
        {
            RB4_InterruptHandler_LOW();
        }
        break;
        
        case 1:
        if(NULL != RB4_InterruptHandler_HIGH)
        {
            RB4_InterruptHandler_HIGH();
        }
        break;
    }   
}

void RB5_ISR(uint8 RB5_Int)
{
    //clear flag
    EXTI_RBx_InterruptClearFlag();
    switch(RB5_Int)
    {
        case 0:
        if(NULL != RB5_InterruptHandler_LOW)
        {
            RB5_InterruptHandler_LOW();
        }
        break;
        
        case 1:
        if(NULL != RB5_InterruptHandler_HIGH)
        {
            RB5_InterruptHandler_HIGH();
        }
        break;
    }   
}


void RB6_ISR(uint8 RB6_Int)
{
    //clear flag
    EXTI_RBx_InterruptClearFlag();
    switch(RB6_Int)
    {
        case 0:
        if(NULL != RB6_InterruptHandler_LOW)
        {
            RB6_InterruptHandler_LOW();
        }
        break;
        
        case 1:
        if(NULL != RB6_InterruptHandler_HIGH)
        {
            RB6_InterruptHandler_HIGH();
        }
        break;
    }   
}

void RB7_ISR(uint8 RB7_Int)
{
    //clear flag
    EXTI_RBx_InterruptClearFlag();
    switch(RB7_Int)
    {
        case 0:
        if(NULL != RB7_InterruptHandler_LOW)
        {
            RB7_InterruptHandler_LOW();
        }
        break;
        
        case 1:
        if(NULL != RB7_InterruptHandler_HIGH)
        {
            RB7_InterruptHandler_HIGH();
        }
        break;
    }   
}