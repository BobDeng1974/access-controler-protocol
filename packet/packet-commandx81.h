#ifndef __PACKET_COMMAND_X81_H__
#define __PACKET_COMMAND_X81_H__
#include "data-define.h"
#include "packet-access.h"

/* Commandx81 */
class Commandx81 : public PacketAccess
{
private:
	typedef enum
	{
		Idx_Delay = 0,			//len=1
		Idx_Page = 1,			//len=1
		Idx_Card_String = 2,	//len=18
		Idx_Name_String = 20,	//len=16
		Idx_Event_String = 36,	//len=40
		Idx_Time_String = 76,	//len=20
	}FieldIndex;

public:
	Commandx81(void);
public:
	void SetDelay(unsigned char delay);
	void SetPage(unsigned char page);
	void SetCardNumString( CardNumString& cs );
	void SetNameString( NameString& ns );
	void SetEventString( EventString& es );
	void SetTimeString( TimeString& ts );
};


/* Responsex81 */
class Responsex81 : public PacketAccess
{
private:
	typedef enum
	{
		Idx_Ack = 0,		//len=1
	}FieldIndex;
public:
	unsigned char GetAck(void);
};

#endif//__PACKET_COMMAND_X81_H__
