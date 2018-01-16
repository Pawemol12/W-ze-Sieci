#pragma once
#include "Packet.h"
class MixedPacket : public Packet
{
private:
	char * mixedArray;
public:
	MixedPacket() : Packet() {
		this->mixedArray = new char[this->length];
		this->generate();
	};
	virtual void generate();
	~MixedPacket();
};

