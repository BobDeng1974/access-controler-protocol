#ifndef __PACKET_COMMAND_X82_H__
#define __PACKET_COMMAND_X82_H__
#include "data-define.h"
#include "packet-access.h"

/* Commandx82 */
class Commandx82 : public PacketAccess
{
private:
	typedef enum
	{
		Idx_Delay = 0,			//len=1
		Idx_Page = 1,			//len=1
		Idx_CardNum_String = 2,	//len=18
		Idx_Name_String = 20,	//len=16
		Idx_Event_String = 36,	//len=40
		Idx_Time_String = 76,	//len=20
	}FieldIndex;

public:
	Commandx82(void);
public:
	void SetDelay(unsigned char delay);
	void SetPage(unsigned char page);
	void SetCardNumString( CardNumString& cs );
	void SetNameString( NameString& ns );
	void SetEventString( EventString& es );
	void SetTimeString( TimeString& ts );
};


/* Responsex82 */
class Responsex82 : public PacketAccess
{
private:
	typedef enum
	{
		Idx_Ack = 0,		//len=1
	}FieldIndex;
public:
	unsigned char GetAck(void);
};

#endif//__PACKET_COMMAND_X82_H__
