#ifndef __PACKET_COMMAND_X63_H__
#define __PACKET_COMMAND_X63_H__
#include "data-define.h"
#include "packet-access.h"


class Commandx63: public PacketAccess
{
private:
	typedef enum
	{
		Idx_Open_Keep = 0,			//len=2
		Idx_Timeout_Value = 2,		//len=1
		Idx_Timeout_Warning = 3,	//len=1
		Idx_Warning_Type = 4,		//len=1
		Idx_Warning_Keep = 5,		//len=2
		Idx_FireWarn_Keep = 7,		//len=2
		Idx_TriggeWarn_Keep = 9,	//len=2
		Idx_Hostage_Passwd = 11,	//len=4
	}FieldIndex;
public:
	Commandx63(void);
public:
	void SetOpenKeep(unsigned short second);
	void SetTimeoutValue(unsigned char second);
	void SetTimeoutWarning(unsigned char record);
	void SetWarningType(unsigned char type);
	void SetWarningKeep(unsigned short second);
	void SetFireWarnKeep(unsigned short second);
	void SetTriggeWarnKeep(unsigned short second);
	void SetHostagePassword(unsigned int passwd);
};


/* Responsex63 */
class Responsex63 : public PacketAccess
{
private:
	typedef enum
	{
		Idx_Ack = 0,			//len=1
	}FieldIndex;

public:
	unsigned char GetAck(void);

};


#endif//__PACKET_COMMAND_X63_H__
