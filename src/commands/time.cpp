#include "time.hpp"
#include "command.hpp"
#include "../utils/exceptions.hpp"
#include <string>
#include <vector>
#include <chrono>
#include <iomanip>
#include <sstream>

using namespace std;

namespace commands {
    Time::Time() : Command(OutputStreamType::Default, "time") {}

    Command* Time::commandCreate()
    {
        return new Time();
    }

    string Time::run() {
        auto now = std::chrono::system_clock::now();
        std::time_t currentTime = std::chrono::system_clock::to_time_t(now);
        std::tm* localTime = std::localtime(&currentTime);
        std::stringstream ss;
        ss << std::put_time(localTime, "%H:%M:%S");
        return ss.str();
    }

    void Time::addParameters(vector<string> tokens) {
        if (tokens.size() == 1)
            return;
        int currentToken = 1;
        addFirstParameter(tokens, currentToken);

        if (currentToken < tokens.size())
            throw TooManyArgumentsException(getCommandName());
    }

    void Time::addFirstParameter(vector<string>& tokens, int& currentToken) {
        if (!isOutputStreamSign(tokens[currentToken]))
            throw TooManyArgumentsException(getCommandName());
        if (currentToken + 1 >= tokens.size())
            throw MissingRedirectionArgumentException(getCommandName());
        outputStreamRedirection(tokens[currentToken], tokens[currentToken + 1]);
        currentToken += 2;
    }

}