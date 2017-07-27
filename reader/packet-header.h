#ifndef __PACKET_HEADER_H__
#define __PACKET_HEADER_H__
#include <vector>
using namespace std;

#define STX 0x02
#define HEADER_LENGTH	7
typedef enum
{
	Idx_Stx = 0,
	Idx_Rand = 1,
	Idx_Command = 2,
	Idx_Address = 3,
	Idx_Door = 4,
	Idx_Length = 5,
}FieldIndx;
typedef enum
{
	Cmd_x04 = 0x04,
	Cmd_x07 = 0x07,
	Cmd_x18 = 0x18,
	Cmd_x19 = 0x19,
	Cmd_x2C = 0x2C,
	Cmd_x2D = 0x2D,
	Cmd_x2E = 0x2E,
	Cmd_x2F = 0x2F,
	Cmd_x53 = 0x53,
	Cmd_x56 = 0x56,
	Cmd_x5A = 0x5A,
	Cmd_x63 = 0x63,
	Cmd_x73 = 0x73,
	Cmd_x80 = 0x80,
	Cmd_x81 = 0x81,
	Cmd_x82 = 0x82,
	Cmd_x83 = 0x83,
	Cmd_x84 = 0x84,
	Cmd_xB1 = 0xB1,
}Command;
typedef enum
{
	Door_1 = 1,
	Door_2 = 2,
	Door_3 = 3,
	Door_4 = 4,
}Door;
class PacketHeader
{
public:
	static int GetStx(vector<char>& data);
	static int GetRand(vector<char>& data);
	static int GetCommand(vector<char>& data);
	static int GetAddress(vector<char>& data);
	static int GetDoor(vector<char>& data);
	static int GetBodyLength(vector<char>& data);
	static int GetPacketLength(vector<char>& data);
public:
	static int CheckHeader(vector<char>& data);
};

#endif//__PACKET_HEADER_H__
