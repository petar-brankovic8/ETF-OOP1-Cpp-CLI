#pragma once

#include "command.hpp"
#include <string>

namespace commands {

	class InputStreamCommand : virtual public Command {
	public:
		virtual void insertPipeline(std::string pipeline);
	private:
		std::string input_;
	};

}