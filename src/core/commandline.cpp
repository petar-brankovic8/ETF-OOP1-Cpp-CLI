#include "commandline.hpp"
#include "../utils/translator.hpp"
#include "../utils/constants.hpp"
#include "../utils/exceptions.hpp"
#include "../commands/command.hpp"
#include "../commands/iscommand.hpp"
#include "../commands/oscommand.hpp"
#include <string>
#include <iostream>
#include <fstream>

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
	if (commands_[0] == nullptr) 
		return;

	//Execution
	string pipeline;
	bool pipelineActive = false;

	for (auto command : commands_) {
		if (pipelineActive)
			dynamic_cast<InputStreamCommand*>(command)->setInput(pipeline);
		else
			pipelineActive = true;
		pipeline = command->run();
	}

	//Output
	Command* lastCommand = commands_[commands_.size() - 1];
	OutputStreamType myOutputStream = lastCommand->getOutputStream();

	string outputFilename = "";
	if (myOutputStream == OutputStreamType::TxtFileOverwrite || myOutputStream == OutputStreamType::TxtFileAppend)
		outputFilename = dynamic_cast<OutputStreamCommand*>(lastCommand)->getOutputFilename();

	write(pipeline, myOutputStream, outputFilename);
}

void CommandLine::checkSemantics() const {
	for (int i = 0; i < commands_.size(); i++) {
		if (commands_.size() > 1 && commands_[i] == nullptr)
			throw ExpectedCommandAroundPipelineException("");

		if (i > 0) {
			if (commands_[i]->getInputStream() == InputStreamType::NoInputStream)
				throw NoInputStreamException(commands_[i]->getCommandName());
			if (commands_[i]->getInputStream() != InputStreamType::Default)
				throw TooManyInputStreamDefinitionsException(commands_[i]->getCommandName());
		}
		if (i < commands_.size() - 1) {
			if (commands_[i]->getOutputStream() == OutputStreamType::NoOutputStream)
				throw NoOutputStreamException(commands_[i]->getCommandName());
			if (commands_[i]->getOutputStream() != OutputStreamType::Default)
				throw TooManyOutputStreamDefinitionsException(commands_[i]->getCommandName());
		}
	}
}

void CommandLine::write(std::string text, OutputStreamType outputStream, std::string outputFilename) {
	switch (outputStream) {
	case OutputStreamType::NoOutputStream:
		return;
	case OutputStreamType::Default:
		cout << text << '\n';
		break;
	case OutputStreamType::TxtFileOverwrite: {
		ofstream outFile(outputFilename);
		if (!outFile)
			throw FileNotOpenedException(outputFilename);
		outFile << text; 
		break;
	}
	case OutputStreamType::TxtFileAppend: {
		ofstream outFile(outputFilename, ios::app);
		if (!outFile)
			throw FileNotOpenedException(outputFilename);
		outFile << text;
		break;
	}
	}
}
