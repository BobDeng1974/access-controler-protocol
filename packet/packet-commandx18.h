#ifndef __PACKET_COMMAND_X18_H__
#define __PACKET_COMMAND_X18_H__
#include "data-define.h"
#include "packet-access.h"


class Commandx18: public PacketAccess
{
private:
	typedef enum
	{
		Idx_Close_Warning = 0,	//len=1
		Idx_Keep_Warning = 1,	//len=1
	}FieldIndex;
public:
	Commandx18(void);
public:
	void SetCloseWarning(unsigned char close);
	void SetKeepWarning(unsigned char keep);
};


/* Responsex18 */
class Responsex18 : public PacketAccess
{
private:
	typedef enum
	{
		Idx_Ack = 0,			//len=1
	}FieldIndex;

public:
	unsigned char GetAck(void);

};

#endif//__PACKET_COMMAND_X18_H__
