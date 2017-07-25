#include "packet-commandx84.h"


Commandx84::Commandx84(void)
{
	SetStx( Packet_Stx );
	SetCommand(Command_x84);
	SetDataLength(Command_x84_Length);
	SetEtx( Packet_Etx );
}
void Commandx84::SetPage(unsigned char page)
{
	packet.data[ Idx_Page ] = page;
}
void Commandx84::SetDelay(unsigned char delay)
{
	packet.data[ Idx_Delay ] = delay;
}
void Commandx84::SetCardId(unsigned int id)
{
	packet.data[ Idx_Card_Id ] = id;
}


/* Responsex84 */
unsigned char Responsex84::GetAck(void)
{
	return packet.data[ Idx_Ack ];
}
