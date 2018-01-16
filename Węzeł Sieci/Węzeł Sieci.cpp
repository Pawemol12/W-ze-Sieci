// @description Zadanie nr 40 z wybor
// @author Paweł Lodzik
// @createDate 15.01.2018r

#include "stdafx.h"
#include "InputManager.h"
#include "TextPacket.h"
using namespace std;

int main(int argc, char* argv[])
{
	InputManager inputManger;
	int parseArgsResult = inputManger.tryParseInputArguments(argc, argv);
	if (parseArgsResult != PRASE_INPUT_RESULT_OK) {
		switch (parseArgsResult) {
			case PARSE_INPUT_RESULT_NOT_ENAUGH_ARGUMENTS: {
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

	TextPacket textPacket;
    return 0;
}

