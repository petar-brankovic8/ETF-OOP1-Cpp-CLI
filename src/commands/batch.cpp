#include "batch.hpp"
#include "command.hpp"
#include "../utils/exceptions.hpp"
#include "../core/commandline.hpp"
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <iostream>

using namespace std;

namespace commands {

	Batch::Batch() : Command(InputStreamType::Default, OutputStreamType::Default, "batch") {}

	Command* Batch::commandCreate()
	{
		return new Batch();
	}

	string Batch::run() {
		string result = "";

		if (getInputStream() == InputStreamType::Default) {
			//Multiline input until EOF char
			while (true) {
				string line = "";
				bool eof = false;
				int c = getInputSource()->get();
				while (c != '\n') {
					if (c == '\x1A' || c == EOF) {
						eof = true;
						break;
					}
					line += static_cast<char>(c);
					c = getInputSource()->get();
				}

				//Batch command line execution
				if (line.size() > kMaxLineSize)
					line.resize(kMaxLineSize);
				try {
					CommandLine commandLine = CommandLine(line, myTranslator_, getInputSource(), myController_);
					result += commandLine.execute();
				}
				catch (runtime_error& e) {
					result += e.what();
				}
				if (eof) {
					getInputSource()->clear();
					break;
				}
			}
		}
		else {
			//Setting up input stream source
			istream* myInputSource = nullptr;

			istringstream iss(getInput());
			if (getInputStream() == InputStreamType::QuoteArgument || getInputStream() == InputStreamType::Pipeline)
				myInputSource = &iss;

			ifstream ifs(getInputFilename());
			if (getInputStream() == InputStreamType::TxtFile) {
				if (!ifs)
					throw FileNotOpenedException(getCommandName());
				myInputSource = &ifs;
			}

			//Batch command line execution
			string line;
			while (getline(*myInputSource, line)) {
				if (line.size() > kMaxLineSize)
					line.resize(kMaxLineSize);
				try {
					CommandLine commandLine = CommandLine(line, myTranslator_, myInputSource, myController_);
					result += commandLine.execute();
				}
				catch (runtime_error& e) {
					result += e.what();
				}
			}
		}
		return result;
	}

	void Batch::addParameters(vector<string> tokens) {
		if (tokens.size() == 1)
			return;
		int currentToken = 1;
		addFirstParameter(tokens, currentToken);

		if (currentToken >= tokens.size())
			return;
		addSecondParameter(tokens, currentToken);

		if (currentToken < tokens.size())
			throw TooManyArgumentsException(getCommandName());
	}

	void Batch::addFirstParameter(vector<string>& tokens, int& currentToken) {
		if (isQuoteArgument(tokens[currentToken])) {
			setInputStream(InputStreamType::QuoteArgument);
			setInput(tokens[currentToken].substr(1, tokens[currentToken].size() - 2));
			currentToken++;
			return;
		}
		else if (isRedirectionSign(tokens[currentToken])) {
			if (currentToken + 1 >= tokens.size())
				throw MissingRedirectionArgumentException(getCommandName());
			if (isInputStreamSign(tokens[currentToken])) {
				inputStreamRedirection(tokens[currentToken], tokens[currentToken + 1]);
			}
			if (isOutputStreamSign(tokens[currentToken])) {
				outputStreamRedirection(tokens[currentToken], tokens[currentToken + 1]);
			}
			currentToken += 2;
			return;
		}
		else {
			setInputStream(InputStreamType::TxtFile);
			setInputFilename(tokens[currentToken]);
			currentToken++;
			return;
		}
	}

	void Batch::addSecondParameter(vector<string>& tokens, int& currentToken) {
		if (isRedirectionSign(tokens[currentToken])) {
			if (currentToken + 1 >= tokens.size())
				throw MissingRedirectionArgumentException(getCommandName());
			if (isInputStreamSign(tokens[currentToken])) {
				inputStreamRedirection(tokens[currentToken], tokens[currentToken + 1]);
			}
			if (isOutputStreamSign(tokens[currentToken])) {
				outputStreamRedirection(tokens[currentToken], tokens[currentToken + 1]);
			}
			currentToken += 2;
		}
		else throw TooManyArgumentsException(getCommandName());
	}

}