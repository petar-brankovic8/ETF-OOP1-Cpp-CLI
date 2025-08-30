#include "controller.hpp"
#include "commandline.hpp"
#include "../utils/exceptions.hpp"
#include <string>
#include <iostream>

using namespace std;

Controller::Controller(Translator* translator) : myTranslator_(translator) {};

void Controller::run() {
	while (true) {
		//Prompt
		cout << "\n" + prompt_ + " ";
		
		//Read line
		string line;
		getline(cin, line);
		if (line.size() > kMaxLineSize)
			line.resize(kMaxLineSize);

		//Construct and execute command line
		try {
			CommandLine commandLine = CommandLine(line, myTranslator_, &cin, this);
			cout << commandLine.execute() << '\n';
		}
		catch (runtime_error& e) {
			cerr << exceptionHandler(e) << '\n';
		}
	}
}

string Controller::exceptionHandler(runtime_error& e) {
	if (dynamic_cast<UnkownCommandException*>(&e)) {
		return string("Unkown command: ") + e.what();
	}
	if (dynamic_cast<MissingRedirectionArgumentException*>(&e)) {
		return string("Missing redirection argument in command: ") + e.what();
	}
	if (dynamic_cast<TooManyArgumentsException*>(&e)) {
		return string("Too many arguments in command: ") + e.what();
	}
	if (dynamic_cast<TooManyInputStreamDefinitionsException*>(&e)) {
		return string("Too many input streams defined in command: ") + e.what();
	}
	if (dynamic_cast<TooManyOutputStreamDefinitionsException*>(&e)) {
		return string("Too many output streams defined in command: ") + e.what();
	}
	if (dynamic_cast<ExpectedArgumentException*>(&e)) {
		return string("Expected argument in command: ") + e.what();
	}
	if (dynamic_cast<ExpectedQuotedArgumentException*>(&e)) {
		return string("Expected quoted argument in command: ") + e.what();
	}
	if (dynamic_cast<ExpectedFilenameArgumentException*>(&e)) {
		return string("Expected filename argument in command: ") + e.what();
	}
	if (dynamic_cast<ExpectedOptionArgumentException*>(&e)) {
		return string("Exptect option argument in command: ") + e.what();
	}
	if (dynamic_cast<InvalidOptionException*>(&e)) {
		return string("Invalid option for command: ") + e.what();
	}
	if (dynamic_cast<ExpectedArgumentBeforeRedirectionException*>(&e)) {
		return string("Expected argument before redirection in command: ") + e.what();
	}
	if (dynamic_cast<RedirectionNotAtEndException*>(&e)) {
		return string("Redirection not at the end of command: ") + e.what();
	}
	if (dynamic_cast<NoInputStreamException*>(&e)) {
		return string("This command cannot have input stream: ") + e.what();
	}
	if (dynamic_cast<NoOutputStreamException*>(&e)) {
		return string("This command cannot have output stream: ") + e.what();
	}
	if (dynamic_cast<ExpectedCommandAroundPipelineException*>(&e)) {
		return string("Expected command around pipeline '|'");
	}
	if (dynamic_cast<FileNotOpenedException*>(&e)) {
		return string("Error file not opened, command: ") + e.what();
	}
	if (dynamic_cast<FileAlreadyExistsException*>(&e)) {
		return string("Error file already exists, command: ") + e.what();
	}
	if (dynamic_cast<FileNotCreatedException*>(&e)) {
		return string("Error file not created, command: ") + e.what();
	}
	if (dynamic_cast<FileNotFoundException*>(&e)) {
		return string("File not found, command: ") + e.what();
	}
	return "Unknown exception";
}
