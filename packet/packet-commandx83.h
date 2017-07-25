#ifndef __PACKET_COMMAND_X83_H__
#define __PACKET_COMMAND_X83_H__
#include "data-define.h"
#include "packet-access.h"

/* Commandx83 */
class Commandx83 : public PacketAccess
{
private:
	typedef enum
	{
		Idx_Page = 0,	//len=1
		Idx_Address = 1,//len=1
		Idx_Delay = 3,	//len=1
		Idx_Data = 4,	//len=46
	}FieldIndex;
public:
	Commandx83(void);
public:
	void SetPage(unsigned char page);
	void SetAddress(unsigned char address);
	void SetDelay(unsigned char delay);
	void SetData( DataBuffer& db);
};


/* Responsex83 */
class Responsex83 : public PacketAccess
{
private:
	typedef enum
	{
		Idx_Ack = 0,		//len=1
	}FieldIndex;
public:
	unsigned char GetAck(void);
};

#endif//__PACKET_COMMAND_X83_H__
