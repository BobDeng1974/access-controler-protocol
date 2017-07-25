#ifndef __PACKET_INTERFACE_H__
#define __PACKET_INTERFACE_H__
#include <map>
#include <string>
using namespace std;

/*
本接口类对应用程序提供两个接口:

 1、用于设置接收数据的回调函数
	SetRecvMethod( void(*)(map<string,string>&) )

 2、用于向控制器发送命令的回调
	SendCommand(map<string,string>&)

对控制器协议模块提供一个接口：
１、控制器协议模块接收到数据后整理发往应用层
	本函数是直接调用回调完成数据传递.
	Recv( map<string,string>& );
*/

class PacketInterface
{
private:
	void (*recv)(map<string,string> &m);

public:
	static int Recv( map<string,string>& m);

public:
	static int SetRecvMethod( void (*func)( map<string,string>& m) );
	static int SendCommand( map<string,string>& m);
};

#endif//__PACKET_INTERFACE_H__
