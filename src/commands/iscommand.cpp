#include "iscommand.hpp"
#include <string>

using namespace std;

namespace commands {

	void InputStreamCommand::insertPipeline(string pipeline) {
		// Add logic
		;
	}

	InputStreamCommand::InputStreamCommand() : Command(InputStreamType::Default) {}

	void InputStreamCommand::inputStreamRedirection(string redirectionSign, string filename) {
		// Add logic
		;
	}

}