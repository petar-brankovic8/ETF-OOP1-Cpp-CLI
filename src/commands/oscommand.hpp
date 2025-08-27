#pragma once

#include "command.hpp"
#include <string>

namespace commands {
	
	class OutputStreamCommand : virtual Command {
	public:
		std::string getOutputFilename() { return outputFilename_; }
	private:
		std::string outputFilename_;
	};

}