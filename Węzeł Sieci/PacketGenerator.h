#pragma once
#include "Packet.h"

using namespace std;

enum Packets {
	PACKET_TYPES_MIN,
	PACKET_TYPE_NUMERIC,
	PACKET_TYPE_TEXT,
	PACKET_TYPE_MIXED,
	PACKETS_TYPE_MAX,
};

class PacketGenerator
{
private:
	int packetsToGenerateCount;
	bool canGeneratePackets;
	int timeBetweenPacketGeneration;
	int simulationTotalTime;
	vector<shared_ptr<Packet>> packets;

	void countPacketsToGenerate();

public:
	PacketGenerator(int timeBetweenPacketGeneration, int simulationTotalTime);
	bool isValid() { return this->canGeneratePackets; };

	int getGeneratedPacketCount() { return packets.size(); };
	int getPacketsToGenerateCount() { return packetsToGenerateCount; };

	void generatePacket(int packetType);
	void generateRandomPacket();
	void generateRandomPackets();

	vector<shared_ptr<Packet>> getPackets() {
		return this->packets;
	};
	~PacketGenerator();
};

