#include "packet-commandx53.h"


Commandx53::Commandx53(void)
{
	SetStx( Packet_Stx );
	SetCommand(Command_x53);
	SetDataLength(Command_x53_Length);
	SetEtx( Packet_Etx );
}
void Commandx53::GetSerialNumber( SerialNumber& sn )
{
	int len = sn.Length();
	unsigned char *p = sn.Data();
	unsigned char *s = &packet.data[ Idx_Serial_Number ];

	for(int i = 0; i < len; i++)
	{
		p[i] = s[i];
	}
}
void Commandx53::GetLableString( LableString & ls )
{
	int len = ls.Length();
	unsigned char *p = ls.Data();
	unsigned char *s = &packet.data[ Idx_Lable_String ];

	for(int i = 0; i < len; i++)
	{
		p[i] = s[i];
	}
}
char Commandx53::GetReaderNumber( void )
{
	return packet.data[ Idx_Reader_Number ];
}
char Commandx53::GetDataType( void )
{
	return packet.data[ Idx_Data_Type ];
}
void Commandx53::GetSystemTime( SystemTime& st )
{
	int len = st.Length();
	unsigned char *p = st.Data();
	unsigned char *s = &packet.data[ Idx_System_Time ];

	for(int i = 0; i < len; i++)
	{
		p[i] = s[i];
	}
}
int  Commandx53::GetCardId(void)
{
	unsigned int id = 0;

	id += packet.data[ Idx_Card_Id+0 ] << 24;
	id += packet.data[ Idx_Card_Id+1 ] << 16;
	id += packet.data[ Idx_Card_Id+2 ] <<  8;
	id += packet.data[ Idx_Card_Id+3 ] <<  0;

	return 0xffffffff & id;
}
void Commandx53::GetCardData( CardData& cd)
{
	int len = cd.Length();
	unsigned char *p = cd.Data();
	unsigned char *s = &packet.data[ Idx_Card_Data ];

	for(int i = 0; i < len; i++)
	{
		p[i] = s[i];
	}
}


/* Responsex53 */
void Responsex53::SetOpenDoor(unsigned char open)
{
	packet.data[ Idx_Open_Door ] = open;
}
void Responsex53::SetRelayNumber(unsigned char number)
{
	packet.data[ Idx_Relay_Number ] = number;
}
void Responsex53::SetRelayKeep(unsigned short second)
{
	packet.data[ Idx_Relay_Keep+0 ] = 0xff & (second >> 8);
	packet.data[ Idx_Relay_Keep+1 ] = 0xff & (second >> 0);
}
void Responsex53::SetReaderNumber(unsigned char number)
{
	packet.data[ Idx_Reader_Number ] = number;
}
void Responsex53::SetShowKeep(unsigned char second)
{
	packet.data[ Idx_Show_Keep ] = second;
}
void Responsex53::SetCardNumType(unsigned char type)
{
	packet.data[ Idx_Open_Door ] = type;
}
void Responsex53::SetCardNumString( CardNumString& cs )
{
	int len = cs.Length();
	unsigned char *s = cs.Data();
	unsigned char *p = &packet.data[ Idx_CardNum_String ];

	for(int i = 0; i < len; i++)
	{
		p[i] = s[i];
	}
}
void Responsex53::SetVoiceString( VoiceString& vs )
{
	int len = vs.Length();
	unsigned char *s = vs.Data();
	unsigned char *p = &packet.data[ Idx_Voice_String ];

	for(int i = 0; i < len; i++)
	{
		p[i] = s[i];
	}
}
void Responsex53::SetNameString( NameString& ns )
{
	int len = ns.Length();
	unsigned char *s = ns.Data();
	unsigned char *p = &packet.data[ Idx_Name_String ];

	for(int i = 0; i < len; i++)
	{
		p[i] = s[i];
	}
}
void Responsex53::SetEventString( EventString& ev )
{
	int len = ev.Length();
	unsigned char *s = ev.Data();
	unsigned char *p = &packet.data[ Idx_Event_String ];

	for(int i = 0; i < len; i++)
	{
		p[i] = s[i];
	}
}
void Responsex53::SetTimeString( TimeString& ts )
{
	int len = ts.Length();
	unsigned char *s = ts.Data();
	unsigned char *p = &packet.data[ Idx_Time_String ];

	for(int i = 0; i < len; i++)
	{
		p[i] = s[i];
	}
}


/* Responsex53 Ack */
unsigned char Responsex53Ack::GetAck(void)
{
	return packet.data[ Idx_Ack ];
}
