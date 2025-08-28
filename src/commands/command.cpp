#include "command.hpp"
#include "command.hpp"
#include "command.hpp"
#include "command.hpp"
#include "..\utils\constants.hpp"

namespace commands {

	Command::Command() {}

	Command::Command(InputStreamType inputStream) : inputStream_(inputStream) {}

	Command::Command(OutputStreamType outputStream) : outputStream_(outputStream) {}

	Command::Command(InputStreamType inputStream, OutputStreamType outputStream) : inputStream_(inputStream), outputStream_(outputStream) {}

}