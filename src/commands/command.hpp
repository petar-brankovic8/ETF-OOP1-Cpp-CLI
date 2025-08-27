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

	private:
		InputStreamType inputStream_ = InputStreamType::NoInputStream;
		OutputStreamType outputStream_ = OutputStreamType::NoOutputStream;
	};

}