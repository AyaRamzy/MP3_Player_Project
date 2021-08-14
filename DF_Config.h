#ifndef DF_CONFIG_H
#define DF_CONFIG_H





#define     MP3_CMD_SIZE   10
#define     MP3_STARTBYTE  0x7E
#define     MP3_VERSION    0xFF

/* Some of MP3 commands */
#define    MP3_CMD_PLAYBACK   0x03
#define    MP3_CMD_SETVOLUME  0x06
#define    MP3_CMD_RESET      0x0C
#define    MP3_CMD_PLAY       0x0D
#define    MP3_CMD_PAUSE      0x0E

#define   MP3_CMD_NOFEEDBACK  0x00
#define   MP3_RQTFEEDBACK     0x01
#define   MP3_ENDBYTE         0xEF


#endif
