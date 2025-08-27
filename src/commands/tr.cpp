#include "tr.hpp"
#include "command.hpp"
#include <string>
#include <vector>

using std::string;
using std::vector;

namespace commands {

    Command* Tr::commandCreate()
    {
        return new Tr();
    }

    string Tr::run() {
        return string();
    }

    void Tr::addParameters(vector<string> tokens) {
        return;
    }

}