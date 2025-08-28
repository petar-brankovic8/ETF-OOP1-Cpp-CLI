#pragma once

#include "command.hpp"
#include <string>

using std::string;

namespace commands {

	class InputStreamCommand : virtual public Command {
	public:
		virtual void insertPipeline(string pipeline);

	protected:
		InputStreamCommand();

		void setInput(string input) { input_ = input; }
		void setInputFilename(string inputFilename) { inputFilename_ = inputFilename; }

		virtual bool isInputStreamSign(string sign) { return sign == "<"; }

		virtual void inputStreamRedirection(string redirectionSign, string filename);

	private:
		string inputFilename_;
		string input_;
	};

}