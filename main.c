#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include <util/delay.h>
#include "DIO_interface.h"
#include "UART_Interface.h"
#include "DF_Interface.h"

void main (void )
{
	/* Set RX as Input and TX as output */
	DIO_u8SetPinDirection(DIO_u8PORTD,DIO_u8PIN0,DIO_u8PORT_INPUT);
	DIO_u8SetPinDirection(DIO_u8PORTD,DIO_u8PIN1,DIO_u8PORT_OUTPUT);


	MP3_voidInit();
	MP3_voidSelectVolume(30);
	MP3_voidPlayTrack(2);
	_delay_ms(5000);
	MP3_voidPlayTrack(1);



	while(1)
	{

	}
}
