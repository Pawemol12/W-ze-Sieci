#pragma once
#define MIN_PACKET_LENGTH 10
#define MAX_PACKET_LENGTH 255


class Packet
{
protected:
	int length;


public:
	Packet();
	virtual void generate() = 0;
	int getLength() { return length; };
	~Packet();
};

