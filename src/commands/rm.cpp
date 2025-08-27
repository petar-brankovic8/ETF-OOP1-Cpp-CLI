#include "rm.hpp"
#include "command.hpp"
#include <string>
#include <vector>

using std::string;
using std::vector;

namespace commands {

    Command* Rm::commandCreate()
    {
        return new Rm();
    }

    string Rm::run() {
        return string();
    }

    void Rm::addParameters(vector<string> tokens) {
        return;
    }

}