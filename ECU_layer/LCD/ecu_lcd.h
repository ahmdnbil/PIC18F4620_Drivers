/**
 * @file ecu_lcd.h
 * @author Ahmed Nabil (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-11-10
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef ECU_LCD_H
#define	ECU_LCD_H

/*-------------------------------------section includes---------------------------------------*/
#include "./../../MCAL_layer/GPIO/hal_gpio.h"
#include "./ecu_lcd_cfg.h"

/*---------------------------------------MACRO Declarations-----------------------------------*/
#define LCD_CLEAR_DISPLAY                                              0x01
#define LCD_RETURN_HOME                                                0x02
#define LCD_ENTRY_MODE_SET_DEC_SHIFT_OFF                               0x04
#define LCD_ENTRY_MODE_SET_DEC_SHIFT_ON                                0x05
#define LCD_ENTRY_MODE_SET_INC_SHIFT_OFF                               0x06
#define LCD_ENTRY_MODE_SET_INC_SHIFT_ON                                0x07
#define LCD_DISPLAY_OFF                                                0x08
#define LCD_CURSOR_OFF_BLINK_OFF                                       0x0C
#define LCD_CURSOR_OFF_BLINK_ON                                        0x0D
#define LCD_CURSOR_ON_BLINK_OFF                                        0x0E
#define LCD_CURSOR_ON_BLINK_ON                                         0x0F
#define LCD_SHIFT_CURSOR_POSTION_LEFT                                  0x10
#define LCD_SHIFT_CURSOR_POSTION_RIGHT                                 0x14
#define LCD_SHIFT_ENTIRE_DISPLAY_LEFT                                  0x18
#define LCD_SHIFT_ENTIRE_DISPLAY_RIGHT                                 0x1C
#define LCD_FUNC_SET_4BIT_MODE                                         0x28
#define LCD_FUNC_SET_8BIT_MODE                                         0x38
#define CGRAM_FIRST_ADDRESS                                            0x40

#define DDRAM_FIRST_ROW_ADDRESS                                        0x80
#define DDRAM_SECOND_ROW_ADDRESS                                       0xC0
#define DDRAM_THIRD_ROW_ADDRESS                                        0x94
#define DDRAM_FOURTH_ROW_ADDRESS                                       0xD4

//for delay function calculation
#define _XTAL_FREQ 4000000UL

#define ROW1 1
#define ROW2 2
#define ROW3 3
#define ROW4 4
/*---------------------------------------MACRO function declarations--------------------------*/
/*---------------------------------------Data types-------------------------------------------*/
typedef struct
{
    pin_config_t lcd_rs;
    pin_config_t lcd_en;
    pin_config_t lcd_data[4];
}lcd_4bit_t;

typedef struct
{
    pin_config_t lcd_rs;
    pin_config_t lcd_en;
    pin_config_t lcd_data[8];
}lcd_8bit_t;
/*-------------------------------------function declarations-------------------------------------*/
/**
 * @brief 
 * 
 * @param lcd 
 * @return Std_ReturnType 
 */
Std_ReturnType lcd_4bit_initalize(const lcd_4bit_t* lcd);
/**
 * @brief 
 * 
 * @param lcd 
 * @param command 
 * @return Std_ReturnType 
 */
Std_ReturnType lcd_4bit_send_command(const lcd_4bit_t* lcd,uint8 command);
/**
 * @brief 
 * 
 * @param lcd 
 * @param data 
 * @return Std_ReturnType 
 */
Std_ReturnType lcd_4bit_send_data(const lcd_4bit_t* lcd,uint8 data);
/**
 * @brief 
 * 
 * @param lcd 
 * @param row 
 * @param col 
 * @param data 
 * @return Std_ReturnType 
 */
Std_ReturnType lcd_4bit_send_data_pos(const lcd_4bit_t* lcd,uint8 row,uint8 col,uint8 data);
/**
 * @brief 
 * 
 * @param lcd 
 * @param string 
 * @return Std_ReturnType 
 */
