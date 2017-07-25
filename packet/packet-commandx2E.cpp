#include "packet-commandx2E.h"


Commandx2E::Commandx2E(void)
{
	SetStx( Packet_Stx );
	SetCommand(Command_x2E);
	SetDataLength(Command_x2E_Length);
	SetEtx( Packet_Etx );
}

void Commandx2E::SetDoorNumber(unsigned char number)
{
	packet.data[ Idx_Door_Number ] = number;
}


unsigned char Responsex2E::GetAck(void)
{
	return packet.data[ Idx_Ack ];
}
