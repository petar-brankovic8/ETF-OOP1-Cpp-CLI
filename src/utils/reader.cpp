#include "reader.hpp"
#include <iostream>
#include <string>

using namespace std;

string Reader::readLine() {
	string input;
	getline(cin, input);
	return input;
}