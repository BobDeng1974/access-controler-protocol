#include "packet-commandx04.h"


/* Commandx04 Ack */
Commandx04::Commandx04(void)
{
	SetStx( Packet_Stx );
	SetCommand( Command_x04 );
	SetDataLength(Command_x04_Length);
	SetEtx( Packet_Etx );
}
unsigned char Responsex04::GetAck(void)
{
	return packet.data[ Idx_Ack ];
}
