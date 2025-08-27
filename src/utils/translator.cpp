#include "translator.hpp"
#include "../commands/command.hpp"
#include <string>
#include <vector>

using namespace std;
using namespace commands;

Translator::Translator() {}

vector<string> Translator::parsePipelines(const string& lineString) {
	vector<string> commandStrings = { "" };
	int i = 0;
	bool inQuote = false;

	for (auto c : lineString) {
		if (c == '\"') {
			inQuote = !inQuote;
			commandStrings[i] += c;
		}
		else if (!inQuote && c == '|') {
			commandStrings.push_back("");
			i++;
		}
		else {
			commandStrings[i] += c;
		}
	}
	return commandStrings;
}

Command* Translator::createCommand(string& commandString) {
	// Add logic
	return nullptr;
}