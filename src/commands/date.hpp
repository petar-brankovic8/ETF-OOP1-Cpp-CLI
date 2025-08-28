#pragma once

#include "command.hpp"
#include "oscommand.hpp"
#include <string>
#include <vector>

using std::string;
using std::vector;

namespace commands {

	class Date : public OutputStreamCommand {
	public:
		Date();

		static Command* commandCreate();

		string run() override;

		void addParameters(vector<string> tokens) override;
	};

}