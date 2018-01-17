#include "stdafx.h"
#include "Packet.h"
#include "RandomNumbersGenerator.h"

Packet::Packet()
{
	this->length = RandomNumbersGenerator::generateRandomInt(MIN_PACKET_LENGTH, MAX_PACKET_LENGTH);
}


Packet::~Packet()
{
}
