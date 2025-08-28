#pragma once

#include <stdexcept>
#include <string>

using std::runtime_error;
using std::string;

struct UnkownCommandException : public runtime_error {
	explicit UnkownCommandException(string& unknownCommand) : runtime_error("Unkown command: " + unknownCommand) {}
};