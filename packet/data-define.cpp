#include "data-define.h"

/* SerialNumber */
SerialNumber::SerialNumber(void)
{
	for(int i = 0; i < sizeof(data); i++)
	{
		data[i] = (unsigned char)0;
	}
}
unsigned char* SerialNumber::Data(void)
{
	return data;
}
unsigned long SerialNumber::Length(void)
{
	return sizeof(data);
}

/* LableNumber */
LableNumber::LableNumber(void)
{
	for(int i = 0; i < sizeof(data); i++)
	{
		data[i] = (unsigned char)0;
	}
}
unsigned char* LableNumber::Data(void)
{
	return data;
}
unsigned long LableNumber::Length(void)
{
	return sizeof(data);
}


/* TimeSMHdmy */
TimeSMHdmy::TimeSMHdmy(void)
{
	for(int i = 0; i < sizeof(data); i++)
	{
		data[i] = (unsigned char)0;
	}
}
unsigned char* TimeSMHdmy::Data(void)
{
	return data;
}
unsigned long TimeSMHdmy::Length(void)
{
	return sizeof(data);
}

/* Lable String*/
LableString::LableString(void)
{
	for(int i = 0; i < sizeof(data); i++)
	{
		data[i] = (unsigned char)0;
	}
}
unsigned char* LableString::Data(void)
{
	return data;
}
unsigned long LableString::Length(void)
{
	return sizeof(data);
}

/* System Time */
SystemTime::SystemTime(void)
{
	for(int i = 0; i < sizeof(data); i++)
	{
		data[i] = (unsigned char)0;
	}
}
unsigned char* SystemTime::Data(void)
{
	return data;
}
unsigned long SystemTime::Length(void)
{
	return sizeof(data);
}

/* Card Data */
CardData::CardData(void)
{
	for(int i = 0; i < sizeof(data); i++)
	{
		data[i] = (unsigned char)0;
	}
}
unsigned char* CardData::Data(void)
{
	return data;
}
unsigned long CardData::Length(void)
{
	return sizeof(data);
}

/* Card Number String To Be Show */
CardNumString::CardNumString(void)
{
	for(int i = 0; i < sizeof(data); i++)
	{
		data[i] = (unsigned char)0;
	}
}
unsigned char* CardNumString::Data(void)
{
	return data;
}
unsigned long CardNumString::Length(void)
{
	return sizeof(data);
}

/* Voice String To Be Anounce */
VoiceString::VoiceString(void)
{
	for(int i = 0; i < sizeof(data); i++)
	{
		data[i] = (unsigned char)0;
	}
}
unsigned char* VoiceString::Data(void)
{
	return data;
}
unsigned long VoiceString::Length(void)
{
	return sizeof(data);
}

/* Name String To Be Show */
NameString::NameString(void)
{
	for(int i = 0; i < sizeof(data); i++)
	{
		data[i] = (unsigned char)0;
	}
}
unsigned char* NameString::Data(void)
{
	return data;
}
unsigned long NameString::Length(void)
{
	return sizeof(data);
}

/* Event String To Be Show */
EventString::EventString(void)
{
	for(int i = 0; i < sizeof(data); i++)
	{
		data[i] = (unsigned char)0;
	}
}
unsigned char* EventString::Data(void)
{
	return data;
}
unsigned long EventString::Length(void)
{
	return sizeof(data);
}

/* Time String To Be Show */
TimeString::TimeString(void)
{
	for(int i = 0; i < sizeof(data); i++)
	{
		data[i] = (unsigned char)0;
	}
}
unsigned char* TimeString::Data(void)
{
	return data;
}
unsigned long TimeString::Length(void)
{
	return sizeof(data);
}

/* DataBuffer To Be Show */
DataBuffer::DataBuffer(void)
{
	for(int i = 0; i < sizeof(data); i++)
	{
		data[i] = (unsigned char)0;
	}
}
unsigned char* DataBuffer::Data(void)
{
	return data;
}
unsigned long DataBuffer::Length(void)
{
	return sizeof(data);
}

