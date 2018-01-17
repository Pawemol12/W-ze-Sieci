#pragma once
class RandomNumbersGenerator
{
public:
	RandomNumbersGenerator();
	~RandomNumbersGenerator();
	static int generateRandomInt(int min, int max);
	static void setRandom();
};

