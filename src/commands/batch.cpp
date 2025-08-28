#include "batch.hpp"
#include "command.hpp"
#include "../utils/exceptions.hpp"
#include <string>
#include <vector>

using std::string;
using std::vector;

namespace commands {
    Batch::Batch() : Command(InputStreamType::Default, OutputStreamType::Default, "batch") {}

    Command* Batch::commandCreate()
    {
        return new Batch();
    }

    string Batch::run() {
        return string();
    }

    void Batch::addParameters(vector<string> tokens) {
        if (tokens.size() == 1)
            return;
        int currentToken = 1;
        addFirstParameter(tokens, currentToken);

        if (currentToken >= tokens.size())
            return;
        addSecondParameter(tokens, currentToken);

        if (currentToken < tokens.size())
            throw TooManyArgumentsException(getCommandName());
    }

    void Batch::addFirstParameter(vector<string>& tokens, int& currentToken) {
        if (isQuoteArgument(tokens[currentToken])) {
            setInputStream(InputStreamType::QuoteArgument);
            setInput(tokens[currentToken].substr(1, tokens[currentToken].size() - 2));
            currentToken++;
            return;
        }
        else if (isRedirectionSign(tokens[currentToken])) {
            if (currentToken + 1 >= tokens.size())
                throw MissingRedirectionArgumentException(getCommandName());
            if (isInputStreamSign(tokens[currentToken])) {
                inputStreamRedirection(tokens[currentToken], tokens[currentToken + 1]);
            }
            if (isOutputStreamSign(tokens[currentToken])) {
                outputStreamRedirection(tokens[currentToken], tokens[currentToken + 1]);
            }
            currentToken += 2;
            return;
        }
        else {
            setInputStream(InputStreamType::TxtFile);
            setInputFilename(tokens[currentToken]);
            currentToken++;
            return;
        }
    }

    void Batch::addSecondParameter(vector<string>& tokens, int& currentToken) {
        if (isRedirectionSign(tokens[currentToken])) {
            if (currentToken + 1 >= tokens.size())
                throw MissingRedirectionArgumentException(getCommandName());
            if (isInputStreamSign(tokens[currentToken])) {
                inputStreamRedirection(tokens[currentToken], tokens[currentToken + 1]);
            }
            if (isOutputStreamSign(tokens[currentToken])) {
                outputStreamRedirection(tokens[currentToken], tokens[currentToken + 1]);
            }
            currentToken += 2;
        }
        else throw TooManyArgumentsException(getCommandName());
    }

}