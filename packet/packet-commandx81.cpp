#include "packet-commandx81.h"

/* Commandx81 */
Commandx81::Commandx81(void)
{
	SetStx( Packet_Stx );
	SetCommand(Command_x81);
	SetDataLength(Command_x81_Length);
	SetEtx( Packet_Etx );
}
void Commandx81::SetDelay(unsigned char delay)
{
	packet.data[ Idx_Delay ] = delay;
}
void Commandx81::SetPage(unsigned char page)
{
	packet.data[ Idx_Page ] = page;
}
void Commandx81::SetCardNumString( CardNumString& cs )
{
	int len = cs.Length();
	unsigned char *s = cs.Data();
	unsigned char *p = &packet.data[ Idx_Card_String ];

	for(int i = 0; i < len; i++)
	{
		p[i] = s[i];
	}
}
void Commandx81::SetNameString( NameString& ns )
{
	int len = ns.Length();
	unsigned char *s = ns.Data();
	unsigned char *p = &packet.data[ Idx_Name_String ];

	for(int i = 0; i < len; i++)
	{
		p[i] = s[i];
	}
}
void Commandx81::SetEventString( EventString& es )
{
	int len = es.Length();
	unsigned char *s = es.Data();
	unsigned char *p = &packet.data[ Idx_Event_String ];

	for(int i = 0; i < len; i++)
	{
		p[i] = s[i];
	}
}
void Commandx81::SetTimeString( TimeString& ts )
{
	int len = ts.Length();
	unsigned char *s = ts.Data();
	unsigned char *p = &packet.data[ Idx_Time_String ];

	for(int i = 0; i < len; i++)
	{
		p[i] = s[i];
	}
}


/* Responsex81 */
unsigned char Responsex81::GetAck(void)
{
	return packet.data[ Idx_Ack ];
}
