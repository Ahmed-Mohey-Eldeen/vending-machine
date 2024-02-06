/*************************************************/
/*  Title        : keypad program file           */
/*  Auther       : Ahmed Mohey Eldeen            */
/*  Release      : 1.0                           */
/*  Last Update  : Aug 18, 2021                  */
/*************************************************/

#include "../../HAL_LIB/KEYPAD/KEYPAD_config.h"
#include "../../HAL_LIB/KEYPAD/KEYPAD_interface.h"
#include "../../HAL_LIB/KEYPAD/KEYPAD_Private.h"
#include "G:\NTI_WORK\vending-machine\UTILES_LIB\BIT_math.h"
#include "G:\NTI_WORK\vending-machine\UTILES_LIB\STD_Types.h"
#include "G:\NTI_WORK\vending-machine\MCAL_LIB\DIO\DIO_interface.h"


void KEYPAD_int(void)
{
	#if KEYPAD_u8_MODE == KEYPAD_u8_IN_PULL
	DIO_Setpinvalue(row1 , HIGH);
	DIO_Setpinvalue(row2 , HIGH);
	DIO_Setpinvalue(row3 , HIGH);
	DIO_Setpinvalue(row4 , HIGH);
	
	#endif

}


u8 KEYPAD_CheckRow(u8 Col)
{
	u8 Data;
	if(DIO_ReadPinVal(row1) == LOW)
	{
		switch(Col)
		{
			case 0:
				Data = KEYPAD_R1C1;
			break;
			
			case 1:
				Data = KEYPAD_R1C2;
			break;
			
			case 2:
				Data = KEYPAD_R1C3;
			break;
			
			case 3:
				Data = KEYPAD_R1C4;
			break;
		}
		
		return Data;
	}
	
	if(DIO_ReadPinVal(row2) == LOW)
	{
		switch(Col)
		{
			case 0:
				Data = KEYPAD_R2C1;
			break;
			
			case 1:
				Data = KEYPAD_R2C2;
			break;
			
			case 2:
				Data = KEYPAD_R2C3;
			break;
			
			case 3:
				Data = KEYPAD_R2C4;
			break;
		}
		
		return Data;
	}
	
	if(DIO_ReadPinVal(row3) == LOW)
	{
		switch(Col)
		{
			case 0:
				Data = KEYPAD_R3C1;
			break;
			
			case 1:
				Data = KEYPAD_R3C2;
			break;
			
			case 2:
				Data = KEYPAD_R3C3;
			break;
			
			case 3:
				Data = KEYPAD_R3C4;
			break;
		}
		
		return Data;
	}
	
	if(DIO_ReadPinVal(row4) == LOW)
	{
		switch(Col)
		{
			case 0:
				Data = KEYPAD_R4C1;
			break;
			
			case 1:
				Data = KEYPAD_R4C2;
			break;
			
			case 2:
				Data = KEYPAD_R4C3;
			break;
			
			case 3:
				Data = KEYPAD_R4C4;
			break;
		}
		
		return Data;
	}
	
	return '\0';
}



u8 KEYPAD_Get_Button(void)
{
	u8 Button = '\0';
	u8 Flag = 0;
	/*applay sequance*/
	if(Flag == 0)
	{
		DIO_Setpinvalue(col1 , LOW);
		DIO_Setpinvalue(col2 , HIGH);
		DIO_Setpinvalue(col3 , HIGH);
		DIO_Setpinvalue(col4 , HIGH);

		Button = KEYPAD_CheckRow(0);
	if(Button != '\0')
	{
		Flag = 1;
	}
	} //return Local_u8_Button;

	if(Flag == 0)
	{
		DIO_Setpinvalue(col1 , HIGH);
		DIO_Setpinvalue(col2 , LOW);
		DIO_Setpinvalue(col3 , HIGH);
		DIO_Setpinvalue(col4 , HIGH);

		Button = KEYPAD_CheckRow(1);
	if(Button != '\0')
	{
		Flag = 1;
	}
	} //return Local_u8_Button;

	if(Flag == 0)
	{
		DIO_Setpinvalue(col1 , HIGH);
		DIO_Setpinvalue(col2 , HIGH);
		DIO_Setpinvalue(col3 , LOW);
		DIO_Setpinvalue(col4 , HIGH);

		Button = KEYPAD_CheckRow(2);
	if(Button != '\0')
	{
		Flag = 1;
	}
	} //return Local_u8_Button;

	if(Flag == 0)
	{
		DIO_Setpinvalue(col1 , HIGH);
		DIO_Setpinvalue(col2 , HIGH);
		DIO_Setpinvalue(col3 , HIGH);
		DIO_Setpinvalue(col4 , LOW);

		Button = KEYPAD_CheckRow(3);
	if(Button != '\0')
	{
		Flag = 1;
	}
	} //return Local_u8_Button;

	return Button;
}





