#include "stdafx.h"
#include "Packet.h"
#include "NumberPacket.h"
#include "TextPacket.h"
#include "MixedPacket.h"
#include "Node.h"
#include "PacketStats.h"

#define MILISECONDS_PER_CHAR 2
#define MILISECONDS_PER_INT 1

using namespace std;

Node::Node()
{
}

Node::Node(vector<shared_ptr<Packet>> generatedPackets)
{
	setGeneratedPackets(generatedPackets);
	
}

void Node::setGeneratedPackets(vector<shared_ptr<Packet>> generatedPackets)
{
	this->generatedPackets = generatedPackets;
}

void Node::increaseStatsForNumbers(int number) 
{
	auto iter = this->packetsStats.statsForIntegers.find(number);
	if (iter == this->packetsStats.statsForIntegers.end()) {
		this->packetsStats.statsForIntegers[number] = PacketStatsForSign(1, MILISECONDS_PER_INT);
	}
	else {
		this->packetsStats.statsForIntegers[number].count++;
		this->packetsStats.statsForIntegers[number].generateTime += MILISECONDS_PER_INT;
	}
}

void Node::increaseStatsForChars(char character)
{

	auto iter = this->packetsStats.statsForChars.find(character);
	if (iter == this->packetsStats.statsForChars.end()) {
		this->packetsStats.statsForChars[character] = PacketStatsForSign(1, MILISECONDS_PER_CHAR);
	}
	else {
		this->packetsStats.statsForChars[character].count++;
		this->packetsStats.statsForChars[character].generateTime += MILISECONDS_PER_CHAR;
	}
}

void Node::generateStatsForNumericPacket(NumberPacket *numberPacket)
{
	int * numbersArray = numberPacket->getNumberArray();
	int packetLength = numberPacket->getLength();
	int generatedTime = packetLength * MILISECONDS_PER_INT;
	this->packetsStats.numericPacketsGeneratedTime += generatedTime;
	this->packetsStats.totalPacketsGeneratedTime += generatedTime;


	string stringRepresentation;
	for (int i = 0; i < packetLength; i++)
	{
		int number = numbersArray[i];
		stringRepresentation += to_string(number);
		
		increaseStatsForNumbers(number);
	}
	PacketInfo packetInfo;
	packetInfo.generatedTime = generatedTime;
	packetInfo.stringRepresentation = stringRepresentation;
	this->packetsStats.numericPacketsInfo.push_back(packetInfo);
}

void Node::generateStatsForTextPacket(TextPacket *textPacket)
{
	char * charArray = textPacket->getCharArray();
	int packetLength = textPacket->getLength();
	int generatedTime = packetLength * MILISECONDS_PER_CHAR;

	this->packetsStats.textPacketsGeneratedTime += generatedTime;
	this->packetsStats.totalPacketsGeneratedTime += generatedTime;


	string stringRepresentation(charArray);


	for (int i = 0; i < packetLength; i++)
	{
		char character = charArray[i];
		increaseStatsForChars(character);
	}

	PacketInfo packetInfo;
	packetInfo.generatedTime = generatedTime;
	packetInfo.stringRepresentation = stringRepresentation;
	this->packetsStats.textPacketsInfo.push_back(packetInfo);
}

void Node::generateStatsForMixedPacket(MixedPacket *mixedPacket)
{
	char * mixedArray = mixedPacket->getMixedArray();
	int packetLength = mixedPacket->getLength();
	int generatedTime = 0;
	for (int i = 0; i < packetLength; i++)
	{
		char character = mixedArray[i];
		if (isdigit(character)) {
			this->packetsStats.totalPacketsGeneratedTime += MILISECONDS_PER_INT;
			this->packetsStats.mixedPacketsGeneratedTime += MILISECONDS_PER_INT;
			generatedTime += MILISECONDS_PER_INT;
			int number = character - '0';
			increaseStatsForNumbers(number);
		}
		else {
			this->packetsStats.totalPacketsGeneratedTime += MILISECONDS_PER_CHAR;
			this->packetsStats.mixedPacketsGeneratedTime += MILISECONDS_PER_CHAR;
			generatedTime += MILISECONDS_PER_CHAR;
			increaseStatsForChars(character);
		}
	}

	string stringRepresentation(mixedArray);
	PacketInfo packetInfo;
	packetInfo.generatedTime = generatedTime;
	packetInfo.stringRepresentation = stringRepresentation;
	this->packetsStats.mixedPacketsInfo.push_back(packetInfo);
}

void Node::generateStatsForPacket(Packet *packet)
{
	NumberPacket *numberPacket = dynamic_cast<NumberPacket*>(packet);
	TextPacket *textPacket = dynamic_cast<TextPacket*>(packet);
	MixedPacket *mixedPacket = dynamic_cast<MixedPacket*>(packet);
	if (numberPacket)
	{
		generateStatsForNumericPacket(numberPacket);
	}
	else if (textPacket)
	{
		generateStatsForTextPacket(textPacket);
	}
	else if (mixedPacket) {
		generateStatsForMixedPacket(mixedPacket);
	}

	this->packetsStats.packetsCount++;
}

void Node::generateStatsForPackets()
{
	for (auto &packet : generatedPackets) {
		generateStatsForPacket(packet.get());
	}
}

Node::~Node()
{
}
