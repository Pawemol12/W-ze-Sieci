#include "stdafx.h"
#include "RandomNumbersGenerator.h"


RandomNumbersGenerator::RandomNumbersGenerator()
{
}

int RandomNumbersGenerator::generateRandomInt(int min, int max)
{
	return rand() % (max - min + 1) + min;
}

void RandomNumbersGenerator::setRandom() {
	srand(time(NULL));
}

RandomNumbersGenerator::~RandomNumbersGenerator()
{
}
