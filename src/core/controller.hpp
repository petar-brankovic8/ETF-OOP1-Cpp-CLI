#pragma once

#include "../utils/translator.hpp"
#include "../utils/exceptions.hpp"
#include "../commands/prompt.hpp"
#include <string>

using std::string;
using std::runtime_error;

class Controller {
public:
	Controller(Translator* translator);

	virtual void run();

	virtual string exceptionHandler(runtime_error& e);

	friend string commands::Prompt::run();

protected:
	void setPrompt(string prompt) { prompt_ = prompt; }

private:
	string prompt_ = "$";
	Translator* myTranslator_;
};