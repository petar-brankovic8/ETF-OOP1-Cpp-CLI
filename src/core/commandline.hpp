#pragma once

#include "../utils/translator.hpp"
#include "../commands/command.hpp"
#include <string>
#include <vector>

class CommandLine {
public:
	CommandLine(std::string lineString, Translator* translator);

	virtual void execute();

protected:
	virtual void checkSemantics() const;

	virtual void write(std::string text, OutputStreamType outputStream, std::string outputFilename = "");

private:
	Translator* myTranslator_;
	std::vector<Command*> commands_;
};