#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <arpa/inet.h>
#include "reader-socket.h"

ReaderSocket::ReaderSocket(void)
{
	fd = -1;
	Open();
}
ReaderSocket::~ReaderSocket(void)
{
	Close();
	fd = -1;
}

bool ReaderSocket::Open(void)
{
	if( -1 == fd )
	{
		fd = socket(AF_INET, SOCK_STREAM, 0);
	}
	return (-1 != fd);
}
bool ReaderSocket::Connect(char *ip, int port)
{
	struct sockaddr_in address;
	const char *p = ip ? ip : "0.0.0.0";

	address.sin_family = AF_INET;
	address.sin_addr.s_addr = inet_addr(p);
	address.sin_port = htons( (short)port );
	return (connect(fd, (struct sockaddr*)&address, sizeof(address))==0);
}
int ReaderSocket::Recv(char *buf, int len)
{
	if( buf && len > 0 )
	{
		return recv(fd, buf, len, 0);
	}
	return 0;
}
int ReaderSocket::Send(char *buf, int len)
{
	if( buf && len > 0 )
	{
		return send(fd, buf, len, 0);
	}
	return 0;
}
bool ReaderSocket::Close(void)
{
	return (close(fd) == 0);
}

