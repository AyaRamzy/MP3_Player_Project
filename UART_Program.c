#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "UART_Private.h"
#include "UART_Interface.h"
#include "UART_Config.h"



void USART_voidInit(void)
{
	u8 Local_u8UCSRCValue =0;


	/* write on UCSRC
	 * select it by set bit number  7
                                  */
	SET_BIT(Local_u8UCSRCValue,UCSRC_URSEL);

    /* select Async */
	CLR_BIT(Local_u8UCSRCValue,UCSRC_UMSEL);
	/* set the Character size */
    SET_BIT(Local_u8UCSRCValue,UCSRC_UCSZ1);
    SET_BIT(Local_u8UCSRCValue,UCSRC_UCSZ0);

    /* No parity */
    CLR_BIT(Local_u8UCSRCValue,UCSRC_UPM1);
    CLR_BIT(Local_u8UCSRCValue,UCSRC_UPM0);
    /* 1 stop Bit */
    CLR_BIT(Local_u8UCSRCValue,UCSRC_USBS );

    UCSRC= Local_u8UCSRCValue;


	/* set the boadrate at 9600 bps*/
     UBRRL = 51;
	/* Enable RX and TX */
	SET_BIT(UCSRB,UCSRB_RXEN);
	SET_BIT(UCSRA,UCSRB_TXEN);


}
void USART_voidSend(u8 Copy_u8data)
{
	while(GET_BIT(UCSRA,UCSRA_UDRE)==0);
	UDR = Copy_u8data;   //write at TXB and send it
}
u8 USART_voidReceive(void)
{
	while (GET_BIT(UCSRA,UCSRA_RXC)==0);
	return UDR;  //read from RXB
	
}
