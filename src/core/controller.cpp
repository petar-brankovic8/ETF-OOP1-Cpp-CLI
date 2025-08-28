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
			CommandLine commandLine = CommandLine(line, myTranslator_);
			commandLine.execute();
		}
		catch (const UnkownCommandException& e) {
			cerr << "Unkown command: " << e.what() << '\n';
		}
		catch (const MissingRedirectionArgumentException& e) {
			cerr << "Missing redirection argument in command: " << e.what() << '\n';
		}
		catch (const TooManyArgumentsException& e) {
			cerr << "Too many arguments in command: " << e.what() << '\n';
		}
		catch (const TooManyInputStreamDefinitionsException& e) {
			cerr << "Too many input streams defined in command: " << e.what() << '\n';
		}
		catch (const TooManyOutputStreamDefinitionsException& e) {
			cerr << "Too many output streams defined in command: " << e.what() << '\n';
		}
		catch (const ExpectedArgumentException& e) {
			cerr << "Expected argument in command: " << e.what() << '\n';
		}
		catch (const ExpectedQuotedArgumentException& e) {
			cerr << "Expected quoted argument in command: " << e.what() << '\n';
		}
		catch (const ExpectedFilenameArgumentException& e) {
			cerr << "Expected filename argument in command: " << e.what() << '\n';
		}
	}
}