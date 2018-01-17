#pragma once
#define TOTAL_PARAMETRS_NUMBER 3 

enum ParseInputResult {
	PARSE_INPUT_RESULT_NOT_ENAUGH_ARGUMENTS = -3,
	PARSE_INPUT_RESULT_NOT_PARAMETER_VALUE_AFTER_SWITCHER,
	PARSE_INPUT_SWITCHER_AFTER_SWITCHER,
	PARSE_INPUT_RESULT_WRONG_VALUE,
	PARSE_INPUT_RESULT_OK,
};

class InputManager
{
protected:
	int timeBetweenPacketGeneration;
	int simulationTotalTime;
	std::string outputFileName;

	bool isValidSwitcherKey(std::string switcherKey);
	bool isSwitcherKey(std::string switcherKey);
public:
	InputManager();

	int tryParseInputArguments(int argc, char* argv[]);

	int getTimeBetweenPacketGeneration() const { return this->timeBetweenPacketGeneration; };
	int getSimulationTotalTime() const { return this->simulationTotalTime; }
	std::string getOutputFileName() const { return this->outputFileName; }

	~InputManager();
};

