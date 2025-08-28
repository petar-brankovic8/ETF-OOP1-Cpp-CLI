#include "rm.hpp"
#include "command.hpp"
#include "../utils/exceptions.hpp"
#include <string>
#include <vector>

using std::string;
using std::vector;

namespace commands {
    Rm::Rm() : Command("rm") {}

    Command* Rm::commandCreate()
    {
        return new Rm();
    }

    string Rm::run() {
        return string();
    }

    void Rm::addParameters(vector<string> tokens) {
        if (tokens.size() == 1)
            throw ExpectedArgumentException(getCommandName());
        int currentToken = 1;
        addFirstParameter(tokens, currentToken);

        if (currentToken < tokens.size())
            throw TooManyArgumentsException(getCommandName());
    }

    void Rm::addFirstParameter(vector<string>& tokens, int& currentToken) {
        if (isQuoteArgument(tokens[currentToken]) || isRedirectionSign(tokens[currentToken]))
            throw ExpectedFilenameArgumentException(getCommandName());
        setFilename(tokens[currentToken]);
        currentToken++;
    }

}