#include <stdio.h>
#include "packet-header.h"


int PacketHeader::GetPacketLength(vector<char>& data)
{
	return HEADER_LENGTH + GetBodyLength(data) + 2;
}
int PacketHeader::GetStx(vector<char>& data)
{
	return 0xff & data[ Idx_Stx ];
}
int PacketHeader::GetRand(vector<char>& data)
{
	return 0xff & data[ Idx_Rand ];
}
int PacketHeader::GetCommand(vector<char>& data)
{
	return 0xff & data[ Idx_Command ];
}
int PacketHeader::GetAddress(vector<char>& data)
{
	return 0xff & data[ Idx_Address ];
}
int PacketHeader::GetDoor(vector<char>& data)
{
	return 0xff & data[ Idx_Door ];
}
int PacketHeader::GetBodyLength(vector<char>& data)
{
	return 0xffff & ((data[ Idx_Length+0 ] << 8)
					|(data[ Idx_Length+1 ] << 0));
}
int PacketHeader::CheckHeader(vector<char>& data)
{
	if( data.size() < HEADER_LENGTH )
	{
		printf("CheckHeader(data.size=%d)\n", data.size());
		return 0;
	}
	if( STX != GetStx(data) )
	{
		printf("PacketHeader.Stx=%02X\n", GetStx(data));
		return -(Idx_Stx+1);
	}
	switch( GetCommand(data) )
	{
		case Cmd_x04:
		case Cmd_x07:	
		case Cmd_x18:
		case Cmd_x19:
		case Cmd_x2C:
		case Cmd_x2D:
		case Cmd_x2E:
		case Cmd_x2F:
		case Cmd_x53:
		case Cmd_x56:
		case Cmd_x5A:
		case Cmd_x63:
		case Cmd_x73:
		case Cmd_x80:
		case Cmd_x81:
		case Cmd_x82:
		case Cmd_x83:
		case Cmd_x84:
		case Cmd_xB1:
			break;
		default:
			printf("PacketHeader.Command=%02X\n", GetCommand(data));
			return -(Idx_Command+1);
	}
	switch( GetDoor(data) )
	{
		case Door_1:
		case Door_2:	
		case Door_3:
		case Door_4:	
			break;
		default:
			printf("PacketHeader.Door=%02X\n", GetDoor(data));
			return -(Idx_Door+1);
	}
	switch( GetBodyLength(data) )
	{
		case 133:
			break;
		default:
			printf("PacketHeader.Length=%02X\n", GetBodyLength(data));
			return -(Idx_Length+1);
	}
	return 1;
}
