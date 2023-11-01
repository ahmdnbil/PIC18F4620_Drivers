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
uint8 getValue;
pin_config_t pin1=
{
  .direction=OUTPUT,
  .logic=LOW,
  .port=PORTD_INDEX,
  .pin=PIN0
};
/*-------------------------------------------------------------------*/

int main()
{

  Std_ReturnType ret=E_OK;
  ret=keypad_initalize(&keypad);
  ret=gpio_pin_direction_initalize(&pin1);
  ret=gpio_pin_write_logic(&pin1,HIGH);

  while (1)
  {
      ret=keypad_get_value(&keypad,&getValue);
    
  }
  return (EXIT_SUCCESS);
}

