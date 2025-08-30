#include "truncate.hpp"
#include "command.hpp"
#include "../utils/exceptions.hpp"
#include <string>
#include <vector>
#include <filesystem>
#include <fstream>

using namespace std;

namespace commands {
    Truncate::Truncate() : Command("truncate") {}

    Command* Truncate::commandCreate()
    {
        return new Truncate();
    }

    string Truncate::run() {
        if (!filesystem::exists(filename_))
            throw FileNotFoundException(getCommandName());
        if (ofstream ofs(filename_); !ofs)
            throw FileNotOpenedException(getCommandName());
        return "";
    }

    void Truncate::addParameters(vector<string> tokens) {
        if (tokens.size() == 1)
            throw ExpectedArgumentException(getCommandName());
        int currentToken = 1;
        addFirstParameter(tokens, currentToken);

        if (currentToken < tokens.size())
            throw TooManyArgumentsException(getCommandName());
    }

    void Truncate::addFirstParameter(vector<string>& tokens, int& currentToken) {
        if (isQuoteArgument(tokens[currentToken]) || isRedirectionSign(tokens[currentToken]))
            throw ExpectedFilenameArgumentException(getCommandName());
        setFilename(tokens[currentToken]);
        currentToken++;
    }
}