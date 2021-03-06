// @description Zadanie nr 40 z wybor
// @author Paweł Lodzik
// @createDate 15.01.2018r
// @lastModDate 18.01.2018r

#include "stdafx.h"
#include "InputManager.h"
#include "RandomNumbersGenerator.h"
#include "PacketGenerator.h"
#include "Node.h"
#include "OutputManager.h"

using namespace std;

int main(int argc, char* argv[])
{
	RandomNumbersGenerator::setRandom();
	InputManager inputManger;
	int parseArgsResult = inputManger.tryParseInputArguments(argc, argv);
	if (parseArgsResult != PARSE_INPUT_RESULT_OK) {
		switch (parseArgsResult) {
			case PARSE_INPUT_RESULT_NOT_ENOUGH_ARGUMENTS: {
				cout << "Nie podałeś wszystkich wymaganych argumentów!" << endl;
				break;
			}
			case PARSE_INPUT_RESULT_NOT_PARAMETER_VALUE_AFTER_SWITCHER:
			{
				cout << "Brak wartości po przełączniku!" << endl;
				break;
			}
			case PARSE_INPUT_SWITCHER_AFTER_SWITCHER:
			{
				cout << "Nie może być przełącznika po przełączniku" << endl;
				break;
			}
			case PARSE_INPUT_RESULT_WRONG_VALUE: {
				cout << "Nieprawidłowa wartość parametru!" << endl;
				break;
			}
		}

		return -1;
	}

	PacketGenerator packetGenerator(inputManger.getTimeBetweenPacketGeneration(), inputManger.getSimulationTotalTime());
	if (!packetGenerator.isValid()) {
		cout << "Czas symulacji nie może być mniejszy od odstępu pomiędzy generacją kolejnych pakietów." << endl;
		cout << "Obie wartości nie mogą też się równać 0." << endl;
		return -1;
	}

	packetGenerator.generateRandomPackets();
	cout << "Wygenerowano " << packetGenerator.getGeneratedPacketCount() << " pakietów" << endl;

	vector<shared_ptr<Packet>> generatedPackets = packetGenerator.getPackets();

	Node node(generatedPackets);
	node.generateStatsForPackets();

	if (OutputManager::createStatsFile(node.getPacketsStats(), inputManger.getOutputFileName())) {
		cout << "Pomyślnie utworzono plik ze statystykami." << endl;
	}
	else {
		cout << "Nie udało się utworzyć pliku ze statystykami." << endl;
	}

	#ifdef _DEBUG
		system("pause");
	#endif
	return 0;
}

