#include "stdafx.h"
#include "Packet.h"


Packet::Packet()
{
	this->length = rand() % MAX_PACKET_LENGTH + MIN_PACKET_LENGTH;
}


Packet::~Packet()
{
}
