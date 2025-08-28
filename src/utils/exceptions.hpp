#pragma once

#include <stdexcept>
#include <string>

using std::runtime_error;
using std::string;

struct UnkownCommandException : public runtime_error {
	using runtime_error::runtime_error;
};

struct MissingRedirectionArgument : public runtime_error {
	using runtime_error::runtime_error;
};

struct TooManyArguments : public runtime_error {
	using runtime_error::runtime_error;
};