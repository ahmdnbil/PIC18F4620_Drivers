# 1 "ECU_layer/KEYPAD/ecu_keypad.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 288 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "D:/New folder (2)/Microchip/MPLABX/v6.15/packs/Microchip/PIC18Fxxxx_DFP/1.4.151/xc8\\pic\\include\\language_support.h" 1 3
# 2 "<built-in>" 2
# 1 "ECU_layer/KEYPAD/ecu_keypad.c" 2
# 12 "ECU_layer/KEYPAD/ecu_keypad.c"
# 1 "ECU_layer/KEYPAD/./ecu_keypad.h" 1
# 16 "ECU_layer/KEYPAD/./ecu_keypad.h"
# 1 "ECU_layer/KEYPAD/./../../MCAL_layer/GPIO/hal_gpio.h" 1
# 16 "ECU_layer/KEYPAD/./../../MCAL_layer/GPIO/hal_gpio.h"
# 1 "ECU_layer/KEYPAD/./../../MCAL_layer/GPIO/../mcal_std_types.h" 1
# 13 "ECU_layer/KEYPAD/./../../MCAL_layer/GPIO/../mcal_std_types.h"
# 1 "ECU_layer/KEYPAD/./../../MCAL_layer/GPIO/.././std_libraries.h" 1
# 13 "ECU_layer/KEYPAD/./../../MCAL_layer/GPIO/.././std_libraries.h"
# 1 "D:\\ME\\EE\\career\\tools\\xc8\\v2.45\\pic\\include\\c99\\stdio.h" 1 3



# 1 "D:\\ME\\EE\\career\\tools\\xc8\\v2.45\\pic\\include\\c99\\musl_xc8.h" 1 3
# 5 "D:\\ME\\EE\\career\\tools\\xc8\\v2.45\\pic\\include\\c99\\stdio.h" 2 3





# 1 "D:\\ME\\EE\\career\\tools\\xc8\\v2.45\\pic\\include\\c99\\features.h" 1 3
# 11 "D:\\ME\\EE\\career\\tools\\xc8\\v2.45\\pic\\include\\c99\\stdio.h" 2 3
# 24 "D:\\ME\\EE\\career\\tools\\xc8\\v2.45\\pic\\include\\c99\\stdio.h" 3
# 1 "D:\\ME\\EE\\career\\tools\\xc8\\v2.45\\pic\\include\\c99\\bits/alltypes.h" 1 3
# 12 "D:\\ME\\EE\\career\\tools\\xc8\\v2.45\\pic\\include\\c99\\bits/alltypes.h" 3
typedef void * va_list[1];




typedef void * __isoc_va_list[1];
# 128 "D:\\ME\\EE\\career\\tools\\xc8\\v2.45\\pic\\include\\c99\\bits/alltypes.h" 3
typedef unsigned size_t;
# 143 "D:\\ME\\EE\\career\\tools\\xc8\\v2.45\\pic\\include\\c99\\bits/alltypes.h" 3
typedef __int24 ssize_t;
# 174 "D:\\ME\\EE\\career\\tools\\xc8\\v2.45\\pic\\include\\c99\\bits/alltypes.h" 3
typedef __int24 int24_t;
# 210 "D:\\ME\\EE\\career\\tools\\xc8\\v2.45\\pic\\include\\c99\\bits/alltypes.h" 3
typedef __uint24 uint24_t;
# 255 "D:\\ME\\EE\\career\\tools\\xc8\\v2.45\\pic\\include\\c99\\bits/alltypes.h" 3
typedef long long off_t;
# 409 "D:\\ME\\EE\\career\\tools\\xc8\\v2.45\\pic\\include\\c99\\bits/alltypes.h" 3
typedef struct _IO_FILE FILE;
# 25 "D:\\ME\\EE\\career\\tools\\xc8\\v2.45\\pic\\include\\c99\\stdio.h" 2 3
# 52 "D:\\ME\\EE\\career\\tools\\xc8\\v2.45\\pic\\include\\c99\\stdio.h" 3
typedef union _G_fpos64_t {
 char __opaque[16];
 double __align;
} fpos_t;

extern FILE *const stdin;
extern FILE *const stdout;
extern FILE *const stderr;





