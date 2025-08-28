#include "date.hpp"
#include "command.hpp"
#include "../utils/exceptions.hpp"
#include <string>
#include <vector>

using std::string;
using std::vector;

namespace commands {
    Date::Date() : Command(OutputStreamType::Default, "date") {}

    Command* Date::commandCreate()
    {
        return new Date();
    }

    string Date::run() {
        return string();
    }

    void Date::addParameters(vector<string> tokens) {
        if (tokens.size() == 1)
            return;
        int currentToken = 1;
        addFirstParameter(tokens, currentToken);

        if (currentToken < tokens.size())
            throw TooManyArgumentsException(getCommandName());
    }

    void Date::addFirstParameter(vector<string>& tokens, int& currentToken) {
        if (!isOutputStreamSign(tokens[currentToken]))
            throw TooManyArgumentsException(getCommandName());
        if (currentToken + 1 >= tokens.size())
            throw MissingRedirectionArgumentException(getCommandName());
        outputStreamRedirection(tokens[currentToken], tokens[currentToken + 1]);
        currentToken += 2;
    }

}