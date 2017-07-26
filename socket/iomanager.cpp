#include "iomanager.h"

Buffer IoManager::buffer;

int IoManager::SendData(char *buf, int len)
{
	//call the real socket send method
}
int IoManager::RecvData(char *buf, int len)
{
	if( 0 == buf || len < 1 )
	{
		return -1;
	}
	if( buffer.Push(buf, len) == false )
	{
		return -1;
	}
	return ProcessBuffer();
}

/*
如果数据头字节不是协议包头就直接
丢掉，
*/
int IoManager::ProcessBuffer(void)
{
	if( buffer.Length() < 1 )
	{
		return -1;
	}
	if( Packet_Stx != buffer.Data()[0] )
	{
		buffer.Pop(1);
	}
	int len = GetPacket();
	if( len > 0 )
	{
		buffer.Pop(len);
	}
}

/*
 Socket 接收的数据放在buffer里，
 检测到缓冲区的数据有一个有校包
 就直接取出，
*/
int IoManager::GetPacket(void)
{
	PacketAccess *p = buffer.Data();
	
	if( p->CheckSelf() )
	{
		//
		PostPacet(*p);
	}
	else
	{
		return 0;
	}
	return p->GetPacketLength();
}
int IoManager::PostPacet( PacketAccess& packet )
{
	switch( packet.GetCommand() )
	{
		case Command_x04:
		case Command_x07:
		case Command_x18:
		case Command_x19:
		case Command_x2C:
		case Command_x2D:
		case Command_x2E:
		case Command_x2F:
		case Command_x53:
		case Command_x56:
		case Command_x5A:
		case Command_x63:
		case Command_x73:
		case Command_x80:
		case Command_x81:
		case Command_x82:
		case Command_x83:
		case Command_x84:
		case Command_xB1:
			break;
	}
}
