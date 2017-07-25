#ifndef __PACKET_COMMAND_X56_H__
#define __PACKET_COMMAND_X56_H__
#include "data-define.h"
#include "packet-access.h"

class Commandx56 : public PacketAccess
{
private:
	typedef enum
	{
		Idx_Reserv_1 = 0,		//len=0
		Idx_Time_SHMdmy = 1,	//len=6
		Idx_Door_Status = 7,	//len=1
		Idx_Reserv_2 = 8,		//len=1
		Idx_Door_Dir = 9,		//len=1
		Idx_Reserv_3 = 10,		//len=1
		Idx_Door_Type = 11,		//len=1
		Idx_Lock_Status = 12,	//len=1
		Idx_Reserv_4 = 13,		//len=4
		Idx_Warn_Relay = 17,	//len=1
		Idx_Firmware_Ver = 18,	//len=1
		Idx_OEM_Code = 19,		//len=2
		Idx_Serial_Number = 21,	//len=6
		Idx_Input_Ports = 27,	//len=2
		Idx_Lable_Number = 29,	//len=6
	}FieldIndex;

public:
	Commandx56(void);
public:
	void GetTimeSMHdmy( TimeSMHdmy& t);
	bool GetOutDoorLockStatus(void);
	bool GetInDoorLockStatus(void);
	bool GetOutDoorStatus(void);
	bool GetInDoorStatus(void);
	char GetDoorDir(void);
	char GetDoorType(void);
	bool GetWarningRelay(void);
	bool GetFireWarnRelay(void);
	char GetFirmwareVersion(void);
	short GetOemCode(void);
	void GetSerialNumber( SerialNumber& sn);
	short GetInputPorts(void);
	bool GetResetInput(void);
	bool GetTamperInput(void);
	bool GetFireWarnInput(void);
	bool GetWarningInput(void);
	bool GetInButtonInput(void);
	bool GetOutButtonInput(void);
	void GetLableNumber( LableNumber& ln);
};


class Responsex56 : public PacketAccess
{
private:
	typedef enum
	{
		Idx_User_Code = 0, //len=2
	}FieldIndex;
public:
	void SetUserCode(unsigned short code);
};

#endif//__PACKET_COMMAND_X56_H__
