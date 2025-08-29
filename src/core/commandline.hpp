#pragma once

#include "controller.hpp"
#include "../utils/translator.hpp"
#include "../commands/command.hpp"
#include <string>
#include <vector>
#include <istream>

using std::string;

class CommandLine {
public:
	CommandLine(string lineString, Translator* translator, istream* inputSource, Controller* controller);

	virtual string execute();

protected:
	virtual void checkSemantics() const;

	virtual void write(std::string text, OutputStreamType outputStream, std::string outputFilename = "");

private:
	Translator* myTranslator_;
	std::vector<Command*> commands_;
};