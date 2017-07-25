#ifndef __DATA_DEFINE_H__
#define __DATA_DEFINE_H__

/* SerialNumber */
class SerialNumber
{
public:
	unsigned char data[6];

public:
	SerialNumber(void);

public:
	unsigned char* Data(void);
	unsigned long Length(void);
};

/* SerialNumber */
class LableNumber 
{
public:
	unsigned char data[6];

public:
	LableNumber(void);

public:
	unsigned char* Data(void);
	unsigned long Length(void);
};


/* Time */
class TimeSMHdmy
{
public:
	unsigned char data[6];

public:
	TimeSMHdmy(void);

public:
	unsigned char* Data(void);
	unsigned long Length(void);
};

/* Lable String */
class LableString
{
public:
	unsigned char data[10];

public:
	LableString(void);

public:
	unsigned char* Data(void);
	unsigned long Length(void);
};

/* System Time */
class SystemTime 
{
public:
	unsigned char data[16];

public:
	SystemTime(void);

public:
	unsigned char* Data(void);
	unsigned long Length(void);
};


/* Card Data */
class CardData
{
public:
	unsigned char data[56];

public:
	CardData(void);

public:
	unsigned char* Data(void);
	unsigned long Length(void);
};

/* Card Number String To Be Show */
class CardNumString
{
public:
	unsigned char data[18];
public:
	CardNumString(void);
public:
	unsigned char* Data(void);
	unsigned long Length(void);
};

/* Voice String To Be Anounce */
class VoiceString
{
public:
	unsigned char data[40];
public:
	VoiceString(void);
public:
	unsigned char* Data(void);
	unsigned long Length(void);
};

/* Name String To Be Show */
class NameString
{
public:
	unsigned char data[16];
public:
	NameString(void);
public:
	unsigned char* Data(void);
	unsigned long Length(void);
};

/* Event String To Be Show */
class EventString
{
public:
	unsigned char data[32];
public:
	EventString(void);
public:
	unsigned char* Data(void);
	unsigned long Length(void);
};

/* Time String To Be Show */
class TimeString
{
public:
	unsigned char data[20];
public:
	TimeString(void);
public:
	unsigned char* Data(void);
	unsigned long Length(void);
};

/* DataBuffer To Be Show @Command=0x83 */
class DataBuffer 
{
public:
	unsigned char data[48];
public:
	DataBuffer(void);
public:
	unsigned char* Data(void);
	unsigned long Length(void);
};





#endif//__DATA_DEFINE_H__
