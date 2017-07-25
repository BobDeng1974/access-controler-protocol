#ifndef _PACKET_ACCESS_H
#define _PACKET_ACCESS_H
#include "command-define.h"


//协议包缓冲
typedef struct packet
{
	unsigned char stx;
	unsigned char rand;
	unsigned char command;
	unsigned char address;
	unsigned char door;
	unsigned char lenhig;
	unsigned char lenlow;
	unsigned char data[256];
}packet_t;

//协议包处理基类
class PacketAccess
{
protected:
	unsigned short length;
	struct packet packet;

public:
	PacketAccess(void);

public:
	//清零包缓冲区
	void InitPacket(void);

public:
	//设置,获取包头起始字
	void SetStx(unsigned char stx);
	unsigned char GetStx(void);

	//暂时无用,预留
	void SetRand(unsigned char rand);
	unsigned char GetRand(void);

	//设置,获取包命令字
	void SetCommand(unsigned char cmd);
	unsigned char GetCommand(void);

	//暂时无用,预留
	void SetAddress(unsigned char address);
	unsigned char GetAddress(void);

	//设置,获取包数内容数据长度
	void SetDataLength(unsigned short len);
	unsigned short GetDataLength(void);

	//配置,获取包内容裸数据
	bool SetData(unsigned char* data, int len);
	unsigned char* GetData(void);

	//配置,获取,计算包校验字
	void SetCheckSum(unsigned char cs);
	unsigned char GetCheckSum(void);
	unsigned char CalcCheckSum(void);

	//配置,获取结束字
	void SetEtx(unsigned char etx);
	unsigned char GetEtx(void);

	//获取包总有校长度
	unsigned int GetPacketLength(void);
public:
	//计算包自身的校验字然后与包内容的校验字比较
	bool CheckSelf(void);

	//发送包前调用,重新设置数据长度与校验字
	bool MakePacket(void);
};

#endif//_PACKET_ACCESS_H
