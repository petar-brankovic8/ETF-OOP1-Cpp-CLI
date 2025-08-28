#pragma once

#include "command.hpp"
#include "iscommand.hpp"
#include "oscommand.hpp"
#include <string>
#include <vector>

using std::string;
using std::vector;

namespace commands {

	class Head : public InputStreamCommand, public OutputStreamCommand {
	public:
		Head();

		static Command* commandCreate();

		string run() override;

		void addParameters(vector<string> tokens) override;

	protected:
		void setNcount(int ncount) { ncount_ = ncount; }
		int getNcount() { return ncount_; }

		virtual void addFirstParameter(vector<string>& tokens, int& currentToken);

		virtual void addSecondParameter(vector<string>& tokens, int& currentToken);

		virtual void addThirdParameter(vector<string>& tokens, int& currentToken);

	private:
		int ncount_ = 0;
	};

}