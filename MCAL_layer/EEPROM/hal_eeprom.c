/**
 * @file hal_eeprom.c
 * @author Ahmed Nabil (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-11-17
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "./hal_eeprom.h"

Std_ReturnType Data_EEPROM_WriteByte(uint16 bAdd, uint8 bData)
{
    Std_ReturnType ret = E_OK;
    
    /*Read the Interrupt status "Enabled or Disabled" */
    uint8 GlobalInterruptStatus = INTCONbits.GIE;
    
    /*update the address Register*/
    EEADRH= (uint8)((bAdd >>8) & 3);
    EEADR = (uint8)bAdd;
    
    /*Update the Data Register*/
    EEDATA=bData;
    
    /*Select Access data EEPROM memory*/
    EECON1bits.EEPGD= ACCESS_EEPROM_PROGRAM_MEMORY;
    EECON1bits.CFGS=ACCESS_EEPROM_OR_FLASH;
    
    /*Allows write cycles to flash program/data EEPROM*/
    EECON1bits.WREN= ALLOW_WRITE_CYCLE_FLASH_EEPROM;
    
    /*Disable all interrupts "General Interrupt" */
    INTERRUPT_GlobalInterruptDisable();
    
    /* Write Required Sequence : 0x55 -> 0xAA  */
    EECON2=0x55;
    EECON2=0xAA;
    
    /*Initiate a data EEPROM Erase/write cycle */
    EECON1bits.WR=INITIATE_DATA_EEPROM_WRITE_ERASE;
    
    /*wait for write to complete*/
    while( 1 == EECON1bits.WR);
    
    /*Inhibit write cycle to flash program/ data EEPROM*/
    EECON1bits.WREN=INHIBIT_WRITE_CYCLE_FLASH_EEPROM;
    
    /*Restore the Interrupt status "Enabled or disabled " */
    INTCONbits.GIE=GlobalInterruptStatus;
}
Std_ReturnType Data_EEPROM_ReadByte(uint16 bAdd, uint8 *bData)
{
    Std_ReturnType ret = E_OK;
    if (NULL == bData)
    {
        ret = E_NOT_OK;
    }
    else
    {
        /*update the address Register*/
        EEADRH= (uint8)((bAdd >>8) & 3);
        EEADR = (uint8)bAdd;
        
        /*Select Access data EEPROM memory*/
        EECON1bits.EEPGD= ACCESS_EEPROM_PROGRAM_MEMORY;
        EECON1bits.CFGS=ACCESS_EEPROM_OR_FLASH;
        
        /*Initiate a data EEPROM read cycle*/
        EECON1bits.RD=INITIATE_DATA_EEPROM_READ;
        
        NOP();
        NOP();
        *bData =EEDATA;
    }
    return ret;
}