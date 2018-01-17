#pragma once
#include "Packet.h"
class MixedPacket : public Packet
{
private:
	char * mixedArray;
public:
	MixedPacket() : Packet() {
		this->mixedArray = new char[this->length + 1];
		this->generate();
	};
	virtual void generate();
	char * getMixedArray() { return mixedArray; };
	~MixedPacket();
};