FILE *fopen(const char *restrict, const char *restrict);
FILE *freopen(const char *restrict, const char *restrict, FILE *restrict);
int fclose(FILE *);

int remove(const char *);
int rename(const char *, const char *);

int feof(FILE *);
int ferror(FILE *);
int fflush(FILE *);
void clearerr(FILE *);

int fseek(FILE *, long, int);
long ftell(FILE *);
void rewind(FILE *);

int fgetpos(FILE *restrict, fpos_t *restrict);
int fsetpos(FILE *, const fpos_t *);

size_t fread(void *restrict, size_t, size_t, FILE *restrict);
size_t fwrite(const void *restrict, size_t, size_t, FILE *restrict);

int fgetc(FILE *);
int getc(FILE *);
int getchar(void);





int ungetc(int, FILE *);
int getch(void);

int fputc(int, FILE *);
int putc(int, FILE *);
int putchar(int);





void putch(char);

char *fgets(char *restrict, int, FILE *restrict);

char *gets(char *);


int fputs(const char *restrict, FILE *restrict);
int puts(const char *);

__attribute__((__format__(__printf__, 1, 2)))
int printf(const char *restrict, ...);
__attribute__((__format__(__printf__, 2, 3)))
int fprintf(FILE *restrict, const char *restrict, ...);
__attribute__((__format__(__printf__, 2, 3)))
int sprintf(char *restrict, const char *restrict, ...);
__attribute__((__format__(__printf__, 3, 4)))
int snprintf(char *restrict, size_t, const char *restrict, ...);

__attribute__((__format__(__printf__, 1, 0)))
int vprintf(const char *restrict, __isoc_va_list);
int vfprintf(FILE *restrict, const char *restrict, __isoc_va_list);
__attribute__((__format__(__printf__, 2, 0)))
int vsprintf(char *restrict, const char *restrict, __isoc_va_list);
__attribute__((__format__(__printf__, 3, 0)))
int vsnprintf(char *restrict, size_t, const char *restrict, __isoc_va_list);

__attribute__((__format__(__scanf__, 1, 2)))
int scanf(const char *restrict, ...);
__attribute__((__format__(__scanf__, 2, 3)))
int fscanf(FILE *restrict, const char *restrict, ...);
__attribute__((__format__(__scanf__, 2, 3)))
int sscanf(const char *restrict, const char *restrict, ...);

__attribute__((__format__(__scanf__, 1, 0)))
int vscanf(const char *restrict, __isoc_va_list);
int vfscanf(FILE *restrict, const char *restrict, __isoc_va_list);
__attribute__((__format__(__scanf__, 2, 0)))
int vsscanf(const char *restrict, const char *restrict, __isoc_va_list);

void perror(const char *);

int setvbuf(FILE *restrict, char *restrict, int, size_t);
void setbuf(FILE *restrict, char *restrict);

char *tmpnam(char *);
FILE *tmpfile(void);




FILE *fmemopen(void *restrict, size_t, const char *restrict);
FILE *open_memstream(char **, size_t *);
FILE *fdopen(int, const char *);
FILE *popen(const char *, const char *);
int pclose(FILE *);
int fileno(FILE *);
int fseeko(FILE *, off_t, int);
off_t ftello(FILE *);
int dprintf(int, const char *restrict, ...);
int vdprintf(int, const char *restrict, __isoc_va_list);
void flockfile(FILE *);
int ftrylockfile(FILE *);
void funlockfile(FILE *);
int getc_unlocked(FILE *);
int getchar_unlocked(void);
int putc_unlocked(int, FILE *);
int putchar_unlocked(int);
ssize_t getdelim(char **restrict, size_t *restrict, int, FILE *restrict);
ssize_t getline(char **restrict, size_t *restrict, FILE *restrict);
int renameat(int, const char *, int, const char *);
char *ctermid(char *);







char *tempnam(const char *, const char *);
# 13 "ECU_layer/KEYPAD/./../../MCAL_layer/GPIO/.././std_libraries.h" 2

