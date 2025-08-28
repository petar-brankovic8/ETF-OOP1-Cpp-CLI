#pragma once

#include "command.hpp"
#include <string>
#include <vector>

using std::string;
using std::vector;

namespace commands {

	class Prompt : public Command {
	public:
		Prompt();

		static Command* commandCreate();

		string run() override;

		void addParameters(vector<string> tokens) override;

	protected:
		void setPromptString(string promptString) { promptString_ = promptString; }

		virtual void addFirstParameter(vector<string>& tokens, int& currentToken);
	
	private:
		string promptString_;
	};

}