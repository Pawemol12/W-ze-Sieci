#include "stdafx.h"
#include "NumberPacket.h"
#include "RandomNumbersGenerator.h"

NumberPacket::~NumberPacket()
{
	delete[] numberArray;
}

void NumberPacket::generate() {
	for (int i = 0; i < this->length; i++) {
		this->numberArray[i] = RandomNumbersGenerator::generateRandomInt(0, 9);
	}
};
