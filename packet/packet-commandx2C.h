#ifndef __PACKET_COMMAND_X2C_H__
#define __PACKET_COMMAND_X2C_H__
#include "data-define.h"
#include "packet-access.h"

class Commandx2C: public PacketAccess
{
private:
	typedef enum
	{
		Idx_Door_Number = 0,	//len=1
	}FieldIndex;
public:
	Commandx2C(void);
public:
	void SetDoorNumber(unsigned short number);
};


/* Responsex2C */
class Responsex2C : public PacketAccess
{
private:
	typedef enum
	{
		Idx_Ack = 0,			//len=1
	}FieldIndex;

public:
	unsigned char GetAck(void);

};

#endif//__PACKET_COMMAND_X2C_H__
