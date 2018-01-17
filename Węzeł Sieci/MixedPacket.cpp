#include "stdafx.h"
#include "MixedPacket.h"
#include "RandomNumbersGenerator.h"

#define CHARACTERS_NUM_MIXED 35

void MixedPacket::generate() {
	const char avaliableChars[] = {
		'a','b','c','d','e','f','g','h','i','j',
		'k','l','m','n','o','p','q','r','s','t',
		'u','v','w','x','y','z',
		'1', '2', '3', '4', '5', '6', '7', '8', '9'
	};
	
	for (int i = 0; i < this->length; i++) {
		int index = RandomNumbersGenerator::generateRandomInt(0, CHARACTERS_NUM_MIXED - 1);
		char randomChar = avaliableChars[index];
		this->mixedArray[i] = randomChar;
	}

	this->mixedArray[this->length] = '\0';
}


MixedPacket::~MixedPacket()
{
	delete[] mixedArray;
}
