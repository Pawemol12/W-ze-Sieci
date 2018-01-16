#include "stdafx.h"
#include "TextPacket.h"

#define CHARACTERS_NUM_TEXT 26

void TextPacket::generate() {
	const char avaliableChars[CHARACTERS_NUM_TEXT] = {
		'a','b','c','d','e','f','g','h','i','j',
		'k','l','m','n','o','p','q','r','s','t',
		'u','v','w','x','y','z',
	};
	this->generationTime = 0;
	for (int i = 0; i < this->length; i++) {
		int index = rand() % (CHARACTERS_NUM_TEXT - 1);
		this->charArray[i] = avaliableChars[index];
		this->generationTime += MILISECONDS_PER_CHAR;
	}
}


TextPacket::~TextPacket()
{
	delete[] charArray;
}
