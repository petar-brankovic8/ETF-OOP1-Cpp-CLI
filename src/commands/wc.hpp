#pragma once

#include "command.hpp"
#include "iscommand.hpp"
#include "oscommand.hpp"
#include <string>
#include <vector>

using std::string;
using std::vector;

namespace commands {

	class Wc : public InputStreamCommand, public OutputStreamCommand {
	public:
		Wc();

		static Command* commandCreate();

		string run() override;

		void addParameters(vector<string> tokens) override;

	protected:
		enum class Option { Word, Char };

		void setOption(Option option) { option_ = option; }

		virtual void addFirstParameter(vector<string>& tokens, int& currentToken);

		virtual void addSecondParameter(vector<string>& tokens, int& currentToken);

		virtual void addThirdParameter(vector<string>& tokens, int& currentToken);

		virtual int countWords(const string& s);

		virtual int countChars(const string& s);

	private:
		Option option_ = Option::Word;
	};

}