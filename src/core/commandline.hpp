#pragma once

#include "../utils/translator.hpp"
#include "../commands/command.hpp"
#include <string>
#include <vector>

class CommandLine {
public:
	CommandLine(std::string lineString, Translator* translator);

	virtual void execute();

private:
	Translator* myTranslator_;
	std::vector<Command*> commands;
};