#include "packet-commandx19.h"

Commandx19::Commandx19(void)
{
	SetStx( Packet_Stx );
	SetCommand(Command_x19);
	SetDataLength(Command_x19_Length);
	SetEtx( Packet_Etx );
}
void Commandx19::SetCloseFireWarn(unsigned char close)
{
	packet.data[ Idx_Close_FireWarn ] = close;
}
void Commandx19::SetKeepFireWarn(unsigned char keep)
{
	packet.data[ Idx_Keep_FireWarn ] = keep;
}

/* Responsex19 */
unsigned char Responsex19::GetAck(void)
{
	return packet.data[ Idx_Ack ];
}
