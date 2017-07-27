#ifndef __READER_THREAD_H__
#define __READER_THREAD_H__
#include <pthread.h>

class ReaderThread
{
private:
	bool run;
	pthread_t tid;
	int (*reader)(char*,int);
	int (*poster)(char*,int);

public:
	ReaderThread(void);
	~ReaderThread(void);

public:
	void SetReader( int(*f)(char*,int) );
	void SetPoster( int(*f)(char*,int) );

private:
	static void* ThreadEntry(void *p);
};
#endif//__READER_THREAD_H__