# 1 "D:\\ME\\EE\\career\\tools\\xc8\\v2.45\\pic\\include\\c99\\stdlib.h" 1 3
# 21 "D:\\ME\\EE\\career\\tools\\xc8\\v2.45\\pic\\include\\c99\\stdlib.h" 3
# 1 "D:\\ME\\EE\\career\\tools\\xc8\\v2.45\\pic\\include\\c99\\bits/alltypes.h" 1 3
# 24 "D:\\ME\\EE\\career\\tools\\xc8\\v2.45\\pic\\include\\c99\\bits/alltypes.h" 3
typedef long int wchar_t;
# 22 "D:\\ME\\EE\\career\\tools\\xc8\\v2.45\\pic\\include\\c99\\stdlib.h" 2 3

int atoi (const char *);
long atol (const char *);

long long atoll (const char *);

double atof (const char *);


float strtof (const char *restrict, char **restrict);
double strtod (const char *restrict, char **restrict);
long double strtold (const char *restrict, char **restrict);



long strtol (const char *restrict, char **restrict, int);
unsigned long strtoul (const char *restrict, char **restrict, int);

long long strtoll (const char *restrict, char **restrict, int);
unsigned long long strtoull (const char *restrict, char **restrict, int);


unsigned long __strtoxl(const char * s, char ** endptr, int base, char is_signed);

unsigned long long __strtoxll(const char * s, char ** endptr, int base, char is_signed);
# 55 "D:\\ME\\EE\\career\\tools\\xc8\\v2.45\\pic\\include\\c99\\stdlib.h" 3
int rand (void);
void srand (unsigned);

void *malloc (size_t);
void *calloc (size_t, size_t);
void *realloc (void *, size_t);
void free (void *);

          void abort (void);
int atexit (void (*) (void));
          void exit (int);
          void _Exit (int);

void *bsearch (const void *, const void *, size_t, size_t, int (*)(const void *, const void *));







__attribute__((nonreentrant)) void qsort (void *, size_t, size_t, int (*)(const void *, const void *));

int abs (int);
long labs (long);

long long llabs (long long);


typedef struct { int quot, rem; } div_t;
typedef struct { long quot, rem; } ldiv_t;

typedef struct { long long quot, rem; } lldiv_t;


div_t div (int, int);
ldiv_t ldiv (long, long);

lldiv_t lldiv (long long, long long);


typedef struct { unsigned int quot, rem; } udiv_t;
typedef struct { unsigned long quot, rem; } uldiv_t;
udiv_t udiv (unsigned int, unsigned int);
uldiv_t uldiv (unsigned long, unsigned long);
# 14 "ECU_layer/KEYPAD/./../../MCAL_layer/GPIO/.././std_libraries.h" 2
# 13 "ECU_layer/KEYPAD/./../../MCAL_layer/GPIO/../mcal_std_types.h" 2

# 1 "ECU_layer/KEYPAD/./../../MCAL_layer/GPIO/.././compiler.h" 1
# 14 "ECU_layer/KEYPAD/./../../MCAL_layer/GPIO/../mcal_std_types.h" 2
# 35 "ECU_layer/KEYPAD/./../../MCAL_layer/GPIO/../mcal_std_types.h"
typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned int uint32;
typedef signed char sint8;
typedef signed short sint16;
typedef signed int sint32;

typedef uint8 Std_ReturnType;
# 16 "ECU_layer/KEYPAD/./../../MCAL_layer/GPIO/hal_gpio.h" 2

# 1 "ECU_layer/KEYPAD/./../../MCAL_layer/GPIO/../device_config.h" 1
# 17 "ECU_layer/KEYPAD/./../../MCAL_layer/GPIO/hal_gpio.h" 2

# 1 "ECU_layer/KEYPAD/./../../MCAL_layer/GPIO/./hal_gpio_cfg.h" 1
# 18 "ECU_layer/KEYPAD/./../../MCAL_layer/GPIO/hal_gpio.h" 2
# 58 "ECU_layer/KEYPAD/./../../MCAL_layer/GPIO/hal_gpio.h"
typedef enum{
    LOW=0,
    HIGH
}logic_t;

typedef enum{
    OUTPUT=0,
    INPUT
}direction_t;

typedef enum{
    PIN0=0,
    PIN1,
    PIN2,
    PIN3,
    PIN4,
    PIN5,
    PIN6,
    PIN7
}pin_index_t;


