#pragma once

#include "command.hpp"
#include <string>

using std::string;

namespace commands {
	
	class OutputStreamCommand : virtual public Command {
	public:
		string getOutputFilename() { return outputFilename_; }

	protected:
		OutputStreamCommand();

		inline void setOutputFilename(string outputFilename) { outputFilename_ = outputFilename; }

		virtual bool isOutputStreamSign(string sign) { return sign == ">" || sign == ">>"; }

		virtual void outputStreamRedirection(string sign, string outputFilename);

	private:
		string outputFilename_ = "";
	};

}