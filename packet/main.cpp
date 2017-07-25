#include <stdio.h>
#include "packet-include.h"

#define TestCommand(x) \
do{\
	Command##x cmd##x;\
	printf("%s.GetDataLength=%d\n", #x, cmd##x.GetDataLength());\
}while(0)

int main(int argc, char **argv)
{
/*
	Commandx04 cmdx04;
	Commandx07 cmdx07;
	Commandx18 cmdx18;
	Commandx19 cmdx19;
	Commandx2C cmdx2C;
	Commandx2D cmdx2D;
	Commandx2E cmdx2E;
	Commandx2F cmdx2F;
	Commandx53 cmdx53;
	Commandx56 cmdx56;
	Commandx5A cmdx5A;
	Commandx63 cmdx63;
	Commandx73 cmdx73;
	Commandx80 cmdx80;
	Commandx81 cmdx81;
	Commandx82 cmdx82;
	Commandx83 cmdx83;
	Commandx84 cmdx84;
	CommandxB1 cmdxB1;
*/
	TestCommand( x04 );
	TestCommand( x07 );
	TestCommand( x18 );
	TestCommand( x19 );
	TestCommand( x2C );
	TestCommand( x2D );
	TestCommand( x2E );
	TestCommand( x2F );
	TestCommand( x53 );
	TestCommand( x56 );
	TestCommand( x5A );
	TestCommand( x63 );
	TestCommand( x73 );
	TestCommand( x80 );
	TestCommand( x81 );
	TestCommand( x82 );
	TestCommand( x83 );
	TestCommand( x84 );
	TestCommand( xB1 );

	getchar();
	
	return 0;
}
