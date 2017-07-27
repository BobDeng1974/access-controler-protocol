#ifndef __PACKET_READER_H__
#define __PACKET_READER_H__
#include <vector>

class PacketReader
{
private:
	int droplen;
	std::vector<char> data;
	void(*poster)(const char* data, int len);

public:
	PacketReader(void);

public:
	void PushData(const char *buf, int len);
	void SetPoster( void(*f)(const char*,int) );
	int CheckPacket(void);

private:
	int PostPacket(int);
};
#endif//__PACKET_READER_H__
