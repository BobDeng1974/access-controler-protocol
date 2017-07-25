#ifndef __PACKET_COMMAND_X53_H__
#define __PACKET_COMMAND_X53_H__
#include "data-define.h"
#include "packet-access.h"

class Commandx53 : public PacketAccess
{
private:
	typedef enum
	{
		Idx_Serial_Number = 0,		//len=6
		Idx_Lable_String = 6,		//len=10
		Idx_Reader_Number = 16,		//len=1
		Idx_Reserved_1 = 17,		//len=1
		Idx_Reserved_2 = 18,		//len=4
		Idx_Data_Type = 22,			//len=1
		Idx_System_Time = 23,		//len=16
		Idx_Card_Id = 39,			//len=4
		Idx_Card_Data = 43,			//len=56
	}FieldIndex;
public:
	Commandx53(void);
public:
	void GetSerialNumber( SerialNumber& sn );
	void GetLableString( LableString & ls );
	char GetReaderNumber( void );
	char GetDataType( void );
	void GetSystemTime( SystemTime& st );
	 int GetCardId(void);
	 void GetCardData( CardData& cd);
};


class Responsex53 : public PacketAccess
{
private:
	typedef enum
	{
		Idx_Open_Door = 0,		//len=1
		Idx_Relay_Number = 1,	//len=1
		Idx_Relay_Keep = 2,		//len=2
		Idx_Reader_Number = 4,	//len=1
		Idx_Show_Keep = 5,		//len=1
		Idx_CardNum_Type = 6,	//len=1
		Idx_CardNum_String = 7,	//len=18
		Idx_Voice_String = 25,	//len=40
		Idx_Name_String = 65,	//len=16
		Idx_Event_String = 81,	//len=32
		Idx_Time_String = 113,	//len=20
	}FieldIndex;
public:
	void SetOpenDoor(unsigned char open);
	void SetRelayNumber(unsigned char number);
	void SetRelayKeep(unsigned short second);
	void SetReaderNumber(unsigned char number);
	void SetShowKeep(unsigned char second);
	void SetCardNumType(unsigned char type);
	void SetCardNumString( CardNumString& cs );
	void SetVoiceString( VoiceString& vs );
	void SetNameString( NameString& ns );
	void SetEventString( EventString& ev );
	void SetTimeString( TimeString& ts );
};

/* Responsex53 Ack */
class Responsex53Ack : public PacketAccess
{
private:
	typedef enum
	{
		Idx_Ack = 0,			//len=1
	}FieldIndex;

public:
	unsigned char GetAck(void);

};

#endif//__PACKET_COMMAND_X53_H__
