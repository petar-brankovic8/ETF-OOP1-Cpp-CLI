#pragma once

#include "command.hpp"
#include "iscommand.hpp"
#include "oscommand.hpp"
#include "../utils/translator.hpp"
#include <string>
#include <vector>

using std::string;
using std::vector;

namespace commands {

	class Batch : public InputStreamCommand, public OutputStreamCommand {
	public:
		Batch();

		static Command* commandCreate();

		string run() override;

		void addParameters(vector<string> tokens) override;

		void setTranslator(Translator* translator) { myTranslator_ = translator; }

	protected:
		virtual void addFirstParameter(vector<string>& tokens, int& currentToken);

		virtual void addSecondParameter(vector<string>& tokens, int& currentToken);

	private:
		Translator* myTranslator_ = nullptr;
	};

}