#pragma once

#include "command.hpp"
#include <string>

namespace commands {
	
	class OutputStreamCommand : virtual public Command {
	public:
		std::string getOutputFilename() { return outputFilename_; }
	private:
		std::string outputFilename_;
	};

}