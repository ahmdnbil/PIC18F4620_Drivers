/**
 * @file ecu_lcd.c
 * @author Ahmed Nabil (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-11-10
 * 
 * @copyright Copyright (c) 2023
 * 
 */

/*---------------------------Include Section-------------------------------------*/
#include "./ecu_lcd.h"
/*---------------------------Static Prototype function---------------------------*/
static Std_ReturnType lcd_send_4bits(const lcd_4bit_t *lcd, uint8 _command_data);
static Std_ReturnType lcd_4bit_send_enable(const lcd_4bit_t *lcd);
static Std_ReturnType lcd_send_8bits(const lcd_8bit_t *lcd, uint8 _command_data);
static Std_ReturnType lcd_8bit_send_enable(const lcd_8bit_t *lcd);
static Std_ReturnType lcd_8bit_set_cursor(const lcd_8bit_t *lcd, uint8 row, uint8 col);
static Std_ReturnType lcd_4bit_set_cursor(const lcd_4bit_t *lcd, uint8 row, uint8 col);
static void convertNumberToString(uint32 value, uint8 *str);


/*---------------------------Function Definition-------------------------------------*/

Std_ReturnType lcd_4bit_initalize(const lcd_4bit_t *lcd)
{
    Std_ReturnType ret = E_OK;
    if (NULL == lcd)
    {
        ret = E_NOT_OK;
    }
    else
    {
        ret = gpio_pin_initalize(&(lcd->lcd_en));
        ret = gpio_pin_initalize(&(lcd->lcd_rs));
        ret = gpio_pin_initalize(&(lcd->lcd_data[0]));
        ret = gpio_pin_initalize(&(lcd->lcd_data[1]));
        ret = gpio_pin_initalize(&(lcd->lcd_data[2]));
        ret = gpio_pin_initalize(&(lcd->lcd_data[3]));

        __delay_ms(20);
        ret = lcd_4bit_send_command(lcd, LCD_FUNC_SET_8BIT_MODE);
        __delay_ms(5);
        ret = lcd_4bit_send_command(lcd, LCD_FUNC_SET_8BIT_MODE);
        __delay_us(150);
        ret = lcd_4bit_send_command(lcd, LCD_FUNC_SET_8BIT_MODE);

        ret = lcd_4bit_send_command(lcd, LCD_CLEAR_DISPLAY);
        ret = lcd_4bit_send_command(lcd, LCD_RETURN_HOME);
        ret = lcd_4bit_send_command(lcd, LCD_ENTRY_MODE_SET_INC_SHIFT_OFF);
        ret = lcd_4bit_send_command(lcd, LCD_CURSOR_OFF_BLINK_OFF);
        ret = lcd_4bit_send_command(lcd, LCD_FUNC_SET_4BIT_MODE);
        ret = lcd_4bit_send_command(lcd, DDRAM_FIRST_ROW_ADDRESS);
    }
    return ret;
}
Std_ReturnType lcd_4bit_send_command(const lcd_4bit_t *lcd, uint8 command)
{
    Std_ReturnType ret = E_OK;
    if (NULL == lcd)
    {
        ret = E_NOT_OK;
    }
    else
    {
        // RS=LOW to send command
        ret = gpio_pin_write_logic(&(lcd->lcd_rs), LOW);
        // sending HIGH nipple
        ret = lcd_send_4bits(lcd, command >> 4);
        // sned enable signal
        ret = lcd_4bit_send_enable(lcd);
        // sending LOW nipple
        ret = lcd_send_4bits(lcd, command);
        // sned enable signal
        ret = lcd_4bit_send_enable(lcd);
    }
    return ret;
}

Std_ReturnType lcd_4bit_send_data(const lcd_4bit_t *lcd, uint8 data)
{
    Std_ReturnType ret = E_OK;
    if (NULL == lcd)
    {
        ret = E_NOT_OK;
    }
    else
    {
        // RS=LOW to send command
        ret = gpio_pin_write_logic(&(lcd->lcd_rs), HIGH);
        // sending HIGH nipple
        ret = lcd_send_4bits(lcd, data >> 4);
        // sned enable signal
        ret = lcd_4bit_send_enable(lcd);
        // sending LOW nipple
        ret = lcd_send_4bits(lcd, data);
        // sned enable signal
        ret = lcd_4bit_send_enable(lcd);
    }
    return ret;
}

Std_ReturnType lcd_4bit_send_data_pos(const lcd_4bit_t *lcd, uint8 row, uint8 col, uint8 data)
{
    Std_ReturnType ret = E_OK;
    if (NULL == lcd)
    {
        ret = E_NOT_OK;
    }
    else
    {
        ret = lcd_4bit_set_cursor(lcd, row, col);
        ret = lcd_4bit_send_data(lcd, data);
    }
    return ret;
}

