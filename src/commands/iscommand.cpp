#include "iscommand.hpp"
#include "../utils/constants.hpp"
#include "../utils/exceptions.hpp"
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

namespace commands {
	string InputStreamCommand::loadInput()
	{
		if (getInputStream() == InputStreamType::QuoteArgument || getInputStream() == InputStreamType::Pipeline)
			return getInput();

		if (getInputStream() == InputStreamType::Default)
			return inputDefault();

		if (getInputStream() == InputStreamType::TxtFile)
			return inputTxt();
		return "";
	}

	void InputStreamCommand::inputStreamRedirection(string redirectionSign, string filename) {
		if (getInputStream() != InputStreamType::Default)
			throw TooManyInputStreamDefinitionsException(getCommandName());
		setInputStream(InputStreamType::TxtFile);
		setInputFilename(filename);
	}

	string InputStreamCommand::inputDefault() {
		string result = "";
		int c = getInputSource()->get();;
		while (c != '\x1A' && c != EOF) {
			result += static_cast<char>(c);
			c = getInputSource()->get();
		}
		getInputSource()->clear();
		return result;
	}

	string InputStreamCommand::inputTxt()
	{
		ifstream ifs(getInputFilename());
		if (!ifs)
			throw FileNotOpenedException(getCommandName());
		string result = "";
		char c;
		while (ifs.get(c))
			result += c;
		return result;
	}

}