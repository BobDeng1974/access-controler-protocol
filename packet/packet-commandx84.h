#ifndef __PACKET_COMMAND_X84_H__
#define __PACKET_COMMAND_X84_H__
#include "data-define.h"
#include "packet-access.h"

/* Commandx84 */
class Commandx84 : public PacketAccess
{
private:
	typedef enum
	{
		Idx_Delay = 0,	//len=1
		Idx_Page = 1,	//len=1
		Idx_Card_Id = 2,//len=4
	}FieldIndex;

public:
	Commandx84(void);
public:
	void SetPage(unsigned char page);
	void SetDelay(unsigned char delay);
	void SetCardId(unsigned int id);
};


/* Responsex84 */
class Responsex84 : public PacketAccess
{
private:
	typedef enum
	{
		Idx_Ack = 0,		//len=1
	}FieldIndex;
public:
	unsigned char GetAck(void);
};

#endif//__PACKET_COMMAND_X84_H__
