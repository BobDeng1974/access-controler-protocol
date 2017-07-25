#include "packet-commandx73.h"


/* Commandx73 */
Commandx73::Commandx73(void)
{
	SetStx( Packet_Stx );
	SetCommand(Command_x73);
	SetDataLength(Command_x73_Length);
	SetEtx( Packet_Etx );
}
void Commandx73::SetOpenDoor(unsigned char open)
{
	packet.data[ Idx_Open_Door ] = open;
}
void Commandx73::SetRelayNumber(unsigned char number)
{
	packet.data[ Idx_Relay_Number ] = number;
}
void Commandx73::SetRelayKeep(unsigned short second)
{
	packet.data[ Idx_Relay_Keep+0 ] = 0xff & (second >> 8);
	packet.data[ Idx_Relay_Keep+1 ] = 0xff & (second >> 0);
}
void Commandx73::SetReaderNumber(unsigned char number)
{
	packet.data[ Idx_Reader_Number ] = number;
}
void Commandx73::SetShowKeep(unsigned char second)
{
	packet.data[ Idx_Show_Keep ] = second;
}
void Commandx73::SetCardNumType(unsigned char type)
{
	packet.data[ Idx_Open_Door ] = type;
}
void Commandx73::SetCardNumString( CardNumString& cs )
{
	int len = cs.Length();
	unsigned char *s = cs.Data();
	unsigned char *p = &packet.data[ Idx_CardNum_String ];

	for(int i = 0; i < len; i++)
	{
		p[i] = s[i];
	}
}
void Commandx73::SetVoiceString( VoiceString& vs )
{
	int len = vs.Length();
	unsigned char *s = vs.Data();
	unsigned char *p = &packet.data[ Idx_Voice_String ];

	for(int i = 0; i < len; i++)
	{
		p[i] = s[i];
	}
}
void Commandx73::SetNameString( NameString& ns )
{
	int len = ns.Length();
	unsigned char *s = ns.Data();
	unsigned char *p = &packet.data[ Idx_Name_String ];

	for(int i = 0; i < len; i++)
	{
		p[i] = s[i];
	}
}
void Commandx73::SetEventString( EventString& ev )
{
	int len = ev.Length();
	unsigned char *s = ev.Data();
	unsigned char *p = &packet.data[ Idx_Event_String ];

	for(int i = 0; i < len; i++)
	{
		p[i] = s[i];
	}
}
void Commandx73::SetTimeString( TimeString& ts )
{
	int len = ts.Length();
	unsigned char *s = ts.Data();
	unsigned char *p = &packet.data[ Idx_Time_String ];

	for(int i = 0; i < len; i++)
	{
		p[i] = s[i];
	}
}


/* Commandx73 Ack */
unsigned char Responsex73::GetAck(void)
{
	return packet.data[ Idx_Ack ];
}
