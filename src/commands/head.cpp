#include "head.hpp"
#include "command.hpp"
#include <string>
#include <vector>

using std::string;
using std::vector;

namespace commands {
    Head::Head() : Command(InputStreamType::Default, OutputStreamType::Default) {}

    Command* Head::commandCreate()
    {
        return new Head();
    }

    string Head::run() {
        return string();
    }

    void Head::addParameters(vector<string> tokens) {
        return;
    }

}