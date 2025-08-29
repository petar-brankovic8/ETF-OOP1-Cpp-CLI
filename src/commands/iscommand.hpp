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

	protected:
		InputStreamCommand() : Command("inputStreamCommand") {}
		
		void setInputFilename(string inputFilename) { inputFilename_ = inputFilename; }

		istream* getInputSource() { return inputSource_; }
		string getInputFilename() { return inputFilename_; }
		string getInput() { return input_; }

		virtual bool isInputStreamSign(string sign) { return sign == "<"; }

		virtual void inputStreamRedirection(string redirectionSign, string filename);

	private:
		istream* inputSource_ = nullptr;
		string inputFilename_ = "";
		string input_ = "";
	};

}