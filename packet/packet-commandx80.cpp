#include "packet-commandx80.h"

Commandx80::Commandx80(void)
{
	SetStx( Packet_Stx );
	SetCommand(Command_x80);
	SetDataLength(Command_x80_Length);
	SetEtx( Packet_Etx );
}
void Commandx80::SetVoiceDevice(unsigned char device)
{
	packet.data[ Idx_Voice_Device ] = device;
}
void Commandx80::SetVoiceLength(unsigned char length)
{
	packet.data[ Idx_Voice_Length ] = length;
}
void Commandx80::SetVoiceString( VoiceString& vs )
{
	int len = vs.Length();
	unsigned char *s = vs.Data();
	unsigned char *p = &packet.data[ Idx_Voice_String ];

	for(int i = 0; i < len; i++)
	{
		p[i] = s[i];
	}
}

unsigned char Responsex80::GetAck(void)
{
	return packet.data[ Idx_Ack ];
}
