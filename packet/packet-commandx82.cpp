#include "packet-commandx82.h"

/* Commandx82 */
Commandx82::Commandx82(void)
{
	SetStx( Packet_Stx );
	SetCommand(Command_x82);
	SetDataLength(Command_x82_Length);
	SetEtx( Packet_Etx );
}
void Commandx82::SetDelay(unsigned char delay)
{
	packet.data[ Idx_Delay ] = delay;
}
void Commandx82::SetPage(unsigned char page)
{
	packet.data[ Idx_Page ] = page;
}
void Commandx82::SetCardNumString( CardNumString& cs )
{
	int len = cs.Length();
	unsigned char *s = cs.Data();
	unsigned char *p = &packet.data[ Idx_CardNum_String ];

	for(int i = 0; i < len; i++)
	{
		p[i] = s[i];
	}
}
void Commandx82::SetNameString( NameString& ns )
{
	int len = ns.Length();
	unsigned char *s = ns.Data();
	unsigned char *p = &packet.data[ Idx_Name_String ];

	for(int i = 0; i < len; i++)
	{
		p[i] = s[i];
	}
}
void Commandx82::SetEventString( EventString& es )
{
	int len = es.Length();
	unsigned char *s = es.Data();
	unsigned char *p = &packet.data[ Idx_Event_String ];

	for(int i = 0; i < len; i++)
	{
		p[i] = s[i];
	}
}
void Commandx82::SetTimeString( TimeString& ts )
{
	int len = ts.Length();
	unsigned char *s = ts.Data();
	unsigned char *p = &packet.data[ Idx_Time_String ];

	for(int i = 0; i < len; i++)
	{
		p[i] = s[i];
	}
}


/* Responsex82 */
unsigned char Responsex82::GetAck(void)
{
	return packet.data[ Idx_Ack ];
}
