#include "packet-commandx63.h"


Commandx63::Commandx63(void)
{
	SetStx( Packet_Stx );
	SetCommand(Command_x63);
	SetDataLength(Command_x63_Length);
	SetEtx( Packet_Etx );
}
void Commandx63::SetOpenKeep(unsigned short second)
{
	packet.data[ Idx_Open_Keep+0 ] = 0xff & (second >> 8);
	packet.data[ Idx_Open_Keep+1 ] = 0xff & (second >> 0);
}
void Commandx63::SetTimeoutValue(unsigned char second)
{
	packet.data[ Idx_Timeout_Value ] = second;
}
void Commandx63::SetTimeoutWarning(unsigned char warning)
{
	packet.data[ Idx_Timeout_Warning ] = warning;
}
void Commandx63::SetWarningType(unsigned char type)
{
	packet.data[ Idx_Warning_Type ] = type;
}
void Commandx63::SetWarningKeep(unsigned short second)
{
	packet.data[ Idx_Warning_Keep+0 ] = 0xff & (second >> 8);
	packet.data[ Idx_Warning_Keep+1 ] = 0xff & (second >> 0);
}
void Commandx63::SetFireWarnKeep(unsigned short second)
{
	packet.data[ Idx_FireWarn_Keep+0 ] = 0xff & (second >> 8);
	packet.data[ Idx_FireWarn_Keep+1 ] = 0xff & (second >> 0);
}
void Commandx63::SetTriggeWarnKeep(unsigned short second)
{
	packet.data[ Idx_TriggeWarn_Keep+0 ] = 0xff & (second >> 8);
	packet.data[ Idx_TriggeWarn_Keep+1 ] = 0xff & (second >> 0);
}

void Commandx63::SetHostagePassword(unsigned int passwd)
{
	packet.data[ Idx_Hostage_Passwd+0 ] = 0xff & (passwd >> 24);
	packet.data[ Idx_Hostage_Passwd+1 ] = 0xff & (passwd >> 16);
	packet.data[ Idx_Hostage_Passwd+2 ] = 0xff & (passwd >>  8);
	packet.data[ Idx_Hostage_Passwd+3 ] = 0xff & (passwd >>  0);
}


/* Responsex63 */
unsigned char Responsex63::GetAck(void)
{
	return packet.data[ Idx_Ack ];
}
