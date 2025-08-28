#include "controller.hpp"
#include "commandline.hpp"
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
			CommandLine commandLine = CommandLine(line, myTranslator_);
			commandLine.execute();
		}
		catch (...) {

		}
	}
}