#include "time.hpp"
#include "command.hpp"
#include <string>
#include <vector>

using std::string;
using std::vector;

namespace commands {
    Time::Time() : Command(OutputStreamType::Default, "time") {}

    Command* Time::commandCreate()
    {
        return new Time();
    }

    string Time::run() {
        return string();
    }

    void Time::addParameters(vector<string> tokens) {
        return;
    }

}