#include "Logger.h"

Logger::Logger(std::ostream *stream) : stream(stream) {}

void Logger::output(std::string s) {
    (*stream) << s << std::endl;
}

void Logger::error(std::string s) {
    (*stream) << "ERR: " << s << std::endl;
}