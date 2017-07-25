#ifndef __PACKET_COMMAND_X2F_H__
#define __PACKET_COMMAND_X2F_H__
#include "data-define.h"
#include "packet-access.h"


class Commandx2F: public PacketAccess
{
private:
	typedef enum
	{
		Idx_Lock_Door = 0,	//len=1
	}FieldIndex;
public:
	Commandx2F(void);
public:
	//０表示解锁，１表示开锁
	void SetLockDoor(unsigned char lock);
};


/* Responsex2F */
class Responsex2F : public PacketAccess
{
private:
	typedef enum
	{
		Idx_Ack = 0,			//len=1
	}FieldIndex;

public:
	unsigned char GetAck(void);

};

#endif//__PACKET_COMMAND_X2F_H__
