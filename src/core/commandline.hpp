#pragma once

#include "../utils/translator.hpp"
#include "../utils/writer.hpp"
#include "../commands/command.hpp"
#include <string>
#include <vector>

class CommandLine {
public:
	CommandLine(std::string lineString, Translator* translator, Writer* writer);

	virtual void execute();

private:
	Translator* myTranslator_;
	Writer* myWriter_;
	std::vector<Command*> commands_;
};