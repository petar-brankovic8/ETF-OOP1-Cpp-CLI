#include "command.hpp"
#include "command.hpp"
#include "command.hpp"
#include "command.hpp"
#include "command.hpp"
#include "..\utils\constants.hpp"

namespace commands {

	Command::Command(string commandName) : commandName_(commandName) {}

	Command::Command(InputStreamType inputStream, string commandName) : inputStream_(inputStream), commandName_(commandName) {}

	Command::Command(OutputStreamType outputStream, string commandName) : outputStream_(outputStream), commandName_(commandName) {}

	Command::Command(InputStreamType inputStream, OutputStreamType outputStream, string commandName) : inputStream_(inputStream), outputStream_(outputStream), commandName_(commandName) {}

}