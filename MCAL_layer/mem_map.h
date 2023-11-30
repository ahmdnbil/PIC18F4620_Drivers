/**
 * @file mem_map.h
 * @author Ahmed Nabil (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-11-17
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef MEM_MAP_H
#define MEM_MAP_H

/*-------------------------------------section includes---------------------------------------*/
/*---------------------------------------Data types-------------------------------------------*/
typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned int uint32;
typedef signed char sint8;
typedef signed short sint16;
typedef signed int sint32;

typedef uint8 Std_ReturnType;

/*---------------------------------------MACRO function declarations--------------------------*/
#define HWRREG8(_X) *((uint8 volatile *)_X)
#define __at(x) __attribute__((address(x)))

/*---------------------------------------MACRO Declarations-----------------------------------*/
/*--------------------GPIO Register--------------------*/
#define TRISE HWRREG8(0xF96)
#define TRISD HWRREG8(0xF95)
#define TRISC HWRREG8(0xF94)
#define TRISB HWRREG8(0xF93)
#define TRISA HWRREG8(0xF92)

#define LATE HWRREG8(0xF8D)
#define LATD HWRREG8(0xF8C)
#define LATC HWRREG8(0xF8B)
#define LATB HWRREG8(0xF8A)
#define LATA HWRREG8(0xF89)

#define PORTE HWRREG8(0xF84)
#define PORTD HWRREG8(0xF83)
#define PORTC HWRREG8(0xF82)
#define PORTB HWRREG8(0xF81)
#define PORTA HWRREG8(0xF80)
/*-----------------------------------------------------*/

/*--------------------Interrupt Reg--------------------*/
#define INTCON HWRREG8(0xFF2)
#define INTCON2 HWRREG8(0xFF1)
#define INTCON3 HWRREG8(0xFF0)

//typedef union
//{
//    struct
//    {
//        uint8 RBIF : 1;
//        uint8 INT0IF : 1;
//        uint8 TMR0IF : 1;
//        uint8 RBIE : 1;
//        uint8 INT0IE : 1;
//        uint8 TMR0IE : 1;
//        uint8 PEIE : 1;
//        uint8 GIE : 1;
//    };
//
//    struct
//    {
//        uint8 : 1;
//        uint8 INT0IF : 1;
//        uint8 T0IF : 1;
//        uint8 : 1;
//        uint8 INT0E : 1;
//        uint8 T0IE : 1;
//        uint8 PEIE : 1;
//        uint8 GIE : 1;
//    };
//    struct
//    {
//        uint8 : 6;
//        uint8 GIEL : 1;
//        uint8 GIEH : 1;
//    };
//
//} INTCONbits_t;
//extern volatile INTCONbits_t INTCONbits __at(0xFF2);

/*-----------------------------------------------------*/

/*--------------------EEPROM Reg-----------------------*/
#define EEADRH HWRREG8(0xFAA)
#define EEADR HWRREG8(0xFA9)
#define EEDATA HWRREG8(0xFA8)
#define EECON2 HWRREG8(0xFA7)
#define EECON1 HWRREG8(0xFA6)

//typedef union 
//{
//    struct
//    {
//        uint8 RD:1;
//        uint8 WR:1;
//        uint8 WREN:1;
//        uint8 WRERR:1;
//        uint8 FREE:1;
//        uint8 :1;
//        uint8 CFGS:1;
//        uint8 EEPGD:1;
//    };
//    
//}EECON1bits_t;
//
//extern volatile EECON1bits_t EECON1bits __at(0xFA6) ;


/*-----------------------------------------------------*/

/*---------------------------------------function declarations--------------------------------*/

#endif /* MEM_MAP_H */
