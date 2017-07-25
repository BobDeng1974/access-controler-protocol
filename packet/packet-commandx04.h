#ifndef __PACKET_COMMAND_X04_H__
#define __PACKET_COMMAND_X04_H__
#include "data-define.h"
#include "packet-access.h"


class Commandx04: public PacketAccess
{
public:
	Commandx04(void);
};


/* Responsex73 */
class Responsex04 : public PacketAccess
{
private:
	typedef enum
	{
		Idx_Ack = 0,			//len=1
	}FieldIndex;
public:
	unsigned char GetAck(void);

};



#endif//__PACKET_COMMAND_X04_H__
