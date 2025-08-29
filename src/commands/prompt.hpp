#pragma once

#include "command.hpp"
#include <string>
#include <vector>

using std::string;
using std::vector;

class Controller;

namespace commands {

	class Prompt : public Command {
	public:
		Prompt();

		static Command* commandCreate();

		string run() override;

		void addParameters(vector<string> tokens) override;

		void setController(Controller* controller) { myController_ = controller; }

	protected:
		void setPromptString(string promptString) { promptString_ = promptString; }

		virtual void addFirstParameter(vector<string>& tokens, int& currentToken);
	
	private:
		string promptString_;
		Controller* myController_ = nullptr;
	};

}