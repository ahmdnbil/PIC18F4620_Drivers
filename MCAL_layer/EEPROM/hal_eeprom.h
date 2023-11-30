/**
 * @file hal_eeprom.h
 * @author Ahmed Nabil (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-11-17
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef HAL_EEPROM_H
#define HAL_EEPROM_H

/*-------------------------------------section includes---------------------------------------*/
#include "./../proc/pic18f4620.h"
#include "./../device_config.h"
#include "./../mcal_std_types.h"
#include "./hal_eeprom_cfg.h"
#include "./../interrupt/mcal_external_interrupt.h"
/*---------------------------------------MACRO Declarations-----------------------------------*/
#define ACCESS_FLASH_PROGRAM_MEMORY 1
#define ACCESS_EEPROM_PROGRAM_MEMORY 0

#define ACCESS_CONFIG_REGISTERS 1
#define ACCESS_EEPROM_OR_FLASH 0

#define ALLOW_WRITE_CYCLE_FLASH_EEPROM 1
#define INHIBIT_WRITE_CYCLE_FLASH_EEPROM 0

#define INITIATE_DATA_EEPROM_WRITE_ERASE 1
#define DATA_EEPROM_WRITE_ERASE_COMPLETED 0

#define INITIATE_DATA_EEPROM_READ 1
#define DATA_EEPROM_WRITE_ERASE_COMPLETED 0

/*---------------------------------------MACRO function declarations--------------------------*/
/*---------------------------------------Data types-------------------------------------------*/
/*---------------------------------------function declarations--------------------------------*/
Std_ReturnType Data_EEPROM_WriteByte(uint16 bAdd, uint8 bData);
Std_ReturnType Data_EEPROM_ReadByte(uint16 bAdd, uint8 *bData);

#endif /* HAL_EEPROM_H */
