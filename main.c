/*
 * main.c
 *
 *  Created on: Feb 5, 2024
 *      Author: Ahmed
 */


#include "UTILES_LIB/BIT_math.h"
#include "UTILES_LIB/STD_Types.h"
#include "MCAL_LIB/DIO/DIO_interface.h"
#include "MCAL_LIB/DIO/DIO_Private.h"
#include "MCAL_LIB/DIO/DIO_config.h"
#include "HAL_LIB/KEYPAD/KEYPAD_interface.h"
#include "HAL_LIB/KEYPAD/KEYPAD_Private.h"
#include "HAL_LIB/KEYPAD/KEYPAD_config.h"
#include "HAL_LIB/LCD/LCD_interface.h"
#include "HAL_LIB/LCD/LCD_Private.h"
#include "HAL_LIB/LCD/LCD_config.h"
#include "util/delay.h"

typedef struct
{
	u8 Productname[];
	u32 Productprice;
	u32 Productamount;
}Product_S;

typedef struct
{
	u32 userID;
	u32 password;
}Seller_S;

u32 product_number=3;

int main()
{
	u8 x='/0';
	u8 y='/0';
	u8 d='/0';
	u8 a='/0';

	u8 P='/0';
	u8 name='/0';
	u8 nprice='/0';
	u8 namount='/0';
	u8 ch='/0';
	u8 pamount='/0';
	u8 de='/0';

	u8 c='/0';
	u8 O='/0';
	u8 M='/0';
	u8 B='/0';
	u32 counter=0;
	u32 price=0;
	u32 money=0;
	u32 moneyback=0;
	u32 amount=0;
	u32 sell=0;
	Seller_S seller;
	Product_S product[product_number];
	product[0].Productname[5]="ships";
	product[0].Productprice=10;
	product[0].Productamount=50;

	product[1].Productname[5]="juice";
	product[1].Productprice=20;
	product[1].Productamount=50;

	product[2].Productname[7]="biscuit";
	product[2].Productprice=5;
	product[2].Productamount=50;

	while(sell==0)
	{
		LCD_clear();
		LCD_Go_To(0,1);
		LCD_send_string("Enter your ID:");
		_delay_ms(500);
		LCD_Go_To(1,6);
		for(int i=0;i<4;i++)
		{
			int cx=0;
			while((x=='/0')&&(cx<4))
			{
				x=KEYPAD_Get_Button();
				LCD_send_char(x);
				_delay_ms(500);
				seller.userID=(seller.userID*10)+x;
				cx++;
				x='/0';
			}

		}
		if(1111==seller.userID)
		{
			LCD_clear();
			LCD_Go_To(0,0);
			LCD_send_string("Enter your pass:");
			LCD_Go_To(1,6);
			for(int i=0;i<4;i++)
			{
				int cy=0;
				while((y=='/0')&&(cy<4))
				{
					y=KEYPAD_Get_Button();
					_delay_ms(500);
					LCD_send_char(y);
					seller.password=(seller.password*10)+y;
					cy++;
					y='/0';
				}

			}

			if(1234==seller.password)
			{
				LCD_clear();
				LCD_Go_To(0,0);
				LCD_send_string("1-POST.");
				LCD_Go_To(1,0);
				LCD_send_string("2-PUT.");
				LCD_Go_To(2,0);
				LCD_send_string("3-DELETE.");
				_delay_ms(500);

				while('/0'==d)
				{
					d=KEYPAD_Get_Button();
				}
				LCD_Go_To(3,7);
				LCD_send_char(d);
				_delay_ms(500);

				switch(d)
				{
					case '1':

						break;
					case '2':
						LCD_clear();
						LCD_Go_To(0,0);
						LCD_send_string("1-NEW.");
						LCD_Go_To(1,0);
						LCD_send_string("2-OLD.");

						while('/0'==P)
						{
							P=KEYPAD_Get_Button();
						}
						LCD_Go_To(0,0);
						LCD_send_char(P);
						_delay_ms(500);

						switch(P)
						{
							case '1':
								product_number++;
								product[product_number-1].Productprice=0;
								product[product_number-1].Productamount=0;
								LCD_clear();
								LCD_Go_To(0,0);
								LCD_send_string("Product Name:");
								u32 z=0;
								LCD_Go_To(1,1);
								while('='!=name)
								{
									name=KEYPAD_Get_Button();
									_delay_ms(500);
									product[product_number-1].Productname[z]=name;
									LCD_send_char(name);
									z++;
								}

								LCD_clear();
								LCD_Go_To(0,0);
								LCD_send_string("Product Price:");
								LCD_Go_To(1,1);
								while('='!=nprice)
								{
									name=KEYPAD_Get_Button();
									_delay_ms(500);
									product[product_number-1].Productprice=(product[product_number-1].Productprice*10)+(nprice-'0');
									LCD_send_char(nprice);
								}

								LCD_clear();
								LCD_Go_To(0,0);
								LCD_send_string("Product amount:");
								LCD_Go_To(1,1);
								while('='!=namount)
								{
									name=KEYPAD_Get_Button();
									_delay_ms(500);
									product[product_number-1].Productamount=(product[product_number-1].Productamount*10)+(namount-'0');
									LCD_send_char(namount);
								}
								break;
							case '2':
								LCD_clear();
								LCD_Go_To(0,1);
								LCD_send_string("please choose:");
								for(u32 i=0;i<product_number;i++)
								{
									LCD_Go_To(i+1,0);
									LCD_send_number((i+1));
									LCD_send_char('-');
									LCD_send_string(product[i].Productname);
									LCD_Go_To(i+1,10);
									LCD_send_number(product[i].Productamount);
								}

								while('/0'==ch)
								{
									ch=KEYPAD_Get_Button();
								}
								_delay_ms(500);

								LCD_clear();
								LCD_Go_To(0,0);
								LCD_send_string("the added amount:");
								LCD_Go_To(1,0);
								u32 addedamount=0;
								while('/0'==pamount)
								{
									addedamount=KEYPAD_Get_Button();
								}
								_delay_ms(500);
								product[(ch-'0')-1].Productamount+=addedamount;
						}

						break;
					case '3':
						LCD_clear();
						LCD_Go_To(0,1);
						LCD_send_string("please choose:");
						for(u32 i=0;i<product_number;i++)
						{
							LCD_Go_To(i+1,0);
							LCD_send_number((i+1));
							LCD_send_char('-');
							LCD_send_string(product[i].Productname);
							LCD_Go_To(i+1,10);
							LCD_send_number(product[i].Productamount);
						}
						while('/0'==de)
						{
							de=KEYPAD_Get_Button();
						}
						_delay_ms(500);

						for(u32 j=de-1;j<product_number;j++)
						{
							product[j]=product[j+1];
						}
						product_number--;

						break;
					default:
						break;
				}

				LCD_clear();
				LCD_Go_To(0,0);
				LCD_send_string("another operation:(1/0)");
				LCD_Go_To(1,0);
				LCD_send_string("1-Yes");
				LCD_Go_To(1,10);
				LCD_send_string("0-No");
				_delay_ms(500);

				while('/0'==a)
				{
					a=KEYPAD_Get_Button();
				}
				LCD_Go_To(2,7);
				LCD_send_char(a);
				_delay_ms(500);

				if(0==a)
				{
					sell=1;
				}
			}
			else
			{
				LCD_clear();
				LCD_Go_To(0,3);
				LCD_send_string("Wrong password");
				LCD_Go_To(1,3);
				LCD_send_string("Try again");
				counter++;
				_delay_ms(500);
				if(3==counter)
				{
					sell=1;
				}
			}
		}
		else
		{
			LCD_clear();
			LCD_Go_To(0,3);
			LCD_send_string("Wrong ID");
			LCD_Go_To(1,3);
			LCD_send_string("Try again");
			counter++;
			_delay_ms(500);
			if(3==counter)
			{
				sell=1;
			}
		}
	}
	x='/0';
	y='/0';
	d='/0';
	a='/0';
	P='/0';
	name='/0';
	nprice='/0';
	namount='/0';
	ch='/0';
	pamount='/0';
	de='/0';

	while(1)
	{
		LCD_clear();
		LCD_Go_To(0,1);
		LCD_send_string("please choose:");
		LCD_Go_To(1,2);
		LCD_send_string("1-GET");
		_delay_ms(1000);
		while(0==amount)
		{
			LCD_clear();
			LCD_Go_To(0,1);
			LCD_send_string("please choose:");
			for(u32 i=0;i<product_number;i++)
			{
				LCD_Go_To(i+1,0);
				LCD_send_number((i+1));
				LCD_send_char('-');
				LCD_send_string(product[i].Productname);
				LCD_Go_To(i+1,10);
				LCD_send_number(product[i].Productamount);
			}

			/*LCD_Go_To(1,0);
			LCD_send_string("1-ships");
			LCD_Go_To(1,10);
			LCD_send_number(product[0].Productamount);
			LCD_Go_To(2,0);
			LCD_send_string("2-juice");
			LCD_Go_To(2,10);
			LCD_send_number(product[1].Productamount);
			LCD_Go_To(3,0);
			LCD_send_string("3-biscuit");
			LCD_Go_To(3,10);
			LCD_send_number(product[2].Productamount);*/

			while('/0'==c)
			{
				c=KEYPAD_Get_Button();
			}
			LCD_clear();
			LCD_Go_To(0,0);
			LCD_send_string("your choice is:");
			LCD_Go_To(1,7);
			LCD_send_char(c);
			_delay_ms(500);


			product[(c-'0')-1].Productamount--;
			price+=product[(c-'0')-1].Productprice;
			/*switch(c)
			{
				case '1':
					product[0].Productamount--;
					price+=product[0].Productprice;
					break;
				case '2':
					product[1].Productamount--;
					price+=product[1].Productprice;
					break;
				case '3':
					product[2].Productamount--;
					price+=product[2].Productprice;
					break;
			}*/

			LCD_clear();
			LCD_Go_To(0,0);
			LCD_send_string("another order:(1/0)");
			LCD_Go_To(1,0);
			LCD_send_string("1-Yes");
			LCD_Go_To(1,10);
			LCD_send_string("0-No");
			while('/0'==O)
			{
				O=KEYPAD_Get_Button();
			}
			LCD_Go_To(2,7);
			LCD_send_char(O);
			_delay_ms(500);
			if(0==O)
			{
				amount=1;
			}
		}
		while(money<price)
		{
			LCD_clear();
			LCD_Go_To(0,1);
			LCD_send_string("Put the Coins:");
			LCD_Go_To(1,0);
			LCD_send_string("1-5Coin.");
			LCD_Go_To(1,9);
			LCD_send_string("2-10Coin.");
			LCD_Go_To(2,0);
			LCD_send_string("3-20Coin.");
			LCD_Go_To(2,9);
			LCD_send_string("4-50Coin.");
			LCD_Go_To(3,0);
			LCD_send_string("5-100Coins");
			while('/0'==M)
			{
				M=KEYPAD_Get_Button();
			}
			LCD_Go_To(3,12);
			LCD_send_char(M);
			_delay_ms(500);
			switch(M)
			{
				case '1':
					money+=5;
					break;
				case '2':
					money+=10;
					break;
				case '3':
					money+=20;
					break;
				case '4':
					money+=50;
					break;
				case '5':
					money+=100;
					break;
			}
		}

		LCD_clear();
		LCD_Go_To(0,0);
		LCD_send_string("reorder:(1/0)");
		LCD_Go_To(1,0);
		LCD_send_string("1-Yes");
		LCD_Go_To(1,10);
		LCD_send_string("0-No");

		while('/0'==B)
		{
			B=KEYPAD_Get_Button();
		}
		LCD_Go_To(2,7);
		LCD_send_char(B);
		_delay_ms(500);

		if(0==B)
		{
			if(money>price)
			{
				moneyback=money-price;
			}
			LCD_clear();
			LCD_Go_To(0,0);
			LCD_send_string("Thank you");
			LCD_Go_To(1,0);
			LCD_send_string("Total price:");
			LCD_Go_To(1,12);
			LCD_send_number(price);
			LCD_Go_To(2,0);
			LCD_send_string("your money:");
			LCD_Go_To(2,12);
			LCD_send_number(money);
			LCD_Go_To(3,0);
			LCD_send_string("The charge:");
			LCD_Go_To(3,12);
			LCD_send_number(moneyback);
			_delay_ms(1000);
		}

		price=0;
		money=0;
		moneyback=0;
		amount=0;
		c='/0';
		O='/0';
		M='/0';
		B='/0';

	}

}
