#include "date.hpp"
#include "command.hpp"
#include "../utils/exceptions.hpp"
#include <string>
#include <vector>
#include <chrono>
#include <iomanip>
#include <sstream>

using std::string;
using std::vector;

namespace commands {
    Date::Date() : Command(OutputStreamType::Default, "date") {}

    Command* Date::commandCreate()
    {
        return new Date();
    }

    string Date::run() {
        auto now = std::chrono::system_clock::now();
        std::time_t currentTime = std::chrono::system_clock::to_time_t(now);
        std::tm* localTime = std::localtime(&currentTime);
        std::stringstream ss;
        ss << std::put_time(localTime, "%d.%m.%Y.");
        return ss.str();
    }

    void Date::addParameters(vector<string> tokens) {
        if (tokens.size() == 1)
            return;
        int currentToken = 1;
        addFirstParameter(tokens, currentToken);

        if (currentToken < tokens.size())
            throw TooManyArgumentsException(getCommandName());
    }

    void Date::addFirstParameter(vector<string>& tokens, int& currentToken) {
        if (!isOutputStreamSign(tokens[currentToken]))
            throw TooManyArgumentsException(getCommandName());
        if (currentToken + 1 >= tokens.size())
            throw MissingRedirectionArgumentException(getCommandName());
        outputStreamRedirection(tokens[currentToken], tokens[currentToken + 1]);
        currentToken += 2;
    }

}