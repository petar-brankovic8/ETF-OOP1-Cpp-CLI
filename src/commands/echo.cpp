#include "echo.hpp"
#include "command.hpp"
#include <string>
#include <vector>

using std::string;
using std::vector;

namespace commands {
    Echo::Echo() : Command(InputStreamType::Default, OutputStreamType::Default) {}

    Command* Echo::commandCreate()
    {
        return new Echo();
    }

    string Echo::run() {
        return string();
    }

    void Echo::addParameters(vector<string> tokens) {
        if (tokens.size() == 1)
            return;
        int currentToken = 1;
        addFirstParameter(tokens, currentToken);

        if (currentToken >= tokens.size())
            return;
        addSecondParameter(tokens, currentToken);

        if (currentToken < tokens.size())
            return; // Add throw exception logic
    }

    void Echo::addFirstParameter(vector<string>& tokens, int& currentToken) {
        if (isQuoteArgument(tokens[currentToken])) {
            setInputStream(InputStreamType::QuoteArgument);
            setInput(tokens[currentToken].substr(1, tokens[currentToken].size() - 2));
            currentToken++;
            return;
        }
        else if (isRedirectionSign(tokens[currentToken])) {
            if (currentToken + 1 >= tokens.size())
                return; // Add throw exception logic
            if (isInputStreamSign(tokens[currentToken])) {
                inputStreamRedirection(tokens[currentToken], tokens[currentToken + 1]);
            }
            if (isOutputStreamSign(tokens[currentToken])) {
                outputStreamRedirection(tokens[currentToken], tokens[currentToken + 1]);
            }
            currentToken += 2;
            return;
        }
        else  {
            setInputStream(InputStreamType::TxtFile);
            setInputFilename(tokens[currentToken]);
            currentToken++;
            return;
        }
    }

    void Echo::addSecondParameter(vector<string>& tokens, int& currentToken) {
        if (isRedirectionSign(tokens[currentToken])) {
            if (currentToken + 1 >= tokens.size())
                return; // Add throw exception logic
            if (isInputStreamSign(tokens[currentToken])) {
                inputStreamRedirection(tokens[currentToken], tokens[currentToken + 1]);
            }
            if (isOutputStreamSign(tokens[currentToken])) {
                outputStreamRedirection(tokens[currentToken], tokens[currentToken + 1]);
            }
            currentToken += 2;
        }
        else return; // Add throw exception logic
    }

}