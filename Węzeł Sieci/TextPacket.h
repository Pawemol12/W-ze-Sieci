#pragma once
#include "Packet.h"
class TextPacket : public Packet
{
private:
	char * charArray;
public:
	TextPacket() : Packet() {
		this->charArray = new char[this->length];
		this->generate();
	};
	virtual void generate();
	~TextPacket();
};

