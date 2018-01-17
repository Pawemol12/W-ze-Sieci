#pragma once
class OutputManager
{
private:

public:
	OutputManager();
	static bool createStatsFile(PacketsStats stats, string fileName);

	~OutputManager();

};

