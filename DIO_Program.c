/*****************************************************************/
/*****************************************************************/
/****************** Author    : Aya Ramzy   **********************/
/****************** Date      : 10 OCT 2020 **********************/
/****************** Version   : V01         **********************/
/*****************************************************************/
/*****************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_Interface.h"
#include "DIO_Register.h"
#include "DIO_Private.h"
#include "DIO_Config.h"



u8 DIO_u8SetPinDirection  (u8 Copy_u8PORT ,u8 Copy_u8PIN , u8 Copy_u8Direction)
{
	u8 Local_u8ErrorState =0;
	
	if (Copy_u8Direction == DIO_u8PIN_OUTPUT)
	{
		switch(Copy_u8PORT)
		{
			case DIO_u8PORTA : SET_BIT(DDRA ,Copy_u8PIN);    break;
			case DIO_u8PORTB : SET_BIT(DDRB ,Copy_u8PIN);    break;
			case DIO_u8PORTC : SET_BIT(DDRC ,Copy_u8PIN);    break;
			case DIO_u8PORTD : SET_BIT(DDRD ,Copy_u8PIN);    break;
		}
	}
	else if(Copy_u8Direction == DIO_u8PIN_INPUT)
	{
		switch(Copy_u8PORT)
		{
			case DIO_u8PORTA : CLR_BIT(DDRA ,Copy_u8PIN);    break;
			case DIO_u8PORTB : CLR_BIT(DDRB ,Copy_u8PIN);    break;
			case DIO_u8PORTC : CLR_BIT(DDRC ,Copy_u8PIN);    break;
		    case DIO_u8PORTD : CLR_BIT(DDRD ,Copy_u8PIN);    break;
		}
		
	}
	else
	{
		Local_u8ErrorState = 1;
	}
	
	return Local_u8ErrorState ;
}


u8 DIO_u8SetPortDirection(u8 Copy_u8PORT ,u8 Copy_u8Direction)
{
	u8 Local_u8ErrorState =0;
	switch(Copy_u8PORT)
	{
		case DIO_u8PORTA : DDRA = Copy_u8Direction ;    break;
		case DIO_u8PORTB : DDRB = Copy_u8Direction ;    break;
		case DIO_u8PORTC : DDRC = Copy_u8Direction ;    break;
		case DIO_u8PORTD : DDRD = Copy_u8Direction ;    break;
		default : Local_u8ErrorState = 1;
	}
	return Local_u8ErrorState ;


}
u8 DIO_u8SetPinValue(u8 Copy_u8PORT ,u8 Copy_u8PIN,u8 Copy_u8Value)
{
	u8 Local_u8ErrorState =0;

	if (Copy_u8Value == DIO_u8PIN_HIGH)
	{
		switch(Copy_u8PORT)
		{
			case DIO_u8PORTA : SET_BIT(PORTA ,Copy_u8PIN);    break;
			case DIO_u8PORTB : SET_BIT(PORTB ,Copy_u8PIN);    break;
			case DIO_u8PORTC : SET_BIT(PORTC ,Copy_u8PIN);    break;
			case DIO_u8PORTD : SET_BIT(PORTD ,Copy_u8PIN);    break;
			default : Local_u8ErrorState = 1;
		}
	}
	else if(Copy_u8Value == DIO_u8PIN_LOW)
	{
		switch(Copy_u8PORT)
		{
			case DIO_u8PORTA : CLR_BIT(PORTA ,Copy_u8PIN);    break;
			case DIO_u8PORTB : CLR_BIT(PORTB ,Copy_u8PIN);    break;
			case DIO_u8PORTC : CLR_BIT(PORTC ,Copy_u8PIN);    break;
			case DIO_u8PORTD : CLR_BIT(PORTD ,Copy_u8PIN);    break;
			default : Local_u8ErrorState = 1;
		}
		
	}
	else
	{
		Local_u8ErrorState = 1;
	}
	
	
	return Local_u8ErrorState ;
}



u8 DIO_u8SetPortValue(u8 Copy_u8PORT ,u8 Copy_u8Value)
{
	u8 Local_u8ErrorState =0;
	switch(Copy_u8PORT)
		{
			case DIO_u8PORTA : PORTA = Copy_u8Value ;    break;
			case DIO_u8PORTB : PORTB = Copy_u8Value ;    break;
			case DIO_u8PORTC : PORTC = Copy_u8Value ;    break;
			case DIO_u8PORTD : PORTD = Copy_u8Value ;    break;
			default : Local_u8ErrorState = 1;
		}
	return Local_u8ErrorState;
}

u8 DIO_u8ClearPinValue(u8 Copy_u8PORT ,u8 Copy_u8PIN)
{
	u8 Local_u8ErrorState =0;
	switch(Copy_u8PORT)
		{
			case DIO_u8PORTA : CLR_BIT(PORTA ,Copy_u8PIN);    break;
			case DIO_u8PORTB : CLR_BIT(PORTB ,Copy_u8PIN);    break;
			case DIO_u8PORTC : CLR_BIT(PORTC ,Copy_u8PIN);    break;
			case DIO_u8PORTD : CLR_BIT(PORTD ,Copy_u8PIN);    break;
		}
	return  Local_u8ErrorState ;

}
u8 DIO_u8ClearPortValue(u8 Copy_u8PORT ) //
{
	u8 Local_u8ErrorState =0;
	switch(Copy_u8PORT)
		{
			case DIO_u8PORTA : PORTA =0;   break;
			case DIO_u8PORTB : PORTB =0;   break;
			case DIO_u8PORTC : PORTC =0;   break;
			case DIO_u8PORTD : PORTD =0;   break;
		}
	return  Local_u8ErrorState ;

}
u8 DIO_u8TogglePinValue(u8 Copy_u8PORT ,u8 Copy_u8PIN) //
{
	u8 Local_u8ErrorState =0;
	switch(Copy_u8PORT)
		{
			case DIO_u8PORTA : TOG_BIT(PORTA ,Copy_u8PIN);    break;
			case DIO_u8PORTB : TOG_BIT(PORTB ,Copy_u8PIN);    break;
			case DIO_u8PORTC : TOG_BIT(PORTC ,Copy_u8PIN);    break;
			case DIO_u8PORTD : TOG_BIT(PORTD ,Copy_u8PIN);    break;
		}
    return Local_u8ErrorState;
}
u8 DIO_u8GetPinValue (u8 Copy_u8PORT ,u8 Copy_u8PIN ,u8* Copy_pu8Value)
{
    u8 Local_u8ErrorState = 0;
	
	if((Copy_pu8Value != NULL) &&(Copy_u8PIN <= DIO_u8PIN7) )
	{
		
		switch(Copy_u8PORT)
			{
				case DIO_u8PORTA :  *Copy_pu8Value = GET_BIT(PINA ,Copy_u8PIN);    break;
				case DIO_u8PORTB :  *Copy_pu8Value = GET_BIT(PINB ,Copy_u8PIN);    break;
				case DIO_u8PORTC :  *Copy_pu8Value = GET_BIT(PINC ,Copy_u8PIN);    break;
				case DIO_u8PORTD :  *Copy_pu8Value = GET_BIT(PIND ,Copy_u8PIN);    break;
			}
			
	}
	else
	{
		Local_u8ErrorState = 1;
	}

    return Local_u8ErrorState;

}
u8   DIO_u8GetPortValue(u8 Copy_u8PORT )//
{
	u8 LOC_u8Result = 0;

	switch(Copy_u8PORT)
		{
			case DIO_u8PORTA :  LOC_u8Result = PINA ;   break;
			case DIO_u8PORTB :  LOC_u8Result = PINB ;   break;
			case DIO_u8PORTC :  LOC_u8Result = PINC ;   break;
			case DIO_u8PORTD :  LOC_u8Result = PIND ;  break;
		}

	return LOC_u8Result;
}
