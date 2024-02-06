/*
 * LCD_interface.h
 *
 *  Created on: Sep 10, 2023
 *      Author: Ahmed
 */

#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_


#define left    0
#define right   1

void LCD_Init(void);
void LCD_sendCommande(u8 command);
void LCD_send_char(u8 character);
void LCD_send_string(u8 *string);
void LCD_send_number(u32 number);
void LCD_shift(u8 shiftDirection);
void LCD_Go_To(u8 row,u8 col);
void LCD_clear(void);




#endif /* LCD_INTERFACE_H_ */
