#include "date.hpp"
#include "command.hpp"
#include <string>
#include <vector>

using std::string;
using std::vector;

namespace commands {
    Date::Date() : Command(OutputStreamType::Default) {}

    Command* Date::commandCreate()
    {
        return new Date();
    }

    string Date::run() {
        return string();
    }

    void Date::addParameters(vector<string> tokens) {
        return;
    }

}