Std_ReturnType lcd_4bit_send_string(const lcd_4bit_t *lcd, uint8 *string)
{
    Std_ReturnType ret = E_OK;
    uint8 local_u8Counter = 0;
    if (NULL == lcd)
    {
        ret = E_NOT_OK;
    }
    else
    {
        while (NULL != string[local_u8Counter])
        {
            ret = lcd_4bit_send_data(lcd, string[local_u8Counter]);
            local_u8Counter++;
        }
    }
    return ret;
}

Std_ReturnType lcd_4bit_send_string_pos(const lcd_4bit_t *lcd, uint8 row, uint8 col, uint8 *string)
{
    Std_ReturnType ret = E_OK;
    uint8 local_u8Counter = 0;
    if (NULL == lcd)
    {
        ret = E_NOT_OK;
    }
    else
    {
        ret = lcd_4bit_set_cursor(lcd, row, col);
        while (NULL != string[local_u8Counter])
        {
            ret = lcd_4bit_send_data(lcd, string[local_u8Counter]);
            local_u8Counter++;
        }
    }
    return ret;
}

Std_ReturnType lcd_4bit_send_custom_char(const lcd_4bit_t *lcd, uint8 row, uint8 col, const uint8 _chr[], uint8 mem_pos)
{
    Std_ReturnType ret = E_OK;
    uint8 counter = 0;
    if (NULL == lcd || mem_pos > 8)
    {
        ret = E_NOT_OK;
    }
    else
    {
        mem_pos--;
        ret = lcd_4bit_send_command(lcd, CGRAM_FIRST_ADDRESS + (8 * mem_pos));
        for (counter = 0; counter < 8; counter++)
        {
            ret = lcd_4bit_send_data(lcd, _chr[counter]);
            __delay_us(50);
        }
        ret = lcd_4bit_send_data_pos(lcd, row, col, mem_pos);
    }
    return ret;
}

Std_ReturnType lcd_4bit_send_number(const lcd_4bit_t * _lcd,const uint8 * str,uint32 number)
{
    Std_ReturnType ret=E_OK;
    if(NULL == _lcd)
    {
        ret=E_NOT_OK;
    }
    else
    {
        convertNumberToString(number,str);
        ret=lcd_4bit_send_string(_lcd,str);
    }
    return ret;
}

Std_ReturnType lcd_4bit_send_number_pos(const lcd_4bit_t * _lcd,const uint8 * str,uint8 row,uint8 col,uint32 number)
{
    Std_ReturnType ret=E_OK;
    if(NULL == _lcd)
    {
        ret=E_NOT_OK;
    }
    else
    {
        convertNumberToString(number,str);
        ret=lcd_4bit_send_string_pos(_lcd,row,col,str);
    }
    return ret;
}

/*---------------------------8bit functions-----------------------------------*/

Std_ReturnType lcd_8bit_initalize(const lcd_8bit_t *lcd)
{
    Std_ReturnType ret = E_OK;
    if (NULL == lcd)
    {
        ret = E_NOT_OK;
    }
    else
    {
        ret = gpio_pin_initalize(&(lcd->lcd_en));
        ret = gpio_pin_initalize(&(lcd->lcd_rs));
        ret = gpio_pin_initalize(&(lcd->lcd_data[0]));
        ret = gpio_pin_initalize(&(lcd->lcd_data[1]));
        ret = gpio_pin_initalize(&(lcd->lcd_data[2]));
        ret = gpio_pin_initalize(&(lcd->lcd_data[3]));
        ret = gpio_pin_initalize(&(lcd->lcd_data[4]));
        ret = gpio_pin_initalize(&(lcd->lcd_data[5]));
        ret = gpio_pin_initalize(&(lcd->lcd_data[6]));
        ret = gpio_pin_initalize(&(lcd->lcd_data[7]));

        __delay_ms(20);
        ret = lcd_8bit_send_command(lcd, LCD_FUNC_SET_8BIT_MODE);
        __delay_ms(5);
        ret = lcd_8bit_send_command(lcd, LCD_FUNC_SET_8BIT_MODE);
        __delay_us(150);
        ret = lcd_8bit_send_command(lcd, LCD_FUNC_SET_8BIT_MODE);

        ret = lcd_8bit_send_command(lcd, LCD_CLEAR_DISPLAY);
        ret = lcd_8bit_send_command(lcd, LCD_RETURN_HOME);
        ret = lcd_8bit_send_command(lcd, LCD_ENTRY_MODE_SET_INC_SHIFT_OFF);
        ret = lcd_8bit_send_command(lcd, LCD_CURSOR_OFF_BLINK_OFF);
        ret = lcd_8bit_send_command(lcd, LCD_FUNC_SET_8BIT_MODE);
        ret = lcd_8bit_send_command(lcd, DDRAM_FIRST_ROW_ADDRESS);
    }
    return ret;
}

