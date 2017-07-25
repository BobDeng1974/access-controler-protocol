#include "buffer.h"

Buffer::Buffer(void)
{
	beg = end = 0;
	for(int i = 0; i < sizeof(data); i++)
	{
		data[i] = char(0);
	}
}

int Buffer::Size(void)
{
	sizeof(data);
}
int Buffer::Space(void)
{
	return sizeof(data) - (end - beg);
}
int Buffer::Length(void)
{
	return end - beg;
}
char* Buffer::Data(void)
{
	return &data[beg];	
}
bool Buffer::Push(char *buf, int len)
{
	if( 0 == buf || len < 1 )
	{
		return false;
	}
	if( (len + end) > sizeof(data) )
	{
		return false;
	}
	for(int i = 0; i < len; i++)
	{
		data[end++] = buf[i];
	}
}

void Pop(int len)
{
	if( len < 1 )
	{
		return;
	}
	if( len >= (end-beg) )
	{
		beg = end = 0;
	}
	beg += len;
	ManageBuffer();
}
bool Buffer::Pop(char *buf, int &len)
{
	if( 0 == buf || len < 1 )
	{
		return false;
	}
	if( (end - beg) < 1  )
	{
		return false;
	}
	if( (end - beg) < len )
	{
		len = end - beg;
	}
	for(int i = 0; i < len; i++)
	{
		buf[i] = data[beg++];
	}
	ManageBuffer();
	return true;
}
void Buffer::ManageBuffer(void)
{
	int len = end - beg;

	if( 0 == beg )
	{
		return;
	}
	if( len < beg )
	{
		MoveData();
	}
	if( Space() < Length() )
	{
		MoveData();
	}
}
void Buffer::MoveData(void)
{
	int len = end - beg;

	for(int i = 0; i < len; i++)
	{
		data[i] = data[beg++];
	}
	beg -= beg;
	end -= len;
}
