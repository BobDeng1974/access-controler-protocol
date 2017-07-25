#include "packet-commandx5A.h"


Commandx5A::Commandx5A(void)
{
	SetStx( Packet_Stx );
	SetCommand(Command_x5A);
	SetDataLength(Command_x5A_Length);
	SetEtx( Packet_Etx );
}
void Commandx5A::SetReaderNumber(unsigned char number)
{
	packet.data[ Idx_Reader_Number ] = number;
}
void Commandx5A::SetPass(unsigned char pass)
{
	packet.data[ Idx_Pass ] = pass;
}
void Commandx5A::SetAll(unsigned char all)
{
	packet.data[ Idx_All ] = all;
}
