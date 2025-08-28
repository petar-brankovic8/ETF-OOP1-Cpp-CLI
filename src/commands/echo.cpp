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

        int currentArg = 1;

        if (isQuoteArgument(tokens[currentArg])) {
            setInputStream(InputStreamType::QuoteArgument);
            setInput(tokens[currentArg].substr(1, tokens[currentArg].size() - 2));
            currentArg++;
        }
        else if (!isRedirectionSign(tokens[currentArg])) {
            setInputStream(InputStreamType::TxtFile);
            setInput(tokens[currentArg]);
            currentArg++;
        }

        if (currentArg >= tokens.size())
            return;

        if (isRedirectionSign(tokens[currentArg])) {
            if (currentArg + 1 >= tokens.size())
                return; // Add throw exception logic
            if (isInputStreamSign(tokens[currentArg])) {
                inputStreamRedirection(tokens[currentArg], tokens[currentArg+1]);
            }
            if (isOutputStreamSign(tokens[currentArg])) {
                outputStreamRedirection(tokens[currentArg], tokens[currentArg + 1]);
            }
            currentArg += 2;
        }
        else return; // Add throw exception logic

        if (currentArg >= tokens.size())
            return;

        if (isRedirectionSign(tokens[currentArg])) {
            if (currentArg + 1 >= tokens.size())
                return; // Add throw exception logic
            if (isInputStreamSign(tokens[currentArg])) {
                inputStreamRedirection(tokens[currentArg], tokens[currentArg + 1]);
            }
            if (isOutputStreamSign(tokens[currentArg])) {
                outputStreamRedirection(tokens[currentArg], tokens[currentArg + 1]);
            }
            currentArg += 2;
        }
        else return; // Add throw exception logic

        if (currentArg < tokens.size())
            return; // Add throw exception logic
    }

}