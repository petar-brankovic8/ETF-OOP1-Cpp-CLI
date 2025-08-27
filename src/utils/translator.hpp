#pragma once

#include "../commands/command.hpp"
#include <string>
#include <vector>

using namespace std;
using namespace commands;

class Translator {
public: 
	Translator();

	virtual vector<string> parsePipelines(string& lineString);

	virtual Command* createCommand(string& commandString);

	// Add functionalities
};