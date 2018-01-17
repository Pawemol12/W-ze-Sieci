#include "stdafx.h"
#include "InputManager.h"
using namespace std;

InputManager::InputManager()
{ 
}

bool InputManager::isValidSwitcherKey(std::string switcherKey) 
{
	return (switcherKey == "-n" || switcherKey == "-t" || switcherKey == "-o");
}

bool InputManager::isSwitcherKey(std::string switcherKey)
{
	return switcherKey[0] == '-';
}

int InputManager::tryParseInputArguments(int argc, char* argv[]) 
{
	if (argc < TOTAL_PARAMETRS_NUMBER + 1)
		return PARSE_INPUT_RESULT_NOT_ENAUGH_ARGUMENTS;

	for (int i = 1; i < argc; i++) {
		string switcherKey(argv[i]);
		if (this->isValidSwitcherKey(switcherKey)) {
			if (i + 1 > argc) {
				cout << argc << endl;
				return PARSE_INPUT_RESULT_NOT_PARAMETER_VALUE_AFTER_SWITCHER;
			}

			string switcherValue = argv[i + 1];
			if (this->isSwitcherKey(switcherValue)) 
			{
				return PARSE_INPUT_SWITCHER_AFTER_SWITCHER;
			}
			else if (switcherKey == "-n") {
				try {
					this->timeBetweenPacketGeneration = stoi(switcherValue);
				}
				catch (const invalid_argument& ia) {
					return PARSE_INPUT_RESULT_WRONG_VALUE;
				}
			}
			else if (switcherKey == "-t") {
				try {
					this->simulationTotalTime = stoi(switcherValue);
				}
				catch (const invalid_argument& ia) {
					return PARSE_INPUT_RESULT_WRONG_VALUE;
				}
			}
			else if (switcherKey == "-o") {
				this->outputFileName = switcherValue;
			}

		}

	}
	return PARSE_INPUT_RESULT_OK;
}


InputManager::~InputManager()
{
}
