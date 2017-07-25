#include "packet-commandx2C.h"


Commandx2C::Commandx2C(void)
{
	SetStx( Packet_Stx );
	SetCommand(Command_x2C);
	SetDataLength(Command_x2C_Length);
	SetEtx( Packet_Etx );
}
void Commandx2C::SetDoorNumber(unsigned short number)
{
	packet.data[ Idx_Door_Number ] = number;
}


unsigned char Responsex2C::GetAck(void)
{
	return packet.data[ Idx_Ack ];
}
