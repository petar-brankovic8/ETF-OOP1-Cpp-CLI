#include "truncate.hpp"
#include "command.hpp"
#include <string>
#include <vector>

using std::string;
using std::vector;

namespace commands {

    Command* Truncate::commandCreate()
    {
        return new Truncate();
    }

    string Truncate::run() {
        return string();
    }

    void Truncate::addParameters(vector<string> tokens) {
        return;
    }

}