#ifndef __COMMAND_DEFINE_H__
#define __COMMAND_DEFINE_H__

typedef enum
{
	Command_x04 = 0x04,	//Reset Controler
	Command_x07 = 0x07,	//Time Sync
	Command_x18 = 0x18,	//Operation Warning
	Command_x19 = 0x19,	//Fire Warning
	Command_x2C = 0x2C,	//Open Door
	Command_x2D = 0x2D,	//Keep Open
	Command_x2E = 0x2E,	//Close Door
	Command_x2F = 0x2F,	//Lock Door
	Command_x53 = 0x53, //Read Card From Device
	Command_x56 = 0x56, //Heart Beat Packet From Device
	Command_x5A = 0x5A,	//Forbit Read Card
	Command_x63 = 0x63,	//Set Parameter
	Command_x73 = 0x73, //Control Device From System
	Command_x80 = 0x80,	//Voice Anounce
	Command_x81 = 0x81,	//LCD Mult Line, Card Number As Int
	Command_x82 = 0x82,	//LCD Mult Line, Card Number As String
	Command_x83 = 0x83,	//LCD Single Line, Card Number As Int    
	Command_x84 = 0x84,	//LCD Single Line, Card Number As String
	Command_xB1 = 0xB1,	//Send Data By 485
}Command_t;

#define Command_x56_Length	(35)
#define Command_x53_Length	(99)
#define Command_x73_Length	(133)
#define Command_x04_Length	(0)
#define Command_x63_Length	(15)
#define Command_x07_Length	(7)
#define Command_x18_Length	(2)
#define Command_x19_Length	(2)
#define Command_x2C_Length	(1)
#define Command_x2D_Length	(1)
#define Command_x2E_Length	(1)
#define Command_x2F_Length	(1)
#define Command_x5A_Length	(5)
#define Command_xB1_Length	(200)
#define Command_x80_Length	(59)
#define Command_x81_Length	(96)
#define Command_x82_Length	(96)
#define Command_x83_Length	(51)
#define Command_x84_Length	(6)

#define Response_x56_Length		(2)
#define Response_x53_Length		(133)
#define Response_x53_Ack_Length	(1)
#define Response_x73_Length		(1)
#define Response_x04_Length		(1)
#define Response_x63_Length		(1)
#define Response_x07_Length		(1)
#define Response_x18_Length		(1)
#define Response_x19_Length		(1)
#define Response_x2C_Length		(1)
#define Response_x2D_Length		(1)
#define Response_x2E_Length		(1)
#define Response_x2F_Length		(1)
#define Response_x5A_Length		(1)
#define Response_xB1_Length		(200)
#define Response_x80_Length		(1)
#define Response_x81_Length		(1)
#define Response_x82_Length		(1)
#define Response_x83_Length		(1)
#define Response_x84_Length		(1)

#define Packet_Stx	0x02
#define Packet_Etx	0x03

#endif//__COMMAND_DEFINE_H__
