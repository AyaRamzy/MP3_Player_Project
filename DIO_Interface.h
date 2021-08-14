/*****************************************************************/
/*****************************************************************/
/****************** Author    : Aya Ramzy   **********************/
/****************** Date      : 10 OCT 2020 **********************/
/****************** Version   : V01         **********************/
/*****************************************************************/
/*****************************************************************/

#ifndef _DIO_INTERFACE_H_
#define _DIO_INTERFACE_H_

#define   DIO_u8PIN_OUTPUT    1
#define   DIO_u8PIN_INPUT     0
							  
#define   DIO_u8PORT_OUTPUT   0xFF
#define   DIO_u8PORT_INPUT    0
							  
#define   DIO_u8PORT_HIGH     0xFF
#define   DIO_u8PORT_LOW      0
							  
#define   DIO_u8PIN_HIGH      1
#define   DIO_u8PIN_LOW       0
							  
#define   DIO_u8PORTA         0
#define   DIO_u8PORTB         1
#define   DIO_u8PORTC         2
#define   DIO_u8PORTD         3
						      
#define   DIO_u8PIN0          0
#define   DIO_u8PIN1          1
#define   DIO_u8PIN2          2
#define   DIO_u8PIN3          3
#define   DIO_u8PIN4          4
#define   DIO_u8PIN5          5
#define   DIO_u8PIN6          6
#define   DIO_u8PIN7          7


u8 DIO_u8SetPinDirection  (u8 Copy_u8PORT ,u8 Copy_u8PIN , u8 Copy_u8Direction);
u8 DIO_u8SetPortDirection (u8 Copy_u8PORT ,u8 Copy_u8Direction);
u8 DIO_u8SetPinValue      (u8 Copy_u8PORT ,u8 Copy_u8PIN,u8 Copy_u8Value);
u8 DIO_u8SetPortValue     (u8 Copy_u8PORT ,u8 Copy_u8Value);
u8 DIO_u8ClearPinValue    (u8 Copy_u8PORT ,u8 Copy_u8PIN);
u8 DIO_u8ClearPortValue   (u8 Copy_u8PORT );
u8 DIO_u8TogglePinValue   (u8 Copy_u8PORT ,u8 Copy_u8PIN);
u8 DIO_u8GetPinValue      (u8 Copy_u8PORT ,u8 Copy_u8PIN ,u8* Copy_pu8Value);
u8 DIO_u8GetPortValue     (u8 Copy_u8PORT );


#endif