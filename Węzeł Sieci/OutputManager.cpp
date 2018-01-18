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

	outputFile << "Statystyki wygenerowanych pakiet�w:" << endl;
	outputFile << "Liczba przetworzonych pakiet�w: " << stats.packetsCount << endl;
	outputFile << "Liczba przetworzonych pakiet�w liczbowych: " << stats.numericPacketsInfo.size() << endl;
	outputFile << "Liczba przetworzonych pakiet�w tekstowych: " << stats.textPacketsInfo.size() << endl;
	outputFile << "Liczba przetworzonych pakiet�w mieszanych: " << stats.mixedPacketsInfo.size() << endl;
	outputFile << endl;
	outputFile << "Ca�kowity czas przetwarzania pakiet�w: " << stats.totalPacketsGeneratedTime << "ms" << endl;
	outputFile << "Ca�kowity czas przetwarzania pakiet�w liczbowych: " << stats.numericPacketsGeneratedTime << "ms" << endl;
	outputFile << "Ca�kowity czas przetwarzania pakiet�w tekstowych: " << stats.textPacketsGeneratedTime << "ms" << endl;
	outputFile << "Ca�kowity czas przetwarzania pakiet�w mieszanych: " << stats.mixedPacketsGeneratedTime << "ms" << endl;
	outputFile << endl;

	outputFile << "Wygenerowane pakiety liczbowe: " << endl;
	outputFile << "Nr\tIlo�� znak�w\tCzas przetwarzania\tTekstowa Reprezentacja" << endl;
	for (int i = 0; i < stats.numericPacketsInfo.size(); i++) {
		outputFile << i + 1 << "\t" << stats.numericPacketsInfo[i].stringRepresentation.length() << "\t" << stats.numericPacketsInfo[i].generatedTime << "ms\t" << stats.numericPacketsInfo[i].stringRepresentation << endl;
	}
	outputFile << endl;

	outputFile << "Wygenerowane pakiety tekstowe: " << endl;
	outputFile << "Nr\tIlo�� znak�w\tCzas przetwarzania\tTekstowa Reprezentacja" << endl;
	for (int i = 0; i < stats.textPacketsInfo.size(); i++) {
		outputFile << i + 1 << "\t" << stats.textPacketsInfo[i].stringRepresentation.length() << "\t" << stats.textPacketsInfo[i].generatedTime << "ms\t" << stats.textPacketsInfo[i].stringRepresentation << endl;
	}
	outputFile << endl;

	outputFile << "Wygenerowane pakiety mieszane: " << endl;
	outputFile << "Nr\tIlo�� znak�w\tCzas przetwarzania\tTekstowa Reprezentacja" << endl;
	for (int i = 0; i < stats.mixedPacketsInfo.size(); i++) {
		outputFile << i + 1 << "\t" << stats.mixedPacketsInfo[i].stringRepresentation.length() << "\t" << stats.mixedPacketsInfo[i].generatedTime << "ms\t" << stats.mixedPacketsInfo[i].stringRepresentation << endl;
	}
	outputFile << endl;

	outputFile << "Statystyki dla znak�w" << endl;
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
