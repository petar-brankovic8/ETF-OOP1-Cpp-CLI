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
			CommandLine commandLine = CommandLine(line, myTranslator_, &cin);
			cout << commandLine.execute();
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
		catch (const ExpectedOptionArgumentException& e) {
			cerr << "Exptect option argument in command: " << e.what() << '\n';
		}
		catch (const InvalidOptionException& e) {
			cerr << "Invalid option for command: " << e.what() << '\n';
		}
		catch (const ExpectedArgumentBeforeRedirectionException& e) {
			cerr << "Expected argument before redirection in command: " << e.what() << '\n';
		}
		catch (const RedirectionNotAtEndException& e) {
			cerr << "Redirection not at the end of command: " << e.what() << '\n';
		}
		catch (const NoInputStreamException& e) {
			cerr << "This command cannot have input stream: " << e.what() << '\n';
		}
		catch (const NoOutputStreamException& e) {
			cerr << "This command cannot have output stream: " << e.what() << '\n';
		}
		catch (const ExpectedCommandAroundPipelineException& e) {
			cerr << "Expected command around pipeline '|'" << '\n';
		}
		catch (const FileNotOpenedException& e) {
			cerr << "Error file not opened: " << e.what() << '\n';
		}
	}
}
