#pragma once

#include "../utils/constants.hpp"
#include <string>
#include <vector>

namespace commands {

	class Command {
	public:
		virtual std::string run() = 0;

		virtual void addParameters(std::vector<std::string> tokens) = 0;

		OutputStreamType getOutputStreamType() const { return outputStream_; }

	private:
		InputStreamType inputStream_;
		OutputStreamType outputStream_;
	};

}