#ifndef __PACKET_INTERFACE_H__
#define __PACKET_INTERFACE_H__
#include <map>
#include <string>
using namespace std;

/*
���ӿ����Ӧ�ó����ṩ�����ӿ�:

 1���������ý������ݵĻص�����
	SetRecvMethod( void(*)(map<string,string>&) )

 2���������������������Ļص�
	SendCommand(map<string,string>&)

�Կ�����Э��ģ���ṩһ���ӿڣ�
����������Э��ģ����յ����ݺ�������Ӧ�ò�
	��������ֱ�ӵ��ûص�������ݴ���.
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