Std_ReturnType lcd_4bit_send_string(const lcd_4bit_t* lcd,uint8 *string);
/**
 * @brief 
 * 
 * @param lcd 
 * @param row 
 * @param col 
 * @param string 
 * @return Std_ReturnType 
 */
Std_ReturnType lcd_4bit_send_string_pos(const lcd_4bit_t* lcd,uint8 row,uint8 col,uint8 *string);
/**
 * @brief 
 * 
 * @param lcd 
 * @param row 
 * @param col 
 * @param _chr 
 * @param mem_pos 
 * @return Std_ReturnType 
 */
Std_ReturnType lcd_4bit_send_custom_char(const lcd_4bit_t* lcd,uint8 row,uint8 col,const uint8 _chr[],uint8 mem_pos);

/**
 * @brief 
 * 
 * @param _lcd 
 * @param str 
 * @param number 
 * @return Std_ReturnType 
 */
Std_ReturnType lcd_4bit_send_number(const lcd_4bit_t * _lcd,const uint8 * str,uint32 number);
/**
 * @brief 
 * 
 * @param _lcd 
 * @param str 
 * @param row 
 * @param col 
 * @param number 
 * @return Std_ReturnType 
 */
Std_ReturnType lcd_4bit_send_number_pos(const lcd_4bit_t * _lcd,const uint8 * str,uint8 row,uint8 col,uint32 number);

/*--------------------------8bit declarations-----------------------------------------------*/
/**
 * @brief 
 * 
 * @param lcd 
 * @return Std_ReturnType 
 */
Std_ReturnType lcd_8bit_initalize(const lcd_8bit_t* lcd);
/**
 * @brief 
 * 
 * @param lcd 
 * @param command 
 * @return Std_ReturnType 
 */
Std_ReturnType lcd_8bit_send_command(const lcd_8bit_t* lcd,uint8 command);
/**
 * @brief 
 * 
 * @param lcd 
 * @param data 
 * @return Std_ReturnType 
 */
Std_ReturnType lcd_8bit_send_data(const lcd_8bit_t* lcd,uint8 data);
/**
 * @brief 
 * 
 * @param lcd 
 * @param row 
 * @param col 
 * @param data 
 * @return Std_ReturnType 
 */
Std_ReturnType lcd_8bit_send_data_pos(const lcd_8bit_t* lcd,uint8 row,uint8 col,uint8 data);
/**
 * @brief 
 * 
 * @param lcd 
 * @param string 
 * @return Std_ReturnType 
 */
Std_ReturnType lcd_8bit_send_string(const lcd_8bit_t* lcd,uint8 *string);
/**
 * @brief 
 * 
 * @param lcd 
 * @param row 
 * @param col 
 * @param string 
 * @return Std_ReturnType 
 */
Std_ReturnType lcd_8bit_send_string_pos(const lcd_8bit_t* lcd,uint8 row,uint8 col,uint8 *string);
/**
 * @brief 
 * 
 * @param lcd 
 * @param row 
 * @param col 
 * @param _chr 
 * @param mem_pos 
 * @return Std_ReturnType 
 */
Std_ReturnType lcd_8bit_send_custom_char(const lcd_8bit_t* lcd,uint8 row,uint8 col,const uint8 _chr[],uint8 mem_pos);

/**
 * @brief 
 * 
 * @param _lcd 
 * @param str 
 * @param number 
 * @return Std_ReturnType 
 */
Std_ReturnType lcd_8bit_send_number(const lcd_8bit_t * _lcd,const uint8 * str,uint32 number);

/**
 * @brief 
 * 
 * @param _lcd 
 * @param str 
 * @param row 
 * @param col 
 * @param number 
 * @return Std_ReturnType 
 */
Std_ReturnType lcd_8bit_send_number_pos(const lcd_4bit_t * _lcd,const uint8 * str,uint8 row,uint8 col,uint32 number);
#endif	/* ECU_LCD_H */

