#pragma once

#include "constants.hpp"
#include <string>

class Writer {
public:
	virtual void defaultWrite(std::string text);

	virtual void write(std::string text, OutputStreamType outputStream, std::string outputFilename = "");

	// Add functionalities
};