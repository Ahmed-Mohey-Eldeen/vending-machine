/*************************************************/
/*  Title        : keypad cofigration file       */
/*  Auther       : Ahmed Mohey Eldeen            */
/*  Release      : 1.0                           */
/*  Last Update  : Aug 18, 2021                  */
/*************************************************/


#ifndef KEYPAD_CONFIG_H_
#define KEYPAD_CONFIG_H_

#define col1   Pin_D7
#define col2   Pin_D6
#define col3   Pin_D5
#define col4   Pin_D3

#define row1   Pin_C5
#define row2   Pin_C4
#define row3   Pin_C3
#define row4   Pin_C2

#define KEYPAD_R1C1     '7'
#define KEYPAD_R1C2     '8'
#define KEYPAD_R1C3     '9'
#define KEYPAD_R1C4     '/'

#define KEYPAD_R2C1     '4'
#define KEYPAD_R2C2     '5'
#define KEYPAD_R2C3     '6'
#define KEYPAD_R2C4     '*'

#define KEYPAD_R3C1     '1'
#define KEYPAD_R3C2     '2'
#define KEYPAD_R3C3     '3'
#define KEYPAD_R3C4     '-'

#define KEYPAD_R4C1     ' '
#define KEYPAD_R4C2     '0'
#define KEYPAD_R4C3     '='
#define KEYPAD_R4C4     '+'

/*
1-KEYPAD_u8_EX_PULL
1-KEYPAD_u8_IN_PULL
*/

#define KEYPAD_u8_MODE   KEYPAD_u8_IN_PULL


#endif
