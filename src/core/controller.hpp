#pragma once

#include "../utils/translator.hpp"
#include <string>

class Controller {
public:
	Controller(Translator* translator);

	void run();

private:
	std::string prompt_ = "$";
	Translator* myTranslator_;
};