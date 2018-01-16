#include "stdafx.h"
#include "MixedPacket.h"


#define CHARACTERS_NUM_MIXED 36

void MixedPacket::generate() {
	const char avaliableChars[CHARACTERS_NUM_MIXED] = {
		'a','b','c','d','e','f','g','h','i','j',
		'k','l','m','n','o','p','q','r','s','t',
		'u','v','w','x','y','z',
		'1', '2', '3', '4', '5', '6', '7', '8', '9'
	};
	this->generationTime = 0;
	for (int i = 0; i < this->length; i++) {
		int index = rand() % (CHARACTERS_NUM_MIXED - 1);
		char randomChar = avaliableChars[index];
		this->mixedArray[i] = randomChar;
		if (isdigit(randomChar))
		{
			generationTime += MILISECONDS_PER_INT;
		}
		else {
			generationTime += MILISECONDS_PER_CHAR;
		}
	}
}


MixedPacket::~MixedPacket()
{
	delete[] mixedArray;
}
