#include "rm.hpp"
#include "command.hpp"
#include "../utils/exceptions.hpp"
#include <string>
#include <vector>
#include <filesystem>

using namespace std;

namespace commands {
    Rm::Rm() : Command("rm") {}

    Command* Rm::commandCreate()
    {
        return new Rm();
    }

    string Rm::run() {
        if (!filesystem::remove(filename_))
            throw FileNotFoundException(getCommandName());
        return "";
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