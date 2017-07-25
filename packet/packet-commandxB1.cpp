#include "packet-commandxB1.h"

/* CommandxB1 */
CommandxB1::CommandxB1(void)
{
	SetStx( Packet_Stx );
	SetCommand(Command_xB1);
	SetDataLength(Command_xB1_Length);
	SetEtx( Packet_Etx );
}
void CommandxB1::SetDataLength(unsigned char length)
{
	packet.data[ Idx_Data_Length ] = length;
}

/* ResponsexB1 */
unsigned char ResponsexB1::GetDataLength(void)
{
	return packet.data[ Idx_Data_Length ];
}
