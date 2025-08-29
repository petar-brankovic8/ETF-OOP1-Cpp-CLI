#pragma once

#include "../utils/translator.hpp"
#include "../commands/prompt.hpp"
#include <string>

using std::string;

class Controller {
public:
	Controller(Translator* translator);

	void run();

	friend string commands::Prompt::run();

protected:
	void setPrompt(string prompt) { prompt_ = prompt; }

private:
	string prompt_ = "$";
	Translator* myTranslator_;
};