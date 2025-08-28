#include "core/controller.hpp"
#include "utils/translator.hpp"


int main() {
	Translator* translator = new Translator();
	
	Controller myController = Controller(translator);
	myController.run();

	delete translator;
	return 0;
}