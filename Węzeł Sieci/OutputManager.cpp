#include "stdafx.h"
#include "PacketStats.h"
#include "OutputManager.h"
using namespace std;
OutputManager::OutputManager()
{
}

bool OutputManager::createStatsFile(PacketsStats stats, string fileName)
{
	ofstream outputFile(fileName);
	if (!outputFile.is_open()) {
		return false;
	}

	outputFile << "Statystyki wygenerowanych pakietów:" << endl;
	outputFile << "Liczba przetworzonych pakietów: " << stats.packetsCount << endl;
	outputFile << "Liczba przetworzonych pakietów liczbowych: " << stats.numericPacketsGenerateTime.size() << endl;
	outputFile << "Liczba przetworzonych pakietów tekstowych: " << stats.textPacketsGenerateTime.size() << endl;
	outputFile << "Liczba przetworzonych pakietów mieszanych: " << stats.mixedPacketsGenerateTime.size() << endl;
	outputFile << endl;
	outputFile << "Ca³kowity czas przetwarzania pakietów: " << stats.totalPacketsGeneratedTime << "ms" << endl;
	outputFile << "Ca³kowity czas przetwarzania pakietów liczbowych: " << stats.numericPacketsGeneratedTime << "ms" << endl;
	outputFile << "Ca³kowity czas przetwarzania pakietów tekstowych: " << stats.textPacketsGeneratedTime << "ms" << endl;
	outputFile << "Ca³kowity czas przetwarzania pakietów mieszanych: " << stats.mixedPacketsGeneratedTime << "ms" << endl;
	outputFile << endl;

	outputFile << "Wygenerowane pakiety liczbowe: " << endl;
	outputFile << "Nr\tIloœæ znaków\tCzas przetwarzania\tTekstowa Reprezentacja" << endl;
	for (int i = 0; i < stats.numericPacketsGenerateTime.size(); i++) {
		outputFile << i + 1 << "\t" << stats.numericPacketsStringRepresentation[i].length() << "\t" << stats.numericPacketsGenerateTime[i] << "ms\t" << stats.numericPacketsStringRepresentation[i] << endl;
	}
	outputFile << endl;

	outputFile << "Wygenerowane pakiety tekstowe: " << endl;
	outputFile << "Nr\tIloœæ znaków\tCzas przetwarzania\tTekstowa Reprezentacja" << endl;
	for (int i = 0; i < stats.textPacketsGenerateTime.size(); i++) {
		outputFile << i + 1 << "\t" << stats.textPacketsStringRepresentation[i].length() << "\t" << stats.textPacketsGenerateTime[i] << "ms\t" << stats.textPacketsStringRepresentation[i] << endl;
	}
	outputFile << endl;

	outputFile << "Wygenerowane pakiety mieszane: " << endl;
	outputFile << "Nr\tIloœæ znaków\tCzas przetwarzania\tTekstowa Reprezentacja" << endl;
	for (int i = 0; i < stats.mixedPacketsGenerateTime.size(); i++) {
		outputFile << i + 1 << "\t" << stats.mixedPacketsStringRepresentation[i].length() << "\t" << stats.mixedPacketsGenerateTime[i] << "ms\t" << stats.mixedPacketsStringRepresentation[i] << endl;
	}
	outputFile << endl;

	outputFile << "Statystyki dla znaków" << endl;
	outputFile << "Znak\tIlosc\tCzas Przetwarzania" << endl;

	for (auto &i : stats.statsForChars) {
		outputFile << i.first << "\t" << i.second.count << "\t" << i.second.generateTime << "ms" << endl;
	}

	outputFile << endl;

	outputFile << "Statystyki dla cyfr" << endl;
	outputFile << "Cyfra\tIlosc\tCzas Przetwarzania" << endl;

	for (auto &i : stats.statsForIntegers) {
		outputFile << i.first << "\t" << i.second.count << "\t" << i.second.generateTime << "ms" << endl;
	}

	outputFile << endl;

	outputFile.close();
	return true;
}

OutputManager::~OutputManager()
{
}
