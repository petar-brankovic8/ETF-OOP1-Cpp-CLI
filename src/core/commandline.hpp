#pragma once

#include "../utils/translator.hpp"
#include <string>

class CommandLine {
public:
	CommandLine(std::string lineString, Translator* translator);

	virtual void execute();

private:
	Translator* myTranslator_;
};