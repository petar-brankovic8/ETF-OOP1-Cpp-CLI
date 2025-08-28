#pragma once

#include "command.hpp"
#include <string>
#include <vector>

using std::string;
using std::vector;

namespace commands {

	class Truncate : public Command {
	public:
		Truncate();

		static Command* commandCreate();

		string run() override;

		void addParameters(vector<string> tokens) override;
	};

}