Std_ReturnType lcd_8bit_send_command(const lcd_8bit_t *lcd, uint8 command)
{
    Std_ReturnType ret = E_OK;
    if (NULL == lcd)
    {
        ret = E_NOT_OK;
    }
    else
    {
        // RS=LOW to send command
        ret = gpio_pin_write_logic(&(lcd->lcd_rs), LOW);
        // send all bits
        ret = lcd_send_8bits(lcd, command);
        // send enable
        ret = lcd_8bit_send_enable(lcd);
    }
    return ret;
}

Std_ReturnType lcd_8bit_send_data(const lcd_8bit_t *lcd, uint8 data)
{
    Std_ReturnType ret = E_OK;
    if (NULL == lcd)
    {
        ret = E_NOT_OK;
    }
    else
    {
        // RS=HIGH to send command
        ret = gpio_pin_write_logic(&(lcd->lcd_rs), HIGH);
        // send all bits
        ret = lcd_send_8bits(lcd, data);
        // send enable
        ret = lcd_8bit_send_enable(lcd);
    }
    return ret;
}

Std_ReturnType lcd_8bit_send_data_pos(const lcd_8bit_t *lcd, uint8 row, uint8 col, uint8 data)
{
    Std_ReturnType ret = E_OK;
    if (NULL == lcd)
    {
        ret = E_NOT_OK;
    }
    else
    {
        ret = lcd_8bit_set_cursor(lcd, row, col);
        ret = lcd_8bit_send_data(lcd, data);
    }
    return ret;
}

Std_ReturnType lcd_8bit_send_string(const lcd_8bit_t *lcd, uint8 *string)
{
    Std_ReturnType ret = E_OK;
    uint8 local_u8Counter = 0;
    if (NULL == lcd)
    {
        ret = E_NOT_OK;
    }
    else
    {
        while (NULL != string[local_u8Counter])
        {
            ret = lcd_8bit_send_data(lcd, string[local_u8Counter]);
            local_u8Counter++;
        }
    }
    return ret;
}

Std_ReturnType lcd_8bit_send_string_pos(const lcd_8bit_t *lcd, uint8 row, uint8 col, uint8 *string)
{
    Std_ReturnType ret = E_OK;
    uint8 local_u8Counter = 0;
    if (NULL == lcd)
    {
        ret = E_NOT_OK;
    }
    else
    {
        ret = lcd_8bit_set_cursor(lcd, row, col);
        while (NULL != string[local_u8Counter])
        {
            ret = lcd_8bit_send_data(lcd, string[local_u8Counter]);
            local_u8Counter++;
        }
    }
    return ret;
}

Std_ReturnType lcd_8bit_send_custom_char(const lcd_8bit_t *lcd, uint8 row, uint8 col, const uint8 _chr[], uint8 mem_pos)
{
    Std_ReturnType ret = E_OK;
    uint8 counter = 0;
    if (NULL == lcd || mem_pos > 8)
    {
        ret = E_NOT_OK;
    }
    else
    {
        mem_pos--;
        ret = lcd_8bit_send_command(lcd, CGRAM_FIRST_ADDRESS + (8 * mem_pos));
        for (counter = 0; counter < 8; counter++)
        {
            ret = lcd_8bit_send_data(lcd, _chr[counter]);
            __delay_us(50);
        }
        ret = lcd_8bit_send_data_pos(lcd, row, col, mem_pos);
    }
    return ret;
}

Std_ReturnType lcd_8bit_send_number(const lcd_8bit_t * _lcd,const uint8 * str,uint32 number)
{
    Std_ReturnType ret=E_OK;
    if(NULL == _lcd)
    {
        ret=E_NOT_OK;
    }
    else
    {
        convertNumberToString(number,str);
        ret=lcd_8bit_send_string(_lcd,str);
    }
    return ret;
}

Std_ReturnType lcd_8bit_send_number_pos(const lcd_4bit_t * _lcd,const uint8 * str,uint8 row,uint8 col,uint32 number)
{
    Std_ReturnType ret=E_OK;
    if(NULL == _lcd)
    {
        ret=E_NOT_OK;
    }
    else
    {
        convertNumberToString(number,str);
        ret=lcd_8bit_send_string_pos(_lcd,row,col,str);
    }
    return ret;
}

/*---------------------------------------helper functions------------------------------------------*/
static void convertNumberToString(uint32 value, uint8 *str)
{
    uint8 rest, counter = 0;
    uint32 reverseNumber = 1;

    if (0 == value)
    {
        str[0] = '0';
        str[1] = '\0';
    }
    else
    {

        while (value != 0)
        {
            reverseNumber = reverseNumber * 10 + (value % 10);
            value /= 10;
        }
        while (reverseNumber != 1)
        {
            rest = reverseNumber % 10;
            str[counter] = '0' + rest;
            reverseNumber /= 10;
            counter++;
        }
        str[counter] = '\0';
    }
}

