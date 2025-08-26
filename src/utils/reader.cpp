#include "reader.hpp"
#include "constants.hpp"
#include <iostream>
#include <string>

using namespace std;

string Reader::readLine() {
	string input;
	getline(cin, input);
	if (input.size() > kMaxLineSize)
		input.resize(kMaxLineSize);
	return input;
}