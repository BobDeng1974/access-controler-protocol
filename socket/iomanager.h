#ifndef __IOMANAGER_H__
#define __IOMANAGER_H__
#include "buffer.h"
#include "packet-access.h"

class IoManager
{
private:
	static Buffer buffer;

public:
	static int SendData(char *buf, int len);
	static int RecvData(char *buf, int len);

private:
	static int ProcessBuffer(void);
	static int GetPacket(void);
	static int PostPacket(PacketAccess&);
};

#endif//__IOMANAGER_H__
