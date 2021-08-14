#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <util/delay.h>
#include "UART_Interface.h"
#include "DF_Interface.h"
#include "DF_Config.h"


u8 Local_u8MP3_DefaultCommand[MP3_CMD_SIZE] ={MP3_STARTBYTE,MP3_VERSION,6,0,MP3_CMD_NOFEEDBACK,0,0,0,0,MP3_ENDBYTE};

static void SendCommandFrame(void)
{
	u8 i =0;
	u16 Local_u16CheckSum =0;
	u16 Local_u16Add_Frame =0;
	for (i=0;i<10;i++)
	{

		if(i>0 && i<7)
		{
			Local_u16Add_Frame +=Local_u8MP3_DefaultCommand[i];
		}
		else if (i==7)
		{
			Local_u16CheckSum = 0xFFFF - Local_u16Add_Frame +1;
			Local_u8MP3_DefaultCommand[7]=Local_u16CheckSum >>8 ;
			Local_u8MP3_DefaultCommand[8]= Local_u16CheckSum & 0xFF;
		}
		USART_voidSend(Local_u8MP3_DefaultCommand[i]);

	}

}
void MP3_voidInit(void)
{
	USART_voidInit();
	Local_u8MP3_DefaultCommand[3]=MP3_CMD_RESET;
	SendCommandFrame();
	Local_u8MP3_DefaultCommand[3]=0;
	_delay_ms(1000); //delay 1 second



}
void MP3_voidPlayTrack(u16 Copy_u16TrackNumber)
{
	Local_u8MP3_DefaultCommand[3]= MP3_CMD_PLAYBACK;
	Local_u8MP3_DefaultCommand[5]= Copy_u16TrackNumber >>8;
	Local_u8MP3_DefaultCommand[6]= (u8 )Copy_u16TrackNumber;
	SendCommandFrame();
	Local_u8MP3_DefaultCommand[3]=0;
	Local_u8MP3_DefaultCommand[5]=0;
	Local_u8MP3_DefaultCommand[6]=0;

}
void MP3_voidSelectVolume(u16 Copy_u16VolumeLevel)
{
	Local_u8MP3_DefaultCommand[3]= MP3_CMD_SETVOLUME;
    Local_u8MP3_DefaultCommand[5]= Copy_u16VolumeLevel >>8;
    Local_u8MP3_DefaultCommand[6]= (u8 )Copy_u16VolumeLevel;
    SendCommandFrame();
    Local_u8MP3_DefaultCommand[3]=0;
    Local_u8MP3_DefaultCommand[5]=0;
    Local_u8MP3_DefaultCommand[6]=0;

}



