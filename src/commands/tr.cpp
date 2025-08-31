#include "tr.hpp"
#include "command.hpp"
#include "../utils/exceptions.hpp"
#include <string>
#include <vector>

using std::string;
using std::vector;

namespace commands {
    Tr::Tr() : Command(InputStreamType::Default, OutputStreamType::Default, "tr") {}

    Command* Tr::commandCreate()
    {
        return new Tr();
    }

    string Tr::run() {
        string input = loadInput();

        if (what_.empty())
            throw InvalidArgumentException(getCommandName());
        size_t pos = 0;
        while ((pos = input.find(what_, pos)) != string::npos) {
            input.replace(pos, what_.size(), with_);
            pos += with_.size();
        }

        return input;
    }

    void Tr::addParameters(vector<string> tokens) {
        if (tokens.size() == 1)
            throw ExpectedArgumentException(getCommandName());
        int currentToken = 1;
        bool whatDefined = false;
        addFirstParameter(tokens, currentToken, whatDefined);

        if (currentToken >= tokens.size() && !whatDefined)
            throw ExpectedArgumentException(getCommandName());
        if (currentToken >= tokens.size() && whatDefined)
            return;
        addSecondParameter(tokens, currentToken, whatDefined);

        if (currentToken >= tokens.size())
            return;
        addThirdParameter(tokens, currentToken);

        if (currentToken >= tokens.size())
            return;
        addFourthParameter(tokens, currentToken);

        if (currentToken < tokens.size())
            throw TooManyArgumentsException(getCommandName());
    }

    void Tr::addFirstParameter(vector<string>& tokens, int& currentToken, bool& whatDefined) {
        if (isRedirectionSign(tokens[currentToken]))
            throw ExpectedArgumentBeforeRedirectionException(getCommandName());
        if (currentToken + 1 < tokens.size() && isQuoteArgument(tokens[currentToken]) && isQuoteArgument(tokens[currentToken + 1])) {
            setInputStream(InputStreamType::QuoteArgument);
            setInput(tokens[currentToken].substr(1, tokens[currentToken].size() - 2));
            currentToken++;
        }
        else if (isQuoteArgument(tokens[currentToken])) {
            setWhat(tokens[currentToken].substr(1, tokens[currentToken].size() - 2));
            whatDefined = true;
            currentToken++;
            return;
        }
        else {
            setInputStream(InputStreamType::TxtFile);
            setInputFilename(tokens[currentToken]);
            currentToken++;
            return;
        }
    }

    void Tr::addSecondParameter(vector<string>& tokens, int& currentToken, bool& whatDefined) {
        if (!whatDefined && isRedirectionSign(tokens[currentToken]))
            throw ExpectedArgumentBeforeRedirectionException(getCommandName());
        if (!whatDefined && !isQuoteArgument(tokens[currentToken]))
            throw ExpectedQuotedArgumentException(getCommandName());
        if (!whatDefined) {
            setWhat(tokens[currentToken].substr(1, tokens[currentToken].size() - 2));
            whatDefined = true;
            currentToken++;
            return;
        }

        if (!isRedirectionSign(tokens[currentToken]))
            throw ExpectedQuotedArgumentException(getCommandName());
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

    void Tr::addThirdParameter(vector<string>& tokens, int& currentToken) {
        if (isQuoteArgument(tokens[currentToken]) && isQuoteArgument(tokens[currentToken - 1])) {
            setWith(tokens[currentToken].substr(1, tokens[currentToken].size() - 2));
            currentToken++;
            return;
        }
        else if (isQuoteArgument(tokens[currentToken]))
            throw RedirectionNotAtEndException(getCommandName());
        
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

    void Tr::addFourthParameter(vector<string>& tokens, int& currentToken) {
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