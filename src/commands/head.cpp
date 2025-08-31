#include "head.hpp"
#include "command.hpp"
#include "../utils/exceptions.hpp"
#include <string>
#include <vector>
#include <sstream>

using namespace std;

namespace commands {
    Head::Head() : Command(InputStreamType::Default, OutputStreamType::Default, "head") {}

    Command* Head::commandCreate()
    {
        return new Head();
    }

    string Head::run() {
        string input = loadInput();
        stringstream ss(input);
        string result = "", line;

        int ncount = ncount_;

        while (ncount-- && getline(ss, line))
            result += line + '\n';
        if (!result.empty())
            result.pop_back();

        return result;
    }

    void Head::addParameters(vector<string> tokens) {
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

    void Head::addFirstParameter(vector<string>& tokens, int& currentToken) {
        if (!isOptionArgument(tokens[currentToken]))
            throw ExpectedOptionArgumentException(getCommandName());
        if (tokens[currentToken].size() >= 3 && tokens[currentToken].size() <= 7 && tokens[currentToken][1] == 'n') {
            string count = tokens[currentToken].substr(2, 5);
            size_t pos = 0;
            try { setNcount(std::stoi(count, &pos)); }
            catch (...) { throw InvalidOptionException(getCommandName()); }
            if (pos != count.size())
                throw InvalidOptionException(getCommandName());
        }
        else
            throw InvalidOptionException(getCommandName());
        currentToken++;
    }

    void Head::addSecondParameter(vector<string>& tokens, int& currentToken) {
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

    void Head::addThirdParameter(vector<string>& tokens, int& currentToken) {
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