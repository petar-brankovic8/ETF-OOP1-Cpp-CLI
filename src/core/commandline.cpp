#include "commandline.hpp"
#include "../utils/translator.hpp"
#include "../commands/command.hpp"
#include <string>

using namespace std;

CommandLine::CommandLine(string lineString, Translator* translator) : myTranslator_(translator) {
	vector<string> commandStrings = myTranslator_->parsePipelines(lineString);
	for (auto commandString : commandStrings) {
		Command* newCommand = myTranslator_->createCommand(commandString);
		commands.push_back(newCommand);
	}
}

void CommandLine::execute() {
	// Add logic
	;
}