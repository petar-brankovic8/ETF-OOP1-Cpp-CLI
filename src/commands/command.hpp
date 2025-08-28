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

		OutputStreamType getOutputStreamType() const { return outputStream_; }

	protected:
		Command(InputStreamType inputStream);
		Command(OutputStreamType outputStream);
		Command(InputStreamType inputStream, OutputStreamType outputStream);

		inline void setInputStream(InputStreamType inputStream) { inputStream_ = inputStream;  }
		inline void setOutputStream(OutputStreamType outputStream) { outputStream_ = outputStream; }

		inline bool isRedirectionSign(string& s) { return s == ">" || s == ">>" || s == "<"; }
		inline bool isQuoteArgument(string& s) { return s[0] == '\"' && s[s.size() - 1] == '\"' && s.size() >= 2; }

	private:
		InputStreamType inputStream_ = InputStreamType::NoInputStream;
		OutputStreamType outputStream_ = OutputStreamType::NoOutputStream;
	};

}