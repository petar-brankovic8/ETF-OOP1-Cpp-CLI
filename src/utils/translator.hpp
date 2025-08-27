#pragma once

#include "../commands/command.hpp"
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;
using namespace commands;

class Translator {
public: 
	Translator();

	virtual vector<string> parsePipelines(const string& lineString);

	virtual Command* createCommand(const string& commandString);

	virtual vector<string> parseTokens(const string& commandString);

private:
	unordered_map<string, Command* (*)()> commandCreateMap;
};