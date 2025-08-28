#pragma once

#include "command.hpp"
#include "oscommand.hpp"
#include <string>
#include <vector>

using std::string;
using std::vector;

namespace commands {

	class Time : public OutputStreamCommand {
	public:
		Time();

		static Command* commandCreate();

		string run() override;

		void addParameters(vector<string> tokens) override;

	protected:
		virtual void addFirstParameter(vector<string>& tokens, int& currentToken);
	};

}