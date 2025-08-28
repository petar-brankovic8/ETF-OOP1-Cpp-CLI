#include "time.hpp"
#include "command.hpp"
#include "../utils/exceptions.hpp"
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
        if (tokens.size() == 1)
            return;
        int currentToken = 1;
        addFirstParameter(tokens, currentToken);

        if (currentToken < tokens.size())
            throw TooManyArgumentsException(getCommandName());
    }

    void Time::addFirstParameter(vector<string>& tokens, int& currentToken) {
        if (!isOutputStreamSign(tokens[currentToken]))
            throw TooManyArgumentsException(getCommandName());
        if (currentToken + 1 >= tokens.size())
            throw MissingRedirectionArgumentException(getCommandName());
        outputStreamRedirection(tokens[currentToken], tokens[currentToken + 1]);
        currentToken += 2;
    }

}