#include "wc.hpp"
#include "command.hpp"
#include "../utils/exceptions.hpp"
#include <string>
#include <vector>
#include <sstream>

using namespace std;

namespace commands {
    Wc::Wc() : Command(InputStreamType::Default, OutputStreamType::Default, "wc") {}

    Command* Wc::commandCreate()
    {
        return new Wc();
    }

    string Wc::run() {
        string input = loadInput();

        int result = -1;
        if (option_ == Option::Word) result = countWords(input);
        if (option_ == Option::Char) result = countChars(input);

        return to_string(result);
    }

    void Wc::addParameters(vector<string> tokens) {
        if (tokens.size() == 1)
            throw ExpectedArgumentException(getCommandName());
        int currentToken = 1;
        addFirstParameter(tokens, currentToken);

        if (currentToken >= tokens.size())
            return;
        addSecondParameter(tokens, currentToken);

        if (currentToken >= tokens.size())
            return;
        addThirdParameter(tokens, currentToken);

        if (currentToken < tokens.size())
            throw TooManyArgumentsException(getCommandName());
    }

    void Wc::addFirstParameter(vector<string>& tokens, int& currentToken) {
        if (!isOptionArgument(tokens[currentToken]))
            throw ExpectedOptionArgumentException(getCommandName());
        if (tokens[currentToken] == "-w")
            setOption(Option::Word);
        else if (tokens[currentToken] == "-c")
            setOption(Option::Char);
        else
            throw InvalidOptionException(getCommandName());
        currentToken++;
    }

    void Wc::addSecondParameter(vector<string>& tokens, int& currentToken) {
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

    void Wc::addThirdParameter(vector<string>& tokens, int& currentToken) {
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

    int Wc::countWords(const string& s) {
        stringstream ss(s);
        int wordCount = 0;
        string temp;
        while (ss >> temp)
            wordCount++;
        return wordCount;
    }

    int Wc::countChars(const string& s) {
        return s.size();
    }

}