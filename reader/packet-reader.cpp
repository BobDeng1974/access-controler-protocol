#include <stdio.h>
#include "packet-header.h"
#include "packet-reader.h"

PacketReader::PacketReader(void)
{
	poster = 0;
	droplen = 0;
}
void PacketReader::PushData(const char *buf, int len)
{
	for(int i = 0; buf && i < len; i++)
	{
		data.push_back(buf[i]);
	}
	PostPacket( CheckPacket() );
}
void PacketReader::SetPoster( void(*f)(const char*,int) )
{
	poster = f;
}
int PacketReader::CheckPacket(void)
{
	printf("data.size(%d)\n", data.size());
	switch( PacketHeader::CheckHeader(data) )
	{
	case 0:
		return 0;
	case -(Idx_Stx+1):
		data.erase(data.begin(), data.begin()+Idx_Stx+1);
		droplen += (Idx_Stx+1);
		return 0;
	case -(Idx_Command+1):
		data.erase(data.begin(), data.begin()+Idx_Command+1);
		return 0;
	case -(Idx_Door+1):
		data.erase(data.begin(), data.begin()+Idx_Door+1);
		return 0;
	case -(Idx_Length+1):
		data.erase(data.begin(), data.begin()+Idx_Length+1);
		return 0;
	}//switch
	int len = PacketHeader::GetPacketLength(data);
	if( data.size() >=  len )
	{
		return len;
	}
	return 0;
}
int PacketReader::PostPacket(int len)
{
	if( len > 0 )
	{
		char *buf = new char[len];
		for(int i = 0; i < len; i++)
		{
			buf[i] = data[i];
		}
		if( poster )
		{
			poster(buf, len);
		}
		data.erase(data.begin(), data.begin() + len);
	}
}
