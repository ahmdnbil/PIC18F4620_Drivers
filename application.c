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

/*-------------------------------------------------------------------*/
int main()
{
    uint8 getValue=0;
  Std_ReturnType ret=E_OK;
  ret=keypad_initalize(&keypad);
  while (1)
  {
      ret=keypad_get_value(&keypad,&getValue);
    
  }
  return (EXIT_SUCCESS);
}

