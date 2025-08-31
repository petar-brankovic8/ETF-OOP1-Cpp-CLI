#include "oscommand.hpp"
#include "../utils/constants.hpp"
#include "../utils/exceptions.hpp"
#include <string>

using std::string;

namespace commands {

	void OutputStreamCommand::outputStreamRedirection(string sign, string outputFilename) {
		if (getOutputStream() != OutputStreamType::Default)
			throw TooManyOutputStreamDefinitionsException(getCommandName());
		if (sign == ">") setOutputStream(OutputStreamType::TxtFileOverwrite);
		else if (sign == ">>") setOutputStream(OutputStreamType::TxtFileAppend);
		setOutputFilename(outputFilename);
	}

}

