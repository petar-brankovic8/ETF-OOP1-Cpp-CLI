#include "iscommand.hpp"
#include "../utils/constants.hpp"
#include "../utils/exceptions.hpp"
#include <string>

using std::string;

namespace commands {

	void InputStreamCommand::inputStreamRedirection(string redirectionSign, string filename) {
		if (getInputStream() != InputStreamType::Default)
			throw TooManyInputStreamDefinitionsException(getCommandName());
		setInputStream(InputStreamType::TxtFile);
		setInputFilename(filename);
	}

}