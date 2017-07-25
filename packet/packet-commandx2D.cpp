#include "packet-commandx2D.h"


Commandx2D::Commandx2D(void)
{
	SetStx( Packet_Stx );
	SetCommand(Command_x2D);
	SetDataLength(Command_x2D_Length);
	SetEtx( Packet_Etx );
}
void Commandx2D::SetDoorNumber(unsigned char number)
{
	packet.data[ Idx_Door_Number ] = number;
}


unsigned char Responsex2D::GetAck(void)
{
	return packet.data[ Idx_Ack ];
}