static Std_ReturnType lcd_send_4bits(const lcd_4bit_t *lcd, uint8 _command_data)
{
    Std_ReturnType ret = E_OK;
    if (NULL == lcd)
    {
        ret = E_NOT_OK;
    }
    else
    {
        ret = gpio_pin_write_logic(&(lcd->lcd_data[0]), (_command_data >> 0) & 1);
        ret = gpio_pin_write_logic(&(lcd->lcd_data[1]), (_command_data >> 1) & 1);
        ret = gpio_pin_write_logic(&(lcd->lcd_data[2]), (_command_data >> 2) & 1);
        ret = gpio_pin_write_logic(&(lcd->lcd_data[3]), (_command_data >> 3) & 1);
    }
    return ret;
}

static Std_ReturnType lcd_4bit_send_enable(const lcd_4bit_t *lcd)
{
    Std_ReturnType ret = E_OK;
    if (NULL == lcd)
    {
        ret = E_NOT_OK;
    }
    else
    {
        ret = gpio_pin_write_logic(&(lcd->lcd_en), HIGH);
        __delay_us(5);
        ret = gpio_pin_write_logic(&(lcd->lcd_en), LOW);
    }
    return ret;
}

static Std_ReturnType lcd_send_8bits(const lcd_8bit_t *lcd, uint8 _command_data)
{
    Std_ReturnType ret = E_OK;
    if (NULL == lcd)
    {
        ret = E_NOT_OK;
    }
    else
    {
        ret = gpio_pin_write_logic(&(lcd->lcd_data[0]), (_command_data >> 0) & 1);
        ret = gpio_pin_write_logic(&(lcd->lcd_data[1]), (_command_data >> 1) & 1);
        ret = gpio_pin_write_logic(&(lcd->lcd_data[2]), (_command_data >> 2) & 1);
        ret = gpio_pin_write_logic(&(lcd->lcd_data[3]), (_command_data >> 3) & 1);
        ret = gpio_pin_write_logic(&(lcd->lcd_data[4]), (_command_data >> 4) & 1);
        ret = gpio_pin_write_logic(&(lcd->lcd_data[5]), (_command_data >> 5) & 1);
        ret = gpio_pin_write_logic(&(lcd->lcd_data[6]), (_command_data >> 6) & 1);
        ret = gpio_pin_write_logic(&(lcd->lcd_data[7]), (_command_data >> 7) & 1);
    }
    return ret;
}

static Std_ReturnType lcd_8bit_send_enable(const lcd_8bit_t *lcd)
{
    Std_ReturnType ret = E_OK;
    if (NULL == lcd)
    {
        ret = E_NOT_OK;
    }
    else
    {
        ret = gpio_pin_write_logic(&(lcd->lcd_en), HIGH);
        __delay_us(5);
        ret = gpio_pin_write_logic(&(lcd->lcd_en), LOW);
    }
    return ret;
}

static Std_ReturnType lcd_8bit_set_cursor(const lcd_8bit_t *lcd, uint8 row, uint8 col)
{
    Std_ReturnType ret = E_OK;
    // to make first column as ONE not ZERO
    col--;
    switch (row)
    {
    case ROW1:
        ret = lcd_8bit_send_command(lcd, DDRAM_FIRST_ROW_ADDRESS + col);
        break;
    case ROW2:
        ret = lcd_8bit_send_command(lcd, DDRAM_SECOND_ROW_ADDRESS + col);
        break;
    case ROW3:
        ret = lcd_8bit_send_command(lcd, DDRAM_THIRD_ROW_ADDRESS + col);
        break;
    case ROW4:
        ret = lcd_8bit_send_command(lcd, DDRAM_FOURTH_ROW_ADDRESS + col);
        break;

    default:
        break;
    }
    return ret;
}

static Std_ReturnType lcd_4bit_set_cursor(const lcd_4bit_t *lcd, uint8 row, uint8 col)
{
    Std_ReturnType ret = E_OK;
    // to make first column as ONE not ZERO
    col--;
    switch (row)
    {
    case ROW1:
        ret = lcd_4bit_send_command(lcd, DDRAM_FIRST_ROW_ADDRESS + col);
        break;
    case ROW2:
        ret = lcd_4bit_send_command(lcd, DDRAM_SECOND_ROW_ADDRESS + col);
        break;
    case ROW3:
        ret = lcd_4bit_send_command(lcd, DDRAM_THIRD_ROW_ADDRESS + col);
        break;
    case ROW4:
        ret = lcd_4bit_send_command(lcd, DDRAM_FOURTH_ROW_ADDRESS + col);
        break;

    default:
        break;
    }
    return ret;
}