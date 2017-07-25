#ifndef __PACKET_COMMAND_X80_H__
#define __PACKET_COMMAND_X80_H__
#include "data-define.h"
#include "packet-access.h"

/* Commandx80 */
class Commandx80 : public PacketAccess
{
private:
	typedef enum
	{
		Idx_Voice_Device = 0,		//len=1
		Idx_Voice_Length = 1,		//len=1
		Idx_Reserved_1 = 2,			//len=1
		Idx_Voice_String = 3		//len=56
	}FieldIndex;

public:
	Commandx80(void);
public:
	void SetVoiceDevice(unsigned char address);
	void SetVoiceLength(unsigned char length);
	void SetVoiceString( VoiceString& vs );
};


/* Responsex80 */
class Responsex80 : public PacketAccess
{
private:
	typedef enum
	{
		Idx_Ack = 0,		//len=1
	}FieldIndex;
public:
	unsigned char GetAck(void);
};

#endif//__PACKET_COMMAND_X80_H__
