/*
 * LCD_prog.c
 *
 *  Created on: Sep 10, 2023
 *      Author: Ahmed
 */

#include "G:\NTI_WORK\vending-machine\UTILES_LIB\BIT_math.h"
#include "G:\NTI_WORK\vending-machine\UTILES_LIB\STD_Types.h"
#include "G:\NTI_WORK\vending-machine\MCAL_LIB\DIO\DIO_interface.h"
#include "util/delay.h"

#include "../LCD/LCD_config.h"
#include "../LCD/LCD_interface.h"
#include "../LCD/LCD_Private.h"



static void private_halfport(u8 value)
{
	DIO_Setpinvalue(LCD_D4,GET_BIT(value,0));
	DIO_Setpinvalue(LCD_D5,GET_BIT(value,1));
	DIO_Setpinvalue(LCD_D6,GET_BIT(value,2));
	DIO_Setpinvalue(LCD_D7,GET_BIT(value,3));

}



void LCD_sendCommande(u8 command)
{
	DIO_Setpinvalue(LCD_RS,LOW);

	private_halfport(command>>4);

	DIO_Setpinvalue(LCD_E,HIGH);
	_delay_ms(1);
	DIO_Setpinvalue(LCD_E,LOW);

	private_halfport(command);

	DIO_Setpinvalue(LCD_E,HIGH);
	_delay_ms(1);
	DIO_Setpinvalue(LCD_E,LOW);

}


void LCD_Init(void)
{
	_delay_ms(35);
	DIO_Setpinvalue(LCD_RS,LOW);
	private_halfport(0b0010);

	DIO_Setpinvalue(LCD_E,HIGH);
	_delay_ms(1);
	DIO_Setpinvalue(LCD_E,LOW);
	LCD_sendCommande(LCD_FunctionSet);
	_delay_ms(45);
	LCD_sendCommande(LCD_DisplayCurser);
	_delay_ms(45);
	LCD_sendCommande(LCD_Clear);
	_delay_ms(2);
	LCD_sendCommande(LCD_CurserDirection);
	_delay_ms(1);
}


void LCD_send_char(u8 value)
{
	DIO_Setpinvalue(LCD_RS,HIGH);

	private_halfport(value>>4);

	DIO_Setpinvalue(LCD_E,HIGH);
	_delay_ms(1);
	DIO_Setpinvalue(LCD_E,LOW);

	private_halfport(value);

	DIO_Setpinvalue(LCD_E,HIGH);
	_delay_ms(1);
	DIO_Setpinvalue(LCD_E,LOW);
}


void LCD_send_string(u8 *string)
{
	u8 counter=0;
	while(string[counter]!='\0')
	{
		LCD_send_char(string[counter]);
		counter++;
	}
}


void LCD_send_number(u32 number)
{
	u32 b=1;
	u8 c=0;
	if(number==0)
	{
		LCD_send_char('0');
	}
	else if(number==1)
	{
		LCD_send_char('1');
	}
	else if(number==10)
	{
		LCD_send_char('1');
		LCD_send_char('0');
	}
	else
	{
		for(int i=0;number>b;i++)
		{
			b*=10;
			c++;
		}
		b/=10;
		u32 tnumber=number;
		for(u8 i=0;i<c;i++)
		{
			LCD_send_char((tnumber/b)+'0');
			tnumber%=b;
			b/=10;
		}
	}
	

}

void LCD_shift(u8 shiftDirection)
{
	switch(shiftDirection)
	{
	case left:
	{
		LCD_sendCommande(LCD_shiftleft);
		break;
	}
	case right:
	{
		LCD_sendCommande(LCD_shiftright);
		break;
	}

	}
}

void LCD_Go_To(u8 row,u8 col)
{
	u8 adress;
	switch(row)
	{
	case 0:
	{
		adress=(( 0x00 + col ) | 0x80);
		break;
	}
	case 1:
	{
		adress=(( 0x40 + col ) | 0x80);
		break;
	}
	case 2:
	{
		adress=(( 0x14 + col ) | 0x80);
		break;
	}
	case 3:
	{
		adress=(( 0x54 + col ) | 0x80);
		break;
	}
	}
	LCD_sendCommande(adress);
}

void LCD_clear(void)
{
	LCD_sendCommande(LCD_Clear);
	_delay_ms(2);
}
