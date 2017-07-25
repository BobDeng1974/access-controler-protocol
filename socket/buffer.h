#ifndef __BUFFER_H__
#define __BUFFER_H__

class Buffer
{
public:
	int beg;
	int end;
	char data[4096];

public:
	Buffer(void);

public:
	int Size(void);
	int Space(void);
	int Length(void);
	char* Data(void);
	bool Push(char *data, int len);
	bool Pop(char *buf, int len);
	void Pop(int len);

private:
	void ModeData(void);
	void ManageBuffer(void);
};

#endif//__BUFFER_H__
