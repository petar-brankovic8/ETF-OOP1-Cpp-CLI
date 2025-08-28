#pragma once

#include "command.hpp"
#include <string>

using std::string;

namespace commands {

	class InputStreamCommand : virtual public Command {
	public:
		void setInput(string input) { input_ = input; }

	protected:
		InputStreamCommand() : Command("inputStreamCommand") {}
		
		void setInputFilename(string inputFilename) { inputFilename_ = inputFilename; }

		virtual bool isInputStreamSign(string sign) { return sign == "<"; }

		virtual void inputStreamRedirection(string redirectionSign, string filename);

	private:
		string inputFilename_;
		string input_;
	};

}