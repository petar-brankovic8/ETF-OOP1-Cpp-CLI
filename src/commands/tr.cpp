#include "tr.hpp"
#include "command.hpp"
#include <string>
#include <vector>

using std::string;
using std::vector;

namespace commands {
    Tr::Tr() : Command(InputStreamType::Default, OutputStreamType::Default) {}

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