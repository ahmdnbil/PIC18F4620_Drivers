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
#include "MCAL_layer/CCP1/hal_ccp1.h"

/*-------------------------------------------------------------------*/
void TIMER_Handeler(void);
/*----------------------------Global Variables-----------------------*/
volatile uint16 flag = 0;

timer2_t tmr2 =
    {
        .Timer2_interruptHandeler = NULL,
        .postscaler = T2_POSTSCALER_1,
        .prescaler = T2_PRESCALER_1,
        .priority = INTERRUPT_HIGH_PRIORITY,
        .tiemr2_preload = 0};

ccp_t ccp1_obj = {
    .ccp_inst = CCP1_INST,
    .CCP_InterruptHandler = NULL,
    .priority = INTERRUPT_HIGH_PRIORITY,

    .ccp_mode = CCP_PWM_MODE_SELECTED,
    .PWM_Freq = 20000,
    .timer2_prescaler_value = CCP_T2_POSTSCALER_1,
    .timer2_postscaler_value = CCP_T2_PRESCALER_1,
    .ccp_mode_variant = CCP_PWM_MODE,
};

ccp_t ccp2_obj = {
    .ccp_inst = CCP2_INST,
    .CCP_InterruptHandler = NULL,
    .priority = INTERRUPT_HIGH_PRIORITY,

    .ccp_mode = CCP_PWM_MODE_SELECTED,
    .PWM_Freq = 20000,
    .timer2_prescaler_value = CCP_T2_POSTSCALER_1,
    .timer2_postscaler_value = CCP_T2_PRESCALER_1,
    .ccp_mode_variant = CCP_PWM_MODE,
};
/*-------------------------------------------------------------------*/
Std_ReturnType ret = E_OK;
int main()
{
  ret = CCP_Init(&ccp1_obj);
  ret = CCP_PWM_Set_Duty(&ccp1_obj, 50);
  ret = CCP_PWM_Start(&ccp1_obj);

  ret = CCP_Init(&ccp2_obj);
  ret = CCP_PWM_Set_Duty(&ccp2_obj, 75);
  ret = CCP_PWM_Start(&ccp2_obj);

  ret = timer2_Intit(&tmr2);
  while (1)
  {
    // for (int i = 0; i < 100; i += 5)
    // {
    //   __delay_ms(5);
    //   ret = CCP_PWM_Set_Duty(&ccp, i);
    // }
  }
  return (EXIT_SUCCESS);
}

void TIMER_Handeler(void)
{
  flag++;
}