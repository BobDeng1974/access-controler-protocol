#include "packet-commandx18.h"

Commandx18::Commandx18(void)
{
	SetStx( Packet_Stx );
	SetCommand(Command_x18);
	SetDataLength(Command_x18_Length);
	SetEtx( Packet_Etx );
}
void Commandx18::SetCloseWarning(unsigned char close)
{
	packet.data[ Idx_Close_Warning ] = close;
}
void Commandx18::SetKeepWarning(unsigned char keep)
{
	packet.data[ Idx_Keep_Warning] = keep;
}

/* Responsex18 */
unsigned char Responsex18::GetAck(void)
{
	return packet.data[ Idx_Ack ];
}
