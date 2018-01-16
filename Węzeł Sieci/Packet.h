#pragma once
#define MIN_PACKET_LENGTH 10
#define MAX_PACKET_LENGTH 255

#define MILISECONDS_PER_CHAR 2;
#define MILISECONDS_PER_INT 1;


class Packet
{
protected:
	int length;
	int generationTime;

public:
	Packet();
	virtual void generate() = 0;
	~Packet();
};

