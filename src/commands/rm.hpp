#pragma once

#include "command.hpp"
#include <string>
#include <vector>

using std::string;
using std::vector;

namespace commands {

	class Rm : public Command {
	public:
		Rm();

		static Command* commandCreate();

		string run() override;

		void addParameters(vector<string> tokens) override;

	protected:
		void setFilename(string filename) { filename_ = filename; }

		virtual void addFirstParameter(vector<string>& tokens, int& currentToken);

	private:
		string filename_;
	};

}