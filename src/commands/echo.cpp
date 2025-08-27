#include "echo.hpp"
#include "command.hpp"
#include <string>
#include <vector>

using std::string;
using std::vector;

namespace commands {

    Command* Echo::commandCreate()
    {
        return new Echo();
    }

    string Echo::run() {
        return string();
    }

    void Echo::addParameters(vector<string> tokens) {
        return;
    }

}