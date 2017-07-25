#ifndef __PACKET_COMMAND_X19_H__
#define __PACKET_COMMAND_X19_H__
#include "data-define.h"
#include "packet-access.h"


class Commandx19: public PacketAccess
{
private:
	typedef enum
	{
		Idx_Close_FireWarn = 0,	//len=1
		Idx_Keep_FireWarn = 1,	//len=1
	}FieldIndex;
public:
	Commandx19(void);
public:
	void SetCloseFireWarn(unsigned char warning);
	void SetKeepFireWarn(unsigned char keep);
};


/* Responsex19 */
class Responsex19 : public PacketAccess
{
private:
	typedef enum
	{
		Idx_Ack = 0,			//len=1
	}FieldIndex;

public:
	unsigned char GetAck(void);

};

#endif//__PACKET_COMMAND_X19_H__
