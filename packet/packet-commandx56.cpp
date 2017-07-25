#include "packet-commandx56.h"

Commandx56::Commandx56(void)
{
	SetStx( Packet_Stx );
	SetCommand(Command_x56);
	SetDataLength(Command_x56_Length);
	SetEtx( Packet_Etx );
}
void Commandx56::GetTimeSMHdmy( TimeSMHdmy& t)
{
	int len = t.Length();
	unsigned char *p = t.Data();
	unsigned char *s = &packet.data[ Idx_Time_SHMdmy ];

	for(int i = 0; i < len; i++)
	{
		p[i] = s[i];
	}
}
bool Commandx56::GetOutDoorLockStatus(void)
{
	return (packet.data[ Idx_Lock_Status ] >> 5) & 0x01;
}
bool Commandx56::GetInDoorLockStatus(void)
{
	return (packet.data[ Idx_Lock_Status ] >> 4) & 0x01;
}
bool Commandx56::GetOutDoorStatus(void)
{
	return (packet.data[ Idx_Lock_Status ] >> 1) & 0x01;
}
bool Commandx56::GetInDoorStatus(void)
{
	return (packet.data[ Idx_Lock_Status ] >> 0) & 0x01;
}
char Commandx56::GetDoorDir(void)
{
	return packet.data[ Idx_Door_Dir ];
}
char Commandx56::GetDoorType(void)
{
	return packet.data[ Idx_Door_Type ];
}
bool Commandx56::GetWarningRelay(void)
{
	return (packet.data[ Idx_Warn_Relay ] >> 1) & 0x01;
}
bool Commandx56::GetFireWarnRelay(void)
{
	return (packet.data[ Idx_Warn_Relay ] >> 0) & 0x01;
}
char Commandx56::GetFirmwareVersion(void)
{
	return packet.data[ Idx_Firmware_Ver ];
}
short Commandx56::GetOemCode(void)
{
	unsigned short oem = 0;

	oem += (packet.data[ Idx_OEM_Code+0 ] << 8);
	oem += (packet.data[ Idx_OEM_Code+1 ] << 0);

	return 0xffff & oem;
}
void Commandx56::GetSerialNumber( SerialNumber& sn)
{
	int len = sn.Length();
	unsigned char *p = sn.Data();
	unsigned char *s = &packet.data[ Idx_Serial_Number ];

	for(int i = 0; i < len; i++)
	{
		p[i] = s[i];
	}
}
short Commandx56::GetInputPorts(void)
{
	unsigned short inputs = 0;

	inputs += packet.data[ Idx_Input_Ports+0 ] << 8;
	inputs += packet.data[ Idx_Input_Ports+1 ] << 0;

	return 0xffff & inputs;
}
bool Commandx56::GetResetInput(void)
{
	return (GetInputPorts() >> 11) & 0x01;
}
bool Commandx56::GetTamperInput(void)
{
	return (GetInputPorts() >> 10) & 0x01;
}
bool Commandx56::GetFireWarnInput(void)
{
	return (GetInputPorts() >> 9) & 0x01;
}
bool Commandx56::GetWarningInput(void)
{
	return (GetInputPorts() >> 8) & 0x01;
}
bool Commandx56::GetInButtonInput(void)
{
	return (GetInputPorts() >> 6) & 0x01;
}
bool Commandx56::GetOutButtonInput(void)
{
	return (GetInputPorts() >> 3) & 0x01;
}
void Commandx56::GetLableNumber( LableNumber& ln)
{
	int len = ln.Length();
	unsigned char *p = ln.Data();
	unsigned char *s = &packet.data[ Idx_Lable_Number ];

	for(int i = 0; i < len; i++)
	{
		p[i] = s[i];
	}
}


/* Responsex56 */

void Responsex56::SetUserCode(unsigned short code)
{
	packet.data[ Idx_User_Code+0 ] = 0xff & (code >> 8);
	packet.data[ Idx_User_Code+1 ] = 0xff & (code >> 0);
}
