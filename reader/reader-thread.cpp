#include <unistd.h>
#include "packet-reader.h"
#include "reader-thread.h"

ReaderThread::ReaderThread(void)
{
	run = true;
	reader = 0;
	poster = 0;
	pthread_create(&tid, 0, ThreadEntry, this);
}
ReaderThread::~ReaderThread(void)
{
	run = false;
	reader = 0;
	poster = 0;
	pthread_join(tid, NULL);
}
void ReaderThread::SetReader( int(*f)(char*,int) )
{
	reader = f;
}
void ReaderThread::SetPoster( int(*f)(char*,int) )
{
	poster = f;
}
void* ReaderThread::ThreadEntry(void *p)
{
	int len = 0;
	char buf[1024] = {0};
	ReaderThread *t = (ReaderThread*)p;

	while(t->run)
	{
		if( 0 == t->reader )
		{
			usleep(100);
			continue;
		}
		len = t->reader(buf, sizeof(buf));
		if( len < 1 )
		{
			usleep(100);
		}
		if( t->poster )
		{
			t->poster(buf, len);
		}
	}
}
