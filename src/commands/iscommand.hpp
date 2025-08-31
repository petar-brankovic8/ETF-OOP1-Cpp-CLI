#pragma once

#include "command.hpp"
#include <string>
#include <istream>

using std::string;
using std::istream;

namespace commands {

	class InputStreamCommand : virtual public Command {
	public:
		void setInput(string input) { input_ = input; }
		void setInputSource(istream* inputSouce) { inputSource_ = inputSouce; }
		void setInputFilename(string inputFilename) { inputFilename_ = inputFilename; }

	protected:
		InputStreamCommand() : Command("inputStreamCommand") {}

		virtual string loadInput();
	
		istream* getInputSource() { return inputSource_; }
		string getInputFilename() { return inputFilename_; }
		string getInput() { return input_; }

		virtual bool isInputStreamSign(string sign) { return sign == "<"; }

		virtual void inputStreamRedirection(string redirectionSign, string filename);

		virtual string inputDefault();

		virtual string inputTxt();

	private:
		istream* inputSource_ = nullptr;
		string inputFilename_ = "";
		string input_ = "";
	};

}