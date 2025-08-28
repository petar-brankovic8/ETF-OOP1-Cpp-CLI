#pragma once

#include "command.hpp"
#include <string>

namespace commands {
	
	class OutputStreamCommand : virtual public Command {
	public:
		std::string getOutputFilename() { return outputFilename_; }
	protected:
		OutputStreamCommand();
		inline void setOutputFilename(std::string outputFilename) { outputFilename_ = outputFilename; }
	private:
		std::string outputFilename_ = "";
	};

}