#include "packet-access.h"


PacketAccess::PacketAccess(void)
{
	InitPacket();
}

void PacketAccess::InitPacket(void)
{
	unsigned char *p = (unsigned char*)&packet;

	for(int i = 0; i < sizeof(packet); i++)
	{
		p[i] = (unsigned char)0;
	}
}

void PacketAccess::SetStx(unsigned char stx)
{
	packet.stx = stx;
}
unsigned char PacketAccess::GetStx(void)
{
	return packet.stx;
}

void PacketAccess::SetRand(unsigned char rand)
{
	packet.rand = rand;
}
unsigned char PacketAccess::GetRand(void)
{
	return packet.rand;
}

void PacketAccess::SetCommand(unsigned char cmd)
{
	packet.command = cmd;
}
unsigned char PacketAccess::GetCommand(void)
{
	return packet.command;
}



void PacketAccess::SetAddress(unsigned char address)
{
	packet.address = address;
}
unsigned char PacketAccess::GetAddress(void)
{
	return packet.address;
}

void PacketAccess::SetDataLength(unsigned short len)
{
	if( len <= (sizeof(packet.data) - 2) )
	{
		packet.lenhig = 0xff & (len >> 8);
		packet.lenlow = 0xff & (len >> 0);
		length = len;
	}
}
unsigned short PacketAccess::GetDataLength(void)
{
	return ((packet.lenhig << 8) | packet.lenlow) % (sizeof(packet.data)-2);
}

bool PacketAccess::SetData(unsigned char* data, int len)
{
	if( 0 == data )
	{
		return 0;
	}
	if( len < 0 )
	{
		return 0;
	}
	if( len > sizeof(packet.data) - 2 )
	{
		return 0;
	}
	for(int i = 0; i < len; i++)
	{
		packet.data[i] = data[i];
	}
	SetDataLength( (unsigned short)len );
	return 1;	
}
unsigned char* PacketAccess::GetData(void)
{
	return packet.data;
}

void PacketAccess::SetCheckSum(unsigned char cs)
{
	packet.data[ GetDataLength() ] = cs;	
}
unsigned char PacketAccess::GetCheckSum(void)
{
	return packet.data[ GetDataLength() ];	
}
unsigned char PacketAccess::CalcCheckSum(void)
{
	unsigned char *p = (unsigned char*)&packet;
	unsigned char checksum = 0;
	int len = packet.data - p;

	len += GetDataLength();
	for(int i = 0; i < len; i++)
	{
		checksum ^= p[i];
	}
	return checksum;
}

void PacketAccess::SetEtx(unsigned char etx)
{
	packet.data[ GetDataLength() + 1 ] = etx;
}
unsigned char PacketAccess::GetEtx(void)
{
	return packet.data[ GetDataLength() + 1 ];
}

unsigned int PacketAccess::GetPacketLength(void)
{
	unsigned char *p = (unsigned char*)&packet; 

	return (packet.data - p) + GetDataLength() + 2;
}
bool PacketAccess::CheckSelf(void)
{
	return GetCheckSum() == CalcCheckSum();
}

bool PacketAccess::MakePacket(void)
{
	SetDataLength( length );
	SetCheckSum( CalcCheckSum() );
	SetEtx( Packet_Etx );
	return CheckSelf();
}
