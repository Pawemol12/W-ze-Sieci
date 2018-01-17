#include "stdafx.h"
#include "TextPacket.h"
#include "RandomNumbersGenerator.h"
#define CHARACTERS_NUM_TEXT 26

void TextPacket::generate() {
	const char avaliableChars[CHARACTERS_NUM_TEXT] = {
		'a','b','c','d','e','f','g','h','i','j',
		'k','l','m','n','o','p','q','r','s','t',
		'u','v','w','x','y','z',
	};

	for (int i = 0; i < this->length; i++) {
		int index = RandomNumbersGenerator::generateRandomInt(0, CHARACTERS_NUM_TEXT - 1);
		this->charArray[i] = avaliableChars[index];
	}
	this->charArray[this->length] = '\0';
}


TextPacket::~TextPacket()
{
	delete[] charArray;
}
