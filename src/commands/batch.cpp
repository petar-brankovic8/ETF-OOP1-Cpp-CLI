#include "batch.hpp"
#include "command.hpp"
#include <string>
#include <vector>

using std::string;
using std::vector;

namespace commands {

    Command* Batch::commandCreate()
    {
        return new Batch();
    }

    string Batch::run() {
        return string();
    }

    void Batch::addParameters(vector<string> tokens) {
        return;
    }

}