typedef enum{
    PORTA_INDEX=0,
    PORTB_INDEX,
    PORTC_INDEX,
    PORTD_INDEX,
    PORTE_INDEX,
}port_index_t;


typedef struct
{
    uint8 port :3;
    uint8 pin :3;
    uint8 direction:1;
    uint8 logic:1;
}pin_config_t;


Std_ReturnType gpio_pin_direction_initalize(const pin_config_t* _pin_config);
Std_ReturnType gpio_pin_get_direction_status(const pin_config_t* _pin_config,direction_t *direction_status);
Std_ReturnType gpio_pin_write_logic(const pin_config_t* _pin_config,logic_t logic);
Std_ReturnType gpio_pin_read_logic(const pin_config_t* _pin_config,logic_t *logic);
Std_ReturnType gpio_pin_toggle_logic(const pin_config_t* _pin_config);
Std_ReturnType gpio_pin_initalize(const pin_config_t* _pin_config);


Std_ReturnType gpio_port_direction_initalize(port_index_t port,uint8 direction);
Std_ReturnType gpio_port_get_direction_status(port_index_t port,uint8 *direction_status);
Std_ReturnType gpio_port_write_logic(port_index_t port,uint8 logic);
Std_ReturnType gpio_port_read_logic(port_index_t port,uint8 *logic);
Std_ReturnType gpio_port_toggle_logic(port_index_t port);
# 16 "ECU_layer/KEYPAD/./ecu_keypad.h" 2

# 1 "ECU_layer/KEYPAD/./ecu_keypad.h" 1
# 17 "ECU_layer/KEYPAD/./ecu_keypad.h" 2







typedef struct
{
    pin_config_t keypad_row_pins[4];
    pin_config_t keypad_col_pins[4];
}keypad_t;

Std_ReturnType keypad_initalize(const keypad_t * keypad);
Std_ReturnType keypad_get_value(const keypad_t *keypad,uint8 *value);
# 12 "ECU_layer/KEYPAD/ecu_keypad.c" 2


const uint8 btn_values[4][4]=
{
    {'7','8','9','/'},
    {'4','5','6','*'},
    {'1','2','3','-'},
    {'#','0','=','+'}
};
Std_ReturnType keypad_initalize(const keypad_t *keypad)
{
    Std_ReturnType ret=(Std_ReturnType)0x01;
    if(((void*)0) == keypad)
    {
        ret=(Std_ReturnType)0x00;
    }
    else
    {
        ret=gpio_pin_initalize(&(keypad->keypad_row_pins[0]));
        ret=gpio_pin_initalize(&(keypad->keypad_row_pins[1]));
        ret=gpio_pin_initalize(&(keypad->keypad_row_pins[2]));
        ret=gpio_pin_initalize(&(keypad->keypad_row_pins[3]));

        ret = gpio_pin_direction_initalize(&(keypad->keypad_col_pins[0]));
        ret = gpio_pin_direction_initalize(&(keypad->keypad_col_pins[1]));
        ret = gpio_pin_direction_initalize(&(keypad->keypad_col_pins[2]));
        ret = gpio_pin_direction_initalize(&(keypad->keypad_col_pins[3]));
    }
    return ret;
}

Std_ReturnType keypad_get_value(const keypad_t *keypad, uint8 *value)
{
    Std_ReturnType ret = (Std_ReturnType)0x01;
    uint8 rows_counter,cols_counter,l_counter,getValue;
    if (((void*)0) == keypad || ((void*)0) == value)
    {
        ret = (Std_ReturnType)0x00;
    }
    else
    {
        for(rows_counter=0;rows_counter<4;rows_counter++)
        {

            for(l_counter=0;l_counter<4;l_counter++)
            {
                ret=gpio_pin_write_logic(&(keypad->keypad_col_pins[l_counter]),LOW);
            }


            ret=gpio_pin_write_logic(&(keypad->keypad_col_pins[rows_counter]),HIGH);
            for(cols_counter=0;cols_counter<4;cols_counter++)
            {
                ret=gpio_pin_read_logic(&(keypad->keypad_col_pins[cols_counter]),&getValue);
                if(HIGH ==getValue)
                {
                    *value=btn_values[rows_counter][cols_counter];
                }
            }

        }
    }
    return ret;
}
