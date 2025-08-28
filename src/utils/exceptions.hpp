#pragma once

#include <stdexcept>
#include <string>

using std::runtime_error;
using std::string;

struct UnkownCommandException : public runtime_error {
	using runtime_error::runtime_error;
};

struct MissingRedirectionArgumentException : public runtime_error {
	using runtime_error::runtime_error;
};

struct TooManyArgumentsException : public runtime_error {
	using runtime_error::runtime_error;
};

struct TooManyInputStreamDefinitionsException : public runtime_error {
	using runtime_error::runtime_error;
};

struct TooManyOutputStreamDefinitionsException : public runtime_error {
	using runtime_error::runtime_error;
};

struct ExpectedArgumentException : public runtime_error {
	using runtime_error::runtime_error;
};

struct ExpectedQuotedArgument : public runtime_error {
	using runtime_error::runtime_error;
};