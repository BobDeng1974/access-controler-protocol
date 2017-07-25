#ifndef __PACKET_COMMAND_X07_H__
#define __PACKET_COMMAND_X07_H__
#include "data-define.h"
#include "packet-access.h"


class Commandx07: public PacketAccess
{
private:
	typedef enum
	{
		Idx_Second = 0,		//len=1
		Idx_Minute = 1,		//len=1
		Idx_Hour = 2,		//len=1
		Idx_Weekday = 3,	//len=1
		Idx_Day = 4,		//len=1
		Idx_Month = 5,		//len=1
		Idx_Year = 6,		//len=1
	}FieldIndex;
public:
	Commandx07(void);
public:
	void SetSecond(unsigned char second);
	void SetMinute(unsigned char minute);
	void SetHour(unsigned char hour);
	void SetWeekday(unsigned char wday);
	void SetDay(unsigned char day);
	void SetMonth(unsigned char month);
	void SetYear(unsigned char year);
};


/* Responsex07 */
class Responsex07 : public PacketAccess
{
private:
	typedef enum
	{
		Idx_Ack = 0,			//len=1
	}FieldIndex;

public:
	unsigned char GetAck(void);

};



#endif//__PACKET_COMMAND_X07_H__
