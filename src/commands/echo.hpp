#pragma once

#include "command.hpp"
#include "iscommand.hpp"
#include "oscommand.hpp"
#include <string>
#include <vector>

using std::string;
using std::vector;

namespace commands {

	class Echo : public InputStreamCommand, public OutputStreamCommand {
	public:
		Echo();

		static Command* commandCreate();

		string run() override;

		void addParameters(vector<string> tokens) override;
	
	protected:
		virtual void addFirstParameter(vector<string>& tokens, int& currentToken);

		virtual void addSecondParameter(vector<string>& tokens, int& currentToken);
	};

}