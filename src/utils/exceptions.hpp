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

struct ExpectedQuotedArgumentException : public runtime_error {
	using runtime_error::runtime_error;
};

struct ExpectedFilenameArgumentException : public runtime_error {
	using runtime_error::runtime_error;
};

struct ExpectedOptionArgumentException : public runtime_error {
	using runtime_error::runtime_error;
};

struct InvalidOptionException : public runtime_error {
	using runtime_error::runtime_error;
};

struct ExpectedArgumentBeforeRedirectionException : public runtime_error {
	using runtime_error::runtime_error;
};

struct RedirectionNotAtEndException : public runtime_error {
	using runtime_error::runtime_error;
};

struct NoInputStreamException : public runtime_error {
	using runtime_error::runtime_error;
};

struct NoOutputStreamException : public runtime_error {
	using runtime_error::runtime_error;
};

struct ExpectedCommandAroundPipelineException : public runtime_error {
	using runtime_error::runtime_error;
};

struct FileNotOpenedException : public runtime_error {
	using runtime_error::runtime_error;
};

struct FileAlreadyExistsException : public runtime_error {
	using runtime_error::runtime_error;
};

struct FileNotCreatedException : public runtime_error {
	using runtime_error::runtime_error;
};

struct FileNotFoundException : public runtime_error {
	using runtime_error::runtime_error;
};