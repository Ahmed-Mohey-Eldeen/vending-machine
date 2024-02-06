/*
 * DIO_interface.h
 *
 * Created: 5/27/2022 4:44:18 PM
 *  Author: En Eslam Eid
 */

#ifndef _DIO_INTERFACE_H_
#define _DIO_INTERFACE_H_

typedef enum {
Pin_A0  ,Pin_A1	,Pin_A2	,Pin_A3	,Pin_A4	,Pin_A5	, Pin_A6 ,Pin_A7 ,
Pin_B0	,Pin_B1 ,Pin_B2 ,Pin_B3	,Pin_B4 ,Pin_B5	, Pin_B6 ,Pin_B7 ,
Pin_C0	,Pin_C1	,Pin_C2	,Pin_C3	,Pin_C4	,Pin_C5	, Pin_C6 ,Pin_C7 ,
Pin_D0	,Pin_D1	,Pin_D2	,Pin_D3	,Pin_D4	,Pin_D5	, Pin_D6 ,Pin_D7 ,
}Pin_Type;

typedef enum {
	OutPut_High , OutPut_Low,
	InPut_Float,InPut_PullUp
}PinMode_type;

typedef enum {
	DIO_PORTA , DIO_PORTB , DIO_PORTC , DIO_PORTD ,
}DIO_PORTS;

#define HIGH    1
#define LOW     0



void Dio_SetPinMode(Pin_Type Pin_ID , PinMode_type Mode);
void DIO_Init(void);
u8 DIO_ReadPinVal(Pin_Type Pin_ID /*,u8 * ReadBufferPTR*/ );
void DIO_Setpinvalue(Pin_Type Pin_ID ,u8 value);
void DIO_Toggle_Pin(DIO_PORTS Port , u8 Pin);





#endif /* DIO_INTERFACE_H_ */













