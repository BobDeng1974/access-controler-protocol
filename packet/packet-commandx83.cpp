#include "packet-commandx83.h"


Commandx83::Commandx83(void)
{
	SetStx( Packet_Stx );
	SetCommand(Command_x83);
	SetDataLength(Command_x83_Length);
	SetEtx( Packet_Etx );
}
void Commandx83::SetPage(unsigned char page)
{
	packet.data[ Idx_Page ] = page;
}
void Commandx83::SetAddress(unsigned char address)
{
	packet.data[ Idx_Address ] = address;
}
void Commandx83::SetDelay(unsigned char delay)
{
	packet.data[ Idx_Delay ] = delay;
}
void Commandx83::SetData( DataBuffer& data )
{
	int len = data.Length();
	unsigned char *s = data.Data();
	unsigned char *p = &packet.data[ Idx_Data ];

	for(int i = 0; i < len; i++)
	{
		p[i] = s[i];
	}
}

