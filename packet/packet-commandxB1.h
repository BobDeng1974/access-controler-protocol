#ifndef __PACKET_COMMAND_XB1_H__
#define __PACKET_COMMAND_XB1_H__
#include "data-define.h"
#include "packet-access.h"

/* CommandxB1 */
class CommandxB1 : public PacketAccess
{
private:
	typedef enum
	{
		Idx_Data_Length = 0,		//len=1
	}FieldIndex;

public:
	CommandxB1(void);
public:
	void SetDataLength(unsigned char length);
};


/* ResponsexB1 */
class ResponsexB1 : public PacketAccess
{
private:
	typedef enum
	{
		Idx_Data_Length = 0,		//len=1
	}FieldIndex;
public:
	unsigned char GetDataLength(void);
};

#endif//__PACKET_COMMAND_XB1_H__
