#pragma once

#include "command.hpp"
#include <string>

namespace commands {

	class InputStreamCommand : virtual public Command {
	public:
		virtual void insertPipeline(std::string pipeline);
	protected:
		InputStreamCommand();
		inline void setInput(std::string input) { input_ = input; }
	private:
		std::string input_;
	};

}