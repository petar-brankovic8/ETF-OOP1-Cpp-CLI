#include "Touch.hpp"
#include "command.hpp"
#include <string>
#include <vector>

using std::string;
using std::vector;

namespace commands {

    Command* Touch::commandCreate()
    {
        return new Touch();
    }

    string Touch::run() {
        return string();
    }

    void Touch::addParameters(vector<string> tokens) {
        return;
    }

}