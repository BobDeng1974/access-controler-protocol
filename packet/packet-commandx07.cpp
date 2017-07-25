#include "packet-commandx07.h"

Commandx07::Commandx07(void)
{
	SetStx( Packet_Stx );
	SetCommand(Command_x07);
	SetDataLength(Command_x07_Length);
	SetEtx( Packet_Etx );
}
void Commandx07::SetSecond(unsigned char second)
{
	packet.data[ Idx_Second ] = second;
}
void Commandx07::SetMinute(unsigned char minute)
{
	packet.data[ Idx_Minute ] = minute;
}
void Commandx07::SetHour(unsigned char hour)
{
	packet.data[ Idx_Hour ] = hour;
}
void Commandx07::SetWeekday(unsigned char wday)
{
	packet.data[ Idx_Weekday ] = wday;
}
void Commandx07::SetDay(unsigned char day)
{
	packet.data[ Idx_Day ] = day;
}
void Commandx07::SetMonth(unsigned char month)
{
	packet.data[ Idx_Month ] = month;
}
void Commandx07::SetYear(unsigned char year)
{
	packet.data[ Idx_Year ] = year;
}

/* Responsex07 */
unsigned char Responsex07::GetAck(void)
{
	return packet.data[ Idx_Ack ];
}
