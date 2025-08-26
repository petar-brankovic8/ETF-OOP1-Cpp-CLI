#pragma once

#include "../utils/reader.hpp"
#include "../utils/translator.hpp"
#include "../utils/writer.hpp"
#include <string>

class Controller {
public:
	Controller(Reader* reader, Translator* translator, Writer* writer);

	void run();

private:
	std::string prompt_ = "$";
	Reader* myReader_;
	Translator* myTranslator_;
	Writer* myWriter_;
};