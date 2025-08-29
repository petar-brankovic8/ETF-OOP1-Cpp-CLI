#include "Touch.hpp"
#include "command.hpp"
#include "../utils/exceptions.hpp"
#include <string>
#include <vector>
#include <fstream>
#include <filesystem>

using namespace std;

namespace commands {
    Touch::Touch() : Command("touch") {}
    Command* Touch::commandCreate()
    {
        return new Touch();
    }

    string Touch::run() {
        if (filesystem::exists(filename_))
            throw FileAlreadyExistsException(getCommandName());
        ofstream outfile(filename_);
        if (!outfile.is_open())
            throw FileNotCreatedException(getCommandName());
        return "";
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