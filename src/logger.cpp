#include "logger.h"

#include <fstream>
#include <ctime>

void Logger::log(const std::string& message)
{
    std::ofstream file(
        "logs/development.log",
        std::ios::app
    );

    if (!file)
    {
        return;
    }

    std::time_t currentTime = std::time(nullptr);

    file << std::ctime(&currentTime)
         << " : "
         << message
         << std::endl;
}
