#ifndef __READER_SOCKET_H__
#define __READER_SOCKET_H__

class ReaderSocket
{
private:
	int fd;
public:
	ReaderSocket(void);
	~ReaderSocket(void);

public:
	bool Open(void);
	bool Connect(char *ip, int port);
	int Recv(char *buf, int len);
	int Send(char *buf, int len);
	bool Close(void);
};

#endif//__READER_SOCKET_H__
