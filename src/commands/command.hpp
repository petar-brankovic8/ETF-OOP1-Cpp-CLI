#pragma once

#include "../utils/constants.hpp"
#include <string>
#include <vector>

using std::string;
using std::vector;

namespace commands {

	class Command {
	public:
		virtual string run() = 0;

		virtual void addParameters(vector<string> tokens) = 0;

		OutputStreamType getOutputStream() const { return outputStream_; }
		
		string getCommandName() { return commandName_; }
		InputStreamType getInputStream() { return inputStream_; }
		OutputStreamType getOutputStream() { return outputStream_; }

		void setInputStream(InputStreamType inputStream) { inputStream_ = inputStream; }
		void setOutputStream(OutputStreamType outputStream) { outputStream_ = outputStream; }

	protected:
		Command(string commandName);
		Command(InputStreamType inputStream, string commandName);
		Command(OutputStreamType outputStream, string commandName);
		Command(InputStreamType inputStream, OutputStreamType outputStream, string commandName);		

		bool isRedirectionSign(string& s) { return s == ">" || s == ">>" || s == "<"; }
		bool isQuoteArgument(string& s) { return  s.size() >= 2 && s[0] == '\"' && s[s.size() - 1] == '\"'; }
		bool isOptionArgument(string& s) { return s[0] == '-'; }

	private:
		const string commandName_;
		InputStreamType inputStream_ = InputStreamType::NoInputStream;
		OutputStreamType outputStream_ = OutputStreamType::NoOutputStream;
	};

}