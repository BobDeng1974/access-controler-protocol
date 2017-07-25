#ifndef __PACKET_COMMAND_X2E_H__
#define __PACKET_COMMAND_X2E_H__
#include "data-define.h"
#include "packet-access.h"

class Commandx2E: public PacketAccess
{
private:
	typedef enum
	{
		Idx_Door_Number = 0,	//len=1
	}FieldIndex;
public:
	Commandx2E(void);
public:
	void SetDoorNumber(unsigned char number);
};


/* Responsex2E */
class Responsex2E : public PacketAccess
{
private:
	typedef enum
	{
		Idx_Ack = 0,			//len=1
	}FieldIndex;

public:
	unsigned char GetAck(void);

};

#endif//__PACKET_COMMAND_X2E_H__
