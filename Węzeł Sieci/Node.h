#pragma once
#include "PacketStats.h"
#include "NumberPacket.h"
#include "TextPacket.h"
#include "MixedPacket.h"

class Node
{
private:
	PacketsStats packetsStats;
	vector<shared_ptr<Packet>> generatedPackets;
	
	void increaseStatsForChars(char character);
	void increaseStatsForNumbers(int number);

	void generateStatsForPacket(Packet *packet);
	void generateStatsForNumericPacket(NumberPacket *numberPacket);
	void generateStatsForTextPacket(TextPacket *textPacket);
	void generateStatsForMixedPacket(MixedPacket *mixedPacket);
public:
	Node();
	Node(vector<shared_ptr<Packet>> generatedPackets);
	void setGeneratedPackets(vector<shared_ptr<Packet>> generatedPackets);
	void generateStatsForPackets();

	PacketsStats getPacketsStats() { return packetsStats; };
	~Node();
};

