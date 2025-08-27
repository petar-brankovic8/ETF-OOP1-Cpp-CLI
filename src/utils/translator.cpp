#include "translator.hpp"
#include "../commands/commands.hpp"
#include <string>
#include <vector>
#include <unordered_map>
#include <cctype>

using namespace std;
using namespace commands;

Translator::Translator() {
	commandCreateMap["echo"] = &Echo::commandCreate;
	commandCreateMap["prompt"] = &Prompt::commandCreate;
	commandCreateMap["time"] = &Time::commandCreate;
	commandCreateMap["date"] = &Date::commandCreate;
	commandCreateMap["touch"] = &Touch::commandCreate;
	commandCreateMap["truncate"] = &Truncate::commandCreate;
	commandCreateMap["rm"] = &Rm::commandCreate;
	commandCreateMap["wc"] = &Wc::commandCreate;
	commandCreateMap["tr"] = &Tr::commandCreate;
	commandCreateMap["head"] = &Head::commandCreate;
	commandCreateMap["batch"] = &Batch::commandCreate;
}

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

Command* Translator::createCommand(const string& commandString) {
	vector<string> tokens = parseTokens(commandString);

	if (tokens.empty())
		return nullptr;
	if (commandCreateMap.count(tokens[0]) == 0)
		return nullptr; // Add throw exception logic
	Command* command = commandCreateMap[tokens[0]]();
	command->addParameters(tokens);

	return command;
}

vector<string> Translator::parseTokens(const string& commandString)
{
	vector<string> tokens;
	int i = -1;
	bool inQuote = false, wasSpace = true;

	for (auto c : commandString) {
		if (c == '\"') {
			inQuote = !inQuote;
			if (wasSpace) {
				wasSpace = false;
				tokens.push_back("");
				i++;
			}
			tokens[i] += c;
		}
		else if (inQuote) {
			tokens[i] += c;
		}
		else if (isspace(c)) {
			wasSpace = true;
		}
		else if (wasSpace) {
			wasSpace = false;
			tokens.push_back("");
			i++;
			tokens[i] += c;
		}
		else {
			tokens[i] += c;
		}
	}

	return tokens;
}