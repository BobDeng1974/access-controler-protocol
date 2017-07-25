#ifndef __PACKET_COMMAND_X2D_H__
#define __PACKET_COMMAND_X2D_H__
#include "data-define.h"
#include "packet-access.h"

class Commandx2D: public PacketAccess
{
private:
	typedef enum
	{
		Idx_Door_Number = 0,	//len=1
	}FieldIndex;
public:
	Commandx2D(void);
public:
	void SetDoorNumber(unsigned char number);
};


/* Responsex2D */
class Responsex2D : public PacketAccess
{
private:
	typedef enum
	{
		Idx_Ack = 0,			//len=1
	}FieldIndex;

public:
	unsigned char GetAck(void);

};

#endif//__PACKET_COMMAND_X2D_H__
