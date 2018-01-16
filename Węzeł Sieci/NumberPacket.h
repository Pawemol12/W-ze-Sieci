#pragma once
#include "Packet.h"
class NumberPacket : public Packet
{
private: 
	int * numberArray;

public:
	NumberPacket() : Packet()
	{
		this->numberArray = new int[this->length];
		this->generate();
	};
	virtual void generate();
	~NumberPacket();
};

