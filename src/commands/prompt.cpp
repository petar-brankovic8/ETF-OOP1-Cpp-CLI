#include "prompt.hpp"
#include "command.hpp"
#include <string>
#include <vector>

using std::string;
using std::vector;

namespace commands {
    Prompt::Prompt() : Command("prompt") {}

    Command* Prompt::commandCreate()
    {
        return new Prompt();
    }

    string Prompt::run() {
        return string();
    }

    void Prompt::addParameters(vector<string> tokens) {
        return;
    }

}