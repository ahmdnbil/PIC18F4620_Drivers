/* 
 * File:   mcal_std_types.h
 * Author: User
 *
 * Created on October 11, 2023, 9:19 PM
 */

#ifndef MCAL_STD_TYPES_H
#define	MCAL_STD_TYPES_H


/* section includes*/
#include "./std_libraries.h"
#include "./compiler.h"

/* MACRO Declarations */



#define STD_HIGH   0x01
#define STD_LOW    0x00

#define STD_ON     0x01
#define STD_OFF    0x00

#define STD_ACTIVE 0x01
#define STD_IDLE   0x00

#define E_OK     (Std_ReturnType)0x01
#define E_NOT_OK (Std_ReturnType)0x00

/* MACRO function declarations */

/* Data types*/
typedef unsigned char  uint8;
typedef unsigned short uint16;
typedef unsigned int   uint32;
typedef signed char    sint8;
typedef signed short   sint16;
typedef signed int     sint32;

typedef uint8 Std_ReturnType;





/*function declarations */
#endif	/* MCAL_STD_TYPES_H */

