#include "writer.hpp"
#include "constants.hpp"
#include <iostream>
#include <string>

using namespace std;

void Writer::defaultWrite(string text) {
	cout << text;
}

void Writer::write(string text, OutputStreamType outputStream, string outputFilename) {
	// Add logic
	;
}