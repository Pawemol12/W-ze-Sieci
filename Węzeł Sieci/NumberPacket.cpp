#include "stdafx.h"
#include "NumberPacket.h"


NumberPacket::~NumberPacket()
{
	delete[] numberArray;
}

void NumberPacket::generate() {
	this->generationTime = 0;
	for (int i = 0; i < this->length; i++) {
		this->numberArray[i] = rand() % 10;
	}
	this->generationTime += MILISECONDS_PER_INT;
};
