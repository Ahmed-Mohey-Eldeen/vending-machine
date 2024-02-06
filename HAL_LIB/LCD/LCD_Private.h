/*
 * LCD_prv.h
 *
 *  Created on: Sep 10, 2023
 *      Author: Ahmed
 */

#ifndef LCD_PRIVATE_H_
#define LCD_PRIVATE_H_



#define LCD_FunctionSet     0b00101000
#define LCD_DisplayCurser   0b00001101
#define LCD_Clear           0b00000001
#define LCD_CurserDirection 0b00000110

#define LCD_shiftleft       0b00010000
#define LCD_shiftright      0b00010100

static void private_halfport(u8 value);



#endif /* LCD_PRIVATE_H_ */
