#include "core/controller.hpp"
#include "utils/reader.hpp"
#include "utils/translator.hpp"
#include "utils/writer.hpp"

int main() {
	Reader* reader = new Reader();
	Translator* translator = new Translator();
	Writer* writer = new Writer();

	Controller myController = Controller(reader, translator, writer);
	myController.run();

	delete reader;
	delete translator;
	delete writer;
	return 0;
}