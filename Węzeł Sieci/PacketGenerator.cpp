#include "stdafx.h"
#include "NumberPacket.h"
#include "Packet.h"
#include "TextPacket.h"
#include "MixedPacket.h"
#include "PacketGenerator.h"
#include "RandomNumbersGenerator.h"

PacketGenerator::PacketGenerator(int timeBetweenPacketGeneration, int simulationTotalTime)
{
	this->timeBetweenPacketGeneration = timeBetweenPacketGeneration;
	this->simulationTotalTime = simulationTotalTime;
	this->countPacketsToGenerate();
}

void PacketGenerator::countPacketsToGenerate()
{
	if (timeBetweenPacketGeneration <= 0 || simulationTotalTime <= 0 || simulationTotalTime < timeBetweenPacketGeneration) {
		this->canGeneratePackets = false;
		return;
	}
	this->canGeneratePackets = true;
	this->packetsToGenerateCount = simulationTotalTime / timeBetweenPacketGeneration;
}

void PacketGenerator::generateRandomPacket()
{
	int packetType = RandomNumbersGenerator::generateRandomInt(PACKET_TYPES_MIN + 1, PACKETS_TYPE_MAX - 1);
	generatePacket(packetType);
}

void PacketGenerator::generatePacket(int packetType) {

	switch (packetType) {
		case PACKET_TYPE_NUMERIC: {
			shared_ptr<Packet> numericPacket(new NumberPacket);
			packets.push_back(numericPacket);
			break;
		}
		case PACKET_TYPE_TEXT: {
			shared_ptr<Packet> textPacket(new TextPacket);
			packets.push_back(textPacket);
			break;
		}
		case PACKET_TYPE_MIXED: {
			shared_ptr<Packet> mixedPacket(new MixedPacket);
			packets.push_back(mixedPacket);
			break;
		}
	}

}

void PacketGenerator::generateRandomPackets()
{
	for (int i = 0; i < packetsToGenerateCount; i++) {
		generateRandomPacket();
	}
}


PacketGenerator::~PacketGenerator()
{
}
