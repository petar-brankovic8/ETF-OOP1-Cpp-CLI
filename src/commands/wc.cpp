#include "wc.hpp"
#include "command.hpp"
#include <string>
#include <vector>

using std::string;
using std::vector;

namespace commands {

    Command* Wc::commandCreate()
    {
        return new Wc();
    }

    string Wc::run() {
        return string();
    }

    void Wc::addParameters(vector<string> tokens) {
        return;
    }

}