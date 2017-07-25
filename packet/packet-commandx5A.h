#ifndef __PACKET_COMMAND_X5A_H__
#define __PACKET_COMMAND_X5A_H__
#include "data-define.h"
#include "packet-access.h"

class Commandx5A : public PacketAccess
{
private:
	typedef enum
	{
		Idx_Reserved_1 = 0,		//len=1
		Idx_Reader_Number = 1,	//len=1
		Idx_Reserved_2 = 3,		//len=1
		Idx_Pass = 4,			//len=1
		Idx_All = 5,			//len=1
	}FieldIndex;

public:
	Commandx5A(void);
public:
	void SetReaderNumber(unsigned char number);
	void SetPass(unsigned char pass);
	void SetAll(unsigned char all);
};


class Responsex5A : public PacketAccess
{
private:
	typedef enum
	{
		Idx_User_Code = 0, //len=2
	}FieldIndex;
public:
	void SetUserCode(unsigned short code);
};

#endif//__PACKET_COMMAND_X5A_H__
