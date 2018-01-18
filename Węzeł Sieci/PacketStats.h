#pragma once
#include "stdafx.h"
using namespace std;
struct PacketStatsForSign {
	int count;
	int generateTime;
	PacketStatsForSign(int count = 0, int generateTime = 0) : count(count), generateTime(generateTime) {

	};
};

struct PacketInfo {
	int generatedTime;
	string stringRepresentation;

	PacketInfo(int generatedTime = 0) : generatedTime(generatedTime) {

	};

};

struct PacketsStats {
	int totalPacketsGeneratedTime;
	int numericPacketsGeneratedTime;
	int textPacketsGeneratedTime;
	int mixedPacketsGeneratedTime;
	int packetsCount;

	vector<PacketInfo> numericPacketsInfo;
	vector<PacketInfo> textPacketsInfo;
	vector<PacketInfo> mixedPacketsInfo;

	map<char, PacketStatsForSign> statsForChars;
	map<int, PacketStatsForSign> statsForIntegers;

	PacketsStats() : totalPacketsGeneratedTime(0), numericPacketsGeneratedTime(0), textPacketsGeneratedTime(0), mixedPacketsGeneratedTime(0), packetsCount(0) {
	
	};

};