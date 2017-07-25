#include "packet-commandx2F.h"

Commandx2F::Commandx2F(void)
{
	SetStx( Packet_Stx );
	SetCommand(Command_x2F);
	SetDataLength(Command_x2F_Length);
	SetEtx( Packet_Etx );
}
void Commandx2F::SetLockDoor(unsigned char lock)
{
	packet.data[ Idx_Lock_Door ] = lock;
}


/* Responsex2F */
unsigned char Responsex2F::GetAck(void)
{
	return packet.data[ Idx_Ack ];
}
