#include "packet-interface.h"

int (*PacketInterface::recv)(map<string,string> &m)=0;

int PacketInterface::Recv( map<string, string> &m)
{
	if( recv )
	{
		recv(m);
	}
}

//接收控制器返回的数据
int PacketInterface::SetRecvMethod( void(*method)(map<string, string> &m) )
{
	recv = method;
}

//向控制器发控制指令
int SendCommand( map<string, string> &m);
{
	if( m["cmd"] == "OpenDoor" )
	{
		return OpenDoorCommand(m);
	}
	if( m["cmd"] == "LockDoor" )
	{
		return LockDoorCommand(m);
	}
	if( m["cmd"] == "TimeSync" )
	{
		return TimeSyncCommand(m);
	}
	if( m["cmd"] == "TimeSync" )
	{
		return TimeSyncCommand(m);
	}
	/*
	...
	xxxCommand(m);
	...
	*/
}
