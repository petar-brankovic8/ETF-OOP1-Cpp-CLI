#include "commandline.hpp"
#include "../utils/translator.hpp"
#include "../utils/constants.hpp"
#include "../commands/command.hpp"
#include "../commands/iscommand.hpp"
#include "../commands/oscommand.hpp"
#include <string>

using namespace std;
using namespace commands;

CommandLine::CommandLine(string lineString, Translator* translator) : myTranslator_(translator) {
	vector<string> commandStrings = myTranslator_->parsePipelines(lineString);

	for (auto commandString : commandStrings) {
		Command* newCommand = myTranslator_->createCommand(commandString);
		commands_.push_back(newCommand);
	}

	this->checkSemantics();
}

void CommandLine::execute() {
	if (commands_.size() == 0) return;

	string pipeline;
	bool pipelineActive = false;

	for (auto command : commands_) {
		if (!command) 
			continue;
		if (pipelineActive)
			dynamic_cast<InputStreamCommand*>(command)->insertPipeline(pipeline);
		else
			pipelineActive = true;
		pipeline = command->run();
	}

	Command* lastCommand = commands_[commands_.size() - 1];
	if (!lastCommand) 
		return;
	OutputStreamType myOutputStream = lastCommand->getOutputStreamType();

	string outputFilename = "";
	if (myOutputStream == OutputStreamType::TxtFileOverwrite || myOutputStream == OutputStreamType::TxtFileAppend)
		outputFilename = dynamic_cast<OutputStreamCommand*>(lastCommand)->getOutputFilename();

	write(pipeline, myOutputStream, outputFilename);
}

void CommandLine::checkSemantics() const {
	// Add logic
	;
}

void CommandLine::write(std::string text, OutputStreamType outputStream, std::string outputFilename) {
	// Add logic
	;
}
