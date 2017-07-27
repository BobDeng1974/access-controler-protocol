#include <stdio.h>
#include <string>
#include "packet-reader.h"
#include "reader-thread.h"
#include "reader-socket.h"
using namespace std;


void poster(const char *data, int len)
{
	printf("%s.len=%d\n", __func__, len);
}

int main(void)
{
	ReaderSocket client;
	ReaderThread thread;
	PacketReader reader;
	string data = "\x02\x01\x01\x01\x11\x01\xB1nonono";

	reader.SetPoster(poster);
	reader.PushData(data.data(), data.length());

	for(int i = 0; i < data.length(); i++)
	{
		reader.CheckPacket();
	}
	client.Connect("0.0.0.0", 8888);

	while(1)
	{
		int len = 0;
		char buf[32] = {0};

		len = client.Recv(buf, sizeof(buf));
		if( len > 0 )
		{
			reader.PushData(buf, len);
			reader.CheckPacket();
		}
	}

	return 0;
}
