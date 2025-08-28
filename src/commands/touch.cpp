#include "Touch.hpp"
#include "command.hpp"
#include "../utils/exceptions.hpp"
#include <string>
#include <vector>

using std::string;
using std::vector;

namespace commands {
    Touch::Touch() : Command("touch") {}
    Command* Touch::commandCreate()
    {
        return new Touch();
    }

    string Touch::run() {
        return string();
    }

    void Touch::addParameters(vector<string> tokens) {
        if (tokens.size() == 1)
            throw ExpectedArgumentException(getCommandName());
        int currentToken = 1;
        addFirstParameter(tokens, currentToken);

        if (currentToken < tokens.size())
            throw TooManyArgumentsException(getCommandName());
    }

    void Touch::addFirstParameter(vector<string>& tokens, int& currentToken) {
        if (isQuoteArgument(tokens[currentToken]) || isRedirectionSign(tokens[currentToken]))
            throw ExpectedFilenameArgumentException(getCommandName());
        setFilename(tokens[currentToken]);
        currentToken++;
    }

}