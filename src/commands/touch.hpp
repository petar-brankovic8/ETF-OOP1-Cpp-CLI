#pragma once

#include "command.hpp"
#include <string>
#include <vector>

using std::string;
using std::vector;

namespace commands {

	class Touch : public Command {
	public:
		Touch();

		static Command* commandCreate();

		string run() override;

		void addParameters(vector<string> tokens) override;
	};

}