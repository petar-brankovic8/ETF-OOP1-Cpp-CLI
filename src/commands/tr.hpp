#pragma once

#include "command.hpp"
#include "iscommand.hpp"
#include "oscommand.hpp"
#include <string>
#include <vector>

using std::string;
using std::vector;

namespace commands {

	class Tr : public InputStreamCommand, public OutputStreamCommand {
	public:
		Tr();

		static Command* commandCreate();

		string run() override;

		void addParameters(vector<string> tokens) override;

	protected:
		void setWhat(string what) { what_ = what; }

		void setWith(string with) { with_ = with; }

		virtual void addFirstParameter(vector<string>& tokens, int& currentToken, bool& whatDefined);

		virtual void addSecondParameter(vector<string>& tokens, int& currentToken, bool& whatDefined);

		virtual void addThirdParameter(vector<string>& tokens, int& currentToken);

		virtual void addFourthParameter(vector<string>& tokens, int& currentToken);

	private:
		string what_ = "";
		string with_ = "";
	};

}