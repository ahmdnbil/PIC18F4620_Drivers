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
void toggleLED_Low(void);
void toggleLED_High(void);
void toggleLED2_Low(void);
void toggleLED2_High(void);
void toggleLED3_Low(void);
void toggleLED3_High(void);
void toggleLED4_Low(void);
void toggleLED4_High(void);


/*----------------------------Global Variables-----------------------*/

led_t led1={.led_status=LOW,.pin=PIN0,.port_name=PORTD_INDEX};
led_t led2={.led_status=LOW,.pin=PIN1,.port_name=PORTD_INDEX};
led_t led3={.led_status=LOW,.pin=PIN2,.port_name=PORTD_INDEX};
led_t led4={.led_status=LOW,.pin=PIN3,.port_name=PORTD_INDEX};

interrupt_RBx_t int0={.pf=toggleLED_Low,.pf2=toggleLED_High,.priority=INTERRUPT_HIGH_PRIORITY,.mcu_pin.pin=PIN4,.mcu_pin.port=PORTB_INDEX,.mcu_pin.logic=LOW,.mcu_pin.direction=INPUT};
interrupt_RBx_t int1={.pf=toggleLED2_Low,.pf2=toggleLED2_High,.priority=INTERRUPT_HIGH_PRIORITY,.mcu_pin.pin=PIN5,.mcu_pin.port=PORTB_INDEX,.mcu_pin.logic=LOW,.mcu_pin.direction=INPUT};
interrupt_RBx_t int2={.pf=toggleLED3_Low,.pf2=toggleLED3_High,.priority=INTERRUPT_HIGH_PRIORITY,.mcu_pin.pin=PIN6,.mcu_pin.port=PORTB_INDEX,.mcu_pin.logic=LOW,.mcu_pin.direction=INPUT};
interrupt_RBx_t int3={.pf=toggleLED4_Low,.pf2=toggleLED4_High,.priority=INTERRUPT_HIGH_PRIORITY,.mcu_pin.pin=PIN7,.mcu_pin.port=PORTB_INDEX,.mcu_pin.logic=LOW,.mcu_pin.direction=INPUT};
/*-------------------------------------------------------------------*/
Std_ReturnType ret=E_OK;
int main()
{

  
  ret=interrupt_RBx_Init(&int0);
  ret=interrupt_RBx_Init(&int1);
  ret=interrupt_RBx_Init(&int2);
  ret=interrupt_RBx_Init(&int3);

  
  ret=led_initalize(&led1);
  ret=led_initalize(&led2);
  ret=led_initalize(&led3);
  ret=led_initalize(&led4);

  while (1)
  {

  }
  return (EXIT_SUCCESS);
}



void toggleLED_Low(void)
{
  ret= led_turn_off(&led1);
}
void toggleLED_High(void)
{
  ret= led_turn_on(&led1);
}

void toggleLED2_Low(void)
{
  ret= led_turn_off(&led2);
}
void toggleLED2_High(void)
{
  ret= led_turn_on(&led2);
}
void toggleLED3_Low(void)
{
  ret= led_turn_off(&led3);
}
void toggleLED3_High(void)
{
  ret= led_turn_on(&led3);
}

void toggleLED4_Low(void)
{
  ret= led_turn_off(&led4);
}
void toggleLED4_High(void)
{
  ret= led_turn_on(&led4);
}