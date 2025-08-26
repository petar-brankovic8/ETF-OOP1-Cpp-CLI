#include "controller.hpp"
#include "commandline.hpp"
#include <string>

Controller::Controller(Reader* reader, Translator* translator, Writer* writer) : myReader_(reader), myTranslator_(translator), myWriter_(writer) {};

void Controller::run() {
	while (true) {
		myWriter_->standardWrite(prompt_ + " ");
		std::string line = myReader_->readLine();
		CommandLine commandLine = CommandLine(line, myTranslator_);
		commandLine.execute();
	}
}