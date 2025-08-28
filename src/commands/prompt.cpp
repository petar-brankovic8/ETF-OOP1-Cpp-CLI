#include "prompt.hpp"
#include "command.hpp"
#include "../utils/exceptions.hpp"
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
        if (tokens.size() == 1)
            throw ExpectedArgumentException(getCommandName());
        int currentToken = 1;
        addFirstParameter(tokens, currentToken);

        if (currentToken < tokens.size())
            throw TooManyArgumentsException(getCommandName());
    }

    void Prompt::addFirstParameter(vector<string>& tokens, int& currentToken) {
        if (!isQuoteArgument(tokens[currentToken]))
            throw ExpectedQuotedArgument(getCommandName());
        setPromptString(tokens[currentToken].substr(1, tokens[currentToken].size()-2));
        currentToken++;
    }

}