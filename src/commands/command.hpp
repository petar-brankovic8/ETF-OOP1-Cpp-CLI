#pragma once

#include "../utils/constants.hpp"
#include <string>

namespace commands {

	class Command {
	public:
		virtual std::string run() = 0;

		OutputStreamType getOutputStreamType() const { return outputStream_; }

	private:
		InputStreamType inputStream_;
		OutputStreamType outputStream_;
	};

}