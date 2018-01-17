#pragma once
#include "stdafx.h"
using namespace std;
struct PacketStats {
	int count;
	int generateTime;
	PacketStats(int count = 0, int generateTime = 0) : count(count), generateTime(generateTime) {

	};
};

struct PacketsStats {
	int totalPacketsGeneratedTime;
	int numericPacketsGeneratedTime;
	int textPacketsGeneratedTime;
	int mixedPacketsGeneratedTime;
	int packetsCount;

	vector<int> numericPacketsGenerateTime;
	vector<string> numericPacketsStringRepresentation;

	vector<int> textPacketsGenerateTime;
	vector<string> textPacketsStringRepresentation;

	vector<int> mixedPacketsGenerateTime;
	vector<string> mixedPacketsStringRepresentation;

	map<char, PacketStats> statsForChars;
	map<int, PacketStats> statsForIntegers;

	PacketsStats() : totalPacketsGeneratedTime(0), numericPacketsGeneratedTime(0), textPacketsGeneratedTime(0), mixedPacketsGeneratedTime(0), packetsCount(0) {
	
	};

};